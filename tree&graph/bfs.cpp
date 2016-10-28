#include <iostream>
using namespace std;

#define MAX 100
#define initial 1
#define waiting 2
#define visited 3

int adj[MAX][MAX];
int que[MAX];
int state[MAX];
int depth[MAX];
int parent[MAX];

int rear=-1,front=-1,n;

void insert(int value){
	if(rear==MAX){
		cout<<"OverFlow";
		return;
	}
	else{
		if(front==-1){
			front=0;
		}
		que[++rear]=value;
	}
}

int del(){
	if(front==-1 || front>rear ){
		cout<<"UnderFlow";
		return 0;
	}
	else
		return que[front++];
}

int isEmpty(){
	if(front==-1 || front>rear)
		return 1;
	else
		return 0;
}

void bfs(int v){
//	cout<<"hello";
	state[v]=waiting;
	depth[v]=0;
	parent[v]=-1;
	insert(v);

	while(!isEmpty()){
//		cout<<"hello";
		v=del();
		cout<<"Vertex: "<<v<<" Parent: "<<parent[v]<<" depth: "<<depth[v]<<"\n";
		state[v]=visited;
		for(int i=1;i<=n;i++){
//			cout<<"hi\n";
			if(adj[v][i]==1 && state[i]==initial){
				state[i]=visited;
				depth[i] = depth[v]+1;
				parent[i] = v;
				insert(i);
			}
		}
	}

}

int main(){
	int e,x,y,s;
	cout<<"Enter edges & vertex: ";
	cin>>e>>n;
	cout<<"Enter connected vertices: ";
	for(int i=1;i<=n;i++){
		state[i]=initial;
	}
	for(int i=1;i<=e;i++){
		cin>>x>>y;
		adj[x][y]=1;
		adj[y][x]=1;
	}

	cout<<"Enter the Source vertex S : ";
	cin>>s;

	bfs(s);
}