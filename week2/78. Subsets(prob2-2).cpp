#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        set<vector<int>>bigS;
        vector<vector<int>>resV;
        for (int i = 0; i < nums.size(); i++) {
            vector<int>tempV;
            dfs(nums, bigS, tempV, i);
        }
        for (set<vector<int>>::iterator it = bigS.begin(); it != bigS.end(); it++) 
            resV.push_back(*it);
        // ∫Û ∫§≈Õ √ﬂ∞°
        vector<int>emptyV;
        resV.push_back(emptyV);
        return resV;
    }
    void dfs(vector<int>& nums, set<vector<int>>& bigS, vector<int>tempV, int curIndex) {
        if (curIndex == nums.size())
            return;
        tempV.push_back(nums[curIndex]);
        bigS.insert(tempV);
        for (int i = 1; i < nums.size() - curIndex; i++)
            dfs(nums, bigS, tempV, curIndex + i);
    }
};

int main() {
    vector<int>v(3);
    v[0] = 1; v[1] = 2; v[2] = 3;
    Solution solution;
    solution.subsets(v);
	return 0;
}