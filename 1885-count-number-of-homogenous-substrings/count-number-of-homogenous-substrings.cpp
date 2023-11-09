class Solution {
public:
    int countHomogenous(string s){
        int mod = 1e9 + 7;
        vector<int> dp(s.length(), 1);
        for(int i = 1; i < s.length(); i++){
            if(s[i] == s[i - 1]){
                dp[i] += dp[i - 1];
            }
        }
        long long sum = accumulate(dp.begin(), dp.end(), 0LL);
        return sum%mod;
    }
};