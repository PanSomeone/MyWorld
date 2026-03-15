#include<bits/stdc++.h>
using namespace std;
const int M=1e6+10;
long long int num[M];
int n,m;
int xia(int x){
    int l=1,r=n;
    while(l<r){
        int mid=l+(r-l)/2;
        if(num[mid]>=x)r=mid;
        else l=mid+1;
    }
    if(num[l]==x) return l;
    else return -1;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&num[i]);
    }
    int x;
    for(int i=0;i<m;i++){
        scanf("%d",&x);
        printf("%d ",xia(x));
    }
    return 0;

}
