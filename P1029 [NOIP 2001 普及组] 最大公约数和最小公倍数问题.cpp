#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int a,b,cnt=0;
	cin>>a>>b;
	for(int i=a;i<=b;i++){
		int j=a*b/i;
		if(__gcd(i,j)==a&&(i*j)/__gcd(i,j)==b) cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}
