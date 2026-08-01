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
  void postorder(Node *root,vector<int> &res)
  {
      if(root == NULL)
        return ;
        
        postorder(root->left,res);
        postorder(root->right,res);
        res.push_back(root->data);
  }
    vector<int> postOrder(Node* root) {
        // code here
        vector<int> res;
        postorder(root,res);
        return res;
    }
};