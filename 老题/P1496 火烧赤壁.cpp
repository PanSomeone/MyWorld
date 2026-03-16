#include<bits/stdc++.h>
using namespace std;
const int M=2e4+10;
int beginn[M];
int endd[M];
int sum;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>beginn[i]>>endd[i];
	}
	sort(beginn,beginn+n);
	sort(endd,endd+n);
	for(int i=0;i<n;i++){
		sum+=endd[i]-beginn[i];
		if(i+1<n){
			if(endd[i]>beginn[i+1]){
				sum-=endd[i]-beginn[i+1];
			}
		}
		
		
		
		
		
		
		
		
//		for(int j=i+1;j<n;j++){
//			if(beginn[j]<endd[i]){
//				if(k==0){
//					sum-=endd[i]-beginn[i];
//					sum-=endd[j]-beginn[j];
//					k=1;
//				}
//				int minn=min(beginn[i],beginn[j]);
//				int maxx=max(endd[i],endd[j]);
//				sum+=maxx-minn;
//			}
//		}
//		sum+=endd[i]-beginn[i];
	}
	cout<<sum;
	cout<<'\n';
	return 0;
}
