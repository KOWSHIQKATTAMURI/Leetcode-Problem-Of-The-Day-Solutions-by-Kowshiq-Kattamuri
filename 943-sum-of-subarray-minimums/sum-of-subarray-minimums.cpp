class Solution {
public:
    vector<int> get_nsl(vector<int>& nums){
        int n = nums.size();
        stack<int> left;
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            while(!left.empty() and nums[left.top()] >= nums[i]){
                left.pop();
            }
            if(!left.empty()){
                ans[i] = left.top();
            }else{
                ans[i] = -1;
            }
            left.push(i);
        }
        return ans;
    }
    vector<int> get_nsr(vector<int>& nums){
        int n = nums.size();
        stack<int> right;
        vector<int> ans(n);
        for(int i = n - 1; i >= 0; i--){
            while(!right.empty() and nums[right.top()] > nums[i]){
                right.pop();
            }
            if(!right.empty()){
                ans[i] = right.top();
            }else{
                ans[i] = n;
            }
            right.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr){
        int n = arr.size();
        vector<int> nsl = get_nsl(arr), nsr = get_nsr(arr);
        long long ans = 0;
        int mod = 1e9 + 7;
        for(int i = 0; i < n; i++){
            long long res = 0;
            long long left = i - nsl[i], right = nsr[i] - i;
            res += left*right*(long long)arr[i];
            ans = (ans + res)%mod;
        }
        return ans%mod;
    }
};