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
int numIslands(vector<vector<char>>& grid) {
    if(grid.size()==0) return 0;
        int count=0;
        for(int i =0;i<grid.size();i++)
        {
            for(int j =0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    count++;
                    queue<vector<int>> q;
                    q.push({i,j});
                    while(q.size()>0)
                {
                    vector<int> currentPos = q.front();
                    q.pop();
                    int row = currentPos[0];
                    int col = currentPos[1];
                   
                    if(row< 0 || col< 0 ||row>=grid.size() || col>=grid[0].size() || grid[row][col]=='0')
                    continue;
                     grid[row][col] = '0';
                    q.push({row-1,col});
                    q.push({row,col+1});
                    q.push({row+1,col});
                    q.push({row,col-1});
                }
                }
            }
        }
        return count;
}
int main()
{
   vector<vector<char>> grid{
       {'1','1','0','0','1'},
       {'1','1','0','1','0'},
       {'0','0','1','0','0'},
       {'0','0','0','1','1'},
   };
    int result = numIslands(grid);
    cout<<result;
}