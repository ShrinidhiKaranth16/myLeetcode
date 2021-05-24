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
    vector<int> l{5,4,3,2,1};
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

NODE reverseBetween(NODE head, int m, int n) {
    if(m==n) return head;
    NODE leftNodes = head;
    NODE prev;
    while(leftNodes->info!=m)
    {
         prev = leftNodes;
        leftNodes = leftNodes->next;
    }
    leftNodes = prev;
    NODE rightNodes = leftNodes->next->next;
    NODE nextNode;
    while(rightNodes->info!=n){
        nextNode = rightNodes->next;
        rightNodes = rightNodes->next;
    }
    rightNodes = nextNode->next;

    cout<<"left:"<<leftNodes->info<<endl;
    cout<<"right:"<<rightNodes->info<<endl;
    NODE  currentNOde = leftNodes->next;
    NODE first;
    NODE tail;
    while(currentNOde->info !=5)
    {
        cout<<"current node: "<<currentNOde->info<<","<<currentNOde->next->info<<endl;
        NODE nextnode= currentNOde->next;
         cout<<"next node: "<<nextnode->info<<endl;
        if(currentNOde->info==m)
        {
           currentNOde->next = rightNodes;
        }
        if(currentNOde->info == n)
        {
            leftNodes->next = currentNOde; 
            return   head;
        }
       nextnode->next = currentNOde;
        cout<<" next node info: "<<nextnode->next->info<<endl;
        currentNOde = nextnode;
    }
    }

int main()
{
    NODE head = new node;
    head = createList();
    display(head);
    int m = 2;
    int n= 4;
    head = reverseBetween(head,m,n);
     display(head);
}