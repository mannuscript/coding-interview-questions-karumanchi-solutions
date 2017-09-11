#include<iostream>
#include<vector>

using namespace std;

int find(int parent[], int index)
{
    if(parent[index] == -1)
        return index;
    return find(parent, parent[index]);
}

void Union(int parent[], int a, int b)
{
    //find the parent element of both sets (a and b)
    int 
        aParent = find(parent, a),
        bParent = find(parent, b);
    parent[aParent] = bParent;
}

int find(vector<int> parent, int index)
{
    if(parent[index] == -1)
        return index;
    return find(parent, parent[index]);
}

void Union(vector<int> parent, int a, int b)
{
    //find the parent element of both sets (a and b)
    int 
        aParent = find(parent, a),
        bParent = find(parent, b);
    parent[aParent] = bParent;
}