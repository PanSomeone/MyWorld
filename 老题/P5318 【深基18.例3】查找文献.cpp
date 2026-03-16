#include<bits/stdc++.h>
using namespace std;
const int M=1e6+5;
int vis[M];
vector<int>f[M];
void dfs(int x){
	vis[x]=1;
	cout<<x<<' ';
	for(auto to:f[x]){
		if(!vis[to]) dfs(to);
	}
}
void bfs(){
	queue<int>p;
	p.push(1);
	vis[1]=1;
	while(!p.empty()){
		int t=p.front();
		p.pop();
		cout<<t<<' ';
		for(int to:f[t]){
			if(!vis[to]){
				p.push(to);
				vis[to]=1;
			}
		}
	}
	return ;
}
int main(){
	int n,m;
	cin>>n>>m;
	while(m--){
		int x,y;
		cin>>x>>y;
		f[x].push_back(y);
	}
	for(int i=1;i<=n;i++){
		sort(f[i].begin(),f[i].end());
	}
	dfs(1);
	cout<<'\n';
	for(int i=1;i<=n;i++)vis[i]=0;
	bfs();
	return 0;
}
