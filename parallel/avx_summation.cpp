/*
    This code assumed Intel i7-4th generation or better (circa 2008)
    avx2

    Note, for mac ARM CPUs, you want Neon which is the equivalent but not as fast

    https://www.intel.com/content/www/us/en/docs/intrinsics-guide/index.html
*/


#include <iostream>
#include <immintrin.h>

uint64_t horizontalAdd(__m256i x) {
    // Permute the 256-bit register to get the lower 128 bits and higher 128 bits separately
    __m128i x_low = _mm256_castsi256_si128(x);
    __m128i x_high = _mm256_extracti128_si256(x, 1);

    // Add the lower 128 bits and higher 128 bits separately
    __m128i sum = _mm_add_epi64(x_low, x_high);

    // Extract the 64-bit integer from the lower 128 bits
    uint64_t result[2];
    _mm_storeu_si128((__m128i*)result, sum);

    // Horizontally add the two 64-bit integers in the result array
    return result[0] + result[1];
}

/*
    Assume that b-a+1 is a multiple of 4
*/
uint64_t sum(uint64_t a, uint64_t b) {
    __m256i sum;
    const uint64_t zeros[4] = {0, 0, 0, 0}; 
    sum = _mm256_loadu_si256((__m256i const *)zeros);

    uint64_t vec[4] = {a, a+1, a+2, a+3}; // if a=1,   1,2,3,4
    uint64_t vec4[4] = {4, 4, 4, 4};

    __m256i x = _mm256_load_si256((__m256i const *)vec);
   __m256i four = _mm256_load_si256((__m256i const *)vec4);

    for (uint64_t i = a; i <= b; i+=4) {
        sum = _mm256_add_epi64(sum, x);
        x = _mm256_add_epi64(x, four);
    }
    //horizontally add sum
    return horizontalAdd(sum);
}

int main(int argc, char* argv[]) {
    int n = atoi(argv[1]);

    std::cout << sum(1,n) << std::endl;
}