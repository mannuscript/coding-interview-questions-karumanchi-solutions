#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;

class Graph {
public:
    int V;
    vector<int> vertexWeights;
    vector<list<pair<int,int> > > adjList;
    Graph(int);
    void DFS(int);
    void BFS(int);
    void addEdge(int, int, int);
    void setVertexWeight(int, int);
    void print(void);
};

Graph::Graph(int V) 
{
    this->V = V;
    this->adjList.resize(V);
    this->vertexWeights.resize(V);
}
void Graph::addEdge(int from, int to, int weight=1)
{
    this->adjList[from].push_back(make_pair(to, weight));
}
void Graph::setVertexWeight(int node, int weight) 
{
    this->vertexWeights[node] = weight;
}
void Graph::print(void)
{
    for(int i = 0; i < this->adjList.size(); i++) {

        cout<<i<<"("<<this->vertexWeights[i]<<") : ";

        for(list<pair<int, int> >::iterator itr = adjList[i].begin();
            itr != this->adjList[i].end();
            itr++) {
            cout<<(*itr).first<<"("<<(*itr).second<<")"<<" ";
        }
        cout<<endl;
    }
}

Graph getASampleGraphTree()
{
    Graph G(13);
    G.addEdge(0,1);
    G.addEdge(0,2);
    G.addEdge(0,3);
    G.addEdge(1,4);
    G.addEdge(2,5);
    G.addEdge(3,6);
    G.addEdge(3,7);
    G.addEdge(7,8);
    G.addEdge(7,9);
    G.addEdge(7,10);
    G.addEdge(10,11);
    G.addEdge(11,12);
    //G.print();
    return G;
}

Graph getASampleGraph()
{
    /*Graph G(13);
    G.addEdge(0,1);
    G.addEdge(0,2);
    G.addEdge(0,3);
    G.addEdge(1,0);
    G.addEdge(2,0);
    G.addEdge(3,0);

    G.addEdge(1,4);
    G.addEdge(4,1);
    
    G.addEdge(2,5);
    G.addEdge(5,2);

    G.addEdge(3,6);
    G.addEdge(3,7);
    G.addEdge(6,3);
    G.addEdge(7,7);


    G.addEdge(7,8);
    G.addEdge(7,9);
    G.addEdge(7,10);
    G.addEdge(8,7);
    G.addEdge(9,7);
    G.addEdge(10,7);

    G.addEdge(10,11);
    G.addEdge(11,10);

    G.addEdge(11,12);
    G.addEdge(12,11);*/

    Graph G(8);
    G.addEdge(0,1);
    G.addEdge(0,5);

    G.addEdge(1,0);
    G.addEdge(1,5);
    
    G.addEdge(2,3);

    G.addEdge(3,2);
    G.addEdge(3,5);
    G.addEdge(3,6);

    G.addEdge(4,5);
    G.addEdge(4,7);

    G.addEdge(5,0);
    G.addEdge(5,1);
    G.addEdge(5,3);
    G.addEdge(5,4);
    
    G.addEdge(6,3);
    G.addEdge(6,7);

    G.addEdge(7,6);
    G.addEdge(7,4);
    int weights[] = {1,2,3,4,5,6,7,8};
    for(int i = 0; i < G.V ; i++)
        G.setVertexWeight(i, weights[i]);

    G.print();
    return G;
}

void Graph::DFS(int node=0)
{
    static int *visited = (int *)calloc(this->V, sizeof(int));
    
    cout<<node<<" ";
    visited[node] = true;

    //Iterate over all child
    for(list<pair<int,int> >::iterator itr = this->adjList[node].begin(); 
            itr != this->adjList[node].end(); itr++) {
        
        if(!visited[(*itr).first])
            this->DFS((*itr).first);

    }
}

void Graph::BFS(int root=0)
{
    queue<int> q;
    q.push(root);
    int node;
    int *visited = (int *)calloc(this->V, sizeof(int));

    while(!q.empty()) {
        node = q.front();
        q.pop();
        cout<<node<<" ";
        visited[node] = true;
        //push every element in the queue
        for(list<pair<int,int> >::iterator itr = this->adjList[node].begin();
            itr != this->adjList[node].end(); itr++) {
                if(!visited[(*itr).first])
                    q.push((*itr).first);
            }
    }

}