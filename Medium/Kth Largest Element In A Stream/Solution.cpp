class Solution {
  public:
    // Function to print kth largest element for each element in the stream.
    void kthLargest(int arr[], int n, int k) {
        // your code here
        priority_queue<int,vector<int>,greater<int>> q;
        for(int i = 0;i<n;i++)
        {
            q.push(arr[i]);
            if(q.size() > k)
                q.pop();
            if(q.size() < k)
                cout<<"-1"<<" ";
            else
                cout<<q.top()<<" ";
        }
    }
};