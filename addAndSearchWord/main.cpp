#include<bits/stdc++.h>
using namespace std;
class wordDictionary{
    public:
    vector<string> str; 
        wordDictionary()
        {
            vector<string> str; 
        }
        void addWord(string word)
        {
            str.push_back(word);
        }
        void showlist() 
        { 
            vector <string> :: iterator it; 
            for(it = str.begin(); it != str.end(); ++it) 
             cout << '\t' << *it; 
             cout << '\n'; 
        } 
        bool searchWord(string word)
        {
             int l = word.length();
            vector <string> :: iterator it; 
            for(it = str.begin(); it != str.end(); ++it) 
            {
                 int j=0,count=0,dot=0;
                string temp = *it;
                if(l==temp.length())
                {
                    while(j!=word.length())
                    {
                         if(word[j]== temp[j])
                        count++;
                        if( word[j]=='.')
                        dot++;
                        j++;
                    }
                   if(count+dot==l)
                    return true;
                    }
            }
        return false;
        }
};
int main()
{
    wordDictionary* wr = new wordDictionary() ;
    wr->addWord("bad");
    wr->addWord("dad");
    wr->addWord("mad");
     wr->addWord("a");
  //  wr.addWord("dad");
   // wr.addWord("mad");
    cout<<wr->searchWord("pad")<<endl;
    cout<<wr->searchWord("bad")<<endl; 
    cout<<wr->searchWord(".ad")<<endl; 
    cout<<wr->searchWord("b..")<<endl;
    cout<<wr->searchWord("..m")<<endl;
     cout<<wr->searchWord(".")<<endl;
return 0;
}