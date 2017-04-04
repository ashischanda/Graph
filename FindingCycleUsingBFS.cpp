#include <stdio.h>
#include <queue>
using namespace std;

/// BFS for finding cycle in undirected graph

int nodes, edges, src;
int graph[100][100], color[100], prev[100];
const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;
void print(int);

int main() {
    printf("Nodes, edges, source? ");
    scanf("%d %d %d ", &nodes, &edges, &src);
    for(int i = 1; i <= edges; i++) {
        printf("Edge %d: ", i);
        int x, y;
        scanf("%d %d", &x, &y);
        graph[x][y] = 1;
    }

    //run BFS
    queue<int> q; 	 //create a queue
    q.push(src); 	 //1. put root node on the queue
    do{
        int u = q.front();  //2. pull a node from the beginning of the queue
        q.pop();
        //printf("%d ", u);  //print the node
        for(int i = 1; i <= nodes; i++) {  //4. get all the adjacent nodes
			 if((graph[u][i] == 1)  && (color[i] == GRAY)){
				 printf("cycle %d - %d\n", u, i);
				 print (u);
				 break;
			 }
                
            if((graph[u][i] == 1)  //if an edge exists between these two nodes,
                && (color[i] == WHITE)) {  //and this adjacent node is still WHITE,
                q.push(i);  		//4. push this node into the queue
                color[i] = GRAY;  	//color this adjacent node with GRAY
                prev[i] = u;
            }
        }
        color[u] = BLACK;  //color the current node black to mark it as dequeued
    } while(!q.empty());  //5. if the queue is empty, then all the nodes havebeen visited

    //find and print cycle from source
    for(int i = 1; i <= nodes; i++) {
        if(graph[i][src] == 1) {
            print(i);
            printf("  \n %d %d\n\n",i, src);
        }
    }

    return 0;
}

void print(int node) {
    if(node == 0)
        return;
    print(prev[node]);
    printf("%d -> ", node);
}
