#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int ShortestBombedStringLength(string const &str);

int main(void)
{
    int n;
    cin >> n;

    string str;
    int result[n];

    // handle the input
    for (int i = 0; i < n; i++)
    {
        cin >> str;

        // solve the problem
        result[i] = ShortestBombedStringLength(str);
    }

    // handle the output
    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
        {
            cout << result[i] << endl;
        }
        else
        {
            cout << result[i];
        }
    }
}

// greedy delete AB and BB
// the format is like a stack, but just records the change of stack size
int ShortestBombedStringLength(string const &str)
{
    // the minimum length of bombed string
    int length = 0;


    for (int i = 0; i < str.size(); i++){
        // when the substring is ended with 'B' and the length of substring before isn't 0
        // it means 'B' and the char before it can be deleted
        // so the remained string is like "BAAA..." or "AAAA..."
        // there are no more better case than this
        if (str[i] == 'B' && length != 0)
        {
            length--;
        }else{
            length++;
        }
        
    }

    return length;
}