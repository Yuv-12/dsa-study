/* Structure for tree and linked list
class Node {
  public:
    int data;
    Node *left, *right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};*/
class Solution {
  public:
  Node *prev = NULL;
  Node *head = NULL;
  
  void inorder(Node *root)
  {
      if(root==NULL)
        return;
    
    inorder(root->left);
    if(prev == NULL)
        head = root;
    else
    {
        prev->right = root;
        root->left = prev;
    }
    prev = root;
    inorder(root->right);
    
  }
    Node* treeToDLL(Node* root) {
        // code here
        if(root==NULL)
            return NULL;
        
        head = NULL;
        prev = NULL;
        inorder(root);
        prev->right = NULL;
        return head;
    }
};