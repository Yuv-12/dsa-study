/* Structure of a Binary Search Tree node
class Node {
   public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
  void inorder(Node * root,int k,int &ans)
  {
      if(root==NULL)
        return;
        inorder(root->left,k,ans);
        ans = min(ans,abs(root->data - k));
        inorder(root->right,k,ans);
  }
    int minDiff(Node *root, int k) {
        // code here
        int ans = INT_MAX;
        inorder(root,k,ans);
        return ans;
        
    }
};