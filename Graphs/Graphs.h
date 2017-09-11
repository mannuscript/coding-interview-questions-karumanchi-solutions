#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;

class Graph {
    public:
        int V;
        int E;
        vector<int> vertexWeights;
        vector<list<pair<int,int> > > adjList;
        vector<vector<int> > adjMatrix;
        Graph(int V) 
        {
            this->V = V;
            this->E = 0;
            this->adjList.resize(V);
            //Define a 2D matrix
            this->adjMatrix.resize(V);
            for(int i=0; i < V; i++) {
                this->adjMatrix[i].resize(V);
            }
            this->vertexWeights.resize(V);
        }
        Graph(){}
    private:
        void DFS_HELPER(int *visited, int node=0) 
        {
            
            cout<<node<<" ";
            visited[node] = true;

            //Iterate over all child
            for(list<pair<int,int> >::iterator itr = this->adjList[node].begin(); 
                    itr != this->adjList[node].end(); itr++) {
                
                if(!visited[(*itr).first])
                    this->DFS_HELPER(visited, (*itr).first);

            }
        }
    public:
        void DFS(int node=0)
        {
            static int *visited = (int *)calloc(this->V, sizeof(int));
            //This iteration is to cover unconnected components
            for(int i = 0; i < this->V; i++)
                if(!visited[i])
                    DFS_HELPER(visited, node);
        }
    private:
        // BFS cum cycle detector, parse all the element and returns
        // true: cycle detected, false: no cycle detected
        int BFS_HELPER(int root, int *visited)
        {
            queue<int> q;
            q.push(root);
            int 
                node,
                isCyclic = false;

            while(!q.empty()) {
                node = q.front();
                q.pop();
                cout<<node<<" ";
                visited[node] = true;
                //push every element in the queue
                for(list<pair<int,int> >::iterator itr = this->adjList[node].begin();
                    itr != this->adjList[node].end(); itr++) {
                        if(visited[(*itr).first])
                            isCyclic = true;
                        else
                            q.push((*itr).first);
                    }
            }
            return isCyclic;
        }
    public:
        int BFS(int root=0)
        {
            int 
                *visited = (int *)calloc(this->V, sizeof(int)),
                flag = false;

            for(int i=0; i < this->V; i++) 
                if(!visited[i]) {
                    flag = BFS_HELPER(root, visited);
                    if(flag) return flag;
                }
            return false;
        }
        
        void addEdge(int from, int to, int weight=1)
        {
            this->adjList[from].push_back(make_pair(to, weight));
            this->E++;
            this->adjMatrix[from][to] = weight;
        }
        
        void setVertexWeight(int node, int weight) 
        {
            this->vertexWeights[node] = weight;
        }
        
        void print(void)
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
        void print2(void)
        {
            for(int i = 0; i < this->adjList.size(); i++) {

                for(list<pair<int, int> >::iterator itr = adjList[i].begin();
                    itr != this->adjList[i].end();
                    itr++) {
                    cout<<i<<" "<<(*itr).first<<" "<<(*itr).second;
                    cout<<endl;
                }
            }
        }
        void printMatrix(void)
        {
            for(int i=0; i < this->V; i++) {
                for(int j= 0; j < this->V; j++) {
                    cout<<this->adjMatrix[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<endl<<endl;
        }
        
        bool isATree(int root=0)
        {
            return !this->BFS(root);
        }
        
        bool isCompleteGraph(void)
        {
            int counter;
            for(int i=0; i < this->V; i++) {
                counter = this->V-1;
                for(list<pair<int, int> >::iterator itr = this->adjList[i].begin();
                    itr != this->adjList[i].end();
                    itr++
                ) {
                    counter--;
                }
                if(counter)
                    return false;
            }
            return true;
        }
};
Graph inputTaker(int nodes, int edges)
{
    int weight,from,to;
    Graph G(nodes);
    //for(int j=0; j < nodes; j++) {
    //    cin>>weight;
    //    G.setVertexWeight(j, weight);
    //}
    for(int j=0; j < edges; j++) {
        cin>>from>>to>>weight;
        G.addEdge(from, to, weight);
        G.addEdge(to, from, weight);
    }
    return G;
}

int findMWVCForCompleteGraph(Graph G, int root=0)
{
    /*
     * For a complete graph we know that MVC would have G.V - 1 nodes
     * Hence to find the MVC calculate the sum of weights and 
     * subtract the weight of node with maximum weight from the sum.
     */

    int sum = 0;
    int max = -9999;
    for(int i = 0; i < G.V; i++) {

        sum += G.vertexWeights[i];
        if(max < G.vertexWeights[i])
            max = G.vertexWeights[i];
    
    }
    return (sum - max);
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
    for(int i = 0; i < G.V ; i++)
        G.setVertexWeight(i, i);
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
    G.addEdge(0,1,5);
    G.addEdge(0,5);

    G.addEdge(1,0,5);
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
    

    /*Graph G(7);
    G.addEdge(0,1);
    G.addEdge(1,0);
    G.addEdge(1,2);
    G.addEdge(1,3);
    G.addEdge(2,1);
    G.addEdge(2,4);
    G.addEdge(2,5);
    G.addEdge(3,1);
    G.addEdge(3,6);
    G.addEdge(4,2);
    G.addEdge(5,2);
    G.addEdge(5,6);
    G.addEdge(6,3);
    G.addEdge(6,5);
*/
    //G.print();
    return G;
}

Graph getASampleCompleteGraph()
{
    Graph G(4);
    G.addEdge(0,1);
    G.addEdge(0,2);
    G.addEdge(0,3);
    
    G.addEdge(1,0);
    G.addEdge(1,2);
    G.addEdge(1,3);
    
    G.addEdge(2,0);
    G.addEdge(2,1);
    G.addEdge(2,3);

    G.addEdge(3,0);
    G.addEdge(3,1);
    G.addEdge(3,2);

    int weights[] = {1,2,3,0};
    for(int i = 0; i < G.V ; i++)
        G.setVertexWeight(i, weights[i]);

    return G;
}

Graph getASampleFullyConnectedGraph(int nodes)
{
    Graph G(nodes);
    //counter for weights of the graph
    int counter = 1;

    //O(N^2)
    for(int i=0;i < nodes; i++) {
        for(int j=0; j < nodes; j++) {
            if(i==j)
                continue;
            G.addEdge(i, j, counter++);
        }
    }
    return G;
}