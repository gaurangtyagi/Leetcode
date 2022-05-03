class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack <int> s;
        int l = nums.size() +1;
        int r = 0;
        for (int i = 0; i<nums.size(); i++)
        {
            while(!s.empty() && nums[s.top()] > nums[i])
            {
                l = min (l, s.top() -1);
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()) // to empty the stack
        {
            s.pop();
        }
        for (int i = nums.size() - 1; i>=0; i--)
        {
            while(!s.empty() && nums[s.top()] < nums[i])
            {
                r = max (r, s.top() - 1);
                s.pop();
            }
            s.push(i);
        }
        return (r - l) > 0 ? (r - l + 1): 0;
    }
};