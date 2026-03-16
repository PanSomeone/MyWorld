#include<bits/stdc++.h>
using namespace std;
int n,k,num[25];
long long cnt;
bool isP(int x){
	if(x==1) return false;
	//if(x==2||x==3) return true;
	for(int i=2;i*i<=x;i++) if(x%i==0){return false;}
	return true;
}
void dfs(int m,int sum,int x){
	if(m==k){
		if(isP(sum))
			cnt++;
		return ;
	}
	for(int i=x;i<n;i++)
		dfs(m+1,sum+num[i],i+1);
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>num[i];
	dfs(0,0,0);
	cout<<cnt<<'\n';
	return 0;
}
