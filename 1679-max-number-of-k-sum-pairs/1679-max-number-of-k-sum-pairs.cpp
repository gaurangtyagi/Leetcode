class Solution {
public: //nlogn
    int maxOperations(vector<int>& nums, int k) {
        unordered_map <int, int> m; 
        for (int i = 0; i<nums.size(); i++)
        {
            m[nums[i]]++;
        }
        int count = 0; 
        for (int i = 0; i<nums.size(); i++)
        {
            int res = k - nums[i];
            if (m.find(res) != m.end())
            {
                if (m[res] != 0)
                {
                    m[res]--;
                    count++;
                }
            }
        }
        return count/2;
    }
};