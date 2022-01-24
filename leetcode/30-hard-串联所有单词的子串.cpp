#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */

// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.empty() || words.empty()) return res;

        int wordSize = words[0].size(), windowSize = words.size() * wordSize;

        if (s.size() < windowSize) return res;

        unordered_map<string, int> sm, wm;
        for (auto w : words) {
            wm[w]++;
        }

        for (int i = 0; i + windowSize < s.size(); ++i) {
            sm.clear();

            for (int j = 0; j < windowSize; j += wordSize) {
                sm[s.substr(i + j, wordSize)]++;
            }

            bool match = true;
            for (auto w : wm) {
                if (sm[w.first] != w.second) {
                    match = false;
                    break;
                };
            }

            if (match) {
                res.push_back(i);
            }
        }

        return res;
    }

private:
};
// @lc code=end

int main(int argc, char** argv) {
    Solution       s;
    vector<string> words = {"word", "good", "best", "good"};

    auto res = s.findSubstring("wordgoodgoodgoodbestword", words);
    for (auto i : res) {
        cout << i << endl;
    }
    return 0;
}
