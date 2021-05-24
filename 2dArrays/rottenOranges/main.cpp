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
int orangesRotting(vector<vector<int>>& grid) {
    if(grid.size()==0) return 10;
    queue<vector<int>> q;
    int fresh = 0;
    int minutes =0;
       for(int i = 0 ;i<grid.size();i++)
       {
           for(int j =0 ;j<grid[0].size();j++)
           {
               if(grid[i][j]==2)
               q.push({i,j});
               if(grid[i][j]==1)
               fresh++;
           }
       }
       cout<<fresh<<endl;
       int currentQueueSize = q.size();
           while(q.size()>0)
           {
               if(currentQueueSize==0)
               {
                   minutes++;
                   currentQueueSize = q.size();
               }
                   vector<int> currentPos = q.front();
                   q.pop();
                   currentQueueSize--;
                   int row = currentPos[0];
                   int col = currentPos[1];
                   for(int i = 0; i < directions.size(); i++) {
                        vector<int> currentDir = directions[i];
                        int nextRow = row + currentDir[0];
                        int nextCol = col + currentDir[1];
                        if(nextRow < 0 || nextRow >= grid.size() || nextCol < 0 || nextCol >= grid[0].size())
                         continue;
                         if (grid[nextRow][nextCol] == 1) {
                        grid[nextRow][nextCol] = 2;
                        fresh--;
                        q.push({nextRow, nextCol});
                        }
                   }
           }
           if(fresh==0)
           return minutes;
           else
           return -1;
}


int main()
{
    vector<vector<int>> grid{
        {1},
    };
    int results = orangesRotting(grid);
    cout<<results;
}