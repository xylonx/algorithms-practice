#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<char> revword(word.rbegin(), word.rend());
        vector<vector<bool>> vis(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (dfs(board, vis, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& vis, string& word, int strpos, int x, int y) {
        char ch = word[strpos];
        if (board[x][y] != ch) {
            return false;
        }

        strpos++;
        vis[x][y] = true;
        if (strpos == word.size()) return true;

        bool res = false;
        if (x > 0 && !vis[x - 1][y]) {
            res = dfs(board, vis, word, strpos, x - 1, y);
        }
        if (res) return res;

        if (x < board.size() - 1 && !vis[x + 1][y]) {
            res = dfs(board, vis, word, strpos, x + 1, y);
        }
        if (res) return res;

        if (y > 0 && !vis[x][y - 1]) {
            res = dfs(board, vis, word, strpos, x, y - 1);
        }
        if (res) return res;

        if (y < board[0].size() - 1 && !vis[x][y + 1]) {
            res = dfs(board, vis, word, strpos, x, y + 1);
        }

        vis[x][y] = false;

        return res;
    }
};
// @lc code=end

/*

"SEE"
*/
int main(int argc, char** argv) {
    vector<vector<char>> board = {
  // {'A', 'B', 'C', 'E'},
  // {'S', 'F', 'C', 'S'},
  // {'A', 'D', 'E', 'E'}
        {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}}
    };
    Solution s;
    cout << s.exist(board, "SEE") << endl;
}
