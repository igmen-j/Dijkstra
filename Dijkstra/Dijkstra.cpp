/*
Justin Igmen
200364880  
CS340

Credits: Lecture notes and 
https://www.tutorialspoint.com/cplusplus-program-for-dijkstra-s-shortest-path-algorithm#:~:text=The%20algorithm%20creates%20a%20tree,minimum%20distance%20from%20the%20source.https://www.tutorialspoint.com/cplusplus-program-for-dijkstra-s-shortest-path-algorithm#:~:text=The%20algorithm%20creates%20a%20tree,minimum%20distance%20from%20the%20source.
graph: https://www.youtube.com/watch?v=pVfj6mxhdMw
*/


#include<iostream>
#include<stdio.h>
using namespace std;

#define INFINITY 9999
#define max 10

void dijkstra(int G[max][max], int n, int startnode);

int main() {

    cout << "******************************************" << endl;
    cout << "*                                        *" << endl;
    cout << "*           Dijkstra's Algorithm         *" << endl;
    cout << "*                                        *" << endl;
    cout << "******************************************" << endl;

    int n;
    int startNode = 0;
    int graph[max][max];
    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter connections for node " << i << ": ";
        for (int j = 0; j < n; j++) 
        {
            cin >> graph[i][j];
        }
    }
    
    dijkstra(graph, n, startNode);

    return 0;
}
void dijkstra(int G[max][max], int n, int startnode) {
    int cost[max][max], distance[max], pred[max];
    int visited[max], count, mindistance, nextnode, i, j;

    //Set cost of node to infinity if there is no connection between nodes
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (G[i][j] == 0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = G[i][j];
        }
    }

    //Get the initial distance of all the nodes from start node -- from before: infinity if there is no direct connection
    for (i = 0; i < n; i++) {
        distance[i] = cost[startnode][i];
        pred[i] = startnode;
        visited[i] = 0;
    }

    distance[startnode] = 0;    //distance from start node to itself is zero
    visited[startnode] = 1;     //mark it as visited
    count = 1;

    //Main algorithm
    while (count < n - 1) {
        mindistance = INFINITY;

        for (i = 0; i < n; i++)
        {
            //if node is not visited and has lower distance, set it as the new minimum distance between nodes
            if (distance[i] < mindistance && !visited[i]) {
                mindistance = distance[i];
                nextnode = i;
            }
        }

        visited[nextnode] = 1;  // mark the node as visited

        for (i = 0; i < n; i++)
        {
            //if node is not yet visited, and the pathway is shorter, set it as the new pathway and move to next node
            if (!visited[i])
            {
                if (mindistance + cost[nextnode][i] < distance[i]) {
                    distance[i] = mindistance + cost[nextnode][i];
                    pred[i] = nextnode;
                }
            }
        }
        count++;
    }

    //Output
    for (i = 0; i < n; i++)
    {
        if (i != startnode) {
            cout << "Node 0 to node " << i << endl;
            cout << "Distance = " << distance[i] << endl;
            cout << "Path = " << i;
            j = i;
            do {
                j = pred[j];
                cout << " <- " << j;
            } while (j != startnode);
        }
        cout << endl << endl;
    }

    system("PAUSE");
}