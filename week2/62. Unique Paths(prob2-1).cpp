#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // m 이 열의 개수, n이 행의 개수
    int uniquePaths(int m, int n) {
        int x = m; // 헷갈리므로 치환
        int y = n;
        vector<vector<int>>dpTable(y, vector<int>(x, 0));
        // dpTable x축 초기화
        for (int i = 0; i < x; i++)
            dpTable[0][i] = 1;
        // dpTable x축 초기화
        for (int i = 0; i < y; i++)
            dpTable[i][0] = 1;
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                if (dpTable[i][j] == 0) 
                    dpTable[i][j] = dpTable[i][j - 1] + dpTable[i - 1][j];
                
            }
        }
        return dpTable[y - 1][x - 1];
    }
};

int main() {
    Solution solution;
    cout << solution.uniquePaths(7, 3);
    return 0;
}