class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        for (int i = 1; i<nums.size(); i++)
        {
            if (nums[i] == nums[i-1])
            {
                count++;
                nums[i-1] = INT_MAX;
            }
        }
        sort(nums.begin(), nums.end());
        return (nums.size() - count);
    }
};