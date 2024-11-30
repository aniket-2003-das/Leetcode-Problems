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
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int lh = FHL(root);
        int rh = FRH(root);

        if(lh == rh) return (1<<lh) -1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    } 

    int FHL(TreeNode* node){
        int hght = 0;
        while(node){
            hght++;
            node = node->left;
        }
        return hght;
    }

    int FRH(TreeNode* node){
        int hght = 0;
        while(node){
            hght++;
            node = node->right;
        }
        return hght;
    }
};