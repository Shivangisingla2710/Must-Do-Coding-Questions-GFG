#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//function to build a segment tree
void build(int node, int start, int end, int*arr, int*tree){
    if(start == end){
        tree[node] = arr[start];
        return;
    }else{
        int mid = (start+end)/2;
        int left = node*2+1;
        int right = node*2+2;
        build(left, start, mid, arr, tree);
        build(right, mid+1, end, arr, tree);
        //tree[node] = max(tree[node*2+1], tree[node*2+2]);// to find maximum element
        tree[node] = tree[node*2+1] + tree[node*2+2];
    }
}

void queryUpdate(int node, int start, int end, int pos, int val, int* tree, int*arr){
    if(start == end){
        arr[start] = val;
        tree[node] = val;
        return;
    }
    int mid = (start+end)/2;
    if(start <= pos && pos <= mid)
    queryUpdate(node*2+1, start, mid, pos, val, tree, arr);
    else
    queryUpdate(node*2+2, mid+1, end, pos, val, tree, arr);
    //tree[node] = max(tree[node*2+1], tree[node*2+2]);
    tree[node] = tree[node*2+1] + tree[node*2+2];
}
int queryMax(int node, int start, int end, int l, int r, int* tree){
    if(r < start || l > end)
    return INT_MIN;
    if(start == end || (l<=start && end<=r))
    return tree[node];
    int mid = (start+end)/2;
    int left = queryMax(node*2+1, start, mid, l, r, tree);
    int right = queryMax(node*2+2, mid+1,end, l, r, tree);
    return max(left, right);
}

int querySum(int node, int start, int end, int l, int r, int* tree){
    if(r < start || l > end)
    return 0;
    if(start == end || (l<=start && end<=r))
    return tree[node];
    int mid = (start+end)/2;
    int left = querySum(node*2+1, start, mid, l, r, tree);
    int right = querySum(node*2+2, mid+1,end, l, r, tree);
    return left+right;
}

int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i =0;i<n;i++)
    cin>>arr[i];
    int x = (int)(ceil(log2(n))); 
    int max_size = 2*(int)pow(2, x) - 1; 
    int *tree = new int[max_size]; 
    build(0,0,n-1, arr, tree);
    //print tree
    // for(int idx = 0;idx<max_size;idx++){
    //     cout<<tree[idx]<<" ";
    // }
    // cout<<endl;
    
    int m;
    cin>>m;
    for(int i = 0;i<m;i++){
        int t,l,r;
        cin>>t>>l>>r;
        if(t == 1){
            int res = querySum(0, 0, n-1, l, r, tree);
            cout<<i+1<<"-> "<<res<<endl;
        }
        else if(t == 0){
            queryUpdate(0,0, n-1, l, r, tree, arr);
            cout<<i+1<<"-> ";
            for(int i = 0;i<n;i++)
            cout<<arr[i]<<" ";
            cout<<endl;
        }
    }
    
    return 0;
}