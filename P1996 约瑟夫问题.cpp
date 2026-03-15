#include<bits/stdc++.h>
using namespace std;
queue<int>q;
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        q.push(i);
    }
    int i=0;
    while(!q.empty()){
        i++;
        if(i==m){
            cout<<q.front()<<" ";
            q.pop();
            i=0;
        }
        else{
            q.push(q.front());
            q.pop();
        }
    }
    return 0;
}
