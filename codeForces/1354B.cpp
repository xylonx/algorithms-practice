#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>

#define INF 0xffffffff

using namespace std;

long long getLengthOfSubstring(string str);

long long getLengthOfReversedSubstring(string str, int index);

int main(int argc, char *argv[])
{
    int n;
    cin >> n;
    long long answer[n];

    string str;

    for (int i = 0; i < n; i++)
    {
        cin >> str;
        answer[i] = getLengthOfSubstring(str);
    }

    for (int i = 0; i < n; i++)
    {
        if (i != 0)
        {
            cout << '\n'
                 << answer[i];
        }
        else
        {
            cout << answer[i];
        }
    }

    return 0;
}

// recording the latest postion that '1', '2', '3' occurred, 
// and caculate the local min length of the substring
// then, by comparing, find the global min length of the substring
long long getLengthOfSubstring(string str)
{
    long long position[3], start, end, minLength;
    memset(position, 0, sizeof(position));

    minLength = INF;

    // ensure value on postion about the first character is not zero
    str = " " + str;

    for (int i = 1; i < str.length(); i++)
    {
        position[str.at(i) - '1'] = i;

        if (position[0] && position[1] && position[2])
        {
            start = std::min(position[0], std::min(position[1], position[2]));
            end = std::max(position[0], std::max(position[1], position[2]));
            minLength = std::min(minLength, end - start + 1);
        }

    }

    if (minLength == INF)
        return 0;

    return minLength;
}
