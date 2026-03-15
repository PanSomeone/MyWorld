#include<bits/stdc++.h>
using namespace std;
int n,a,b,ans=2<<31 -1;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		if(i==0) b=a;
		else b=max(a,a+b);
		ans=max(ans,b);
	}
	cout<<ans;
	
	return 0;
}
