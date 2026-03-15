#include<bits/stdc++.h>
using namespace std;
int n,m,t,x,y,xx,yy,dx,dy,cnt;
const int M=6;
int vis[M][M];
int Map[M][M];
void dfs(int x,int y){
	if(x<1||x>n) return ;
	if(y<1||y>m) return ;
	if(x==xx&&y==yy) {
		cnt++;
		return ;
	}
	if(Map[x][y]||vis[x][y]) return ;
	vis[x][y]=1;
	dfs(x+1,y);
	dfs(x,y+1);
	dfs(x-1,y);
	dfs(x,y-1);
	vis[x][y]=0;
	return ;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m>>t;
	cin>>dx>>dy>>xx>>yy;
	//vis[dx][dy]=1;
	
	for(int i=0;i<t;i++){
		cin>>x>>y;
		Map[x][y]=1;
	}
	if(Map[xx][yy]){
		cout<<0<<endl;
		return 0;
	}
	dfs(dx,dy);
	cout<<cnt<<endl;
	return 0;
}
