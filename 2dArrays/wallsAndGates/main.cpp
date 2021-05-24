#include<bits/stdc++.h>
using namespace std;
int a = numeric_limits<int>::max();
vector<vector<int>> directions {
        {-1,0},
        {0,1},
        {1,0},
        {0,-1}
    };

//dfs
void wallsAndGates(vector<vector<int>>& grid,int row,int col,int step)
{
    if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || step > grid[row][col]) 
    return;
    grid[row][col] = step;
    for(int i = 0;i<directions.size();i++)
    {
        vector<int> currentDir = directions[i];
        wallsAndGates(grid,row+currentDir[0],col+currentDir[1],step+1);
    }
}
//bfs
void wg(vector<vector<int>>& grid,int row,int col,int step)
{
    queue<vector<int>> q ;
    q.push({row,col});
    int currentQueueSize = q.size();
    while (q.size()>0)
    {
        if(currentQueueSize==0)
        {
        step++;
        currentQueueSize = q.size();
        }
       vector<int> currentPos = q.front();
       q.pop();
       currentQueueSize--;
       int row = currentPos[0];
       int col = currentPos[1];

       if(grid[row][col]>step)
       grid[row][col] = step;

       for(int i = 0; i < directions.size(); i++) {
           vector<int> currentDir = directions[i];
            int nextRow = row + currentDir[0];
            int nextCol = col + currentDir[1];
            if(nextRow < 0 || nextRow >= grid.size() || nextCol < 0 || nextCol >= grid[0].size() || grid[nextRow][nextCol]==-1||grid[nextRow][nextCol]==0 ||grid[nextRow][nextCol]<step)
            continue;
            q.push({nextRow, nextCol});
       }
    }
    
}
int main()
{
    
    vector<vector<int>> grid
    {
        {a,-1,0,a},
        {a,a,a,-1},
        {a,-1,a,-1},
        {0,-1,a,a},
    };
    for(int i=0;i<grid.size();i++)
    {
        for(int j=0;j<grid[0].size();j++)
        {
            if(grid[i][j]==0)
            wg(grid,i,j,0);
        }
    }
    for(int i =0;i<grid.size();i++)
    {
        for(int j=0;j<grid[0].size();j++)
        {
            cout<<grid[i][j]<<",";
        }
        cout<<endl;
    }
     for(int i=0;i<grid.size();i++)
    {
        for(int j=0;j<grid[0].size();j++)
        {
            if(grid[i][j]==0)
            wallsAndGates(grid,i,j,0);
        }
    }
    cout<<endl<<"************"<<endl;
     for(int i =0;i<grid.size();i++)
    {
        for(int j=0;j<grid[0].size();j++)
        {
            cout<<grid[i][j]<<",";
        }
        cout<<endl;
    }
}