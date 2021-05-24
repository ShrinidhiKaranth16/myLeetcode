#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
       for(int j=0;j<nums.size();j++)
       {
        int temp = nums[j];
        int count=0;
      for(int i=j;i<nums.size();i++)
      {
          if(nums[i] == temp)
          count++;
      }
      if(count==2)
      result.push_back(temp);
       }
       vector<int> result1;
        for(int k=result.size()-1;k>=0;k--)
        {
           result1.push_back(result[k]);
        }
    return result1;
    }
};
int main()
{
 Solution s;
 vector <int> v{4,3,2,7,8,2,3,1};
 vector<int> result;
 result = s.findDuplicates(v);
 for(int x:result)
 cout<<x<<endl;
 return 0;
}