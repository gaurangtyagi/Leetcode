class Solution {
public:
         int findUnsortedSubarray(vector<int>& nums) {
          vector <int> a(nums.size());
          for (int i = 0; i<nums.size(); i++)
          {
              a[i] = nums[i];
          }
          int counter1 = -1;
          int counter2 = -1;
          sort (nums.begin(), nums.end());
          for (int i = 0; i<nums.size(); i++)
          {
              if (nums[i] != a[i])
              {
                  counter1 = i;
              }
          }
          if (counter1 == -1)
          {
              return 0;
          }
          for (int i = nums.size() - 1; i>=0; i--)
          {
              if (nums[i] != a[i])
              {
                  counter2 = i;
              }
          }
          return abs(counter2 - counter1 - 1);
      }
};