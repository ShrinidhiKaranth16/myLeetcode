#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> v,int left,int right,int k)
{
    while(left<=right)
    {
        int mid =  (left + right)/2;
        if(k==v[mid])
       return mid;
        else if(k>v[mid])
        left = mid +1;
        else
        right = mid-1;
    }
    return -1;
}

vector<int> searchRange(vector<int> v, int target) {
        if(v.size()==0) 
        return {-1,-1};
        int firstPos = binarySearch(v,0,v.size()-1,target);
        if(firstPos==-1)
        return {-1,-1};
        int startPos = firstPos;
        int endPos =  firstPos;
        int temp1,temp2;
        while(startPos!=-1)
        {
            temp1 = startPos;
            startPos = binarySearch(v,0,startPos-1,target);
        }
        startPos = temp1;
         while(endPos!=-1)
        {
            temp1 = endPos;
            endPos = binarySearch(v,endPos+1,v.size()-1,target);
        }
       endPos = temp1;
       return{startPos,endPos};
    }
int main()
{
    vector<int> v{1,2,3,3,3,3,4,5,6,7,8,9,10};
    int left = 0;
    int right = v.size()-1;
    vector<int> r = searchRange(v,3);
    cout<<r[0]<<","<<r[1]<<endl;
}