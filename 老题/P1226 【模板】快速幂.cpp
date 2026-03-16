#include<bits/stdc++.h>
using namespace std;
#define int long long 
int a,b,p;
int64_t powint(int base, int exp)
{
	int64_t result=1;
	while (exp)
	{
		if (exp & 1) result =1ll*result*base%p;
		exp >>= 1;
		base =1ll*base*base%p;
	} 
	return result;
}
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>a>>b>>p;
	int ans=powint(a,b);
	ans %=p;
	printf("%d^%d mod %d=%d",a,b,p,powint(a,b));
	return 0;
}
