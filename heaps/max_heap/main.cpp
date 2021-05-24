#include<bits/stdc++.h>
using namespace std;
#define COUNT 10
struct node
{
    int val;
    node* left;
    node* right;
    node(int x) : left(NULL),right(NULL),val(x){}
};
typedef node* NODE;
void print2DUtil(NODE root, int space) 
{ 
    if (root == NULL) 
        return; 

    space += COUNT; 

    print2DUtil(root->right, space); 
  
    cout<<endl; 
    for (int i = COUNT; i < space; i++) 
        cout<<" "; 
    cout<<root->val<<"\n"; 
  
    print2DUtil(root->left, space); 
}

void print2D(NODE root) 
{ 
    // Pass initial space count as 0 
    print2DUtil(root, 0); 
} 
NODE buildHeap(NODE root,int k,int value)
{
    NODE newnode = new node(value);
    if(root == NULL){
    root = newnode;
    return root;
    }
    queue<NODE>q;
    q.push(root);
    NODE curr;
    bool f = false;
    while(q.size()>0 && !f)
    {
        NODE temp= q.front();
        q.pop();
        if(temp->left==NULL || temp->right==NULL){
        curr = temp;
        !f;
        }
        else
        {
            q.push(temp->left);
            q.push(temp->right);
        }
    }
    if(curr->left==NULL)
    curr->left = newnode;
    else 
    curr->right = newnode;
    return root;
}
vector<int> maxHeap(vector<int> v,int value,int index)
{
    if(v.size()==0)
    {
        v.push_back(value);
        return v;
    }
    else{
        int parent = floor((index-1)/2);
        if(v[parent]<v[index]){
        while(parent!=v[0])
        {
             if(v[parent]<v[index]){
                int t = v[parent];
                v[parent] = value;
                v[index]= t;
                index = parent;
                parent = floor((index-1)/2);
             }
        }
        }else
        {
            v.push_back(value);
        }
    }
}
int main()
{
    NODE root = NULL;
    vector<int> v{50,45,25,40,30,10,15};
    vector<int> r;
    for(int i =0 ;i<v.size();i++)
    {
        r = maxHeap(v,v[i],i);
    }
    for(int i =0;i<v.size();i++)
    {
        int k;
        if(i==0) k=0;
        else
        k =  floor((i-1)/2);
        root = buildHeap(root,k,v[i]);
    }
    print2D(root);
}