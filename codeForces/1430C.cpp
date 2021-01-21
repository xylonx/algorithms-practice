#include <bits/stdc++.h>

using namespace std;

// for each case, the minimum result is 2 and it always works
// for each sequence '1 2 3 ... n' :
// n   n-1 -> n
// n   n-2 -> n-1
// n-1 n-3 -> n-2
// ... 
// so after n-1 iteration, the result is 2
int main(int argc, char *argv[])
{
    int n, maxBoardNumber, p, q;
    cin >> n;
    while(n--){
        cin >> maxBoardNumber;

        cout << 2 << endl;

        p = maxBoardNumber, q = maxBoardNumber - 1;
        for(int i = 0; i < maxBoardNumber - 1; i++){
            cout << p << " " << q << " " << endl;
            p = ceil((p + q--) / 2.0);
        }
    }
    
    return 0;
}