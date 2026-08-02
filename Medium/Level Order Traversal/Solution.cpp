/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    vector<int> levelOrder(Node *root) {
        // code here
        if(root == NULL)
            return {};
        vector<int> res;
        queue<Node *> q;
        q.push(root);
        while(!q.empty())
        {
            Node *curr = q.front();
            res.push_back(curr->data);
            q.pop();
            if(curr->left!=NULL)
                q.push(curr->left);
            if(curr->right!=NULL)
                q.push(curr->right);
        }
        return res;
    }
};