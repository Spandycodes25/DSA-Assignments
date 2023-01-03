//Singly Linked List

#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node * next;
};

class list
{
     node *head,*temp;
     public:
     void create();
     node* getnode();
     //node *newnode();
     void display();
     void Insert_at_Pos( node *newnode, int position);
     void append(node *newnode);
     void traversal();
     void reverse();
     void search();

 list()
    {
     head=NULL;
    }
};


// create function
void list:: create()
{
    node * newnode;
    char choice;
    while(1){
    cout<<"\nDo you want to create new node (Y/N) :";
    cin>>choice;
    if(choice=='N')
        break;


newnode = getnode();
append(newnode);
}
}

/*//append
void list :: append()
{
node *temp;
if(head==NULL){
    head=newnode;
    temp=newnode;
}

else{
    temp->next=newnode;
    temp=newnode;
}
}*/

//getnode functin
node* list::getnode()
{
    node * newnode;
    newnode = new node;
   
    cout<<"\nEnter data :";
    cin>>newnode->data;
    newnode->next=NULL;

 return (newnode);
}



//display function
void list::display()
{
//node * temp;
temp=head;
if(temp==NULL){
cout<<"The list is empty"<<endl;
}

else{
while(temp != NULL){
cout<<temp->data<<"->";
 temp=temp->next;
}
}
 }

//insertion
void list :: Insert_at_Pos(node *newnode, int position)
{
    node *temp = head;
    int count=1, flag=1;
    if(position==1)
    {
        newnode->next=temp;
        head = newnode;
    }
    else
    {
        while(count != position-1)
        {
            temp = temp->next;
            if(temp==NULL)
            {
                flag=0;
                break;
            }
            count++;
        }
        if(flag==1)
        {
            newnode->next = temp->next;
            temp->next = newnode;
        }
        else
        {
            cout<<"Position not found";
        }
    }
}

//append
void list :: append(node* newnode)
{
//node *temp=head;
if(head == NULL)
{
head = newnode;
temp=head;
}
else
{
temp->next = newnode;
temp = temp->next;
}
}

//traverse
void list :: traversal()
{
    node *temp = head;
    if(temp==NULL)
    {
        cout<<"List is empty";
    }
    else
    {
        while(temp!=NULL)
        {
            cout<<temp->data;
            temp=temp->next;
        }
    }
}

//reverse
void list :: reverse()
{
    node *prev=NULL;
    node *nextt=NULL;
    node *temp=head;
    while(temp!=NULL)
    {
        nextt==temp->next;
        temp->next=prev;
        prev=temp;
        temp=nextt;
    }
    head=prev;
}

//search
void list :: search()
{
    int val;
    cout<<"Enter the value to be searched:";
    cin>>val;
    node *temp=head;
    int flag=0;
    while(temp!=NULL)
    {
        if(temp->data==val)
        {
            cout<<"Value found:";
            flag=1;
            break;
        }
        temp=temp->next;
    }
    if(flag==0)
    {
        cout<<"Element not found:";
    }
}


int main()
{
int position,choice;
node *newnode;
list L1;
while(1)
{
    cout<<"CHOOSE WHAT YOU WANT TO PERFORM:\n1)create\n2)display\n3)get_node\n4)insert_at_position\n5)delete\n6)reverse\n7)search\n8)exit"<<endl;
    cin>>choice;
    switch(choice)
    {
       
        case 1:
        {
            L1.create();
   
            break;
        }
       case 2:
        {
            L1.display();
            break;
        }
        case 3:
        {
            newnode = L1.getnode();
            break;
        }
        case 4:
        {
            cout<<"enter new position";
            cin>>position;
            L1.Insert_at_Pos(newnode, position);
            //L1.display();
        break;
        }
        case 5:
        {
            L1.traversal();
            break;
        }
        case 6:
        {
           L1.reverse();
           break;
        }
        case 7:
        {
            L1.search();
            break;
        }
       // L1.display();
     
    }    
}
return 0;
}
