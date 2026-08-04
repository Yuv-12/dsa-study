/* Structure of binary tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
  int postIndex;
  unordered_map<int,int> inorderMap;
  Node *build(vector<int>&inorder,vector<int>&postorder,int left,int right)
  {
      if(left > right)
        return NULL;
    
        int rootData = postorder[postIndex];
        Node *root = new Node(rootData);
        postIndex--;
        
        int splitIndex = inorderMap[rootData];
        
        root->right = build(inorder,postorder,splitIndex+1,right);
        root->left = build(inorder,postorder,left,splitIndex-1);
        return root;
  }
    Node *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // code here
        for(int i = 0;i<inorder.size();i++)
        {
            inorderMap[inorder[i]]=i;
        }
        
        postIndex = postorder.size()-1;
        return build(inorder,postorder,0,inorder.size()-1);
    }
};