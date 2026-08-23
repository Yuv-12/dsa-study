class Solution { public: int getMinDiff(vector<int> &arr, int k) { // code here
	int n = arr.size(); sort(arr.begin(), arr.end()); int ans = arr[n - 1]-arr[0]; int smallest = arr[0]+k; int largest = arr[n - 1]-k; for (int i = 0; i<n; i++) { int minh = min(smallest, arr[i + 1]-k); int maxh = max(largest, arr[i]+k); if (minh<0) continue; ans = min(maxh - minh, ans); } return ans; } };
