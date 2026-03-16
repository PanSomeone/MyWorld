#include<bits/stdc++.h>
using namespace std;
const int M=25;
int num[M],res,n,sum,ans;
int lop[5];
void dfs(int k,int s){
	if(k>n){
		int l=s;
		int r=sum-l;
		ans =min(ans,max(l,r));
		return ;
	}
	dfs(k+1,s+num[k]);
	dfs(k+1,s);
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	for(int i=1;i<=4;i++) cin>>lop[i];
	for(int i=1;i<=4;i++){
		sum=0,ans=1e9;
		n=lop[i];
		for(int j=1;j<=n;j++){
			cin>>num[j];
			sum+=num[j];
		}
		dfs(1,0);
		res+=ans;
	}
		cout<<res<<'\n';
	return 0;
}
