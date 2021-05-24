#include<bits/stdc++.h> 
using namespace std;
class solution{
    public:
            bool isPowerOfFour(int num)
            {
                int a;
                if(num==1)
                return true;
                while(num>4)
                {
                    a = num%4;
                    if(a!=0){
                        cout<<"false";
                        return false;
                    }
                    num = num/4;
                }
                cout<<num;
                if(num==4)
                {
                    cout<<"True";
                    return true;
                }
               else
                {
                    cout<<"false";
                   return false;
                }
              
            }
};
int main()
{
    solution s;
    s.isPowerOfFour(64*64);
}