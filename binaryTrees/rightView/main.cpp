#include<bits/stdc++.h>
using namespace std;
#define COUNT 10 
struct node
{
    int val;
    node* left;
    node* right;
	node(int x):left(NULL), right(NULL), val(x) {}
};
typedef struct node* NODE;


void printPreorder( NODE node1)
{
    if (node1 == NULL)
        return;
    cout << node1->val << " ";
 
    printPreorder(node1->left);
 
    printPreorder(node1->right);
}


NODE buildTree()
{
	vector<int> v{1,2,3,4,5,0,0,0,0,0,6,0,7};
	int count = 0;
     queue<NODE> q;
	 NODE root = new node(v[0]);
     q.push(root);
     NODE cur = NULL;
     for(int i = 1; i < v.size(); i++){
		 if(v[i] != 0){
        NODE newnode = new node(v[i]);
        if(count == 0){
           cur = q.front();
		   q.pop();           
        }
        if(count==0){
          count++;
          cur->left = newnode;
        }else {
          count = 0;
          cur->right = newnode;
        }
        
          q.push(newnode);
        }
     } 
	  return root; 
}
vector<int> rightSideView(NODE root)
{
    if(root == NULL)
	return {};
    vector<int> v;
    queue<NODE> q;
    q.push(root);
    while(q.size()>0)
    {
        int length = q.size();
        int count = 0;
        while(count<length)
        {
            NODE curr = q.front();
            if(curr->left!=NULL)
            q.push(curr->left);
            if(curr->right!=NULL)
            q.push(curr->right);
            count++;
            q.pop();
            if(count==length)
            v.push_back(curr->val);
        }
    }
    return v;

}
void print2DUtil(NODE root, int space) 
{ 
    // Base case 
    if (root == NULL) 
        return; 
  
    // Increase distance between levels 
    space += COUNT; 
  
    // Process right child first 
    print2DUtil(root->right, space); 
  
    // Print current node after space 
    // count 
    cout<<endl; 
    for (int i = COUNT; i < space; i++) 
        cout<<" "; 
    cout<<root->val<<"\n"; 
  
    // Process left child 
    print2DUtil(root->left, space); 
}

void print2D(NODE root) 
{ 
    // Pass initial space count as 0 
    print2DUtil(root, 0); 
} 
int main()
{
    NODE root ;
	root = buildTree();
    vector<int> v = rightSideView(root);
    printPreorder(root);
    cout<<"____________"<<endl;
    for(int i =0;i<v.size();i++)
    cout<<v[i]<<",";

    print2D(root);
}