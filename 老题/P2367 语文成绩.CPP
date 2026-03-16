#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=5e6+10;
int stu[M];
int diff[M];
signed main(){
    int n,p;
    scanf("%d%d",&n,&p);
    for(int i=1;i<=n;i++){
        scanf("%d",&stu[i]);
    }
    for(int i=1;i<=n;i++){
        diff[i]=stu[i]-stu[i-1];
    }
    int l,r,score;
    for(int i=1;i<=p;i++){
        cin>>l>>r>>score;
        diff[l]+=score;
        diff[r+1]-=score;
    }
    int min=1e9;
    for(int i=1;i<=n;i++){
        stu[i]=diff[i]+stu[i-1];
        if(min>stu[i]){
            min=stu[i];
    }
    }
    printf("%d",min);
    return 0;
    }
