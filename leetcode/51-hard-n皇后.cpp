#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
public:
    vector<bool> colvis;
    vector<vector<string>> res;
    vector<string> path;

    vector<vector<string>> solveNQueens(int n) {
        colvis.resize(n, false);
        backtracing(n, 0);
        return res;
    }

    bool check(int i, int j, int n) {
        if (colvis[j]) {
            return false;
        }

        // left-top
        for (int row = i - 1, col = j - 1; row >= 0 && col >= 0; --row, --col) {
            if (path[row][col] == 'Q') return false;
        }

        // right-top
        for (int row = i - 1, col = j + 1; row >= 0 && col < n; --row, ++col) {
            if (path[row][col] == 'Q') return false;
        }

        return true;
    }

    void backtracing(int n, int row) {
        if (row >= n) {
            res.push_back(path);
            return;
        };

        for (int j = 0; j < n; j++) {
            if (check(row, j, n)) {
                string str(n, '.');
                str[j] = 'Q';

                colvis[j] = true;
                path.push_back(str);

                backtracing(n, row + 1);

                colvis[j] = false;
                path.pop_back();
            }
        };
    }
};
// @lc code=end

int main(int argc, char** argv) {
    Solution s;
    auto res = s.solveNQueens(4);
    for (auto i : res) {
        for (auto j : i) {
            cout << j << endl;
        }
        cout << endl;
    }
}