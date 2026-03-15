#include<bits/stdc++.h>
using namespace std;
const int M=1e6+10;
struct node{
	int l,r;
}tree[M];
int ans;
void dfs(int x,int deep){
	if(x==0) return;
	ans=max(ans,deep);
	dfs(tree[x].l,deep+1);
	dfs(tree[x].r,deep+1);
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>tree[i].l>>tree[i].r;
	}
	dfs(1,1);
	cout<<ans<<endl;
	return 0;
}
