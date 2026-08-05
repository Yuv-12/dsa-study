/* Structure of binary tree node
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
  void s(Node *root,vector<int> &res)
  {
      if(root==NULL)
      {
          res.push_back(-1);
          return;
      }
      res.push_back(root->data);
      s(root->left,res);
      s(root->right,res);
  }
    vector<int> serialize(Node *root) {
        //  code here
        vector<int> res;
        s(root,res);
        return res;
    }
    int index = 0;
    Node *deSerialize(vector<int> &arr) {
        
        //  code here
        if(index==arr.size())
            return NULL;
            
        int val = arr[index];
        index++;
        if(val == -1)
            return NULL;
        
        Node *root = new Node(val);
        root->left = deSerialize(arr);
        root->right = deSerialize(arr);
        return root;
    }
};