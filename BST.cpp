//BST

#include<iostream>
using namespace std;

class BSTnode
{
    public:
    int data;
    BSTnode *rchild, *lchild;
};

class BST
{
    public:
   
    BSTnode *root, *temp;
    BST()
    {
        root = NULL;
    }
    void Insert(int key);
    void Display();
    void Delete(int key);
    void Search(int key);
    //bool IsEmpty();
};

class stack_node
{
    public:
    BSTnode * data;
    stack_node *next;
};

class Stack
{
    public:
    stack_node *top;
    int Is_Empty();
    BSTnode* Pop();
    void Push(BSTnode * temp);


    Stack()
    {
        top=NULL;

    }
};

int Stack :: Is_Empty()
{
if(top==NULL)
return 1;
else
return 0;
}

void Stack :: Push(BSTnode * temp)
{
    stack_node *newnode;
    newnode = new stack_node;
    newnode->data=temp;
    newnode->next=top;
    top=newnode;
}

BSTnode* Stack :: Pop()
{
    stack_node *temp=top;
    BSTnode * value;
    value=top->data;

    if(Is_Empty())
    return 0;

    else
    {
    top=top->next;
    delete temp;
    return (value);
    }
}

//stack2 for postorder
class stack2_node
{
    public:
    char data;
    stack2_node *next;
};

class Stack2
{
    public:
    stack2_node *top;
    int Is_Empty();
    char Pop();
    void Push(char temp);


    Stack2()
    {
        top=NULL;

    }
};

int Stack2 :: Is_Empty()
{
if(top==NULL)
return 1;
else
return 0;
}

void Stack2 :: Push(char temp)
{
    stack2_node *newnode;
    newnode = new stack2_node;
    newnode->data=temp;
    newnode->next=top;
    top=newnode;
}

char Stack2 :: Pop()
{
    stack2_node *temp=top;
    char value;
    value=top->data;

    if(Is_Empty())
    return 0;

    else
    {
    top=top->next;
    delete temp;
    return (value);
    }
}

void BST :: Insert(int key)
{
    BSTnode *newnode;
    newnode = new BSTnode ;
    newnode->data=key;
    newnode->rchild=NULL;
    newnode->lchild=NULL;
   
    if(root==NULL)
    {
        root=newnode;  
       
    }
   
    else
    {
        temp=root;
        while(temp != NULL)
        {
            if(key < temp->data )
            {
                if(temp->lchild == NULL)
                {
                    temp->lchild = newnode;
                    break;
                }
                temp= temp->lchild;
            }
            else
            {
                if(temp->rchild == NULL)
                {
                    temp->rchild = newnode;
                    break;
                }
           
                temp = temp->rchild;
            }
       
    }
}
}

void BST :: Display()
{
    //inorder
    cout<<"\nInorder: ";
    Stack S1;
    temp = root;
    while(1)
    {
        while(temp != NULL)
        {
            S1.Push(temp);
            temp = temp->lchild;
        }
        if(S1.Is_Empty())
        break;

        temp = S1.Pop();
        cout << temp->data<<" ";
        temp = temp->rchild;
    }
   
    //preorder
    cout<<"\nPreorder: ";
    Stack S2;
    temp = root;
    while(1)
    {
        while(temp != NULL)
        {
            S2.Push(temp);
            cout << temp->data<<" ";
            temp = temp->lchild;
        }
        if(S2.Is_Empty())
        break;

        temp = S2.Pop();    
        temp = temp->rchild;
    }
   
    //postorder
    cout<<"\nPostorder: ";
    Stack S3;
    Stack2 S;
    temp=root;
    char flag;
    // stack S3 stores the node and S stores the flag ‘L’ or ‘R’
    while(1)
    {
    while(temp != NULL)
    {
        S3.Push(temp);
        S.Push('L');
        temp = temp->lchild;
    }
    if(S3.Is_Empty())
        break;
    else
    {
        temp = S3.Pop();
        flag = S.Pop();
        if(flag == 'R')
        {
            cout << temp->data<<" ";
            temp = NULL;
        }
        else
        {
            S3.Push( temp);
            S.Push('R');
            temp = temp->rchild;
        }
    }
    }
}
   

void BST :: Delete(int key)
{
    int flag=0, count=0;
    temp=root;
    BSTnode *parent, *curr;
    if(root == NULL)
    {
        cout<<"\n BST is empty";
    }
    else
    {
        parent=temp;
        while(temp)
        {
            if(temp->data==key)
                break;
               
            else if(key<temp->data)
            {
                parent=temp;
                temp=temp->lchild;
            }
            else
            {
                parent=temp;
                temp=temp->rchild;  
            }
        }
        if(temp==NULL)
            cout<<"\nkey to be deleted not found!";
        else
        {
            //case of leaf node
            if(temp->rchild == NULL && temp->lchild == NULL)
            {
                if(temp==parent->rchild)
                    parent->rchild=NULL;
                else if(temp==parent->lchild)
                    parent->lchild=NULL;
                   
                delete temp;
            }
           
            //case of BST node having right children
            else if(temp->rchild != NULL && temp->lchild == NULL)
            {
               
                curr = temp->rchild;
               
                if(temp==parent->rchild)
                {
                    parent->rchild=curr;
                }
                else if(temp==parent->lchild)
                {
                    parent->lchild=curr;
                }
               
                delete temp;
            }
           
            //case of BST node having left children
            else if(temp->lchild!=NULL && temp->rchild == NULL)
            {
                curr = temp->lchild;    
                if(temp==parent->rchild)
                {
                    parent->rchild=curr;
                }
                else if(temp==parent->lchild)
                {
                    parent->lchild=curr;
                }
               
                delete temp;
            }
    }
   
}
}

void BST :: Search(int key)
{
    temp=root;
    int flag=0;
    while(temp)
    {
        if(temp->data==key)
        {
            cout<<"\nKey found";
            flag=1;
            break;
        }
       
        else if(key<temp->data)
            temp=temp->lchild;
        else
            temp=temp->rchild;        
    }
    if(flag==0)
        cout<<"\nkey not found!";
   
}

int main()
{
    int ch,key;
    BST obj;
   
    do
    {
        cout<<"\nMenu:\n1.insert\n2.delete\n3.display\n4.search\n5.exit\n";
        cin>>ch;
        switch(ch)
        {
            case 1:
                    cout<<"\nEnter key to be inserted: ";
                    cin>>key;
                    obj.Insert(key);
                    break;
                   
            case 2:
                    cout<<"\nEnter key to be deleted: ";
                    cin>>key;
                    obj.Delete(key);
                    obj.Display();
                    break;
                   
            case 3:
                    obj.Display();
                    break;
                   
            case 4:
                    cout<<"\nEnter key to be searched: ";
                    cin>>key;
                    obj.Search(key);
                    break;
        }
               
       
    }while(ch!=5);
   

    return 0;
}
