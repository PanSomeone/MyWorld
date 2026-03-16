#include<bits/stdc++.h>
using namespace std;
const int M=1e2+10;
int n,pd[M],usd[M];
void print(){
    for(int i=1;i<=n;i++){
        printf("%5d",usd[i]);
    }
    cout<<"\n";
    return;
}
void dfs(int k){
    if(k==n){
       print();
       return;
    }
    for(int i=1;i<=n;i++){
        if(!pd[i]){
            pd[i]=1;
            usd[k+1]=i;
            dfs(k+1);
            pd[i]=0;
        }

    }

}
int main(){
    cin>>n;
    dfs(0);
    return 0;

}
