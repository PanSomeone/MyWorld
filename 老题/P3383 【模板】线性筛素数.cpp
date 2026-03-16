#include<bits/stdc++.h>
using namespace std;
const long int M=1e8+10,N=6e6+10;
bool isP[M];
int P[N],cnt,n,q;
void check(int n){
	memset(isP,1,sizeof(isP));
	isP[1]=0;
	for(int i=2;i<=n;i++){
		if(isP[i])
			P[++cnt]=i;
		for(int j=1;j<=cnt&&i*P[j]<=n;j++){
			isP[i*P[j]]=0;
			if(i%P[j]==0) break;
		}
	}
}
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	check(n);
	while(q--){
		int x;
		cin>>x;
		cout<<P[x]<<endl;
	}
	return 0;
}
