#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> directions {
        {-1,0},
        {0,1},
        {1,0},
        {0,-1}
    };
 
void dfs(vector<vector<int>> matrix,int row,int col,vector<vector<bool>>& seen,vector<int>& results)
{
    if(row< 0 || col< 0 ||row>=matrix.size() || col>=matrix[0].size() || seen[row][col])
    {return;}
    results.push_back(matrix[row][col]);
    seen[row][col] = true;
    for(int i = 0 ; i<directions.size();i++)
    {
        vector<int> constDir = directions[i];
       dfs(matrix,row+constDir[0],col+constDir[1],seen,results);
    }
}

int main()
{
    vector<vector<int>> matrix {
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15},
        {16,17,18,19,20},
    };
    vector<int> results;
    vector<vector<bool>> seen;
   
    for(int i =0;i<matrix.size();i++)
    {
        vector<bool> temp;
        for(int j =0;j<matrix[0].size();j++)
        {
           temp.push_back(false);
        }
        seen.push_back(temp);
    }
   dfs(matrix,0,0,seen,results);
   
   for(int i =0;i<results.size();i++)
    {
        cout<<results[i]<<",";
    }cout<<endl;
}