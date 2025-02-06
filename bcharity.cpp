// Implement Charity Management System using Binary Tree Concept.


#include <iostream>
#include <string>

using namespace std;

class Charity 
{
    string name;
    string phone;
    int donation;
    Charity *next;

public:

    void create();
    void insert(Charity *, Charity *);
    void display(Charity *head);
    void displayTotal(Charity *head);
    
} *head, *tail;

void Charity::create() 
{
    int ch;
    Charity *newDonor;

    head = new Charity;
    
    cout << "\nEnter Donor Name: ";
    cin.ignore();
    getline(cin, head->name);
    
    cout << "Enter Phone Number: ";
    cin >> head->phone;
    
    cout << "Enter Donation Amount: ";
    cin >> head->donation;

    head->next = NULL;
    tail = head;

    do 
    {
        cout << "\nDo you want to add another donor? (1 for Yes / 0 for No): ";
        cin >> ch;

        if (ch == 1) 
        {
            newDonor = new Charity;
            
            cout << "Enter Donor Name: ";
            cin.ignore();
            getline(cin, newDonor->name);
            
            cout << "Enter Phone Number: ";
            cin >> newDonor->phone;
            
            cout << "Enter Donation Amount: ";
            cin >> newDonor->donation;

            newDonor->next = NULL;
            insert(tail, newDonor);
        }
        
    } while (ch == 1);
}

void Charity :: insert(Charity *current, Charity *newDonor) 
{
    current->next = newDonor;
    tail = newDonor;
}

void Charity :: display(Charity *head) 
{
    Charity *temp = head;

    if (!head) 
    {
        cout << "\nNo Donors Available.\n";
        return;
    }


	cout<<"\nDonor Name\tMobNo\tDonation(Rs.)";
    

    // Print donor details
    while (temp) 
    {
        
             cout<<"\n"<<temp->name<<"\t"<<temp->phone<<"\t"<<temp->donation;
             
        temp = temp->next;
    }

    
}

void Charity :: displayTotal(Charity *head) 
{
    Charity *temp = head;
    int total = 0;

    if (!head) 
    {
        cout << "\nNo Donations Available.\n";
        return;
    }

    while (temp) 
    {
        total += temp->donation;
        temp = temp->next;
    }

    cout << "\nTotal Donations Received: Rs." << total << "\n";
}

int main() 
{
    int ch;

    while (true) 
    {
        cout << "\n\nMenu.\n1. Create Donors & Add Data.\n2. Display Donors.\n3. Display Total Donations.\n4. Exit.";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) 
        {
        
        case 1:
            head->create();
            break;

        case 2:
            head->display(head);
            break;

        case 3:
            head->displayTotal(head);
            break;

        case 4:
            return 0;

        default:
            cout << "\nWrong choice.";
        }
    }
}
