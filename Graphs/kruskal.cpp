#include<iostream>
#include"Graphs.h"
#include"../union-find.h"
#include<cstdlib>

using namespace std;

int compare(const void *a, const void *b)
{
    return *(int*)a > *(int*)b;
}

/*
 * Kruskal's Minimum spanning tree implementation.
 * It uses union and find to detect cycles
 * Algo:
 *  * Create the list of edges, having u,v and weight
 *  * Sort the list by weights ()
 */
void kruskal(Graph &G)
{
    //edges[i][0] -> weight, edges[i][1] -> from, edges[i][2] -> to
    int 
        edges[G.E][3],
        counter = 0;


    vector<int> 
        weights(G.V, INT_MAX),
        parent(G.V, -1);
    
    //Get all the edges
    for(int i=0; i< G.V; i++) {
        for(list<pair<int,int> >::iterator itr = G.adjList[i].begin();
            itr != G.adjList[i].end(); i++) {
                edges[counter][0] = (*itr).second;
                edges[counter][2] = i;
                edges[counter][2] = (*itr).first;
                counter++;
        }
    }

    //TODO: sort the edges
    qsort(edges, G.E, sizeof(*edges), compare);

    for(int i=0; i < G.E; i++) {
        int 
            u = edges[i][1],
            v = edges[i][2],
            edgeWeight = edges[i][0];
        
        //Check if they already are in the same set, i.e. forming a cycle
        if(find(parent, u) == find(parent, v))
            continue;
        
        Union(parent, u, v);
    }

}

int main(void)
{
    Graph G = getASampleGraph();
    kruskal(G);
    return 0;
}
