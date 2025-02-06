// Implement the concept of Binary Tree.


#include<iostream>
using namespace std;

class Emp
{
  char data;
  Emp *lc, *rc;
  
  public:
       void create();
       void insert(Emp *, Emp *);
       void display(Emp *root);
}*root;

void Emp :: create()
{
  int ch;
  Emp *next;
  root = new Emp;
  cout<<"\nEnter the data: ";
  cin>>root->data;
  root->lc=root->rc=NULL;
  
  do
  {
    cout<<"\nYou want to add new data enter (1/0): ";
    cin>>ch;
    
    if(ch==1)
    {
     next = new Emp;
     cout<<"Enter the data: ";
     cin>>next->data;
     next->lc=next->rc=NULL;
     insert(root, next);
    }
  }while(ch==1);
}

void Emp :: insert(Emp *root, Emp *next)
{
  char ch1;
  cout<<"Where you want to insert "<<next->data<<" of "<<root->data<< " (L or R): ";
  cin>>ch1;
  
  if(ch1=='L' || ch1=='l')
  {
    if(root->lc == NULL)
    {
      root->lc = next;
    }
    else
    {
     insert(root->lc, next);
    }
  }
  
  if(ch1=='R' || ch1=='r')
  {
    if(root->rc == NULL)
    {
      root->rc = next;
    }
    else
    {
     insert(root->rc, next);
    }
  }
}

void Emp :: display(Emp *root)
{
  if(root == NULL)
  {
    return;
  }
  else
  {
    display(root->lc);
    cout<<"\n"<<root->data;
    display(root->rc);
  }
}


int main()
{
  int ch;
 
  while(true)
  {
     cout<<"\n\nMenu.\n1.Creat Node & Insert Data.\n2.Display.\n3.Exit.";
     cout<<"\nEnter your choice: ";
     cin>>ch;
     
     switch(ch)
     {
       case 1:
           root->create();
           break;
           
       case 2:
            root->display(root);
            break;
            
       case 3:
            return 0;
            
            default:
            cout<<"\nWrong choice.";
            
      }
      
   }
   
}
   
       
