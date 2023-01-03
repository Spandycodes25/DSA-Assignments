//Doubly Linked List

#include<iostream>
using namespace std;

class DNode
{
    public:
        int data;
        DNode *prev, *next;
    DNode()
    {
        prev = next = NULL;
    }
};

class List
{
    private:
        DNode *head, *temp;
    public:
        void create();
        void display();
        DNode *GetNode();
        void append(DNode *NewNode);
        void Insert_at_pos(DNode *NewNode, int pos);
        void startdelete();
        void enddelete();
        void deleten();
        void search();
       // int countelement();
        List()
        {
            head = NULL;
        }
};
//int flag = 0;
void List :: create()
{
    DNode *NewNode;
    char choice;
    while(1)
    {
        cout<<"Do yo want to continue(Y/N)";
        cin>>choice;
        if(choice == 'N')
            break;
        NewNode = GetNode();
        append(NewNode);
       // flag++;
    }
}

DNode *List :: GetNode()
{
    DNode *NewNode;
    NewNode = new DNode;
    cout<<"Enter Data";
    cin>>NewNode->data;
    NewNode->next = NULL;
    NewNode->prev = NULL;
    return(NewNode);
}

void List :: append(DNode *NewNode)
{
    //DNode *temp;
    if(head == NULL)
    {
        head = NewNode;
        temp = head;
    }
    else
    {
        NewNode->prev = temp;
        temp->next = NewNode;
        temp = NewNode;
    }
}

void List :: display()
{
    //DNode *temp;
    temp = head;
    if(temp == NULL)
    {
        cout<<"The list is empty"<<endl;
    }
    else
    {
        while(temp!=NULL)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
    }
}

void List :: Insert_at_pos(DNode *NewNode, int pos)
{
    DNode *temp = head;
    int count =1;
    if(head == NULL)
        head = NewNode;
    else if(pos ==1)
    {
        NewNode->next = head;
        head->prev = NewNode;
        head = NewNode;
        NewNode->prev = NULL;
    }
    else
    {
        while(count != pos)
        {
            temp = temp->next;
            if(temp!=NULL)
                count++;
            else
                break;
        }
    if(count == pos)
    {
        (temp->prev)->next=NewNode;
        NewNode->prev = temp->prev;
        NewNode->next = temp;
        temp->prev = NewNode;
    }
    else
        cout<<"Position not found";
    }
}

void List::startdelete()
{
    DNode *temp=head;
    head=head->next;
    head->prev=NULL;
    delete temp;
}

void List::enddelete()
{
    DNode *temp=head;
    while((temp->next)->next!=NULL)
    {
        temp=temp->next;
    }
    delete temp->next;
    temp->next=NULL;
}

void List::deleten()
{
    int index;
    cout<<"ENTER INDEX: ";
    cin>>index;
    DNode *temp=head;

    if(index==0)
    {
        DNode *temp=head;
        head=head->next;
        head->prev=NULL;
        delete temp;
    }
   /* if(index == flag-1)
    {
        DNode *temp=head;
    while((temp->next)->next!=NULL)
    {
        temp=temp->next;
    }
    delete temp->next;
    temp->next=NULL;
    }*/

    int i=0;
    while(i<index-1)
    {
        temp=temp->next;
        i++;
    }
    DNode *n=(temp->next)->next;
    delete temp->next;
    temp->next=n;
    n->prev=temp;
}

void List :: search()
{
    int element, count = 0;
    cout<<"Enter element to be searched:";
    cin>>element;
   
    DNode *temp = head;
    while(temp!=NULL)
    {
        if(temp->data == element)
        {
            cout<<"Element found at position:"<<count+1<<endl;
            break;
        }
        temp = temp->next;
        count++;
    }
    if(count == 0)
    {
        cout<<"Element not found";
    }
}

int main()
{
   /* int pos;
    DNode *NewNode;
    List L1;
    L1.create();
    L1.display();
    NewNode = L1.GetNode();
    cout<<"Enter Position";
    cin>>pos;
    L1.Insert_at_pos(NewNode, pos);*/
   
    int pos,choice;
    DNode *NewNode;
    List L1;
    do
    {
            cout<<"CHOOSE WHAT YOU WANT TO PERFORM:\n1)create\n2)Display\n3)GetNode\n4)insert_at_position\n5)Delete at start\n6)Delete at end\n7)Delete overall\n8)Search\n9)exit"<<endl;
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
            NewNode = L1.GetNode();
            break;
        }
        case 4:
        {
            cout<<"Enter Position";
            cin>>pos;
            L1.Insert_at_pos(NewNode, pos);
            //L1.display();
        break;
        }
        case 5:
        {
            L1.startdelete();
            break;
        }
        case 6:
        {
            L1.enddelete();
            break;
        }
        case 7:
        {
            L1.deleten();
            break;
        }
        case 8:
        {
            L1.search();
            break;
        }
       // L1.display();
     
        }    
    }while(choice!=9);
   
    return 0;
}
