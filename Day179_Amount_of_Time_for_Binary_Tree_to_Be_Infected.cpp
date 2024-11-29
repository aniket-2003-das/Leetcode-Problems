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
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*> mpp;
        TreeNode* target = bfsToMapParents(root, mpp, start);
        int maxi = findMaxDistance(mpp, target);
        return maxi;
    }

    TreeNode* bfsToMapParents(TreeNode* root, map<TreeNode*, TreeNode*> &mpp, int start){
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* res;
        
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->val==start) res=node;
            if(node->left) {
                mpp[node->left]=node; 
                q.push(node->left);
            }
            if(node->right) {
                mpp[node->right]=node; 
                q.push(node->right);
            }
        }
        return res;
    }

    int findMaxDistance(map<TreeNode*, TreeNode*> &mpp, TreeNode* target){
        queue<TreeNode*> qu;
        qu.push(target);
        map<TreeNode*, int> vis;
        vis[target]=1;
        int maxi=0;

        while(!qu.empty()){
            int n=qu.size();
            int change=0;
            for(int i=0; i<n; i++){
                auto node=qu.front();
                qu.pop();
                if(node->left and !vis[node->left]){
                    qu.push(node->left);
                    vis[node->left]=1;
                    change=1;
                }
                if(node->right and !vis[node->right]){
                    qu.push(node->right);
                    vis[node->right]=1;
                    change=1;
                }
                if(mpp[node] and !vis[mpp[node]]){
                    qu.push(mpp[node]);
                    vis[mpp[node]]=1;
                    change=1;
                }
            }
            if(change) maxi++;
        }
        return maxi;
    }
};