int countTriplet(int arr[], int n)
	{
	    // Your code goes here
	    unordered_map<int, int>mp;
	    int ans = 0;
	    for(int i = 0;i<n;i++){
	        mp[arr[i]]++;
	    }
	    for(int i = 0;i<n-1;i++){
	        for(int j = i+1;j<n;j++){
	            if(mp.find(arr[i]+arr[j])!=mp.end())
	            ans++;
	        }
	    }
	    return ans;
	}
	//Time Complexity - O(n^2)
	//Space Complexity - O(n)