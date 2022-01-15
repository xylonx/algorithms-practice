#include <iostream>

class InverseElement {
public:
    int exgcd(int a, int b, int &x, int &y) {
        if (b == 0) {
            x = 1, b = 0;
            return a;
        }
        int gcd = exgcd(b, a % b, y, x);
        y -= a / b * x;
        return gcd;
    }
};

int main(int argc, char **argv) {
    InverseElement e;
    int x, y;
    std::cout << e.exgcd(22, 60, x, y) << " " << x << " " << y << std::endl;
    return 0;
}