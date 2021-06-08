#include <cstring>
#include <ctime>
#include <iostream>
#include <memory>
#include <string>
#include <openssl/asn1.h>
#include <openssl/bio.h>
#include <openssl/conf.h>
#include <openssl/err.h>
#include <openssl/pem.h>
#include <openssl/x509.h>


// Smart pointers to wrap openssl C types that need explicit free
using BIO_ptr = std::unique_ptr<BIO, decltype(&BIO_free)>;
using X509_ptr = std::unique_ptr<X509, decltype(&X509_free)>;
using ASN1_TIME_ptr = std::unique_ptr<ASN1_TIME, decltype(&ASN1_STRING_free)>;


// Convert the contents of an openssl BIO to a std::string
std::string bio_to_string(const BIO_ptr& bio, const int& max_len)
{
    // We are careful to do operations based on explicit lengths, not depending
    // on null terminated character streams except where we ensure the terminator

    // Create a buffer and zero it out
    char buffer[max_len];
    memset(buffer, 0, max_len);
    // Read one smaller than the buffer to make sure we end up with a null
    // terminator no matter what
    BIO_read(bio.get(), buffer, max_len - 1);
    return std::string(buffer);
}


int main(int argc, char** argv)
{
    OpenSSL_add_all_algorithms();
    ERR_load_crypto_strings();
    OPENSSL_no_config();


    //
    // Read the certificate contents from disk
    //
    if (argc < 2)
    {
        std::cout << "Missing filename" << std::endl;
        return 1;
    }
    std::string inFile(argv[1]);
    std::cout << inFile << std::endl;
    std::cout << std::endl;

    BIO_ptr input(BIO_new(BIO_s_file()), BIO_free);
    if (BIO_read_filename(input.get(), inFile.c_str()) <= 0)
    {
        std::cout << "Error reading file" << std::endl;
        return 1;
    }


    //
    // Or if you already have the certificate in a string
    //
/*
    string cert_content = R"(-----BEGIN CERTIFICATE-----
MIIEdzCCA1+gAwIBAgIJAMwbIhWY43/zMA0GCSqGSIb3DQEBBQUAMIGDMQswCQYD
VQQGEwJVUzELMAkGA1UECBMCTlYxFTATBgNVBAcUDFZlZ2FzLCBCYWJ5ITEhMB8G
A1UEChMYV2hhdCBIYXBwZW5zIGluIFZlZ2FzLi4uMS0wKwYJKoZIhvcNAQkBFh53
aGF0aGFwcGVuc0B2ZWdhc3N0YXlzaW4udmVnYXMwHhcNMTcwMzA4MjI1MDI2WhcN
MjcwMzA2MjI1MDI2WjCBgzELMAkGA1UEBhMCVVMxCzAJBgNVBAgTAk5WMRUwEwYD
VQQHFAxWZWdhcywgQmFieSExITAfBgNVBAoTGFdoYXQgSGFwcGVucyBpbiBWZWdh
cy4uLjEtMCsGCSqGSIb3DQEJARYed2hhdGhhcHBlbnNAdmVnYXNzdGF5c2luLnZl
Z2FzMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA8U+28fnLKQNWEWMR
6akeDKuehSpS79odLGigI18qlCV/AUY5ZLjqsTjBvTJVRv44yoCTgNrx36U7FHP4
t6P/Si0aYr4ovxl5wDpEM3Qyy5JPB7JelOB6AD7fmiTweP20HRYpZvY+Uz7LYEFC
mrgpGZQF3iOSIcBHtLKE5186JVT6j5dg6yjUGQO352ylc9HXHcn6lb/jyl0DmVNU
Z0caQwAmIS3Jmoyx+zj/Ya4WKq+2SqTAX7bX0F3wHHfXnZlHnM8fET5N/9A+K6lS
7dg9cyXu4afXcgKy14JiNBvqbBjhgJtE76yAy6rTHu0xM3jjdkcb9Y8miNzxF+AC
q+itawIDAQABo4HrMIHoMB0GA1UdDgQWBBRvvBRPno5S34zGRhrnDJyTsdnEbTCB
uAYDVR0jBIGwMIGtgBRvvBRPno5S34zGRhrnDJyTsdnEbaGBiaSBhjCBgzELMAkG
A1UEBhMCVVMxCzAJBgNVBAgTAk5WMRUwEwYDVQQHFAxWZWdhcywgQmFieSExITAf
BgNVBAoTGFdoYXQgSGFwcGVucyBpbiBWZWdhcy4uLjEtMCsGCSqGSIb3DQEJARYe
d2hhdGhhcHBlbnNAdmVnYXNzdGF5c2luLnZlZ2FzggkAzBsiFZjjf/MwDAYDVR0T
BAUwAwEB/zANBgkqhkiG9w0BAQUFAAOCAQEAhVND5s71mQPECwVLfiE/ndtIbnpe
Mqo5geQHCHnNlu5RV9j8aYHp9kW2qCDJ5vueZtZ2L1tC4D7JyfS37l4rRolFpX6N
iebEgAaE5eWvB6zgiAcMRIKqu3DmJ7y3CFGk9dHOlQ+WYnoO/eIMy0coT26JBl5H
DEwvdl+DwkxnS1cx1vERv51g1gua6AE3tBrlov8q1G4zMJboo3YEwMFwxLkxAFXR
HgMoPDym099kvc84B1k7HkDGHpr4tLfVelDJy2zCWIQ5ddbVpyPW2xuE4p4BGx2B
7ASOjG+DzUxzwaUI6Jzvs3Xq5Jx8ZAjJDgl0QoQDWNDoTeRBsz80nwiouA==
-----END CERTIFICATE-----)";

    // Put the certificate contents into an openssl IO stream (BIO)
    BIO_ptr input(BIO_new(BIO_s_mem()), BIO_free);
    BIO_write(input.get(), cert_content.c_str(), cert_content.size());
*/

    // Create an openssl certificate from the BIO
    X509_ptr cert(PEM_read_bio_X509_AUX(input.get(), NULL, NULL, NULL), X509_free);

    // Create a BIO to hold info from the cert
    BIO_ptr output_bio(BIO_new(BIO_s_mem()), BIO_free);

/*
    //
    // Get the full human readable representation of the certificate
    //
    X509_print_ex(output_bio.get(), cert.get(), 0, 0);

    // Put the contents of the BIO into a C++ string
    std::string cert_details = bio_to_string(output_bio, 32768);
    BIO_reset(output_bio.get());

    std::cout << "========================================" << std::endl;
    std::cout << "  Certificate details:" << std::endl;
    std::cout << cert_details << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << std::endl;
*/

    //
    // Get the subject of the certificate.
    //

    // According to the openssl documentation:
    // The returned value is an internal pointer which MUST NOT be freed
    X509_NAME *subject = X509_get_subject_name(cert.get());

    // Print the subject into a BIO and then get a string
    X509_NAME_print_ex(output_bio.get(), subject, 0, 0);
    std::string cert_subject = bio_to_string(output_bio, 4096);

    // Max subject length should be 555 bytes with ascii characters or 3690
    // bytes with unicode, based on the max allowed lengths for each component
    // of the subject plus the formatting.
    // Country code - 2 bytes
    // State/locality name - 128 bytes
    // Organization name - 64 bytes
    // Organizational unit name - 64 bytes
    // Common name - 64 bytes
    // email address - 64 bytes

    std::cout << "Subject:" << std::endl;
    std::cout << cert_subject << std::endl;
    std::cout << std::endl;


    //
    // Get the expiration date of the certificate
    //

    // X509_get_notAfter returns the time that the cert expires, in Abstract
    // Syntax Notation
    // According to the openssl documentation:
    // The returned value is an internal pointer which MUST NOT be freed
    ASN1_TIME *expires = X509_get_notAfter(cert.get());

    // Construct another ASN1_TIME for the unix epoch, get the difference
    // between them and use that to calculate a unix timestamp representing
    // when the cert expires
    ASN1_TIME_ptr epoch(ASN1_TIME_new(), ASN1_STRING_free);
    ASN1_TIME_set_string(epoch.get(), "700101000000");
    int days, seconds;
    ASN1_TIME_diff(&days, &seconds, epoch.get(), expires);
    time_t expire_timestamp = (days * 24 * 60 * 60) + seconds;

    std::cout << "Expiration timestamp:" << std::endl;
    std::cout << expire_timestamp << std::endl;
    std::cout << std::endl;


    FIPS_mode_set(0);
    CONF_modules_unload(1);
    CONF_modules_free();
    ERR_free_strings();
    EVP_cleanup();
    CRYPTO_cleanup_all_ex_data();
    ERR_remove_state(0);


    return 0;
}
