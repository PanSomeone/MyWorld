#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e9+10;
string ch[20];
bool cmp(string a,string b){
    return a+b>b+a;
}
signed main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ch[i];
    }
    sort(ch,ch+n,cmp);
    for(int i=0;i<n;i++){
        cout<<ch[i];
    }
    cout<<endl;
    return 0;
}
