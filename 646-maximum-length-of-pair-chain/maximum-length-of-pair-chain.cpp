class Solution {
public:
    int solve(int start, int end, vector<int>& dp, vector<vector<int>>& pairs){
        if(start >= end){
            return 0;
        }
        if(dp[start] != -1){
            return dp[start];
        }
        vector<int> duplicate = {pairs[start][1], INT_MAX};
        int index = upper_bound(pairs.begin() + start + 1, pairs.end(), duplicate) - pairs.begin();
        return dp[start] = max(solve(start + 1, end, dp, pairs), 1 + solve(index, end, dp, pairs));
    }
    int findLongestChain(vector<vector<int>>& pairs){
        sort(pairs.begin(), pairs.end());
        vector<int> dp(pairs.size(), -1);
        return solve(0, pairs.size(), dp, pairs);
    }
};