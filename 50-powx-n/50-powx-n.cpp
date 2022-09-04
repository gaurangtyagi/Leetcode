class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        if (abs(x) == 1)
        {
            if (n%2 == 0) return abs(x);
            return x;
        }
        for (int i = 0; i<n; i++) ans *= x;
        if (n < 0)
        {
            if (n == INT_MIN) return 0;
            for (int i = 0; i< abs(n); i++) ans /= x;
        }
        return ans;
    }
};