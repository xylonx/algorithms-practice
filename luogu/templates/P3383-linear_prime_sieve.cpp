#include <bitset>
#include <cstring>
#include <iostream>
#include <vector>

#define MAX 100

int main(int argc, char **argv) {
    std::bitset<MAX> is_prime;
    std::vector<int> prime;
    is_prime.set();
    is_prime[1] = false;

    for (int i = 2; i <= MAX; ++i) {
        if (is_prime[i]) prime.push_back(i);
        for (int j = 0; j < prime.size() && i * prime[j] <= MAX; j++) {
            is_prime[i * prime[j]] = false;

            if (i % prime[j] == 0) break;
        }
    }

    for (int i = 0; i < prime.size(); ++i) {
        std::cout << prime[i] << " ";
    }

    return 0;
}