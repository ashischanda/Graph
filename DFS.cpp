#include<stdio.h>
#define Size 100		// number of node / Vertex. Size = Node +1, Because arr start from 0

int color[Size], time=0;
int D[Size], F[Size], N;

void dfs_visit(int u, int mat[][Size])
{
	int i;
	color[u]=1;
	time++;
	D[u]=time;

	for(i=0;i< N;i++){
		if(color[i]==0 && mat[u][i]==1 )		// adj test
			dfs_visit(i,mat);
	}

	F[ u ]= ++time;
}

void dfs(int mat[][Size])
{
	int i;

	for(i=0;i< N;i++)
		color[i]=0;
		
	time=0;
	for(i=0;i< N;i++)
		if(color[i]==0){
			dfs_visit(i, mat);
		}

}


int main()
{
	int loop,i,k,j,matrix[Size][Size]={0};

	printf("Give node & edges number:");
	scanf("%d%d",&N, &loop);
	
	for(k=1;k<=loop;k++){
		scanf("%d%d",&i,&j);
		matrix[i][j]=1;
	}
	dfs(matrix);
			
	for(k=0;k<N;++k)
		printf("node is %d,  dis %d and finishing time %d\n", k, D[k], F[k]);

	return 0;
}
