//Infix to Postfix

#include <iostream>
#include<string.h>
#define Max 20
using namespace std;

class Stack
{
    private:
        char stack[Max];
        int top;
    public:
        Stack()
        {
            top = -1;
        }
    int isempty();
    int isfull();
    void push(char ch);
    char pop();
    char getTop();
};

int Stack :: isempty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}

int Stack :: isfull()
{
    if(top == Max-1)
        return 1;
    else
        return 0;
}

void Stack :: push(char element)
{
    if(isfull())
    {
        cout<<"Stack Overflow";
    }
    else
    {
        top++;
        stack[top] = element;
    }
}

char Stack :: pop()
{
    char temp;
    if(isempty())
    {
        cout<<"Stack Underflow";
    }
    else
    {
        temp = stack[top];
        top--;
    }
    return(temp);
}

char Stack :: getTop()
{
    if(top == -1)
    {
        cout<<"Stack Underflow";
    }
    else
    {
        return(stack[top]);
    }
}

char isp(char ch)
{
    switch(ch)
    {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        case '(': return 0;
        case '#': return -2;
    }
}

char icp(char ch)
{
    switch(ch)
    {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        case '(': return 4;
    }
}

void intopost(char infix[20], char postfix[20])
{
    int i=0;
    char ch, x;
    Stack s;
    s.push('#');
    while(infix[i]!='\0')
    {
        ch = infix[i];
        i++;
        if(ch>='a' && ch<='z')
        {
            cout<<ch;
        }
        else
        {
            if(ch == ')')
            {
                while(s.getTop() != '(')
                {
                    x = s.pop();
                    cout<<x;
                }
                x=s.pop();
            }
        else
        {
            while(isp(s.getTop()) >= icp(ch))
            {
                x = s.pop();
                cout<<x;
            }
            s.push(ch);
        }
    }
}

    while(!s.isempty())
    {
        x = s.pop();
        if(x != '#')
        cout<<x;
    }
}


int main()
{
    char infix[20], postfix[20];
    cout<<"Enter the Infix Expression:\n";
    cin>>infix;
    cout<<"Postfix Expression is:";
    intopost(infix, postfix);

    return 0;
}
