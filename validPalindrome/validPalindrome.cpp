#include<bits/stdc++.h> 
using namespace std;
string removeSpaces(string str)  
{ 
    str.erase(remove(str.begin(), str.end(), ' '), str.end()); 
    return str; 
} 
int main()
{
    string str = "A man, a plan, a canal: Panama";
    str = removeSpaces(str); 
    cout<<"string"<<str<<endl;
    for(int i=0;i<str.length();i++)
    {
       // cout<<str;
        if(!isalnum(str[i]))
        {
        str.erase(i,1);
        i--;
        continue;
        }
        if(islower(str[i]))
        str[i] = str[i] -32;
    }
     
    int l = 0; 
    int h =str.length() - 1; 
    while (h > l) 
    { 
        if (str[l++] != str[h--]) 
        { 
            cout<<"false";
            return 0; 
        } 
    } 
   cout<<"true";
   return 1;
}