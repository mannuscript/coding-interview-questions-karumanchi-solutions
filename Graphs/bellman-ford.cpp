#include<iostream>
#include<queue>
#include"Graphs.h"

using namespace std;

void bellmanFord(Graph G, int source)
{
    queue<int> q;
    q.push(source);
    vector<int> distanceVector(G.V);

    for(int i=0; i < G.V; i++) {
        distanceVector[i] = INT_MAX;
    }
    distanceVector[source] = 0;

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(list<pair<int,int> >::iterator itr = G.adjList[node].begin(); 
            itr != G.adjList[node].end(); itr++) {
                int distance  = distanceVector[node] + (*itr).second;
                if(distance < distanceVector[(*itr).first]) {
                    
                }
        }
    }
}