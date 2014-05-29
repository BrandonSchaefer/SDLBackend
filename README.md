Dependices for debian/ubuntu:

  libsdl2-dev
  libsdl2-mixer-dev
  libsdl2-image-dev
  libsdl2-ttf-dev
  libsigc++-2.0-dev

To compile:

  mkdir build
  cd build
  cmake ..
  make -j4
  make install

CMake options:

  -DCMAKE_BUILD_TYPE=[Debug|Release]
