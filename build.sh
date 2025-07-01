mkdir build 2> /dev/null
cd build
PICO_SDK_PATH=../pico-sdk cmake -DPICO_BOARD=pico_w ..
make
cd ..
