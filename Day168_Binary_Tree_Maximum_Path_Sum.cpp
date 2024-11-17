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
    int maxpath(TreeNode* root, int& maxi){
        if(root==NULL) return 0;

        int leftsum = max(0, maxpath(root->left, maxi));
        int rightsum = max(0, maxpath(root->right, maxi));

        maxi = max(maxi, (leftsum + rightsum + root->val));
        return root->val + max(leftsum, rightsum);
    }

    // pair<int,int> solve(TreeNode* root){
    //     if(root==NULL) return {INT_MIN, 0};

    //     pair<int,int> left=solve(root->left);
    //     pair<int,int> right=solve(root->right);

    //     if(left.second<0) left.second=0;
    //     if(right.second<0) right.second=0;

    //     return {max({left.first, right.first, (left.second+right.second+root->val)}), max(left.second, right.second) + root->val};
    // }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxpath(root, maxi);
        return maxi;
        // pair<int,int> ans=solve(root);
        // return ans.first;
    }
};