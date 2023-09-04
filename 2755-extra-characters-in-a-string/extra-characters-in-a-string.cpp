class Solution{
public:
    int solve(string &s, int idx, vector<int>& dp, int n, vector<string>& dictionary){
        if(idx >= n){
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        string current = "";
        int ans = n;
        for(int i = idx; i < n; i++){
            int present = 0;
            current.push_back(s[i]);
            if(find(dictionary.begin(), dictionary.end(), current) == dictionary.end()){
                present += current.length();
            }
            int remaining = solve(s, i + 1, dp, n, dictionary);
            ans = min(ans, present + remaining);
        }
        return dp[idx] = ans;
    }
    int minExtraChar(string s, vector<string>& dictionary){
        int n = s.length();
        vector<int> dp(n, -1);
        return solve(s, 0, dp, n, dictionary);
    }
};















































































































































































































































































































































































































































































































































































































































































































































































































































































































