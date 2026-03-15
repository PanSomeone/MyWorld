#include<bits/stdc++.h>
using namespace std;
const int M=300+10;
struct student{
    int score;
    int ch;
    int num;
}students[M];
bool cmp(student a,student b){
    if(a.score>b.score){
        return 1;
    }
    else if(a.score<b.score){
        return 0;
    }
    else{
        if(a.ch>b.ch){
            return 1;
        }
        else if(a.ch<b.ch){
            return 0;
        }
        else{
            if(a.num<b.num){
                return 1;
            }
            else if(a.num>b.num){
                return 0;
            }
        }
    }

}
int main(){
    int n;
    int a,b,c;
    cin>>n;
   for(int i=1;i<=n;i++){
        cin>>a>>b>>c;
        students[i].num=i;
        students[i].ch=a;
        students[i].score=a+b+c;
   }
   sort(students+1,students+1+n,cmp);
   for(int i=1;i<=5;i++){
    cout<<students[i].num<<" "<<students[i].score<<endl;
   }
   return 0;
}
