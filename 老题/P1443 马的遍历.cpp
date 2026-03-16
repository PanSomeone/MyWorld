#include<bits/stdc++.h>
using namespace std;
int MAP[405][405];
int mx[10]={ 1,1,-2, 2,-1,-1,-2,2};
int my[10]={-2,2,-1,-1,-2, 2, 1,1};
int n,m,dx,dy,x,y;
queue<pair<int,int>>q;
int main(){
	//ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	memset(MAP,-1,sizeof(MAP));
	cin>>n>>m>>dx>>dy;
	MAP[dx][dy]=0;
	q.push(make_pair(dx,dy));
	while(q.size()){
		x=q.front().first;
		y=q.front().second;
		for(int i=0,newx,newy;i<8;i++){
			newx=x+mx[i];
			newy=y+my[i];
			if(newx>=1&&newx<=n&&newy>=1&&newy<=m&&MAP[newx][newy]==-1){
				MAP[newx][newy]=MAP[x][y]+1;
				q.push(make_pair(newx,newy));
			}
		}
		q.pop();
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%-5d",MAP[i][j]);	
		}
		cout<<'\n';
	}
	return 0;
}
