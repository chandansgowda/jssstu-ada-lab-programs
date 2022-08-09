#include <stdio.h>

int graph[40][40], n, visited[40]={0}, acyclic =1;

void createGraph(){
	printf("No. of vertices>> ");
	scanf("%d", &n);
	printf("Enter adjacency matrix:\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&graph[i][j]);
		}
	}
}

void dfs(int v){
	visited[v]=1;
	
	for(int i=0;i<n;i++){
		if (graph[v][i] && !visited[i]){
			printf("%d-->",v);
			dfs(i);
		}
		
		if (graph[v][i] && visited[i]){
			acyclic=0;
		}
	}
}

void main(){
	int i,count=0;
	
	createGraph();
	
	dfs(0);
	
	for(i=0;i<n;i++){
		if (visited[i])
			count++;
	}
	
	(count==n) ? printf("\nConnected Graph\n") : printf("\nGraph not connected!\n");
	(acyclic) ? printf("Acyclic Graph\n") : printf("Graph not acyclic!\n");
	
	//Printing connected components
	
	if (count!=n){
		for(i=0;i<n;i++) visited[i]=0;
	
		for(i=0;i<n;i++){
			dfs(i);
			printf("\n");
		}
	}
}
