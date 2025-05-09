// Assignment No. 7

/*     
Create a student Management system - a software application used to manage the storage and retrieval of records. 
Hash Table can be used as a data structure to efficiently store and retrieve student information using Linear Probing with chain. 
*/



#include <iostream>
using namespace std;

const int SIZE = 10;
int n;

class student 
{
public:
    int rno;
    string name, add;

    static int key[SIZE];
    static student h[SIZE];
    static int chain[SIZE];  // For storing chains

    void Htable();
    void accept();
    void display();
    void search();
    void deleteRecord();
};

int student::key[SIZE];
student student::h[SIZE];
int student::chain[SIZE];

void student::Htable() 
{
    for (int i = 0; i < SIZE; i++) 
    {
        key[i] = -1;
        h[i].rno = -1;
        chain[i] = -1;
    }

    cout << "\nInitial Hash Table:";
    cout << "\nIndex\tRoll No\t Chian";
    for (int i = 0; i < SIZE; i++) 
    {
        cout << "\n" << i << "\t" << h[i].rno<<"\t"<<chain[i];
    }
    cout << endl;
}

void student::accept() 
{
    cout << "\nEnter the number of records: ";
    cin >> n;

    for (int i = 0; i < n; i++) 
    {
        int r;
        cout << "\nEnter roll number: ";
        cin >> r;

        int hashIndex = r % SIZE;
        int index = hashIndex;

        // Find the next available spot using linear probing
        while (h[index].rno != -1) 
        {
            index = (index + 1) % SIZE;
            if (index == hashIndex) 
            {
                cout << "Hash table is full!" << endl;
                return;
            }
        }

        // Insert student data
        h[index].rno = r;
        cout << "Enter name: ";
        cin >> h[index].name;
        cout << "Enter address: ";
        cin >> h[index].add;

        // Chain from original hash index if collision occurred
        if (index != hashIndex) 
        {
            int current = hashIndex;
            while (chain[current] != -1) 
            {
                current = chain[current];
            }
            chain[current] = index;
        }

        key[i] = r;
    }
}

void student::display() 
{
    cout << "\nFinal Hash Table with Chaining:";
    cout << "\n\nLoc\tRoll No\tName\tAddress\tChain";
    for (int i = 0; i < SIZE; i++) 
    {
        
            cout << "\n" << i << "\t" << h[i].rno << "\t" << h[i].name << "\t" << h[i].add << "\t"<<chain[i];
        
        
    }
    cout << endl;
}

void student::search() 
{
    int r;
    cout << "\nEnter roll number to search: ";
    cin >> r;

    int index = r % SIZE;
    while (index != -1) 
    {
        if (h[index].rno == r) 
        {
            cout << "\nRecord Found at index " << index << ":\n";
            cout << "Roll No: " << h[index].rno << "\n";
            cout << "Name: " << h[index].name << "\n";
            cout << "Address: " << h[index].add << "\n";
            return;
        }
        index = chain[index];
    }

    cout << "Record with Roll No " << r << " not found.\n";
}

void student::deleteRecord() 
{
   int r,flag=0,pos,newloc;
    cout << "\nEnter roll number to delete: ";
    cin >> r;

      int loc=r%10;
      pos=loc;
      
      if(h[loc].rno==r && chain[loc]!=-1)
      {
       do
        {
           newloc=chain[loc];
           h[loc]=h[newloc];
           loc=newloc;
           
        } while(chain[newloc]!=-1);
      
        chain[loc]=-1;
        h[newloc].rno=-1;
        h[newloc].name="";
        h[newloc].add="";
        flag=1;
        cout<<"\n Record Deleted";
     
      }
      
      else if(h[loc].rno==r && chain[loc]==-1)
      {
        h[newloc].rno=-1;
        h[newloc].name="";
        h[newloc].add="";
        flag=1;
        cout<<"\n Record Deleted";
      }
      
      if(flag==0)
      cout<<"\n Record not found";     
}

 
int main() 
{
    student s;
    s.Htable();

    int ch;

    while (true) 
    {
        cout << "\n\nMenu.\n1. Accept Record.\n2. Display Final HT.\n3. Search Record.\n4. Delete Record.\n5. Exit.";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) 
        {
            case 1:
                s.accept();
                break;
            case 2:
                s.display();
                break;
            case 3:
                s.search();
                break;
                
            case 4:
                s.deleteRecord();
                break;
                
            case 5:
                return 0;
            default:
                cout << "\nWrong choice.";
        }
    }

    return 0;
}
