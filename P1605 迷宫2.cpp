#include<bits/stdc++.h>
using namespace std;
const int M=10;
int n,m,t;
int qx,qy,zx,zy,x,y,cnt;
int vis[6][6];
void dfs(int x,int y){
	if(x<1||x>n){return ;}
	if(y<1||y>m){return ;}
	if(x==zx&&y==zy){
		cnt++;
		return ;
	}
	if(vis[x][y]) return ;
	vis[x][y]=1;
	dfs(x+1,y);
	dfs(x-1,y);
	dfs(x,y+1);
	dfs(x,y-1);
	vis[x][y]=0;
	return ;
	
}
int main(){
	cin>>n>>m>>t;
	cin>>qx>>qy>>zx>>zy;
	while(t--){
		cin>>x>>y;
		vis[x][y]=1;
	}
	if(vis[zx][zy]){
		cout<<0<<endl;
		return 0;
	}
	dfs(qx,qy);
	cout<<cnt<<endl;
	return 0;
}
