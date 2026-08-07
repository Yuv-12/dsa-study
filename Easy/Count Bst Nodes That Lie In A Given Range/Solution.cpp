/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  void inorder(Node *root,int l,int h,int &count)
  {
      if(root==NULL)
        return;
        inorder(root->left,l,h,count);
        if(root->data >= l && root->data<=h)
            count++;
        inorder(root->right,l,h,count);
  }
    int getCount(Node *root, int l, int h) {
        // your code here
        int count = 0;
        inorder(root,l,h,count);
        return count;
    }
};