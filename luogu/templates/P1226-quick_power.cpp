#include <iostream>

class QuickPower {
public:
    long long power(int a, int b, int m) {
        long long ans = 1, base = a;
        while (b > 0) {
            if (b & 1) {
                ans *= base;
                ans %= m;
            }
            base *= base;
            base %= m;
            b >>= 1;
        }
        return ans;
    }
};