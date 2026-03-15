#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int n,m,x,y,z,cnt;
ll ans;
const int M=2e5+10;
struct edge{
	int start,to;
	ll val;
}edges[M];
int f[M];
int find(int x){
	if(f[x]==x) return x;
	else{
		f[x]=find(f[x]);
		return f[x];
	}
}
bool cmp(edge a,edge b){
	return a.val<b.val;
}
void kruskal(){
	for(int i=1;i<=m;i++){
		int u=find(edges[i].start);
		int v=find(edges[i].to);
		if(u==v) continue;
		ans+=edges[i].val;
		f[u]=v;
		cnt++;
		if(cnt==n-1) break;
	}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		cin>>edges[i].start>>edges[i].to>>edges[i].val;
	}
	sort(edges+1,edges+1+m,cmp);
	kruskal();
	if(find(1)!=find(n)){
		cout<<"orz";
		return 0;
	}
	cout<<ans;
	return 0;
}
