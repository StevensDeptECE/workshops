#include <stdio.h>
#include <string.h>

#include <openssl/engine.h>

#include <openssl/evp.h>
#include "rfc1321/global.h"
#include "rfc1321/md5.h"

static int md5_init(EVP_MD_CTX *ctx)
{
  MD5Init(ctx->md_data);
  return 1;
}

static int md5_update(EVP_MD_CTX *ctx, const void *data, size_t count)
{
  MD5Update(ctx->md_data, data, count);
  return 1;
}

static int md5_final(EVP_MD_CTX *ctx, unsigned char *md)
{
  MD5Final(md, ctx->md_data);
  return 1;
}

static const EVP_MD digest_md5 = {
  NID_md5,                      /* The name ID for MD5 */
  0,                            /* IGNORED: MD5 with private key encryption NID */
  16,                           /* Size of MD5 result, in bytes */
  0,                            /* Flags */
  md5_init,                     /* digest init */
  md5_update,                   /* digest update */
  md5_final,                    /* digest final */
  NULL,                         /* digest copy */
  NULL,                         /* digest cleanup */
  EVP_PKEY_NULL_method,         /* IGNORED: pkey methods */
  64,                           /* Internal blocksize, see rfc1321/md5.h */
  sizeof(MD5_CTX),
  NULL                          /* IGNORED: control function */
};

static int digest_nids[] = { NID_md5, 0 };
static int digests(ENGINE *e, const EVP_MD **digest,
                   const int **nids, int nid)
{
  int ok = 1;
  if (!digest) {
    /* We are returning a list of supported nids */
    *nids = digest_nids;
    return (sizeof(digest_nids) - 1) / sizeof(digest_nids[0]);
  }

  /* We are being asked for a specific digest */
  switch (nid) {
  case NID_md5:
    *digest = &digest_md5;
    break;
  default:
    ok = 0;
    *digest = NULL;
    break;
  }
  return ok;
}

static const char *engine_id = "MD5";
static const char *engine_name = "A simple md5 engine for demonstration purposes";
static int bind(ENGINE *e, const char *id)
{
  int ret = 0;

  if (!ENGINE_set_id(e, engine_id)) {
    fprintf(stderr, "ENGINE_set_id failed\n");
    goto end;
  }
  if (!ENGINE_set_name(e, engine_name)) {
    printf("ENGINE_set_name failed\n");
    goto end;
  }
  if (!ENGINE_set_digests(e, digests)) {
    printf("ENGINE_set_name failed\n");
    goto end;
  }

  ret = 1;
 end:
  return ret;
}

IMPLEMENT_DYNAMIC_BIND_FN(bind)
IMPLEMENT_DYNAMIC_CHECK_FN()
