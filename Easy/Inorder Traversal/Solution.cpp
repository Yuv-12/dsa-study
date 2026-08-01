/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
  vector<int> res;
    vector<int> inOrder(Node* root) {
        // code here
        
        if(root == NULL )
            return{};
        
        inOrder(root->left);
        res.push_back(root->data);
        inOrder(root->right);
        return res;
    }
};