// ***** For Undirected Graph
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#define inf 99999999
using namespace std;

typedef struct {
	int x;
	int y;
	int w;
	int con;
}data;

data d[100];
int parent[100] , node,edg,  Total_cost;


bool compare(data &a, data &b)
{
	return a.w < b.w;
}


void kruskal();

int main()
{
	int i, w;
	scanf("%d%d",&node,&edg);

	for(i=0; i<node; i++)		//  ***********  initial Part
		parent[i]=i;


	for( i=0;i<edg;++i)
	{
		int x,y;
		scanf("%d%d%d",&x,&y , &w);
		d[i].x=x;		d[i].y=y;		d[i].w=w;
		d[i].con=0;					// means connected
	}

	kruskal();


return 0;
}



int findset(int x, int *parent)
{
	    if(x != parent[x])
			parent[x] = findset(parent[x], parent);

		return parent[x];
}


void kruskal()
{
	int i, pu, pv;		// here, pu pv is parent of u, v
	sort( d, d+edg, compare );

	for( i=Total_cost= 0;i<edg ;++i){
		pu= findset( d[i].x , parent );		//parent is array Call by reference
		pv= findset( d[i].y , parent );

		if(pu != pv){
	            d[i].con= 1;				// add to tree
	            Total_cost += d[i].w;		// add edge cost
	            parent[pu] = parent[pv];	// link
	        }
	}


	//**************************** Print
	for(i=0; i<edg;i++)
		if( d[i].con!=0 )
			printf(" %d %d ->  %d\n",d[i].x, d[i].y, d[i].w);


		printf("Minimum Cost %d\n", Total_cost);

}
/*
input files form Cormen book, page 569

9
13
0 1 4
1 2 8
2 3 7
1 7 11
0 7 8
2 5 4
2 8 2
8 6 6
8 7 7
6 5 2
3 5 14
3 4 9
4 5 10

It's have two types of solution : One solution in 569, another in 571
this code shows Output:

 2 8 ->  2
 6 5 ->  2
 0 1 ->  4
 2 5 ->  4
 2 3 ->  7
 8 7 ->  7
 1 2 ->  8
 3 4 ->  9
Minimum Cost 43

*/
