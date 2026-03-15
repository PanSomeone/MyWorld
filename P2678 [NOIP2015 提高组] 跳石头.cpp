#include<bits/stdc++.h>
using namespace std;
const int M=5e4+10;
int len[M];
int length,n,m,left,right,mid,ans;
bool judge(int x){
	int cnt=0,des=0;
	for(int i=1;i<=n;i++) {
		if(len[i]-des<x){cnt++;}
		else{des=len[i];}
	}
	return cnt<=m;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>length>>n>>m;
	for(int i=1;i<=n;i++) cin>>len[i];
	len[++n]=length;
	int left=1,right=length;
	while(left<=right){
		mid=(left+right)/2;
		if(judge(mid)){
			ans=mid;
			left=mid+1;}
		else{right=mid-1;}
	}	
	cout<<ans<<endl;
	return 0;
}
