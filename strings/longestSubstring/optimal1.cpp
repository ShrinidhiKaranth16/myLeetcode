#include<bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string s)
{
    if(s.size()<=1) return s.size();
    map<char,int> presentStrings;
    int longest =0;
    int l=0;
    for(int r = 0; r<s.size();r++)
    {
        char currentChar = s.at(r);
        map<char,int> :: iterator it = presentStrings.find(currentChar);
        if(it!=presentStrings.end() && it->second >=l)
        {
            l = it->second+1;
        }
         presentStrings[s.at(r)] = r;
         longest = max(longest,r-l+1);
    }
    return longest;
}
int main()
{
    string s = "abcbda";
    int result = lengthOfLongestSubstring(s);
    cout<<result;
}