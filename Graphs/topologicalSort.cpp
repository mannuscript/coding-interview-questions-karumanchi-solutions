#include<iostream>
#include"Graphs.h"
#include<queue>
#include<vector>
using namespace std;

//Assumption: graph do not have cycles
void printTopologicalSort(Graph G)
{
    queue<int> q;
    vector<int> inDegree(G.V);
    vector<int> topologicalSort(G.V);
    int topologicalIndex = 0;

    //Initialize the in degree array
    for(int i=0; i < G.V; i++) {
        for(list<pair<int,int> >::iterator itr = G.adjList[i].begin(); 
            itr != G.adjList[i].end(); itr++) {
                inDegree[(*itr).first]++;
            }
    }
    cout<<"\n\n\n";
    for(int i = 0; i < G.V; i++) {
        cout<<inDegree[i]<<" ";
    }
    cout<<"\n\n\n";

    for(int i=0; i < G.V; i++) {
        if(inDegree[i] == 0)
            q.push(i);
    }

    int node;
    while(!q.empty()) {
        node = q.front();
        q.pop();
        cout<<node<<endl;
        topologicalSort[topologicalIndex++] = node;
        //decrement the degree of all adjcent element to node
        for(list<pair<int,int> >::iterator itr = G.adjList[node].begin(); 
            itr != G.adjList[node].end(); itr++) {
                if(!--inDegree[(*itr).first]) {
                    q.push(((*itr).first));
                }
        }
    }

    if(topologicalIndex < G.V) {
        cout<<"ERROR: Cycle found in the given graph";
    //    return;
    } 
    cout<<"Topological sort of given tree is: ";
    for(int i = 0; i < G.V; i++) {
        cout<<topologicalSort[i]<<" ";
    }
    cout<<endl;
    
}

int main(void) 
{
    Graph G = getASampleGraphTree();
    G.print();
    printTopologicalSort(G);
    return 0;
}