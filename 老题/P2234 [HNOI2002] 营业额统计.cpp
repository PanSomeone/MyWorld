#include<bits/stdc++.h>
using namespace std;
set<int>s;
set<int>::iterator k,a;
int _,ans,x;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	s.insert(-192608170);
	s.insert(192608170);
	cin>>_;
	while(_--){
		cin>>x;
		if(s.size()==2){
			ans+=x;
			s.insert(x);
		}
		else{
			k=s.lower_bound(x);
			if(*k!=x){
				a=k;
				a--;
				ans+=min(abs(*a-x),abs(*k-x));
				s.insert(x);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
