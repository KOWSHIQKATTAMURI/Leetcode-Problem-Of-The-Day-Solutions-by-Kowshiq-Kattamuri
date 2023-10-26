class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr){
        sort(arr.begin(), arr.end());
        long long mod = 1e9 + 7, ans = 0;
        unordered_map<int, long long> mp;
        for(int i = 0; i < arr.size(); i++){
            long long temp = 1;
            for(int j = i - 1; j >= 0; j--){
                if(arr[i]%arr[j] == 0){
                    int a = mp[arr[j]], b = mp[arr[i] / arr[j]];
                    temp = (temp + (long long)a*b)%mod;
                }
            }
            mp[arr[i]] = temp;
            ans = (ans + temp)%mod;
        }
        return ans;
    }
};