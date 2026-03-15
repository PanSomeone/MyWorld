#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int M=1e6+10;
int n,m,tree[M],sum,mid;
void solve(){
	int left=tree[0],right=tree[n-1];
	while(left<=right){
		sum=0;
		mid=left+(right-left)/2;
		for(int i=0;i<n;i++){
			if(tree[i]>mid)sum+=tree[i]-mid;
		}
		if(sum<m) right=mid-1;
		else 	  left=mid+1;
	}
	cout<<left-1<<endl;
	return ;
}
signed main(){
	//ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>tree[i];
	}
	sort(tree,tree+n);
	solve();
	return 0;
}
