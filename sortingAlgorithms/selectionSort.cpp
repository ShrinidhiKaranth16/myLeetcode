#include<iostream>
#include<vector>
 using namespace std;

vector<int> selectionSort(vector<int> v)
{
    int i;
    for(i=0;i<v.size()-1;i++){
    int min = i;
    int j;
    for(j = i+1;j<v.size();j++)
    {
        if(v[j]<v[min])
        min = j;
    }
    if(v[i]!=v[min]){
        int temp = v[i];
        v[i] = v[min];
        v[min] = temp;
    }
    }
    return v;
}

int main()
{
     vector<int> v{2,5,6,3,1,4,9,10,7,8};
     v = selectionSort(v);
     int i;
     for( i =0;i<v.size();i++)
    {
        cout<<v[i]<<",";
    }
}