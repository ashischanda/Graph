//  Find Bipartite property in Graph
//  uva 10004

#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define MAX 1001

int n, e;
int visited[MAX];
int part[MAX];
vector< int > G[MAX];

bool is_bipartite()
{
    int i, u, v, start=0;
    queue< int > Q;

	for(i=0; i<n; i++){
		part[i]=0;
		visited[i]=0;
	}

    start = 1; // nodes labeled from 1
    Q.push(start);
    part[ start]=1;
    visited[start] = 1; // set gray

    while(!Q.empty())
    {
        u = Q.front(); Q.pop();
        for(i=0; i < G[u].size(); i++)
        {
            v = G[u][i];
            if(part[u] == part[v])		// mind It, we don't check color here
				return false;
            if(visited[v] == 0)			// and it is start with if not else
            {
                visited[v] = 1;
                part[v] = 3 - part[u]; // alter 1 and 2
                Q.push(v);
            }
        }
    }
    return true;
}

int main()
{
    int i, u, v;
	puts("give node & edge");
    scanf("%d %d", &n, &e);

    for(i=0; i<e; i++)
    {
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }

    if(is_bipartite()) printf("Bipartite\n");
    else printf("Non-Bipartite\n");

return 0;
}
/*

5
5
0 1
1 2
2 3
3 4
4 0
Non-Bipartite

4
4
0 1
1 2
2 3
3 0
*/
