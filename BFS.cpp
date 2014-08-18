#include<stdio.h>
#include<vector>
#include<queue>
#define Size 11		// number of node / Vertex. Size = Node +1, Because arr start from 0

using namespace std;


int color[100],D[100], Father[50];			// Father is the predecessor

int print_path(int matrix[][Size], int s, int v);
void BFS(int source, int matrix[][Size]); //Don't forget 2D array Prototype


int main()
{
	//int matrix[Size][Size]={ 0,1,1,0, 1,0,0,1 ,1,0,0,0, 0,1,0,0};
	//{ 0,1,1,0, 1,0,0,1 ,1,0,0,0, 0,1,0,0};
	
	int loop,i,k,j,matrix[Size][Size]={0};

	printf(" Give num of edge :");
	scanf("%d",&loop);

	printf("\nGive the node num that connected\n");

	for(k=1;k<=loop;k++){
		scanf("%d%d",&i,&j);
		matrix[i][j]=1;
	//	matrix[j][i]=1;
	}

	int source,des;
		
	printf("\nGive Source & distance:");
	for(k=0;k<5;++k)
	{
		scanf("%d%d",&source,&des);
		BFS(source, matrix);
		printf("Distance %d\n",D[des]);

		printf("The path is : ");

		print_path(matrix, source, des);
		printf("\n");
	}

	

return 0;
}

void BFS(int source, int matrix[][Size])
{
	for(int i=0;i<Size;++i)
	{
		color[i]=0;
		D[i]=-1;
		Father[i]=-100;
	}

	D[source]=0;
	color[source]=1;
	queue<int>Q;
	Q.push(source);
	
	while(!Q.empty())
	{
		int pop;
		pop=Q.front();

		for(int i=0;i<Size;++i)
		{
			if(color[i]==0 && matrix[pop][i] ==1 )		// means conected node
			{
				color[i]=1;
				D[i]=D[pop]+1;
				Father[i]=pop;				// pop is the father of i
				Q.push(i);
			}
		}
		Q.pop();
	}
}

int print_path(int matrix[][Size], int s, int v)
{
	if(v==s)
	{
		printf("-> %d ",s);
		return 0;
	}
	else if(Father[v]== -100)
		printf("No path between %d to %d\n",s,v);
	else{
		print_path(matrix, s, Father[v]);			// recursion
		printf("-> %d ",v);
	}
return 0;
}
