#include<iostream>
#include<vector>
using namespace std;
struct node
{
    int info;
    struct node *next;
};typedef struct node *NODE;

NODE createList()
{
    NODE list ;
    NODE first = NULL;
    vector<int> l{5,3};
    for(int i =0 ;i<l.size();i++)
    {
        NODE newnode= new node;
        newnode->info= l.at(i);
        newnode->next = first;
        first = newnode;
        list = first;
    }
    return list;
}

void display(NODE list)
{
    NODE temp = list;
    while(temp!=NULL)
    {
        cout<<temp->info<<",";
        temp = temp->next;
    }
    cout<<endl;
}
NODE reverseBetween(NODE head, int m, int n) {
   if(m==n) return head;
    int currentPosition = 1;
    NODE currentNode = head;
    NODE start = head;
    while(currentPosition<m)
    {
        start = currentNode;
        currentNode = currentNode->next;
        currentPosition++;
    }
    NODE newList = NULL;
    NODE tail = currentNode;
    while(currentPosition>=m && currentPosition<=n)
    {
        NODE next = currentNode->next;
        currentNode->next = newList;
        newList = currentNode;
        currentNode = next;
        currentPosition++;
    }
   
        tail->next = currentNode;
        if(m>1)
        start->next = newList;
    if(m>1)
    return head;
    else
    return newList;

}

int main()
{
    NODE head = new node;
    head = createList();
    display(head);
    int m = 1;
    int n= 2;
    cout<<"display of "<<endl;
    head = reverseBetween(head,m,n);
     display(head);
}