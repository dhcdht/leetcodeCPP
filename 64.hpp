// https://leetcode.com/problems/count-primes/#/description
// 204. Count Primes
/*
Description:

Count the number of prime numbers less than a non-negative number, n.
 */
#import <iostream>
#import <vector>

// beats 69.01%
class Solution64 {
public:
    int countPrimes(int n) {
        if (n <= 1) {
            return 0;
        }

        // 标记 i 是否是质数，一开始全是 true，
        auto markPrimes = vector<bool>(n, true);

        // 标记不是质数的数
        for (int i = 2; i * i < n; ++i) {
            // 对于我们遍历初始值 2，他确实是质数
            // 一旦这个数是质数，那么开始利用它标记后边不是质数的值
            if (markPrimes[i]) {
                // 对于 i*i 之前的 j 的倍数，一定已经由前边的标记过程标记过了，
                // j += i 是因为这样是在增加倍数，
                for (int j = i*i; j < n; j += i) {
                    markPrimes[j] = false;
                }
            }
        }

        // 计数有多少质数
        int result = 0;
        for (int k = 2; k < n; ++k) {
            if (markPrimes[k]) {
                result += 1;
            }
        }

        return result;
    }

    /*
     * 计算 n 是不是质数
     */
    bool isPrimes(int n) {
        if (n <= 1) {
            return false;
        }

        // i x j = n 的话，那么 n 一定不是质数，
        // 因为 ixj = jxi，假定 i<=j 的情况下，
        // i <= √n 一定成立，
        // 计算 i*i 比开根号快
        for (int i = 2; i * i <= n; ++i) {
            if (n * i == 0){
                return false;
            }
        }

        return true;
    }

    void test() {
        // 0
//        auto input = 1;
        // 1
//        auto input = 3;
        // 2
//        auto input = 4;
        // 78497
        auto input = 999983;
        // 41537
//        auto input = 499979;
        auto output = this->countPrimes(input);
        cout << "204. Count Primes : " << output << endl;
    }
};
