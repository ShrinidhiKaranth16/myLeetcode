#include<iostream>
#include<vector>
using namespace std;

struct node{
    int info;
    struct node *next;
};
typedef struct node *NODE;

NODE createList()
{
    NODE list ;
    NODE first = NULL;
    vector<int> l{1,2,3,4,5};
    for(int i =0 ;i<5;i++)
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
NODE reversePrint(NODE list)
{
    NODE currenNode = list;
    NODE prev = NULL;
    while(currenNode!=NULL)
    {
        NODE next = currenNode->next;
        currenNode->next = prev;
        prev = currenNode;
        currenNode = next;
    }
    return prev;
}
int main()
{
    NODE head;
    head = createList();
    display(head);
    head = reversePrint(head);
    display(head);
}