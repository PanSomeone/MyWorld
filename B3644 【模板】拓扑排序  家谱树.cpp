#include<bits/stdc++.h>
using namespace std;
const int M=105;
int n,x,du[M];
vector<int>f[M];
queue<int>q;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		while(true){
			cin>>x;
			if(x==0)break;
			f[i].push_back(x);
			du[x]++;
		}	
	}
	for(int i=1;i<=n;i++)
		if(du[i]==0)
			q.push(i);
	while(!q.empty()){
		int t=q.front();
		q.pop();
		cout<<t<<' ';
		for(auto to:f[t]){
			du[to]--;
			if(du[to]==0)
				q.push(to);
		}
	}
	return 0;
}
