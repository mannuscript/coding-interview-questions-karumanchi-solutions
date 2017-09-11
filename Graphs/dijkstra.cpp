#include<iostream>
#include<queue>
#include"Graphs.h"
#include<functional>
#include<algorithm>

using namespace std;

/* O(E logV)  //LogV for min heap
 * Greedy approach
 * Dijkstra implementation for shortest path distance:
 * Uses a priority queue (min heap)
 * Create a distance vector having INT_MAX distance, this will represent the 
 * the distance of vertices from source.
 * Start with pushing source in the min heap and iterate till queue is non empty
 * pop from the top of the queue(sorted),
 * iterate over all children of this node and update the distance of these children
 * if required
 */
void dijkstra(Graph &G, int source=0)
{
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    vector<int> distanceVector(G.V, INT_MAX);

    pq.push(make_pair(0, source));
    distanceVector[source] = 0;

    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for(list<pair<int,int> >::iterator itr = G.adjList[u].begin(); 
            itr != G.adjList[u].end(); itr++) {

                int v = (*itr).first;

                int distance = distanceVector[u] + (*itr).second;
                if(distance < distanceVector[v]) {
                    distanceVector[v] = distance;
                    pq.push(make_pair(distance, v));
                }
        }
    }
    //print distanceVector
    copy(distanceVector.begin(), distanceVector.end(), ostream_iterator<int>(cout, " "));
}

int main(void)
{
    Graph G = getASampleGraph();//getASampleCompleteGraph();
    G.print();
    dijkstra(G, 0);
    return 0;
}