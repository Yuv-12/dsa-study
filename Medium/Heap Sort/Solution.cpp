// The functions should be written in a way that array become sorted
// in increasing order when heapSort() is called.

class Solution {
  public:
    // Function to sort an array using Heap Sort.
    void heapSort(vector<int>& arr) {
        // code here
        priority_queue<int,vector<int>,greater<int>> hp;
        for(int x : arr)
            hp.push(x);
        for(int i = 0;i<arr.size();i++)
        {
            arr[i] = hp.top();
            hp.pop();
        }
    }
};