//DFS BFS

#include<iostream>
#include<queue>
using namespace std;

#define max 5

class node
{
    public:
    int vertex;
    node *next;
    node()
    {
        vertex=0;
        next=NULL;
    }
};
class graph
{
    node *heads[max];
    int n, visited[max], visited2[max];
    public:
    graph()
    {
        for(int i=0;i<max;i++)
        {
            heads[i]=NULL;
            visited[i]=0;
            visited2[i]=0;
        }
    }
    void create();

    void BFS(int);
    void DFS(int);

};
void graph::create()
{
    node *curr, *prev;
    int n1,i,j,vertex;
    bool done=false;
    cout<<"\nEnter number of vertices : ";
    cin>>n;
    for(i=0;i<n;i++)
    {
        if(!(heads[i]=new node))
        {
            cout<<"\nMemory not allocated!\n";
            exit;
        }
        heads[i]->vertex=i+1;
        cout<<"\nEnter number of vertices connected to "<<i+1<<" : ";
        cin>>n1;
        prev=heads[i];
        for(int j=0;j<n1;j++)
        {
            if(!(curr=new node))
            {
                cout<<"\nMemory not allocated!\n";
                exit;
            }
            done=false;
            do
            {
                cout<<"\nEnter vertex number of connected vertex : ";
                cin>>vertex;
                if(vertex > n && vertex < 1)
                {
                    cout<<"\nVertex out of range!";
                }
                else
                {
                    curr->vertex=vertex;
                    prev->next=curr;
                    prev=curr;
                    done=true;
                }
            }
            while(!done);
        }
        if(n1==0)
        prev->next=NULL;
    }
    return;
}
void graph::DFS(int v)
{
    node *curr;
    int w;
    curr=heads[v];
    cout<<"\t"<<curr->vertex;
    visited2[v]=true;
    curr=curr->next;
    while(curr!=NULL)
    {
        if(!visited2[w=(curr->vertex - 1)])
        DFS(w);
        curr=curr->next;
    }
    return;
}
void graph::BFS(int v)
{
    queue<node*>q;
    node *curr;
    visited[v]=true;
    cout<<"\t"<<heads[v]->vertex;
    q.push(heads[v]);
    while(!q.empty())
    {
        curr=q.front();
        q.pop();
        curr=curr->next;
        while(curr!=NULL)
        {
            if(!visited[curr->vertex -1])
            {
                q.push(heads[curr->vertex -1]);
                cout<<"\t"<<curr->vertex;
                visited[curr->vertex -1]=true;
            }
            curr=curr->next;
        }
    }
    return;
}
int main()
{
    graph obj;
    int choice;
    while(1)
    {
        cout<<"1.Create\n2.Display DFS\n3.Display BFS\n0.Exit";
        cout<<"\nEnter choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            obj.create();
            cout<<"\n";
            break;
            case 2:
            obj.DFS(1);
            cout<<"\n";
            break;
            case 3:
            obj.BFS(1);
            cout<<"\n";
            break;
            case 0:
            return 0;
            break;
            default:
            cout<<"Enter valid choice!\n";
            break;
        }
    }
    return 0;
}
