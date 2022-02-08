#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
#include <bitset>
class Solution {
public:
    bitset<9> colvis;
    vector<bitset<9> > vismap;
    int cnt = 0;

    int totalNQueens(int n) {
        vismap.resize(n);
        for (auto& i : vismap) i.reset();
        colvis.reset();
        backtracing(n, 0);
        return cnt;
    }

    bool check(int i, int j, int n) {
        // check col
        if (colvis.test(j)) return false;

        // check left-top
        for (int row = i - 1, col = j - 1; row >= 0 && col >= 0; --row, --col) {
            if (vismap[row][col]) return false;
        }

        // check right-top
        for (int row = i - 1, col = j + 1; row >= 0 && col < n; --row, ++col) {
            if (vismap[row][col]) return false;
        }

        return true;
    }

    void backtracing(int n, int row) {
        if (row == n) {
            ++cnt;
            return;
        }

        for (int j = 0; j < n; ++j) {
            if (check(row, j, n)) {
                colvis[j] = true;
                vismap[row].set(j);

                backtracing(n, row + 1);

                vismap[row].reset(j);
                colvis[j] = false;
            }
        }
    }
};
// @lc code=end

int main(int argc, char** argv) {
    Solution s;
    auto res = s.totalNQueens(4);
    cout << res;
}