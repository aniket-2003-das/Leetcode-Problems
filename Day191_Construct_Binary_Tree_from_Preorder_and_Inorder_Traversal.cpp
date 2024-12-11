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
    // Function to make BT from preorder & inorder 
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
        map<int, int> inMap;
        for(int i=0; i<inorder.size(); i++) inMap[inorder[i]] = i;
        // Call private helper to build tree
        TreeNode* root = buildTree(preorder, 0, preorder.size()-1, 
                                    inorder, 0, inorder.size()-1, inMap);
        return root;
    }
private:
    // Recursive helper function to build tree
    TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, 
                        vector<int>& inorder, int inStart, int inEnd, map<int, int>& inMap){
        // If the start indices exceed the end indices, return NULL
        if(preStart>preEnd || inStart>inEnd) return NULL;
        // New TreeNode with value at the current preorder index
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = inMap[root->val];
        // No of elements in the left subtree
        int numsLeft = inRoot - inStart;
        root->left = buildTree(preorder, preStart + 1, preStart + numsLeft, 
                        inorder, inStart, inRoot - 1, inMap);
        root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd, 
                        inorder, inRoot + 1, inEnd, inMap);
        return root;
    }
};