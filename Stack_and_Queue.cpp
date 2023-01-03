//Stack and Queue

//Stack

#include <iostream>

using namespace std;

class stack_node
{
    public:
        int data;
        stack_node *next;
};

class Stack_New
{
    private:
        stack_node *top;
        int size;
   
    public:
        int is_empty();
        int pop();
        void push(int element);
        int Gettop();
   
    Stack_New()
    {
        top = NULL;
        size=0;
    }
};

int Stack_New :: is_empty()
{
    if(top==NULL)
   
        return 1;
   
    else
   
        return 0;
   
}

int Stack_New :: Gettop()
{
    if(!is_empty())
   
        return(top->data);
   
}

void Stack_New :: push(int value)
{
    stack_node *NewNode;
    NewNode = new stack_node;
    NewNode->data = value;
    NewNode->next = top;
    top = NewNode;
}

int Stack_New :: pop()
{
    int data;
    stack_node *temp = top;
    data = top->data;
    if(is_empty())
   
        cout<<"Stack Underflow"<<endl;
   
    else
   
     {   top = top->next;
        delete(temp);
        return data;
     }
}


int main()
{
    Stack_New s;
    int choice,element;
    while(1)
    {
        cout<<"Enter the action to be performed\n1.Push\n2.pop\n3.Gettop\n4.Exit"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
               cout<<"Enter element to be added:";
               cin>>element;
               s.push(element);
               break;
            }
           
            case 2:
            {
                cout<<"Popped element is:"<<s.pop()<<endl;
                break;
            }
           
            case 3:
            {
                cout<<"Top element is:"<<s.Gettop()<<endl;
                break;
            }
           
            case 4:
            {
                break;
            }
        }
    }
   

    return 0;
}

//Queue

#include <iostream>

using namespace std;

class QueueNode
{
    public:
    int data;
    QueueNode *next;
};

class QueueNew
{
    private:
        QueueNode *front, *rear;
    public:
        int empty();
        void insert(int element);
        int Delete();
        int Getfront();
       
    QueueNew()
    {
        front = rear = NULL;
    }
};

int QueueNew :: empty()
{
    if(front = NULL)
        return 1;
    else
        return 0;
}

void QueueNew :: insert(int value)
{
    QueueNode *NewNode;
    NewNode = new QueueNode;
    NewNode->data =  value;
    NewNode->next = NULL;
    if(rear == NULL)
    {
        front = NewNode;
        rear = NewNode;
    }
    else
    {
        rear->next = NewNode;
        rear = NewNode;
    }
}

int QueueNew :: Delete()
{
    int temp;
    QueueNode *curr = NULL;
    if(!empty())
    {
        temp = front->data;
        curr = front;
        front = front->next;
        delete curr;
        return temp;
    }
    else
    {
        cout<<"Queue is empty";
        return 0;
       
    }
}

int QueueNew :: Getfront()
{
    if(!empty())
    {
        return(front->data);
    }
    else
        return 0;
}

int main()
{
   QueueNew Q;
   int choice, element;
    while(1)
    {
        cout<<"Enter the action to be performed\n1.INsert\n2.Delete\n3.Getfront\n4.Exit"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
               cout<<"Enter element to be added:";
               cin>>element;
               Q.insert(element);
               break;
            }
           
            case 2:
            {
                cout<<"DEleted element is:"<<Q.Delete()<<endl;
                break;
            }
           
            case 3:
            {
                cout<<"Front element is:"<<Q.Getfront()<<endl;
                break;
            }
           
            case 4:
            {
                break;
            }
        }
    }
   
  /* Q.insert(11);
   Q.insert(12);
   cout<<endl<<Q.Delete()<<endl;
   cout<<endl<<Q.Getfront()<<endl;*/
   return 0;
}
