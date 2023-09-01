class Solution {
public:
    int nofbits(int n){
        int ans = 0;
        for(int i = 0; i < 32; i++){
            long long int b = pow(2, i);
            if((n&b) != 0){
                ans++;
            }
        }
        return ans;
    }
    vector<int> countBits(int n){
        vector<int> ans(n + 1 , 0);
        for(int i = 0; i <= n; i++){
            ans[i] = nofbits(i);
        }
        return ans;
    }
};