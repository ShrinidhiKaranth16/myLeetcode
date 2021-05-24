#include<bits/stdc++.h>
using namespace std;

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
	vector<int> v{3,9,20,0,0,15,7};
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

vector<vector<int>> levelOrder(NODE root)
{
	if(root == NULL)
	return {};
	NODE currentNode = root;
	vector<vector<int>> v;
	queue<NODE> q;
	q.push(currentNode);
	while(q.size()>0)
	{
		int length = q.size();
		int count = 0;
		vector<int> v1;
		while(count<length)
		{
		currentNode = q.front();
		v1.push_back(currentNode->val);
		q.pop();
		if(currentNode->left!=NULL)
		q.push(currentNode->left);
		if(currentNode->right!=NULL)
		q.push(currentNode->right);
		count++;
		}
		v.push_back(v1);
	}
	return v;
}

int main()
{
	NODE root ;
	root = buildTree();
	vector<vector<int>>result = levelOrder(root);
	for(int i =0;i<result.size();i++)
	{
		for(int j =0;j<result[i].size();j++)
		cout<<result[i][j]<<",";
		cout<<endl;
	}
	printPreorder(root);
}