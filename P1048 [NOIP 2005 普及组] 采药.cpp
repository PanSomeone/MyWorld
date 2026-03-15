#include<bits/stdc++.h>
using namespace std;
const int M=105;
int ti[M],v[M];
int dp[10005][10005];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t,m;
	cin>>t>>m;
	for(int i=1;i<=m;i++){
		cin>>ti[i]>>v[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=t;j++){
			if(j<ti[i]) dp[i][j]=dp[i-1][j];
			else dp[i][j]=max(dp[i-1][j],dp[i-1][j-ti[i]]+v[i]);
		}
	}
	cout<<dp[m][t]<<endl;
	return 0;
}
