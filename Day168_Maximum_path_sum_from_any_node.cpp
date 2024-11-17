//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User Fuction template for C++

class Solution {
  public:
    //Function to return maximum path sum from any node in a tree.
    int maxpath(Node* root, int& maxi){
        if(root==NULL) return 0;

        int leftsum = max(0, maxpath(root->left, maxi));
        int rightsum = max(0, maxpath(root->right, maxi));

        maxi = max(maxi, (leftsum + rightsum + root->data));
        return root->data + max(leftsum, rightsum);
    }

    // pair<int,int> solve(TreeNode* root){
    //     if(root==NULL) return {INT_MIN, 0};

    //     pair<int,int> left=solve(root->left);
    //     pair<int,int> right=solve(root->right);

    //     if(left.second<0) left.second=0;
    //     if(right.second<0) right.second=0;

    //     return {max({left.first, right.first, (left.second+right.second+root->data)}), max(left.second, right.second) + root->data};
    // }

    int findMaxSum(Node* root) {
        int maxi = INT_MIN;
        maxpath(root, maxi);
        return maxi;
        // pair<int,int> ans=solve(root);
        // return ans.first;
    }
};

//{ Driver Code Starts.


int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        cout << ob.findMaxSum(root) << "\n";

    
cout << "~" << "\n";
}


    return 0;
}
// } Driver Code Ends