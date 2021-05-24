#include<bits/stdc++.h>
using namespace std;

string removeSpaces(string str)  
{ 
    str.erase(remove(str.begin(), str.end(), ' '), str.end()); 
    transform(str.begin(),str.end(),str.begin(),::tolower);
    return str; 
} 
bool isPalindrome(string str) {
    str = removeSpaces(str);
    int l = 0;
    int r = str.size()-1;
    while(l<r)
    {
        if(isalnum(str.at(l)) && isalnum(str.at(r)))
        {
            if(str.at(l)!= str.at(r))
            return false;
            else{
                l++;
                r--;
            }
        }else
        {
            if(!isalnum(str.at(l)))
            l++;
            if(!isalnum(str.at(r)))
            r--;
        }
    }
    return true;
    }
int main()
{
   string str =  "race a car";
    str = removeSpaces(str);
    cout<<str;
    bool result = isPalindrome(str);
    cout<<result;
}