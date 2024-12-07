mkdir bin 2> /dev/null
cd bin
PICO_SDK_PATH=../pico-sdk cmake -DPICO_BOARD=pico_w ..
make
cd ..
