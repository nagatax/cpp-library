#include <string>

std::string convert_base_number(unsigned int target, int base_number)
{
    std::string digitString = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string result{""};

    if (target <= 0) {
        return "0";
    }

    while (target > 0) {
        result.push_back(digitString[target % base_number]);
        target /= base_number;
    }
    std::reverse(result.begin(), result.end());

    return result;
}