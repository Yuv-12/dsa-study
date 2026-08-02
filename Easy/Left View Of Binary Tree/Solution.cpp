/* Structure of Binary Tree Node
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
    vector<int> leftView(Node *root) {
        // code here
        vector<int> res;
        if(root == NULL)
            return res;
        queue<Node *> q;
        q.push(root);
        while(!q.empty())
        {
            int levSize = q.size();
            for(int i =0;i<levSize;i++)
            {
                Node *temp =  q.front();
                q.pop();
                if(i==0)
                    res.push_back(temp->data);
                if(temp->left!=NULL)
                    q.push(temp->left);
                if(temp->right!=NULL)
                    q.push(temp->right);
            }
        }
        return res;
    }
};