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
    pair<int, int> solve(TreeNode* root){
        if(root==NULL) return {0,0};

        pair<int, int> left=solve(root->left);
        pair<int, int> right=solve(root->right);

        int height = max(left.first, right.first)+1;
        int Maxdiameter = max({left.second, right.second, left.first+right.first});
        return {height, Maxdiameter};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int,int> ans = solve(root);
        return ans.second;
    }

    // int findDiameter(TreeNode* root, int& maxi) {
    //     if (root == NULL) return 0;
    //     int lh = findDiameter(root->left, maxi);
    //     int rh = findDiameter(root->right, maxi);
    //     maxi = max(maxi, lh + rh);
    //     return 1 + max(lh, rh);
    // }
    // int diameterOfBinaryTree(TreeNode* root) {
    //     int diameter = 0;
    //     findDiameter(root, diameter);
    //     return diameter;
    // }
};