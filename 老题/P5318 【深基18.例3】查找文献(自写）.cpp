#include<bits/stdc++.h>
using namespace std;
const int M=1e6+10;
int n,m,x,y;
vector<int>f[M];
int vis[M];
void dfs(int x){
	vis[x]=1;
	cout<<x<<' ';
	for(auto to:f[x]){
		if(!vis[to]) dfs(to);	}
	return ;
}
int main(){
	cin>>n>>m;
	while(m--){
		cin>>x>>y;
		f[x].push_back(y);
	}
	for(int i=1;i<=n;i++){
		sort(f[i].begin(),f[i].end());
	}
	dfs(1);
	cout<<'\n';
	queue<int>q;
	for(int i=0;i<=n;i++)vis[i]=0;
	q.push(1);
	vis[1]=1;
	while(!q.empty()){
		int t=q.front();
		q.pop();
		cout<<t<<' ';
		for(int to:f[t]){
			if(!vis[to]){
				q.push(to);
				vis[to]=1;
			}
		}
	}
	return 0;
}        
