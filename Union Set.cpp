//       10608	Friends
//  Union Set:   Find the largest member of a group in Network

// Like: 11503	Virtual Friends
// Like: 10685  Nature
// Like:   793

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#include<iostream>
#include<string>
#include<map>

using namespace std;
#define Size 30009

int par[Size];     // parent of Friend/node
int ans[Size];
bool new_tree;

int findParent(int p)
{
    if( par[p]==p)
        return p;
    else
        findParent(par[p]);
}

int unionFriend(int a, int b)
{
    int x= findParent(a);
    int y= findParent(b);

    if(x !=y )
            ans[x]+= ans[y];
     if(x !=y )
            par[y]= x;      // parent of a
                            //printf(" a b %d %d xy %d %d   %d\n",a,b, x,y, ans[y]);
    ans[y]=ans[x];          // look it, union part

    return ans[y];
}
int main()
{
	int N, pairs, i,j, k;


    while( scanf("%d",&N)!=EOF){
        scanf("%d",&pairs);
        int a,b;
        int max=-1;
        map<int, int> m;
        int n=0;                       // number of given unique friends name

        /// initial case
        for(i=1; i<= N; i++){
            par[i]= i;              // every fri/node is fri of his own
            ans[i]= 1;              // num of friend 1
        }

        for(i=0; i< pairs; i++){
            scanf("%d%d",&a, &b);

            if( m[a] ==0 )
                m[a]= ++n;
            if( m[b] ==0 )
                m[b]= ++n;

                j= unionFriend(m[a], m[b]);     // friend n is given

                if(max<j)
                    max=j;

        }
        printf("%d\n",max);
    }

return 0;
}


/**
input:
-----------------------

9
7
1 2
2 3
5 6
5 7
3 4
9 8
6 2

9
9
1 2
2 3
5 6
5 7
3 4
9 8
6 2
6 5
8 9

10
12
1 2
3 1
3 4
5 4
3 5
4 6
5 2
2 1
7 10
1 2
9 10
8 9

output:

7
7
6

*/
