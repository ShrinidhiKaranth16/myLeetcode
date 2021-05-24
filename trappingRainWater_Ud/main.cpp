#include<bits/stdc++.h>
using namespace std;

int totolWater(vector<int> &height){
    int leftmax=0,rightmax= 0;
    int left = 0, right = height.size()-1;
    int totalWater = 0;
    while (left<right)
    {
        if(height[left] <= height[right]){
            if(height[left] >= leftmax){
                leftmax = height[left];
            }else{
                totalWater += leftmax - height[left]; 
            }
            left++;
        }else{
            if(height[right] >= rightmax){
               rightmax = height[right];
            }else{
                totalWater += rightmax - height[right];
            }
            right--;
        }
    }
    return totalWater;
}

int main()
{
  vector<int> height{0,1,0,2,1,0,1,3,2,1,2,1};
  int result = totolWater(height);
  cout<<result;
}