#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int>> directions {
        {-1,0},
        {0,1},
        {1,0},
        {0,-1}
    };
void bfs(vector<vector<int>> matrix,int row,int col,vector<vector<bool>>& seen,vector<int>& results )
{
    queue<vector<int>> q;
    q.push({0,0});
    while(q.size()>0)
    {
        vector<int> currentPos = q.front();
        q.pop();
        int row = currentPos[0];
        int col = currentPos[1];
        if(row< 0 || col< 0 ||row>=matrix.size() || col>=matrix[0].size() || seen[row][col])
        continue;
        results.push_back(matrix[row][col]);
        seen[row][col] = true;
        for(int i = 0;i<directions.size();i++)
        {
            vector<int> currentDir = directions[i];
            q.push({row+currentDir[0],col+currentDir[1]});
        }
    }
    
}
int main()
{
    vector<vector<int>> matrix {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
     vector<vector<bool>> seen;
     vector<int> results;
    for(int i =0;i<matrix.size();i++)
    {
        vector<bool> temp;
        for(int j =0;j<matrix[0].size();j++)
        {
           temp.push_back(false);
        }
        seen.push_back(temp);
    }

    bfs(matrix,0,0,seen,results);
     for(int i =0;i<results.size();i++)
    {
        cout<<results[i]<<",";
    }cout<<endl;
}