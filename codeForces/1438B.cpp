#include <algorithm>
#include <cstdio>
#include <map>
#include <string>

using namespace std;

bool hasSameValue(long long b[], int length);

int main(void)
{

    int n = 0, length = 0;

    scanf("%d", &n);
    string answer[n];

    // handle the input data
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &length);

        long long b[length];

        for (int i = 0; i < length; i++)
        {
            scanf("%lld", &b[i]);
        }

        // solve the problem
        if (hasSameValue(b, length))
        {
            answer[i] = "YES";
        }
        else
        {
            answer[i] = "NO";
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (i > 0)
        {
            printf("\n");
        }

        printf("%s", answer[i].c_str());
        
    }
    

    return 0;
}

// sum of subarray a can be seen as a binary number
// so the problem can be transformed to whether there are two same continuous subarrrays of array b expected order
//
// if there are no same value in array b, it means no carry in binary number, which means there are no same value in array a

bool hasSameValue(long long b[], int length)
{

    map<long long, int> sameValueMap;
    sameValueMap.clear();

    for (int i = 0; i < length; i++)
    {
        // it means the value does not exist
        if (sameValueMap.find(b[i]) == sameValueMap.end())
        {
            sameValueMap.insert(pair<long long, int>(b[i], 1));
        }
        else
        {
            sameValueMap[b[i]]++;
        }
    }

    map<long long, int>::iterator i;
    for (i = sameValueMap.begin(); i != sameValueMap.end(); i++)
    {
        if (i->second > 1)
        {
            return true;
        }
    }
    return false;
}