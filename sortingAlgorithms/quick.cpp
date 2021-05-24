#include<bits/stdc++.h>
using namespace std;

void toswap(int* p,int* q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

void print(vector<int> v)
{
for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<",";
    }
    cout<<endl;
}
int partition(vector<int> &v,int left,int right)
{
    int i =  left;
    for(int j=left;j<=right;j++)
    {
        if(v[j]<=v[right])
        {
            toswap(&v[i],&v[j]);
            i++;
        }
    }
    return i-1;
}

int  quickselect(vector<int> &v,int left,int right,int k)
{
        int pi = partition(v,left,right);
        if(pi==k)
        return v[pi];
        else if(k<pi)
        return quickselect(v,left,pi-1,k);
        else
        return quickselect(v,pi+1,right,k);
    
}


int main()
{
    vector<int> v{2,1};
    int indexTofind = v.size()-1;
    int r = quickselect(v,0,v.size()-1,indexTofind);
    cout<<r<<endl;
     print(v);
    
}