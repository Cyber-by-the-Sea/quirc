#include <cstring>
#include <stdint.h>
#include <stddef.h>
#include <quirc.h>

static struct quirc *qr;

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
  if (size < 100) {
    return;
  }
  qr = quirc_new();
  int i;
  int w = 100;
  int h = (size - (size % w)) / w;
  uint8_t *buff = quirc_begin(qr, &w, &h);
  memcpy(buff,data,w*h);
  quirc_end(qr);
  int num_codes = quirc_count(qr);
  for (i = 0; i < num_codes; i++) {
    struct quirc_code code;
    struct quirc_data data;
    quirc_decode_error_t err;
    quirc_extract(qr, i, &code);
    err = quirc_decode(&code, &data);
    }
}
