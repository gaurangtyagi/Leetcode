class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int ans = 1;
        for (int k = 2; k < n; k++)
        {
            if (n*2 <= k*(k-1)) break;
            if ((n - k*(k-1)/2)%k == 0) ans ++;
        }
        return ans;
        
    }
};