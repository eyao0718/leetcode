class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {return 0;}
        sort(nums.begin(), nums.end());
        int curr = 1, longest = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i-1]+1==nums[i]) {
                curr++;
                longest = max(curr, longest);
            } else if (nums[i-1] == nums[i]) {
                continue;
            } else {
                curr = 1;
            }
        }
        return longest;
    }
};