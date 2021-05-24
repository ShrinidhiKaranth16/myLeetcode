#include<bits/stdc++.h>
using namespace std;
void bfs(vector<int>& results,vector<vector<int>>connections ){
    queue<int> q;
    q.push(0);
    int s = connections.size();
    vector<bool> seen(s,false);
   
    while(q.size()>0)
    {
        int currentVertex = q.front();
        q.pop();
        results.push_back(currentVertex);
         seen[currentVertex] = true;
        for(int i = 0 ;i<connections[currentVertex].size();i++)
        {
            int num = connections[currentVertex][i];
            if(!seen[num])
            q.push(num);
        }
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

 vector<vector<int>> vertexConnections;
    for(int i = 0;i<graph.size();i++)
    {
        vector<int> temp{};
        for(int j =0; j<graph[0].size();j++)
        {
            if(graph[i][j]==1)
            temp.push_back(j);
        }
        vertexConnections.push_back(temp);
    }

    for(int i = 0;i<vertexConnections.size();i++)
    {
        cout<<i<<"->";
        for(int j =0; j<vertexConnections[i].size();j++)
        cout<<vertexConnections[i][j]<<" ";
        cout<<endl;
    }

    //BFS
    vector<int> results;
   // bfs(results,vertexConnections);

   // for(int i =0 ; i<results.size();i++)
   // cout<<results[i]<<",";
}