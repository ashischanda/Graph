#include<iostream>
#include<stdio.h>
#include<vector>
#define M 50
#define Inf 999999
using namespace std;

int  N, E;
int par[M], d[M];

typedef struct da{
	int x;
	int y;
	int w;
}Data;


void path(int s, int v)
{
	if( s==v)
		printf("%d ",s);
	else if ( par[v]== -1){
		printf("No path\n");
		return ;
	}
	else{
		path( s, par[v]);
		printf("%d ",v);
	}
}
int main()
{
	int i,j;
	Data data[M];				// we need only N size
	
	puts("Give node & edge  Num");
	scanf("%d%d",&N , & E);
	
	puts(" (node - node)  -> weight");
	for( i=0; i<E ;i++){
		scanf("%d%d%d",&data[i].x, &data[i].y ,&data[i].w);
	}
	
	for( i=0; i< N; i++)
	{
		d[i]= Inf;
		par[i]= -1;
	}
	
	d[0]= 0;		//   Let source =0
	bool fl= true;
	//*************************				Bellman
	
	for(i=1 ;i <= ( N-1) ;i++)				//  one less than N
	{
		for( j=0; j<E ;j++){				//  Relax
			if( d[ data[j].y ]> ( d[ data[j].x ]+ data[j].w )  ){
				d[ data[j].y ]=  d[ data[j].x ]+ data[j].w ;
				par[ data[j].y ]= data[j].x ;
				
			}
		}//end of relax
		
	}
	for( j=0; j<E ;j++)
		if(  d[ data[j].y ]> ( d[ data[j].x ]+ data[j].w )  ){
			fl= false;
			break;
	}
	
	
	int s=0;				//   Let source =0
	if( fl== false)
		printf("No  Path\n");
	else{
		puts("weight of each eage from zero");
		for( j=1; j< N ; j++){
			printf("node %d  weight -> %d\n\t", j, d[j]);
			path( s, j);
			printf("\n");		
		}
	}
	
	
	
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
  
cormen page 589
5
10
0 1 6
0 3 7
1 3 8
1 2 5
1 4 -4
2 1 -2
3 2 -3
3 4 9
4 0 2
4 2 7

*/
