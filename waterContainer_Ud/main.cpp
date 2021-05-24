#include<bits/stdc++.h>
using namespace std;

int maxArea(vector<int> & height )
{
    int p1 = 0;
    int p2 = height.size()-1;
    int maxarea = 0;
    
    while(p1<p2)
    {
        int minHeight = min(height[p1],height[p2]);
        int width = p2 - p1;
        int area = minHeight * width;
        maxarea = max(area,maxarea);
        
        if(height[p1]<=height[p2])
    {
        p1++;
    }else{
        p2--;
    }
    }
    return maxarea;
}
int main()
{
    vector<int> height {6,9,3,4,5,8};
    int result = maxArea(height);
    cout<<result;
}