#include<iostream>
#include<vector>
using namespace std;

struct node
{
    int val;
    struct node  *prev;
    struct node  *next;
    struct node  *child;
};typedef struct node *NODE;

vector<int> v{1,2,3,4,5,6,NULL,NULL,NULL,7,8,9,10,NULL,NULL,11,12};
 int pos = 0;
 vector<NODE> h;
NODE createSublist(NODE head)
{
    head = NULL;
    NODE next = NULL;
    NODE prev = NULL;
    NODE child = NULL;
    while(pos<v.size() && v[pos]!=NULL)
    {
        cout<<"pos"<<pos<<endl;
        NODE newnode = new node;
        if(head == NULL)
        {
            cout<<"here 2"<<endl;
            newnode->val = v[pos];
            newnode->next = next;
            newnode->prev = prev;
            newnode->child = child;
            prev = newnode;
            head = newnode;
        }else{
        cout<<"here 1"<<endl;
        newnode->val = v[pos];
        newnode->prev = prev;
        newnode->next = next;
        prev->next = newnode;
        newnode->child = child;
        prev =  newnode;
        }
        pos++;
    }
    return head;
}

NODE createList(NODE head)
{
    head = createSublist(head);
    h.push_back(head);
    NODE first = head;
    cout<<"head "<<head->val<<endl;
    while(pos<v.size()){
    int n =0;
    while(v[pos]==NULL)
    {
        pos++;
        n++;
    }
    NODE temp = head;
    int p =0;
    while(p<n-1)
    {
        temp = temp->next;
        p++;
    }
    cout<<" before pos"<<pos<<endl;
    head =  createSublist(head);
    h.push_back(head);
     cout<<" after pos"<<pos<<endl;
    temp->child = head;
    cout<<" new head "<<head->val<<","<<endl;
    if(head->next==NULL)
    cout<<"adasf"<<endl;
    else
    cout<<"123"<<endl;
    }
    return first;
}
void display(NODE list)
{
    cout<<"display"<<endl;
    cout<<endl<<endl<<endl<<endl;
    NODE temp = list;
  while(temp!=NULL)
  {
      NODE next = temp->next;
      if(temp->child!=NULL)
      {
          NODE first  = temp->child;
          NODE temp1 = first;
          NODE prev;
          while(temp1!=NULL)
          {
              prev = temp1;
              temp1 = temp1->next;
          }
          NODE tail = prev; 
          first->prev = temp;
          temp->next = first;
          tail->next = next;
          tail->next->prev = tail
      }
      if(temp->next!=NULL)
      cout<<temp->val<<",";
      else
      cout<<temp->val;
      temp = temp->next;
  }
}
int main()
{
    cout<<v.size()<<endl;
    NODE head = new node;
    head =createList(head);
    display(head);
}