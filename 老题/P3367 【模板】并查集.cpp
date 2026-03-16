#include<bits/stdc++.h>
using namespace std;
const int M=2e5+10;
int num[M];
int z,x,y;
int find(int x){
	if(num[x]==x) return x;
	else{
		int t=find(num[x]);
		num[x]=t;
		return num[x];
	}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) num[i]=i;
	while(m--){
		cin>>z>>x>>y;
		if(z==1) num[find(x)]=find(y);
		else {
			if(find(x)==find(y)) cout<<"Y"<<endl;
			else cout<<"N"<<endl;
		}
	}
	return 0;
}
