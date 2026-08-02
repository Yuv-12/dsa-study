/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> rightView(Node *root) {
        //  code here
        vector<int> res;
        if(root == NULL)
            return res;
        queue<Node *> q;
        q.push(root);
        while(!q.empty())
        {
            int levSize = q.size();
            for(int i = 0;i<levSize;i++)
            {
                Node *temp = q.front();
                q.pop();
                if(i==levSize-1)
                    res.push_back(temp->data);
                
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
        return res;
    }
};