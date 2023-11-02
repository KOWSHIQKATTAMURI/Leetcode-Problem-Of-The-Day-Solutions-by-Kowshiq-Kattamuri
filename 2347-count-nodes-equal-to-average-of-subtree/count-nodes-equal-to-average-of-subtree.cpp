/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans;
    pair<int, int> solve(TreeNode* root){
        if(!root){
            return {0, 0};
        }
        auto left = solve(root -> left);
        auto right = solve(root -> right);
        int total_sum = left.first + root -> val + right.first;
        int total_count = left.second + right.second + 1;
        int avg = total_sum/total_count;
        if(avg == root -> val){
            ans += 1;
        }
        return {total_sum, total_count};
    }
    int averageOfSubtree(TreeNode* root) {
        ans = 0;
        auto temp = solve(root);
        return ans;
    }
};