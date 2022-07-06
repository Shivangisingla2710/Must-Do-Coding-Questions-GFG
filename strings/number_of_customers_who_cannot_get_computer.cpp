#include <iostream>
using namespace std;
#include<bits/stdc++.h>
int main() {
	// your code goes here
	int n;
	string s;
	cin>>n>>s;
	int hash[26]={0};
	int i;
	for(i = 0;i<s.size();i++){
	    if(hash[s[i] - 65]){
	        n++;
	        hash[s[i]- 65] = 0;
	        continue;
	    }
	    if(!n){
	        cout<<"couldn't"<<endl;
	        break;
	    }
	    n--;
	    hash[s[i] - 65] = 1;
	}
	if(i == s.size())
	cout<<"Could"<<endl;
	return 0;
}
