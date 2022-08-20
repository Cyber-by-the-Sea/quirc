FROM aflplusplus/aflplusplus

RUN  apt-get update \
     && apt-get install -y --no-install-recommends libjpeg9-dev libpng-dev python3-pip \
     && pip3 install qrcode \
     && cd /AFLplusplus/utils/aflpp_driver \
     && make

# docker run -it -v "$PWD:/share" --workdir /share quirc

# afl-cc -lm -I. -I./lib harness.cpp lib/*.c /AFLplusplus/utils/aflpp_driver/aflpp_driver.o /usr/local/lib/afl/afl-compiler-rt.o -o harness
