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