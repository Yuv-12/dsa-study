/* Structure of tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/
class Solution {
  public:
 
  void inorder(Node *root,int low,int high,vector<int> &res)
  {
      if(root==NULL)
        return;
        
        inorder(root->left,low,high,res);
        if(root->data >= low && root->data<=high)
            res.push_back(root->data);
        inorder(root->right,low,high,res);
  }
    vector<int> nodesInRange(Node *root, int low, int high) {
         vector<int> res;
        inorder(root,low,high,res);
        return res;
    }
};