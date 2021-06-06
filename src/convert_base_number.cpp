#include <string>

/**
 * 基数変換を行う
 *
 * @param unsigned int target 基数変換対象
 * @param int base_number 基数
 * @return std::string
 */
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