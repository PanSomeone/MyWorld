#include<bits/stdc++.h>
using namespace std;
int n,m,x,y;
const int M=1e5+10;
int f[M][M];
int vis[M][M];
void  dfs(int j,int k){
	vis[j][k]=1;
	for(auto to:vis)
	
	
	
}
int main(){
	cin>>n>>m;
	while(m--){
		cin>>x>>y;
		f[x][y]=1;
	}
	dfs(1,1);
	return 0;
}
