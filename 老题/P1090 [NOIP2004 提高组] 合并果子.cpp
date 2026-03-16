#include<bits/stdc++.h>
using namespace std;
const int M=1e5+10;
int n,x,ans;
priority_queue<int,vector<int>,greater<int> >q;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		q.push(x);
	}
	while(q.size()>=2){
		int x1=q.top();
		q.pop();
		int x2=q.top();
		q.pop();
		ans+=x1+x2;
		q.push(x1+x2);
	}
	cout<<ans<<endl;
	return 0;
}
