# C++ language library

## Set up Google Test

### Build

```bash
curl -OL https://github.com/google/googletest/archive/release-1.8.1.tar.gz \
&& tar xvf release-1.8.1.tar.gz \
&& cd googletest-release-1.8.1 \
&& cmake . \
&& make \
&& cd .. \
&& rm -f release-1.8.1.tar.gz
```

### Copy Google Test library files

```bash
mkdir -p vendor/googletest/lib \
&& cp -a googletest-release-1.8.1/googlemock/gtest/libgtest.a vendor/googletest/lib/libgtest.a \
&& cp -a googletest-release-1.8.1/googlemock/gtest/libgtest_main.a vendor/googletest/lib/libgtest_main.a \
&& cp -a googletest-release-1.8.1/googletest/include vendor/googletest/include
```

### Copy Google Mock library files

```bash
mkdir -p vendor/googlemock/lib \
&& cp -a googletest-release-1.8.1/googlemock/libgmock.a vendor/googlemock/lib/libgmock.a \
&& cp -a googletest-release-1.8.1/googlemock/libgmock_main.a vendor/googlemock/lib/¥libgmock_main.a \
&& cp -a googletest-release-1.8.1/googlemock/include vendor/googlemock/include
``` 

## Build Project files

```bash
cmake . \
&& make
```

## Execute executable file

```bash
./cpplang_library
```