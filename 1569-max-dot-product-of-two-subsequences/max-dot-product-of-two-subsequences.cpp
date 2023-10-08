class Solution {
public:
    int dp[501][501];
    int n, m;
    int solve(vector<int> &nums1, vector<int>& nums2, int i, int j){
        if(i >= n or j >= m){
            return -1001;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int choice_one = nums1[i]*nums2[j] + solve(nums1, nums2, i + 1, j + 1);
        int choice_two = solve(nums1, nums2, i, j + 1);
        int choice_three = solve(nums1, nums2, i + 1, j);
        int choice_four = solve(nums1, nums2, i + 1, j + 1);
        int choice_five = nums1[i]*nums2[j];
        return dp[i][j] = max({choice_one, choice_two, choice_three, choice_four, choice_five}); 
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2){
        memset(dp, -1, sizeof(dp));
        n = nums1.size(), m = nums2.size();
        return solve(nums1, nums2, 0, 0);
    }
};