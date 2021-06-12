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

/**
 * 素数かどうか判定する
 * (素数: 自分自身と1以外の整数で割り切ることができない整数)
 *
 * @param unsigned int target 判定対象
 * @return bool 判定結果
 */
bool is_prime(unsigned int target)
{
    for (int i = 2; i < target; i++) {
        if ((target % i) == 0) {
            return false;
        }
    }

    return true;
}