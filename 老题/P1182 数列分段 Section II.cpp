#include<bits/stdc++.h>
using namespace std;
int n,m;
const int M=1e5+10;
int num[M];
int summ;
int maxx=0,l,r;
bool judge(int x){
	int cnt=0,sum=0;
	for(int i=1;i<=n;i++){
		if((sum+num[i])<=x){
			sum+=num[i];
		}
		else{
			sum=num[i];
			cnt++;
		}
	}
	return cnt>=m;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>num[i];
		maxx=max(maxx,num[i]);
		summ+=num[i];
	}
		l=maxx;
		r=1e9+1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(judge(mid)){
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout<<l<<endl;
	return 0;
}
