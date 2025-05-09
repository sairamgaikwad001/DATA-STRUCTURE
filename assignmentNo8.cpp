// DS Assignment No. 8

/*  Implement the concept of Max Heap And Min Heap.    */
        


#include<iostream>
using namespace std;

int n, value;

class Heap
{
  public:
  int key[20];
  int key2[20];
  
  void accept();
  void buildmax(int key[], int m, int value);
  void buildmin(int key2[], int m, int value);
  void insert();
  void displaymax();
  void displaymin();
  
}h;


void Heap :: accept()
{
  int cnt=1;
  
  cout<<"\nEnter no. of keys: ";
  cin>>n;
  
  cout<<"\nEnter the key values: ";
  for(int i=1; i<=n; i++)
  {
    cin>>value;
    buildmax(key, i, value);
    buildmin(key2, i, value);
    cnt++;
  }
}



void Heap :: buildmax(int key[], int m, int value)
{
  int loc, parent;
  
  key[m]=value;
  loc=m;
  
  while(loc > 1)
  {
    parent = loc/2;
    
    if(key[parent] < key[loc])
    {
      int temp = key[parent];
      key[parent] = key[loc];
      key[loc] = temp;
      
      loc = parent;
    }
    else
    {
      return;
    }
  }
}

void Heap :: buildmin(int key2[], int m, int value)
{
  int loc, parent;
  
  key2[m]=value;
  loc=m;
  
  while(loc > 1)
  {
    parent = loc/2;
    
    if(key2[parent] > key2[loc])
    {
      int temp = key2[parent];
      key2[parent] = key2[loc];
      key2[loc] = temp;
      
      loc = parent;
    }
    else
    {
      return;
    }
  }
}


void Heap :: insert()
{
  int nkey;
  cout<<"\nEnter new key which you have to insert: ";
  cin>>nkey;
  n++;
  
  buildmax(key, n, nkey);
  buildmin(key2, n, nkey);
}

void Heap :: displaymax()
{
  cout<<"\nMax Heap is: ";
  for(int i=1; i<=n; i++)
  {
    cout<<"\t"<<key[i];
  }
}  


void Heap :: displaymin()
{
  cout<<"\nMin Heap is: ";
  for(int i=1; i<=n; i++)
  {
    cout<<"\t"<<key2[i];
  }
}  
  
  
  
  
  

int main()
{
  int ch, i;
  
  while(true)
  {
    cout<<"\n\nMenu.\n1. Accept Keys.\n2. Insert New Key.\n3. Display Max Heap.\n4. Display Min Heap.\n5. Exit.";
    cout<<"\nEnter your choice: ";
    cin>>ch;
    
    switch(ch)
    {
      case 1:
          h.accept();
          break;
          
      case 2:
          h.insert();
          break;
          
      case 3:
          h.displaymax();
          break;
          
      case 4:
          h.displaymin();
          break;
          
      case 5:
            return 0;
            
            default:
              cout<<"\nWrong Choice.";
              
    }
  }
  
  return 0;
}
