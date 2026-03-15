#include<bits/stdc++.h>
using namespace std;
int n,ming=1<<30,pl[15];
struct a{
    int suan;
    int ku;
}as[15];
void dfs(int k,int x,int y){
    if(k>n){
        if(y==0)
            return ;
        ming=min(abs(x-y),ming);
        return;
    }
    dfs(k+1,x,y);
    dfs(k+1,x*as[k].suan,y+as[k].ku);
    return ;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>as[i].suan>>as[i].ku;
    }
    dfs(1,1,0);
    cout<<ming;
    return 0;
}
