class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int i = 0; i<nums.size(); i++)
        {
            m[nums[i]]++;
        }
        pair <int, int> p; 
        priority_queue<pair<int, int>> pq;
        
        for (auto &it : m)
        {
            pq.push(make_pair(it.second, it.first));
        }
        vector <int> res;
        for (int i = 0; i<k; i++)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};