#include<bits/stdc++.h> 
using namespace std;
bool detectCapitalUse(string str) {
if(str[0]>=65 && str[0]<=90)
     {
         int j =1,k=1,c=1;
         while(j<str.length()){
            
             if(str[j]<65 || str[j] >90)
             {
                    k++;
             }
             if(str[j]>=65 && str[j]<=90)
                 {
                    c++;
                 }
              j++;
           
         }
         if(k==1 && c== str.length())
            {  
             return true;
            }
         else if(k==str.length()&& c==1)
         {
            return true;
         }
         else
         {
             return false;
         }
     }
    int i;
     if(str[0]<65 || str[0] >90)
     {
            for( i=1;i<str.length();i++)
        {
             if (str[i]< 65 || str[i]>90)   
            continue;
            else
          return false;
            
        }
    return true;
     }
     
}
int main(){
    string str;
    getline(cin,str);
    bool c= detectCapitalUse(str);
    if(c)
    cout<<"True";
    else 
    cout<<"False";
    
    return 0;
}