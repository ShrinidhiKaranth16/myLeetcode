#include<iostream>
#include<vector>
using namespace std;

vector<int> bubbleSort(vector<int> v)
{
    int i;
    for(i = 0;i<v.size()-1;i++)
    {
        int j;
        for(j=0;j<v.size()-i-1;j++)
        {
            if(v[j]>v[j+1])
            {
                int temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
    }
    return v;
}

int main()
{
    vector<int> v{2,5,6,3,1,4,9,10,7,8};
    v = bubbleSort(v);
    int i;
     for( i =0;i<v.size();i++)
    {
        cout<<v[i]<<",";
    }
}