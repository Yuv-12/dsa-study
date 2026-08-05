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
};*/

class Solution {
  public:
  void inorder(Node *r,map<int,int>&freq)
  {
      if(r == NULL)
        return;
        inorder(r->left,freq);
        freq[r->data]++;
        inorder(r->right,freq);
  }
    vector<int> findCommon(Node* r1, Node* r2) {
        // code here
       map<int,int> freq;
        vector<int> res;
        inorder(r1,freq);
        inorder(r2,freq);
        for(auto it : freq)
        {
            if(it.second == 2)
                res.push_back(it.first);
        }
        return res;
    }
};