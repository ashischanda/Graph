/*  here we use 3d array to take weighted edge.  m[M][M][2]

		m[M][M][0] = weight
		m[M][M][1] = 1           means connect

You also can do it in 2d array.   Initaially all 0 . m[M][M] ={0}   menas not connected
		now m[M][M]= weight
		if m[M][M] is > 0 that means connect 	


  */
#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#define M 15
#define Inf 999999
using namespace std;

int  N, E;
int par[M];

typedef struct da{
	int node;
	int time;
	bool operator<(const da& b) const{
		return time< b.time ;			//		This is the important line 
	}
}Data;
Data data[M];				// we need only N size

void dijkstra(int mat[][M][2])
{
	int i, u, v,j,  s=0 ;
	
	// ********  Initial
	for( i=0; i< N ;i++){	// clear all node
		data[i].node= i;
		data[i].time= Inf;
		par[i]= -1;
		
	}
	data[s].time= 0;				//   think 0 as Source
	
	priority_queue< Data > q;
	q.push( data[s] );
	Data ob;

	while( !q.empty() ){
			ob= q.top();
			q.pop();
			u= ob.node;

			for ( i=0; i< N ;i++)
			{
				if( mat[u][i][1]==1)		//   Adj
				{		
					for( v=0; v<N; v++){
						if( data[v].node== i)		// getting v with i
							break;
					}
					// *****   Relax
					
					if( data[v].time > ( ob.time + mat[u][i][0]) )	{		// weight( u,v) = mat[u][i][0]
						data[v].time= ob.time + mat[u][i][0];
						par[ data[v].node ]= ob.node;
						q.push( data[v] );

					}

				}//  end of adj if

			}
	}// end of while
}

int main()
{
	int i,j,k, l;
	puts("Give node & edge  Num");
	scanf("%d%d",&N , & E);
	
	int mat[M][M][2]={0};
	puts(" (node - node)  -> weight");
	for( i=0; i<E ;i++){
		scanf("%d%d%d",&j, &k ,&l);
		mat[j][k][0]= l ;				// weight
		mat[j][k][1]= 1 ;				//   connected	
	}

	dijkstra(mat);

	for( i=0; i< N; i++)
		printf(" weight of %d node to zero is -> %d\n", i, data[i].time);
	
	return 0;
}

/*
cormen page 596
5
10
0 1 10
0 3 5
1 3 2
1 2 1
2 4 4
3 1 3
3 2 9
3 4 2
4 0 7
4 2 6
*/
