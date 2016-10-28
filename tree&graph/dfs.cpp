#include <iostream>
using namespace std;

#define initial 1
#define waiting 2
#define visited 3
#define MAX 100
char adj[MAX][MAX];
int state[MAX];
int start[MAX];
int end[MAX];
int n,m;
int timer = 0;
int count = 0;

void dfs(char c){


	for(int i=1;i<=n;i++){
		if(state[i]==initial && adj[v][i]==1){
			dfs(i);
		}
	}

	state[v] = visited;
	end[v] = ++timer;
}

int main(){
	int e,x,y;
//	cout<<"Enter number of edges and vertices: ";
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>adj[i][j];
		}
	}

	string s;
	cin>>s;
	int l = s.size();

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(adj[i][j]==s[0])
				dfs(adj[i][j]);
		}
	}


}