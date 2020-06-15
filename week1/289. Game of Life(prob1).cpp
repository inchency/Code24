#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int boardYSize = board.size();
        int boardXSize = board[0].size();
        vector<vector<int>>newBoard(board.size(), vector<int>(board[0].size(), 0));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                int surviveCnt = 0, deadCnt = 0;
                // 좌 위
                if (isInBoard(i - 1, j - 1, boardYSize, boardXSize)) {
                    if (board[i - 1][j - 1] == 0) deadCnt++;
                    else surviveCnt++;
                        
                }
                // 위
                if (isInBoard(i - 1, j, boardYSize, boardXSize)) {
                    if (board[i - 1][j] == 0) deadCnt++;
                    else surviveCnt++;
                }
                // 우 위
                if (isInBoard(i - 1, j + 1, boardYSize, boardXSize)) {
                    if (board[i - 1][j + 1] == 0) deadCnt++;
                    else surviveCnt++;
                }
                // 좌
                if (isInBoard(i, j - 1, boardYSize, boardXSize)) {
                    if (board[i][j - 1] == 0) deadCnt++;
                    else surviveCnt++;
                }
                // 우
                if (isInBoard(i, j + 1, boardYSize, boardXSize)) {
                    if (board[i][j + 1] == 0) deadCnt++;
                    else surviveCnt++;
                }
                // 좌 아래
                if (isInBoard(i + 1, j - 1, boardYSize, boardXSize)) {
                    if (board[i + 1][j - 1] == 0) deadCnt++;
                    else surviveCnt++;
                }
                // 아래
                if (isInBoard(i + 1, j, boardYSize, boardXSize)) {
                    if (board[i + 1][j] == 0) deadCnt++;
                    else surviveCnt++;
                }
                // 우 아래
                if (isInBoard(i + 1, j + 1, boardYSize, boardXSize)) {
                    if (board[i + 1][j + 1] == 0) deadCnt++;
                    else surviveCnt++;
                }

                // next step (죽이거나 살리거나)
                if (board[i][j] == 1 && surviveCnt <= 1) newBoard[i][j] = 0;
                else if (board[i][j] == 1 && surviveCnt == 2 || surviveCnt == 3) newBoard[i][j] = 1;
                else if (board[i][j] == 1 && surviveCnt > 3) newBoard[i][j] = 0;
                else if (board[i][j] == 0 && surviveCnt == 3) newBoard[i][j] = 1;
            }
        }
        // 출력
        /*for (int i = 0; i < newBoard.size(); i++) {
            for (int j = 0; j < newBoard[i].size(); j++) {
                cout << newBoard[i][j] << " ";
            }
            cout << endl;
        }*/
        board = newBoard;
    }
    bool isInBoard(int y, int x, int boardYSize, int boardXSize) {
        if (y >= 0 && x >= 0 && y < boardYSize && x < boardXSize)
            return true;
        return false;
    }
};

int main() {
    vector<vector<int>>arr(4, vector<int>(3, 0));
    arr[0][0] = 0; arr[0][1] = 1; arr[0][2] = 0;
    arr[1][0] = 0; arr[1][1] = 0; arr[1][2] = 1;
    arr[2][0] = 1; arr[2][1] = 1; arr[2][2] = 1;
    arr[3][0] = 0; arr[3][1] = 0; arr[3][2] = 0;

    Solution solution;
    solution.gameOfLife(arr);
    return 0;
}