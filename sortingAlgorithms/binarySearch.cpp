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

int main()
{
    vector<int> v{1,2,3,3,3,3,4,5,6,7,8,9,10};
    int r = binarySearch(v,0,v.size()-1,3);
    cout<<r<<endl;
}