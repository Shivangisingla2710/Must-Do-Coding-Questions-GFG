long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        int mx = INT_MIN;
        int sm = 0;
        for(int i = 0;i<n;i++){
            sm+=arr[i];
            if(arr[i] > sm)
            sm = arr[i];
            mx = max(mx, sm);
        }
        return mx;
    }
    //Time Complexity - O(n)
    //Space Complexity - O(1)