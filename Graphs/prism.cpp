#include<iostream>
#include"Graphs.h"
#include<queue>

using namespace std;

void prism(Graph G, int source=0)
{
    vector<int> covered(G.V);
    vector<int> distanceVector(G.V);
    vector<int> parent(G.V);

    for(int i=0; i< G.V; i++) {
        distanceVector[i] = INT_MAX;
    }
    distanceVector[source] = 0;
    parent[source] = source;

    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;

    pq.push(make_pair(0,source));

    while(!pq.empty()) {
        int node = pq.top().second;
        pq.pop();

        //This check is essential as we are pushing some nodes multiple times.
        //However only the first occurrence is important as we are using min heap 
        if(covered[node])
            continue;


        covered[node] = 1;
        for(list<pair<int,int> >::iterator itr = G.adjList[node].begin(); 
            itr != G.adjList[node].end(); itr++) {
                if(covered[(*itr).first])
                    continue;
                int distance = distanceVector[node] + (*itr).second;
                if(distance < distanceVector[(*itr).first]) {
                    distanceVector[(*itr).first] = distance;
                    parent[(*itr).first] = node;
                }
                pq.push(make_pair(distanceVector[(*itr).first], (*itr).first));
        }
    }

    queue<int> q;
    q.push(source);
    while(!q.empty()) {
        int par = q.front();
        q.pop();
        cout<<par<<"->>>>> ";
        for(int i=0; i< G.V; i++) {
            if(parent[i] == par && i != par) {
                cout<<i<<" ";
                q.push(i);
            }
        }
        cout<<endl;
    }
}

int main(void)
{
    Graph G = getASampleGraph();
    prism(G);
    return 0;
}