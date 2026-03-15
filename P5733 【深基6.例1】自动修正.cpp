#include<bits/stdc++.h>
using namespace std;
char ch;
int main(){
	//ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	if(cin>>ch){
		if(ch>='a'&&ch<='z') cout<<char(ch-32);
		else cout<<ch;
		main();
	}
	return 0;
}
