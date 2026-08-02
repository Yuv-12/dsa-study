/* A binary tree Node

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
 */
class Solution {
  public:
    vector<vector<int>> levelOrder(Node* root) {
        // code here
        vector<vector<int>> res;
        if(root==NULL)
            return res;
        
        
        queue<Node *> q;
        q.push(root);
        while(!q.empty())
        {
            int levSize = q.size();
            vector<int> lev;
            for(int i =0;i<levSize;i++)
            {
                Node*temp = q.front();
                q.pop();
                lev.push_back(temp->data);
                if(temp->left!=NULL)
                    q.push(temp->left);
                if(temp->right!=NULL)
                    q.push(temp->right);
            }
            res.push_back(lev);
        }
        return res;
        
    }
};