/* Implement the concept of Railway Reservation System using Binary Search Tree. Write the display function without using recursive function (Non-recursive way).
   - Also display the AC class Passenger.
   - Also display the Sleeper class Passenger.
   - Also calculate the total Number of Passenger.       */
   
   
#include<iostream>
using namespace std;

int n = 0;

class RRS 
{
    string name;
    string add;
    int pz;
    RRS *lc, *rc;

public:

    void create();
    void insert(RRS *, RRS *);
    void insertPassenger();  // New function to insert passengers into an existing tree
    void display(RRS *root);
    void displayACPassengers(RRS *root);
    void displaySleeperPassengers(RRS *root);
    int countpass(RRS* root);
    void search(RRS *root, int price);
    
} *root = NULL, *st[100];

void RRS::create() 
{
    int ch;
    RRS *next;
    root = new RRS;
    
    cout << "\n   Enter the Name: ";
    cin >> root->name;
    cout << "   Enter the Address: ";
    cin >> root->add;
    cout << "   Enter the Ticket Price: ";
    cin >> root->pz;
    root->lc = root->rc = NULL;

    do 
    {
        cout << "\nYou want to add new passenger enter (1/0): ";
        cin >> ch;
        
        if (ch == 1) 
        {
            next = new RRS;
            cout << "\n   Enter the Name: ";
            cin >> next->name;
            cout << "   Enter the Address: ";
            cin >> next->add;
            cout << "   Enter the Ticket Price: ";
            cin >> next->pz;
            
            next->lc = next->rc = NULL;
            insert(root, next);
        }
        
    } while (ch == 1);
}

// Function to insert new passengers into the existing BST
void RRS::insertPassenger() 
{
    if (root == NULL) 
    {
        cout << "No passengers found! Create the tree first.\n";
        return;
    }
    
    RRS *next = new RRS;
    
    cout << "\n   Enter the Name: ";
    cin >> next->name;
    cout << "   Enter the Address: ";
    cin >> next->add;
    cout << "   Enter the Ticket Price: ";
    cin >> next->pz;
    
    next->lc = next->rc = NULL;
    insert(root, next);
}

void RRS::insert(RRS *root, RRS *next) 
{
    if (root->pz > next->pz) 
    {
        if (root->lc == NULL) 
        {
            root->lc = next;
        } 
        else 
        {
            insert(root->lc, next);
        }
    } 
    
    else if (root->pz < next->pz) 
    {
        if (root->rc == NULL) 
        {
            root->rc = next;
        } 
        else 
        {
            insert(root->rc, next);
        }
    }
}

void RRS::display(RRS *root) 
{
    RRS *temp;
    int top = -1;
    
    cout << "\nName\tAddress\tPrice(Rs.)\n";
    temp = root;
    
    if (root != NULL) 
    {
        do 
        {
            while (temp != NULL) 
            {
                top++;
                st[top] = temp;
                temp = temp->lc;
            }
            if (top != -1) 
            {
                temp = st[top];
                top--;
                cout << "\n" << temp->name << "\t" << temp->add << "\t" << temp->pz;
                temp = temp->rc;
            }
        } while (temp != NULL || top != -1);
    }
}

void RRS::displayACPassengers(RRS *root) 
{
    if (root == NULL) 
    {
        cout << "No passengers in the system.\n";
        return;
    }

    RRS *temp;
    int top = -1;
    int rootPrice = root->pz; // Store the root ticket price
    
    cout << "\nAC Class Passengers (Ticket Price >= " << rootPrice << "):\n";
    cout << "\nName\tAddress\tPrice(Rs.)\n\n";

    temp = root;

    do 
    {
        while (temp != NULL) 
        {
            top++;
            st[top] = temp;
            temp = temp->lc;
        }

        if (top != -1) 
        {
            temp = st[top];
            top--;

            // Condition: Only display if price is greater than root's price
            if (temp->pz >= rootPrice) 
            {
                cout <<temp->name << "\t" << temp->add << "\t" << temp->pz << endl;
            }
            
            temp = temp->rc;
        }
    } while (temp != NULL || top != -1);
}


void RRS::displaySleeperPassengers(RRS *root) 
{
    if (root == NULL) 
    {
        cout << "No passengers in the system.\n";
        return;
    }

    RRS *temp;
    int top = -1;
    int rootPrice = root->pz; // Store the root ticket price
    
    cout << "\nSLEEPER Class Passengers (Ticket Price < " << rootPrice << "):\n";
    cout << "\nName\tAddress\tPrice(Rs.)\n\n";

    temp = root;

    do 
    {
        while (temp != NULL) 
        {
            top++;
            st[top] = temp;
            temp = temp->lc;
        }

        if (top != -1) 
        {
            temp = st[top];
            top--;

            // Condition: Only display if price is smaller than root's price
            if (temp->pz < rootPrice) 
            {
                cout <<temp->name << "\t" << temp->add << "\t" << temp->pz << endl;
            }
            
            temp = temp->rc;
        }
    } while (temp != NULL || top != -1);
}



int RRS::countpass(RRS *root) 
{
    if (root == NULL) 
    {
        return 0;
    } 
    else 
    {
        return 1 + countpass(root->lc) + countpass(root->rc);
    }
}

void RRS::search(RRS *root, int price)
{
    while (root != NULL)
    {
        if (root->pz == price)
        {
            cout << "\nPassenger Found: " <<"\nName: "<< root->name << "\nAddress: " << root->add << "\nTicket Price: " << root->pz << endl;
            return;
        }
        else if (price < root->pz)
        {
            root = root->lc;
        }
        else
        {
            root = root->rc;
        }
    }
    cout << "\nPassenger with ticket price " << price << " not found.\n";
}



int main() 
{
    int ch;
    
    while (true) 
    {
        cout << "\n\nMain Menu.\n\n   1. Create & Insert Passengers.\n   2. Insert New Passenger.\n   3. Display Passengers.\n   4. Display AC Class Passengers.\n   5. Display SLEEPER Class Passengers.\n   6. Count Passengers.\n   7. Search passenger(Through Ticket Price).\n   8. Exit.";
        cout << "\n\nEnter your choice: ";
        cin >> ch;
        
        switch (ch) 
        {
            case 1:
                if (root == NULL) 
                {
                    root = new RRS;
                    root->create();
                } 
                else 
                {
                    cout << "Passengers already created! Use option 2 to add more.\n";
                }
                break;
                
            case 2:
                root->insertPassenger();
                break;

            case 3:
                root->display(root);
                break;
                
            case 4:
                root->displayACPassengers(root);
                break;
                
            case 5:
                root->displaySleeperPassengers(root);
                break;

            case 6:
                cout << "\nThe total number of passengers is: " << root->countpass(root);
                break;
                
            case 7:
                int price;
                cout << "\nEnter ticket price to search: ";
                cin >> price;
                root->search(root, price);
                break;

            case 8:
                return 0;

            default:
                cout << "\nWrong choice.";
        }
    }
}
