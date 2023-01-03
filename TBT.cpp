//TBT

#include<iostream>
using namespace std;

class TreeNode
{
public:
TreeNode *lchild, *rchild;
int data;
bool lbit, rbit;
TreeNode()
{
lchild=rchild=NULL;
}
};

class TBT
{
TreeNode* Root;

public:
TreeNode* Insert(TreeNode*, int);
TreeNode* Successor(TreeNode*);
void Inorder(TreeNode*);

TBT()
{
Root=NULL;
}
};

TreeNode* TBT :: Insert(TreeNode* Root, int Key)
{
TreeNode* ptr = Root;
  TreeNode*par=NULL;
  while(ptr!=NULL)
  {
      if(ptr->data==Key)
      {
        return Root;
}
        par=ptr;
        if (Key < ptr->data)
        {
            if (ptr -> lbit == false)
                ptr = ptr -> lchild;
            else
                break;
        }
        else
        {
            if (ptr->rbit == false)
                ptr = ptr -> rchild;
            else
                break;
        }
  }
    TreeNode *Temp = new TreeNode;
    Temp -> data = Key;
    Temp -> lbit = true;
    Temp -> rbit = true;
 
    if (par == NULL)
    {
        Root = Temp;
        Temp -> lchild = NULL;
        Temp -> rchild = NULL;
    }
    else if (Key < (par -> data))
    {
        Temp -> lchild = par -> lchild;
        Temp -> rchild = par;
        par -> lbit = false;
        par -> lchild = Temp;
    }
    else
    {
        Temp -> lchild = par;
        Temp -> rchild = par -> rchild;
        par -> rbit = false;
        par -> rchild = Temp;
    }
 
    return Root;
 }

TreeNode* TBT :: Successor(TreeNode* ptr)
{
if(ptr->rbit == true)
return ptr->rchild;

ptr= ptr->rchild;
while(ptr->lbit == false)
ptr = ptr->lchild;
return ptr;
}

void TBT :: Inorder(TreeNode* Root)
{
if (Root == NULL)
cout<<"Tree is empty";
 
   
TreeNode *ptr = Root;

while (ptr -> lbit == false)
ptr = ptr -> lchild;
 
    //print successors one by one
while (ptr != NULL)
{
        cout<<" "<<ptr -> data;
        ptr =Successor(ptr);
}
}

int main()
{
TBT a;
TreeNode* Root = NULL;
Root = a.Insert(Root, 90);
Root = a.Insert(Root, 56);
Root = a.Insert(Root, 600);
Root = a.Insert(Root, 9);
Root = a.Insert(Root, 10);

a.Inorder(Root);
return 0;
}
