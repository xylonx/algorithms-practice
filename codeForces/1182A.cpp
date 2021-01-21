#include<bits/stdc++.h>

using namespace std;

// there are just 2 kind for each 3 * 2 grids
// so F(n) = 2 * F(n/2) n is even
// F(n) == 0 n is odd
int main(int argc, char* argv[]){
    int n;
    long long answer;
    cin >> n;
    if(n&1){
        cout << 0;
    }else{
        // attention: if just `cout << pow()`, it will be transformed to double not "integer"
        answer = pow(2, n/2);
        cout << answer;
    }

    return 0;
}