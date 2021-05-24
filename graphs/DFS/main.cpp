#include<bits/stdc++.h>
using namespace std;
void DFS(int vertex ,vector<vector<int>> graph,vector<int>& results, vector<bool>& seen)
{
    results.push_back(vertex);
    seen[vertex] = true;
    vector<int> connections = graph[vertex];
    for(int i = 0;i<connections.size();i++)
    {
        if(connections[i]>0 && !seen[i] )
        DFS(i,graph,results,seen);
    }
}
int main()
{
    vector<vector<int>> graph{
        {0, 1, 0, 1, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0},
    };
    vector<bool> seen(graph.size(),false);
    vector<int> results;
   DFS(0,graph,results,seen);

    for(int i =0 ; i<results.size();i++)
    cout<<results[i]<<",";
}