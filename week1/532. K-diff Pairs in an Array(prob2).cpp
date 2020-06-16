#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int res = 0;
        set<int>s;
        sort(nums.begin(), nums.end());
        /*for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << " ";
        }*/
        int size = nums.size();
        for (int i = 0; i < size-1; i++) {
            if (s.find(nums[i]) != s.end()) continue;
            s.insert(nums[i]);
            int targetNum = k + nums[i];
            vector<int>::iterator findIter = lower_bound(nums.begin()+i+1, nums.end(), targetNum);
            if (*findIter == targetNum) res++;
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int>arr(5);
    int k = 0;
    arr[0] = 1; arr[1] = 3; arr[2] = 1; arr[3] = 5; arr[4] = 4;
    cout << solution.findPairs(arr, k);
    return 0;
}