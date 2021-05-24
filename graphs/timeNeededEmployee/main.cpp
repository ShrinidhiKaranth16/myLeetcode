#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> adjMatrix1;
int DFS(int head,vector<int> time,vector<vector<int>> adjMatrix)
{
    if(adjMatrix[head].size()== 0) return 0;
    int maximum = 0;
    vector<int> subordinate = adjMatrix[head];
    for(int i = 0;i<adjMatrix[head].size();i++)
    maximum = max(maximum, DFS(subordinate[i],time,adjMatrix));
    return (maximum + time[head]);
}

int findAdjMatrix1(int head, vector<int> managers,vector<vector<int>>& adjMatrix1,vector<int> informTime)
{
    for(int i = 0 ;i<managers.size();i++)
    {
        if(managers[i]== -1) continue;
        adjMatrix1[managers[i]].push_back(i);
    }
   int r = DFS(head,informTime,adjMatrix1);
   return r;
}


int main()
{
    int n = 8;
    int headId  = 4;
    vector<int> managers{2,2,4,6,-1,4,4,5};
    vector<int>informTime{0,0,4,0,7,3,6,0};
    adjMatrix1.resize(n);
     int r = findAdjMatrix1(headId,managers,adjMatrix1,informTime);
    cout<<r<<endl;
}