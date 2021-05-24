#include<bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string s) {
    if(s.size()<=1) return s.size();
        int longestString =0;
        for(int i =0 ;i<s.size();i++)
        {
            vector<string> seenCahrs{};
            int currentLength =0;
            for(int j=i;j<s.size();j++){
                string currentChar{s.at(j)};
                auto it = find(seenCahrs.begin(),seenCahrs.end(),currentChar);
                if(it!=seenCahrs.end())
                        break;
                else{
                    currentLength++;
                    seenCahrs.push_back(currentChar);
                    longestString = max(currentLength,longestString);
                }
            }
        }
        return longestString;
    }
int main()
{
    string s = "abcbda";
    int result = lengthOfLongestSubstring(s);
    cout<<result;
}