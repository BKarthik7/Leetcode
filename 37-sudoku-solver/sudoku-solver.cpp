#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        map<int, vector<bool>> hor, ver, box;

        for (int i = 0; i < 9; i++) {
            hor[i] = vector<bool>(10, false);
            ver[i] = vector<bool>(10, false);
            box[i] = vector<bool>(10, false);
        }

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    hor[i][num] = true;
                    ver[j][num] = true;
                    box[(i / 3) * 3 + (j / 3)][num] = true;
                }
            }
        }

        solve(board, hor, ver, box);
    }

    bool solve(vector<vector<char>>& board, map<int, vector<bool>>& hor, map<int, vector<bool>>& ver, map<int, vector<bool>>& box) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (int num = 1; num <= 9; num++) {
                        if (!hor[i][num] && !ver[j][num] && !box[(i / 3) * 3 + (j / 3)][num]) {
                            board[i][j] = num + '0';
                            hor[i][num] = true;
                            ver[j][num] = true;
                            box[(i / 3) * 3 + (j / 3)][num] = true;

                            if (solve(board, hor, ver, box)) {
                                return true;
                            }

                            board[i][j] = '.';
                            hor[i][num] = false;
                            ver[j][num] = false;
                            box[(i / 3) * 3 + (j / 3)][num] = false;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
};