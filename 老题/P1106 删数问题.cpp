#include<bits/stdc++.h>
using namespace std;
string s;
int n,minn,maxx=0;
queue<int>q;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);	
	cin>>s;
	cin>>n;
	int length=s.size();
	while(n--){
		for(int i=0;i<=length;i++){
			while(s[0]=='0'){
				s.erase(0,1);
			}
			if(s[i]>s[i+1]){
				s.erase(i,1);
				length--;
				break;
			}
		}
	}
	for(int i=0;i<length;i++){
		cout<<s[i];
	}
	cout<<'\n';
	return 0;
}
