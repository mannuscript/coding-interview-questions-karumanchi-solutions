#include<iostream>
#include<queue>
#include"Graphs.h"
#include<functional>

using namespace std;

void dijkstra(Graph G, int source)
{
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int,int> > > pq;
    pq.push(make_pair(0, source));
    int *distanceVector = (int *)malloc(sizeof(int)*G.V);
    vector<int> visited(G.V);

    for(int i = 0; i < G.V; i++) {
        distanceVector[i] = INT_MAX;
    }

    distanceVector[source] = 0;
    int node;
    while(!pq.empty()) {
        node = pq.top().second;
        pq.pop();
        
        for(list<pair<int,int> >::iterator itr = G.adjList[node].begin(); 
                itr != G.adjList[node].end(); itr++) {
                    int distance = distanceVector[node] + (*itr).second;
                    if(distanceVector[(*itr).first] > distance) {
                        distanceVector[(*itr).first] = distance;
                        if(!visited[(*itr).first]) {
                            pq.push(make_pair(distance, (*itr).first));
                        }
                        visited[(*itr).first] = 1;
                    }
        }
    }
    cout<<"Distances: ";
    for(int i = 0; i < G.V; i++)
        cout<<distanceVector[i]<<" ";
    cout<<endl;
    return;
}

int main(void)
{
    Graph G = getASampleGraph();//getASampleCompleteGraph();
    dijkstra(G, 0);
    return 0;
}