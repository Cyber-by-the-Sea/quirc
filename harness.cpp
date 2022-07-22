#include <stdint.h>
#include <stddef.h>
#include <quirc.h>

static struct quirc *qr;

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
  int w = 100;
  int h = (size - (size % w)) / w;
  uint8_t *buff = quirc_begin(qr, &w, &h);
  memcpy(buff,data,w*h);
  quirc_end(qr);
  quirc_count(qr);
}
