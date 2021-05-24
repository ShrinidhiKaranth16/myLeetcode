#include<bits/stdc++.h>
using namespace std;
#define COUNT 10
struct node
{
    int val;
    node* left;
    node* right;
};
typedef struct node* NODE;

NODE createNode(int val)
{
    NODE root = new node;
    root->val = val;
    root->left = NULL;
    root->right = NULL;
    return root;
}

void print(queue<NODE>q)
{
   while (!q.empty()){
		cout<<" "<<q.front();
		q.pop();
	}
	cout<<endl;
  
}
NODE createTree()
{
    cout<<"starteed"<<endl;
     vector<int>v{1,2,3,0,0,4,0,0,5};
    NODE root = NULL;
    NODE curr = NULL;
    int index = 0;
    queue<NODE> q ;
    for(int i=0;i<v.size();i++)
    {
        if(root == NULL)
        {
            root = createNode(v[i]);
            index = 1;
            q.push(root);
            curr = q.front();
        }else{
            if(v[i]==0){
                if(index==1)
                index = 2;
                else{
                    q.pop();
                    curr = q.front();
                    index = 1;
                }
            }else if(index==1){
                NODE newnode = createNode(v[i]);
                curr->left = newnode;
                q.push(curr->left);
                index= 2;
            }else if(index==2){
                NODE newnode= createNode(v[i]);
                curr->right = newnode;
                q.pop();
                curr = q.front();
                index=  1;
            }
        }
       
       print(q);
    }
    return root;
}


int maxDepth(NODE n, int currentDepth) {
    if (!n) {
      return currentDepth;
    }
    
    currentDepth++;
    
    return max(maxDepth(n->right, currentDepth), maxDepth(n->left, currentDepth));
}
int main()
{
   
    int i;
    NODE root  = new node;
    root = createTree();
    int r = maxDepth(root,0);
    cout<<r<<endl;
}