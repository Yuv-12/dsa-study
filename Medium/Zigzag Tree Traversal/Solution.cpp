/* Structure of Binary Tree Node
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        // code here
        vector<int> res;
        queue<Node*> q;
        q.push(root);
        bool leftToRight = true;
        while(!q.empty())
        {
            int levSize = q.size();
            vector<int> lev(levSize);
            for(int i = 0;i<levSize;i++)
            {
                
                Node *temp = q.front();
                q.pop();
                
                int index = leftToRight?i:levSize-1-i;
                lev[index] = temp->data;
                
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            res.insert(res.end(),lev.begin(),lev.end());
            leftToRight = !leftToRight;
        }
        return res;
    }
};