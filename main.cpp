#include "gtest/gtest.h"
#include "src/array.h"

int main(int argc, char *argv[]) {

    // Execute Google Test
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}