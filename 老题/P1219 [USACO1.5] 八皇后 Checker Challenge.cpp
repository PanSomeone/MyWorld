#include<bits/stdc++.h>
using namespace std;
const int M=15;
int ans[M],lie[M],cnt=0;
int lx_ys[50],ls_yx[50];//左下-》右上,左上-》右下
int n,ansz=0;
void dfs(int index,int n){
	if(index>n){
		ansz++;
		if(cnt<3){
			cnt++;
			for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
			cout<<'\n';
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(lie[i]) continue;
		if(lx_ys[n-index+i])continue;
		if(ls_yx[index+i-1])continue;
		ans[index]=i;
		lie[i]=1;
		lx_ys[n-index+i]=1;
		ls_yx[index+i-1]=1;
		dfs(index+1,n);
		lie[i]=0;
		lx_ys[n-index+i]=0;
		ls_yx[index+i-1]=0;
		
	}
	
	
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	dfs(1,n);
	cout<<ansz<<endl;
	return 0;
}
