#/bin/sh

# shell option
set -eu

# Variables
PACKAGE=release-1.10.0
PACKAGE_FILE=${PACKAGE}.tar.gz
TEMP_FOLDER=googletest-${PACKAGE}

# Build Google Test
curl -OL https://github.com/google/googletest/archive/${PACKAGE_FILE}
tar xvf ${PACKAGE_FILE} 
cd ${TEMP_FOLDER} 
cmake .
make
cd ..

# Copy Google Test library files
mkdir -p vendor/googletest/lib
cp -a ${TEMP_FOLDER}/lib/libgtest.a vendor/googletest/lib/libgtest.a
cp -a ${TEMP_FOLDER}/lib/libgtest_main.a vendor/googletest/lib/libgtest_main.a
cp -a ${TEMP_FOLDER}/googletest/include vendor/googletest/include

# Copy Google Mock library files
mkdir -p vendor/googlemock/lib
cp -a ${TEMP_FOLDER}/lib/libgmock.a vendor/googlemock/lib/libgmock.a
cp -a ${TEMP_FOLDER}/lib/libgmock_main.a vendor/googlemock/lib/libgmock_main.a
cp -a ${TEMP_FOLDER}/googlemock/include vendor/googlemock/include

# Clean
rm -rf ${PACKAGE_FILE} ${TEMP_FOLDER}
