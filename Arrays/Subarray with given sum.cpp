vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
        long long int sum = 0;
        int j = 0, i=0;
        vector<int>ans;
        while(j < n){
            sum+=arr[j++];
            while(sum > s){
                sum-=arr[i++];
            }
            if(sum == s){
                return {i+1, j};
            }
        }
        return {-1};
    }

//Time Complexity - O(n)
//Space Complexity - O(1)