#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str = "a)b(c)d";
    stack<int> s;
    vector<int> ri;
    int i;
    for(i=0;i<str.size();i++)
    {
        char a = str.at(i);
        if(a=='(')
        s.push(i);
        else if(a==')'){
        if(s.empty())
        ri.push_back(i);
        else
        s.pop();
        }
    }
    while(!s.empty())
    {
        int top = s.top();
        s.pop();
       ri.push_back(top);
    }

    sort(ri.begin(),ri.end());

    string ans ="";
    int k =0;
    for(i=0;i<str.length();i++)
    {
        if(k<ri.size() && i == ri[k])k++;
        else
        ans += str.at(i);
    }
    cout<<ans<<endl;
}