//Hashing

#include <iostream>
#include <string>

using namespace std;
#define size 10

class Hash
{
 private:
    struct tel
    {
        string emp_name;
        string comp_name;
        int id;
    }tel[size];
   
    public:
        void insert();
        void display();
        void collision_lp(int,string,string,int);
        void collision_qp(int,string,string,int);
        //void hash_fun(long int);
       
        //constructor to initialize values
        Hash()
        {
            for(int i=0;i<size;i++)
            {
                tel[i].id=0;
                tel[i].emp_name="--";
                tel[i].comp_name="--";
            }
        }
};

void Hash::insert()
{
    int choice;
    string name;
    string cname;
    int id_no;
    int loc;
    cout<<"Enter employee id: ";
    cin>>id_no;
    cout<<"\nEnter name: ";
    cin>>name;
    cout<<"Enter company name: ";
    cin>>cname;
   
    loc=id_no%size;
   
    //if(tel[loc].id==0)
   
        if(tel[loc].id==0)
        {
       tel[loc].emp_name=name;
       tel[loc].comp_name=cname;
       tel[loc].id=id_no;
       display();
        }
   
     else
    {
        cout<<"\nCollision occured\n";
        cout<<"\n1.Linear probing\n2.Quadratic probing: ";
        cin>>choice;
        switch(choice)
        {
          case 1:
            collision_lp(loc,name,cname,id_no);
            cout<<"\n";
            display();
            break;
          case 2:
            collision_qp(loc,name,cname,id_no);
            cout<<"\n";
            display();
            break;
        }
    }
}
void Hash::collision_lp(int Loc,string Name,string Cname,int id_No)
{
int k,new_loc;
for(k=0;k<size;k++)
{
new_loc=(Loc+k)%size;
if(tel[new_loc].id==0)
        {
          tel[new_loc].emp_name=Name;
          tel[new_loc].comp_name=Cname;
          tel[new_loc].id=id_No;
          break;
        }

}


}

void Hash::collision_qp(int Loc,string Name,string Cname,int id_No)
{
int k,new_loc;
for(k=0;k<size;k++)
{
new_loc=(Loc+(k*k))%size;
if(tel[new_loc].id==0)
        {
          tel[new_loc].emp_name=Name;
          tel[new_loc].comp_name=Cname;
          tel[new_loc].id=id_No;
          break;
        }

}


}

void Hash::display()
{
int i;
cout<<"Employee id\t\tEmployee name\t\tCompany name"<<endl;
for(i=0;i<size;i++)
{
    cout<<tel[i].id <<"\t\t\t" <<tel[i].emp_name<<"\t\t\t"<<tel[i].comp_name<<endl;

}


}

int main()
{
    int j,elements;
    cout<<"Enter no of elements: ";
    cin>>elements;
    Hash obj;
    for(j=0;j<elements;j++)
    {
      obj.insert();
    }
    cout<<"\nFinal hash table is:\n";
    obj.display();
   
   

    return 0;
}
