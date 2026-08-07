/* Structure of a Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
}; */

class Solution {
  public:
    Node* constructBst(vector<int>& arr) {
        // code here
        int n = arr.size();
        if(n==0)
            return NULL;
        
        queue<pair<Node *,pair<int,int>>> q;
        Node *root = new Node(arr[0]);
        q.push({root,{INT_MIN,INT_MAX}});
        int i =  1;
        while(!q.empty())
        {
            auto curr = q.front();
            q.pop();
            Node * node = curr.first;
            int low = curr.second.first;
            int high = curr.second.second;
            
            if(i<n && arr[i]>= low && arr[i]<node->data)
            {
                node->left = new Node(arr[i]);
                q.push({node->left,{low,node->data - 1}});
                i++;
            }
            if(i<n && arr[i]<= high && arr[i]>node->data )
            {
                node->right = new Node(arr[i]);
                q.push({node->right,{node->data+1,high}});
                i++;
            }
        }
        return root;
    }
};