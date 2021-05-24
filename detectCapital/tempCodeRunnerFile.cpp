#include<bits/stdc++.h> 
using namespace std;

int main(){
    string str;
    getline(cin,str);
    if(str[0]>=65 && str[0]<=90)
    {
        int i=1;
        while(i<str.length())
        {
            i++;
            if(str[i]<=65 && str[i]>=90)
            break;
          cout<<"true";
        }
    }
    return 0;
}