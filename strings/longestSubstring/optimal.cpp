#include<bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string s)
{
    if(s.size()<=1) return s.size();
    map<char,int> presentStrings;
    int longest =0,currentLength=  0;
    int l=0;
    int r=0;
    while(r<s.size())
    {
        map<char,int>:: iterator it = presentStrings.find(s.at(r));
        if(it!=presentStrings.end()){
            r = presentStrings[s.at(r)]+1;
            currentLength =0;
            presentStrings.clear();
         }else{
             presentStrings[s.at(r)] = r;
             r++;
             currentLength++;
             longest = max(longest,currentLength);
         }
    }
    return longest;
}
int main()
{
    string s = "aaaaa";
    int result = lengthOfLongestSubstring(s);
    cout<<result;
}