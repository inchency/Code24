#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>v(numRows);
        // 초기화
        for (int i = 0; i < numRows; i++) {
            vector<int>elementV(i + 1, 0);
            v[i] = elementV;
        }
        for (int i = 0; i < numRows; i++) {
            v[i][0] = 1;
            v[i][v[i].size() - 1] = 1;
        }
        // 구하기
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < v[i].size(); j++) {
                if (v[i][j] == 0) 
                    v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
            }
        }
        return v;
    }
};

int main() {
    Solution solution;
    solution.generate(5);
	return 0;
}