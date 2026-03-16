#include<bits/stdc++.h>
using namespace std;
const int M=2e5+10;
int n,high,m;
int cow[M];
int main(){
    cin>>n>>high;
    for(int i=0;i<n;i++){
        cin>>cow[i];
    }
    sort(cow,cow+n);
    int sum=0;
    for(int j=n;;j--){
        if(sum>high){
            cout<<n-1-j;
            return 0;
        }
        sum=sum+cow[j];
    }
    return 0;
}
