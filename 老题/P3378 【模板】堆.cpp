    #include<bits/stdc++.h>
    using namespace std;
    const int M=1e6+10;
    int n,x,k;
    priority_queue<int,vector<int>,greater<int> >q;
    int main(){
        cin>>n;
        int j=0;
        for(int i=0;i<n;i++){
            cin>>x;
            switch(x){
        case 1:
            cin>>k;
            q.push(k);
            break;
        case 2:
            cout<<q.top()<<"\n";
            break;
        case 3:
            q.pop();
            }
        }
        return 0;
    }
