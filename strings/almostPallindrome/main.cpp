#include<bits/stdc++.h>
using namespace std;

string removeSpaces(string str)  
{ 
    str.erase(remove(str.begin(), str.end(), ' '), str.end()); 
    transform(str.begin(),str.end(),str.begin(),::tolower);
    return str; 
} 
bool isPalindrome(string str) {
    if(str.size()==2 || str.size()==1) return true;
    str = removeSpaces(str);
    int l = 0;
    int r = str.size()-1;
    int count=0;
    while(l<r)
    {
        if(isalnum(str.at(l)) && isalnum(str.at(r)))
        {
            if(str.at(l)!= str.at(r))
            {
                
                if(str.at(l+1)==str.at(r) && str.at(l+2) == str.at(r-1))
                l++;
                else if(str.at(r-1)==str.at(l) && str.at(r-2)== str.at(l+1))
                r--;
                else{
                    if(count<1 && (r-l)==1)
                    return true;
                }
                    count++;
                if(count>1)
                return false;
           }
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
   string str =  "yd";
    str = removeSpaces(str);
    bool result = isPalindrome(str);
    cout<<result;
}