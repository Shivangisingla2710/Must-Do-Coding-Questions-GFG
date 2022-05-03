int MissingNumber(vector<int>& array, int n) {
        // Your code goes here
        //int sum = int(n*(n+1)/2);
        int s = 0;
        for(int i = 0;i<n-1;i++){
            s=s+array[i];
        }
        //cout<<n<<" "<<s<<endl;
        return n*(n+1)/2 - s;
    }
    //Time complexity - O(n)
    //Space Complexity - O(1)