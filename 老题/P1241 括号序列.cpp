#include<bits/stdc++.h>
using namespace std;
stack<int>q;
string s1,s2;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>s1;
	s2.resize(s1.size(), ' ');
	for(int i=0;i<s1.size();i++){
		if(s1[i]=='('){
			q.push(i);
			s2[i]=')';
		}
		else if(s1[i]=='['){
			q.push(i);
			s2[i]=']';
		}
		else if(s1[i]==')'||s1[i]==']'){
			if(q.empty()||s2[q.top()]!=s1[i]){
				if(s1[i]==')') s2[i]='(';
				else 		   s2[i]='[';
			}
			else{
				s2[q.top()]=' ';
				q.pop();
			}	
		}
	}
	for(int i=0;i<s1.size();i++){
		if(s2[i]=='('||s2[i]=='[') cout<<s2[i];
		cout<<s1[i];
		if(s2[i]==')'||s2[i]==']') cout<<s2[i];
	}
	cout<<'\n';
	
//	reverse(s2.begin(),s2.end());
//	cout<<s1<<endl;
//	cout<<s2<<endl;
	return 0;
}
