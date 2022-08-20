#include <stdint.h>
#include <stddef.h>
#include <quirc.h>

static struct quirc *qr;

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
  int num_codes, i;
  int w = 100;
  int h = (size - (size % w)) / w;
  uint8_t *buff = quirc_begin(qr, &w, &h);
  memcpy(buff,data,w*h);
  quirc_end(qr);
  num_codes = quirc_count(qr);
  for (i = 0; i < num_codes; i++) {
    struct quirc_code code;
    struct quirc_data data;
    quirc_decode_error_t err;

    quirc_extract(qr, i, &code);

    /* Decoding stage */
    err = quirc_decode(&code, &data);
    }
}
