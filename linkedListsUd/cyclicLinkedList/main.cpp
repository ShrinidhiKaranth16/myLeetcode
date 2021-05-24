#include<iostream>
#include<vector>
using namespace std;
struct node
{
    int val;
    struct node * next;
}; typedef struct node *NODE;
vector<int> v{10,9,8,7,6,5,4,3,2,1};
NODE createList(NODE head)
{
    
    int middle = v.size()/2;
    cout<<"middle"<<middle<<","<<v[middle]<<endl;
    int i = 0;
    while (i<v.size())
    {
        NODE newnode = new node;
        newnode->val = v.at(i);
        newnode->next = head;
        head = newnode;
        i++;
    }
    NODE temp = head;
    NODE m ;
    while(temp->next!=NULL)
    {
        if(temp->val==v[middle])
         m = temp;
        temp = temp->next;
    }
    temp->next = m;
    return head;
}


void display(NODE list)
{
    NODE temp = list;
    int n =0;
    while(n<v.size())
    {
        cout<<temp->val<<",";
        temp = temp->next;
        n++;
    }
    cout<<endl;
}

NODE detectCycle(NODE head) {
    if(head->next==NULL){ 
    return NULL;
    }
    NODE tortoise = head;
    NODE hare = head;
    while(true)
    {
        tortoise = tortoise->next;
        hare = hare->next;
        if(hare ==NULL || hare->next==NULL)
        {
            return NULL;
        }
        hare = hare->next;
        if(tortoise==hare)
        break;
    }
    NODE p1 = head;
    NODE p2 = tortoise;
    while(p1!=p2)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p2;
    }

int main()
{ 
    NODE head = NULL;
    head = createList(head);
    display(head);
    NODE cycle = detectCycle(head);
    cout<<cycle->val<<endl;
}