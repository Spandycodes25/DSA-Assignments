//AVL

#include<iostream>
#include<algorithm>

using namespace std;
class avl {
    public:
   int d;
   struct avl *l;
   struct avl *r;
}*root;
class avl_tree {
   public:
      int height(avl *);
      int difference(avl *);
      avl *rr_rotat(avl *);
      avl *ll_rotat(avl *);
      avl *lr_rotat(avl *);
      avl *rl_rotat(avl *);
      avl * balance(avl *);
      avl * insert(avl*, int);
      void inorder(avl *);
      void preorder(avl *);
      void search(int);
      avl_tree() {
         root = NULL;
      }
};
int avl_tree::height(avl *t) {
   int h = 0;
   if (t != NULL) {
      int l_height = height(t->l);
      int r_height = height(t->r);
      int max_height = max(l_height, r_height);
      h = max_height + 1;
   }
   return h;
}
int avl_tree::difference(avl *t) {
   int l_height = height(t->l);
   int r_height = height(t->r);
   int b_factor = l_height - r_height;
   return b_factor;
}
avl *avl_tree::rr_rotat(avl *parent) {
   avl *t;
   t = parent->r;
   parent->r = t->l;
   t->l = parent;
   cout<<"\nRight-Right Rotation\n";
   return t;
}
avl *avl_tree::ll_rotat(avl *parent) {
   avl *t;
   t = parent->l;
   parent->l = t->r;
   t->r = parent;
   cout<<"\nLeft-Left Rotation\n";
   return t;
}
avl *avl_tree::lr_rotat(avl *parent) {
   avl *t;
   t = parent->l;
   parent->l = rr_rotat(t);
   cout<<"\nLeft-Right Rotation\n";
   return ll_rotat(parent);
}
avl *avl_tree::rl_rotat(avl *parent) {
   avl *t;
   t = parent->r;
   parent->r = ll_rotat(t);
   cout<<"\nRight-Left Rotation\n";
   return rr_rotat(parent);
}
avl *avl_tree::balance(avl *t) {
   int bal_factor = difference(t);
   if (bal_factor > 1) {
      if (difference(t->l) > 0)
         t = ll_rotat(t);
      else
         t = lr_rotat(t);
   } else if (bal_factor < -1) {
      if (difference(t->r) > 0)
         t = rl_rotat(t);
      else
         t = rr_rotat(t);
   }
   return t;
}
avl *avl_tree::insert(avl *r, int v) {
   if (r == NULL) {
      r = new avl;
      r->d = v;
      r->l = NULL;
      r->r = NULL;
      return r;
   } else if (v< r->d) {
      r->l = insert(r->l, v);
      r = balance(r);
   } else if (v >= r->d) {
      r->r = insert(r->r, v);
      r = balance(r);
   } return r;
}
void avl_tree::inorder(avl *t) {
   if (t == NULL)
      return;
      inorder(t->l);
      cout << t->d << " ";
      inorder(t->r);
}
void avl_tree::preorder(avl *t) {
   if (t == NULL)
      return;
      cout << t->d << " ";
      preorder(t->l);
      preorder(t->r);
}
 void avl_tree:: search(int val)
    {
        int flag=0;
        avl *temp;
        temp=root;
        while(temp!=NULL)
        {
            if(temp->d == val)
            {
                flag=1;
                break;
            }
            else if(temp->d < val)
            {
                temp=temp->r;
            }
            else if(temp->d > val)
            {
                temp=temp->l;
            }
        }
        if(flag==1)
        cout<<"Key found!!"<<endl;
        else
        cout<<"Key not found!!"<<endl;
    }
   int main() {
   int c, z;
   avl_tree avl;
   while (1) {
      cout << "1.Insert Element into the tree" << endl;
      cout<< "2.Search element "<<endl;
      cout << "3.InOrder traversal" << endl;
      cout << "4.PreOrder traversal" << endl;
      cout << "6.Exit" << endl;
      cout << "Enter your Choice: ";
      cin >> c;
      switch (c) {
         case 1:
            int k;
            cout<<"how many values to insert? ";
            cin>>k;
            for(int i=0;i<k;i++){
            cout << "Enter value to be inserted: ";
            cin >> z;
            root = avl.insert(root, z);
            }
         break;
         case 2:
            cout<<"enter value to search: ";
            int m;
            cin>>m;
            avl.search(m);
            break;
         case 3:
            cout << "Inorder Traversal:" << endl;
            avl.inorder(root);
            cout << endl;
         break;
         case 4:
            cout << "Preorder Traversal:" << endl;
            avl.preorder(root);
            cout << endl;
         break;
         case 6:
           return 0;
         break;
         default:
            cout << "Wrong Choice" << endl;
      }
   }
   return 0;
}
