#include<iostream>
#include<queue>
#include"Graphs.h"
using namespace std;

/*
 * Returns a vector of shortest paths from a given source for an unweighted graph
 * Assumptions:
 * 1. No ioslated nodes
 * 2. No cycles
 */
vector<int> forUnweightedGraph(Graph G, int source)
{
    vector<int> shortestPaths(G.V);
    queue<int> q;
    int node;

    //Initialize the paths with -1
    for(int i=0; i < G.V; i++) {
        shortestPaths[i] = -1;
    }
    //Except the source
    shortestPaths[source] = 0;

    //Lets do a dfs now
    q.push(source);

    while(!q.empty()) {
        node = q.front();
        q.pop();
        for(list<pair<int, int> >::iterator itr = G.adjList[node].begin();
            itr != G.adjList[node].end(); itr++) {
                if(shortestPaths[(*itr).first] == -1) {
                    shortestPaths[(*itr).first] = shortestPaths[node] + 1;
                    q.push((*itr).first);
                }
        }
    }
    //We have the shortest paths by now, lets print
    cout<<endl<<"Shortest paths from source: "<<source<<" are as follows:"<<endl;
    for(int i=0; i<G.V; i++) {
        cout<<shortestPaths[i]<<" ";
    }
    return shortestPaths;
}

int main(void)
{
    Graph G = getASampleGraphTree();
    forUnweightedGraph(G, 0);
    return 0;
}