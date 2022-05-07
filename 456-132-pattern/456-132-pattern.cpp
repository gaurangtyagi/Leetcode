class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        int prefix_min[n];
        prefix_min[0] = nums[0];
        for (int i = 1; i<n; i++)
        {
            prefix_min[i] = min(prefix_min[i-1], nums[i]);
        }
        stack <int> st;
        for (int i = n-1; i>= 0; i--)
        {
            if (nums[i] > prefix_min[i])
            {
                while(!st.empty() && st.top()<=prefix_min[i])
                {
                    st.pop();
                }
                
                if (!st.empty() && nums[i] > st.top())
                {
                    return true;
                }
                st.push(nums[i]);
            }
        }
        return false;
        
    }
};