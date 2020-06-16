#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prevSum;
        int res = 0;
        int curSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            curSum += nums[i];
            if (curSum == k) 
                res++;
            if (prevSum.find(curSum - k) != prevSum.end())
                res += (prevSum[curSum - k]);
            prevSum[curSum]++;
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int>v(4);
    v[0] = 0; v[1] = 0; v[2] = 0; v[3] = 0;
    int k = 0;
    cout << solution.subarraySum(v, k) << endl;
    return 0;
}