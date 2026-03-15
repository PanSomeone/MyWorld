#include<bits/stdc++.h>
using namespace std;
int n,num[15],ans[15];
void print(){
    for(int i=1;i<=n;i++){
        printf("%5d",ans[i]);
    }
    cout<<"\n";
    return ;
}
void dfs(int k){
    if(k>n){
        print();
        return ;
    }
    for(int i=1;i<=n;i++){
        if(!num[i]){
            num[i]=1;
            ans[k]=i;
            dfs(k+1);
            num[i]=0;
        }
    }
    return ;
}
int main(){
    cin>>n;
    dfs(1);
    return 0;
}
