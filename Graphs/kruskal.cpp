#include<iostream>
#include"Graphs.h"
#include"../union-find.h"
#include<cstdlib>

using namespace std;

int compare(const void *a, const void *b)
{
    return *(int*)a > *(int*)b;
}

void kruskal(Graph G)
{
    int E = G.E, counter = 0;
    int edges[E][3];
    vector<pair<int,int> > MST(G.V-1);
    for(int i=0; i<G.V; i++) {
        for(list<pair<int,int> >::iterator itr = G.adjList[i].begin(); 
            itr != G.adjList[i].end(); itr++) {
                edges[counter][0] = (*itr).second;
                edges[counter][1] = i;
                edges[counter][2] = (*itr).first;
                counter++;
        }
    }
    
    qsort(edges, E, sizeof(*edges), compare);
    
    //Create a set for edges to do union and find shit
    int parent[G.V];
    memset(parent, -1, sizeof(int)*G.V);

    counter=0;
    int totalWeight = 0;
    for(int i = 0; i < E && counter <= G.V -1; i++) {
        int 
            weight = edges[i][0],
            from = edges[i][1],
            to = edges[i][2];

        if(find(parent, from) == find(parent, to)) {
            //this edge can cause a cycle skip this
            continue;
        }
        
        totalWeight += weight;
        MST[counter++] = make_pair(from,to);
        Union(parent, from, to);
    }

    //All done, print the MST
    for(int i=0; i < G.V-1; i++) {
        cout<<MST[i].first<<" -> "<<MST[i].second<<endl;
    }
}

int main(void)
{
    Graph G = getASampleGraph();
    kruskal(G);
    return 0;
}
