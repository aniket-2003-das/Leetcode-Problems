/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void marksParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track){
        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty()){
            TreeNode* current = queue.front();
            queue.pop();
            if(current->left){
                parent_track[current->left] = current;
                queue.push(current->left);
            }
            if(current->right){
                parent_track[current->right] = current;
                queue.push(current->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track;
        marksParent(root, parent_track);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> queue;
        queue.push(target);
        visited[target] = true;
        int curr_level = 0;

        while(!queue.empty()){
            int size = queue.size();
            if(curr_level==k) break;
            curr_level++; 
            for(int i=0; i<size; i++){
                TreeNode* current = queue.front(); queue.pop();
                if(current->left && !visited[current->left]){
                    queue.push(current->left);
                    visited[current->left] = true;
                }
                if(current->right && !visited[current->right]){
                    queue.push(current->right);
                    visited[current->right] = true;
                }
                if(parent_track[current] && !visited[parent_track[current]]){
                    queue.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
        }
        vector<int> result;
        while(!queue.empty()){
            TreeNode* current = queue.front(); queue.pop();
            result.push_back(current->val);
        }
        return result;
    }
};