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
 * 整数nの階乗を返す
 *
 * @param int n 整数
 * @return
 */
int factorial(int n)
{
    if (n > 0) {
        return n * factorial(n - 1);
    } else {
        return 1;
    }
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
    if (target == 2) {
        // 判定対象が2の場合
        // 素数である
        return true;
    } else if ((target % 2) == 0) {
        // 判定対象が偶数の場合
        // 2で割り切れるので素数でない
        return false;
    }

    for (int i = 3; i < target; i+=2) {
        // 奇数で判定対象が割り切れるか判定する
        if ((target % i) == 0) {
            return false;
        }
    }

    return true;
}

/**
 * うるう年かどうか判定する
 * (4で割り切れる年がうるう年。ただし、100で割り切れても400で割り切れない年はうるう年でない)
 *
 * @param const int target 判定対象(年)
 * @return
 */
bool is_leap(const int target)
{
    return ((target % 4) == 0 && (target % 100) != 0 || (target % 400) == 0);
}