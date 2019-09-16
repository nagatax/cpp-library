# C++ language library

## Set up Google Test

### Build

```bash
curl -OL https://github.com/google/googletest/archive/release-1.8.1.tar.gz
tar xvf release-1.8.1.tar.gz
cd googletest-release-1.8.1
cmake .
make
```

### Copy Google Test library files

```bash
cp -a googletest-release-1.8.1/googlemock/gtest/libgtest.a vendor/googletest/lib/libgtest.a
cp -a googletest-release-1.8.1/googlemock/gtest/libgtest_main.a vendor/googletest/lib/libgtest_main.a
cp -a googletest-release-1.8.1/googletest/include vendor/googletest/include
```

### Copy Google Mock library files

```bash
cp -a googletest-release-1.8.1/googlemock/libgmock.a vendor/googlemock/lib/libgmock.a
cp -a googletest-release-1.8.1/googlemock/libgmock_main.a vendor/googlemock/lib/¥libgmock_main.a
cp -a googletest-release-1.8.1/googlemock/include vendor/googlemock/include
``` 