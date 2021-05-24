#include<bits/stdc++.h>
using namespace std;

string final(string s)
{
    int i;
    string a;
    for(i =0 ;i<s.size();i++)
    {
        if(s.at(i)!='#'){
            a = a + s.at(i);
        }else{
            if(a.size()>0)
            a.resize(a.size()-1);
        }
    }
    return a;
}

 bool backspaceCompare(string s, string t) {
        string sFinal = final(s);
        string tFinal = final(t);

        if(sFinal == tFinal)
        cout<<"true";
        else
        cout<<"false";
    }
int main()
{
    string s = "a##z#";
    string t = "a#z#";
    bool result = backspaceCompare(s,t);
    
    
}