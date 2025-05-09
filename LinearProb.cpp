// Assignment No. 6

/*     
Create a student Management system - a software application used to manage the storage and retrieval of records. 
Hash Table can be used as a data structure to efficiently store and retrieve student information using Linear Probing. 
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

    void Htable();
    void accept();
    void display();
    void search();  // Added declaration
};

int student::key[SIZE];
student student::h[SIZE];

void student::Htable() 
{
    for (int i = 0; i < SIZE; i++) 
    {
        key[i] = -1;
        h[i].rno = -1;
    }

    cout << "\nInitial Hash Table:";
    cout << "\nIndex\tRoll No";
    for (int i = 0; i < SIZE; i++) {
        cout << "\n" << i << "\t" << h[i].rno;
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
        int index = r % SIZE;

        int start = index;
        while (h[index].rno != -1) 
        {
            index = (index + 1) % SIZE;
            if (index == start) 
            {
                cout << "Hash table is full!" << endl;
                return;
            }
        }

        h[index].rno = r;
        cout << "Enter name: ";
        cin >> h[index].name;
        cout << "Enter address: ";
        cin >> h[index].add;

        key[i] = r;
    }
}

void student::display() 
{
    cout << "\nFinal Hash Table:";
    cout << "\n\nLoc\tRoll No\tName\tAddress";
    for (int i = 0; i < SIZE; i++) 
    {
        if (h[i].rno != -1) 
        {
            cout << "\n" << i << "\t" << h[i].rno << "\t" << h[i].name << "\t" << h[i].add;
        } 
        else 
        {
            cout << "\n" << i << "\t--\t--\t--";
        }
    }
    cout << endl;
}

void student::search() 
{
    int r;
    cout << "\nEnter roll number to search: ";
    cin >> r;
    int index = r % SIZE;
    int start = index;

    while (h[index].rno != -1) 
    {
        if (h[index].rno == r) 
        {
            cout << "\nRecord Found at index " << index << ":\n";
            cout << "Roll No: " << h[index].rno << "\n";
            cout << "Name: " << h[index].name << "\n";
            cout << "Address: " << h[index].add << "\n";
            return;
        }
        index = (index + 1) % SIZE;
        if (index == start) 
        {
            break;
        }
    }
    cout << "Record with Roll No " << r << " not found.\n";
}

int main() 
{
    student s;
    s.Htable();
    
    int ch;
   
   while(true)
   {
     cout<<"\n\nMenu.\n1. Accept Record.\n2. Display Final HT.\n3. Search Record.\n4. Exit.";
     cout<<"\nEnter your choice: ";
     cin>>ch;
     
     switch(ch)
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
             return 0;
             
             default:
                cout<<"\nWrong choice.";
                
      }
    }
    
    return 0;
}
