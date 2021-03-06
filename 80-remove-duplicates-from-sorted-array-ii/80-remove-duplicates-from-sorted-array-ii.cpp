class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        for (int i = 2; i<nums.size(); i++)
        {
            if (nums[i] == nums[i-2])
            {
                count++;
                nums[i-2] = INT_MAX;
            }
        }
        sort(nums.begin(), nums.end());
        return (nums.size() - count);
        
    }
};