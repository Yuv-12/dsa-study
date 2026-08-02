/*
Structre of the node of the tree is as
struct Node
{
    int data;
    Node* left, *right;
};
*/
class Solution {
  public:
  void deleteDeepest(Node* root,Node* last)
  {
      queue<Node *> q;
      q.push(root);
      while(!q.empty())
      {
          Node * temp = q.front();
          q.pop();
          if(temp->left)
          {
              if(temp->left==last)
              {
                  delete temp->left;
                  temp->left = NULL;
                  return;
              }
              q.push(temp->left);
          }
          if(temp->right)
          {
              if(temp->right==last)
              {
                  delete temp->right;
                  temp->right = NULL;
                  return;
              }
              q.push(temp->right);
          }
      }
  }
    Node* deleteNode(Node* root, int key) {
        // code here
        if(root==NULL)
            return NULL;
        
        if(root->left==NULL && root->right==NULL)
        {
            if(root->data == key)
            {
                delete root;
                return NULL;
            }
            return root;
        }
        
        Node *temp = NULL;
        Node *key_node = NULL;
        queue<Node *>q;
        q.push(root);
        while(!q.empty())
        {
            temp = q.front();
            q.pop();
            if(temp->data == key)
                key_node = temp;
            
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        if(key_node!=NULL)
        {
            key_node->data = temp->data;
            deleteDeepest(root,temp);
        }
        return root;
    }
};