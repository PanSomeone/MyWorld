#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,c,x;
const int M=1e5+10;
priority_queue< int,vector<int>,greater<int> >ans;
int f(int x,int a,int b,int c){
	return a*x*x+b*x+c;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	while(n--){
		cin>>a>>b>>c;
		for(int x=1;x<=1000;x++){
			ans.push(f(x,a,b,c));
		}
	}
	for(int i=0;i<m;i++){
		cout<<ans.top()<<' ';
		ans.pop();
	}
	return 0;
}
