class Solution {
public:
    string longestPalindrome(string s){
        int n = s.length();
        vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, true));
        int ans = 0;
        string res;
        res.push_back(s[0]);
        for(int k = 1; k < n; k++){
            for(int i = 0; i < n - k; i++){
                int j = i + k;
                dp[i][j] = (s[i] == s[j] and dp[i + 1][j - 1]);
                if(dp[i][j]){
                    if(j - i + 1 > ans){
                        res = s.substr(i, j - i + 1);
                        ans = j - i + 1;
                    }
                }
            }
        }
        return res;
    }
};