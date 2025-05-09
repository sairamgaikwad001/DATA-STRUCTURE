// DS Assignment No. 9


/*   Construct the OBST for a keys in General Store such that           
          */  
          
          
#include<iostream>
#include<string>

using namespace std;

int n; // Global n

class GS
{
  float p[10], q[10];
  string key[10];
  int w[10][10], c[10][10], r[10][10];
  
  public :
      void accept();
      void build();
      void display();
      void print(int i, int j);
};


void GS::accept()
{
   cout<<"\nEnter the no. of Items: ";
   cin>>n;
   
   for(int i=1; i<=n; i++)
   {
      cout<<"Item"<<i<<": ";
      cin>>key[i];
   }
   
   cout<<"\nEnter Successful Search Probability: \n";
   for(int i=1; i<=n; i++)
   {
     cout<<"p["<<i<<"]: ";
     cin>>p[i];
   }
   
   cout<<"\nEnter Unsuccessful Search Probability: \n";
   for(int i=0; i<=n; i++)
   {
     cout<<"q["<<i<<"]: ";
     cin>>q[i];
   }
}


void GS::build()
{
    for (int i = 0; i <= n; i++) // Initialize w[i][i], c[i][i], r[i][i]
    {
        w[i][i] = q[i];
        c[i][i] = 0;
        r[i][i] = 0;
    }

    for (int i = 0; i <= n; i++) // Also initialize w[i][j], c[i][j] where i > j
    {
        for (int j = 0; j <= n; j++)
        {
            if (i != j)
            {
                w[i][j] = 0;
                c[i][j] = 0;
                r[i][j] = 0;
            }
        }
    }

    for (int m = 1; m <= n; m++) 
    {
        for (int i = 0; i <= n - m; i++)
        {
            int j = i + m;
            w[i][j] =  p[j] + q[j] + w[i][j-1];

            int minCost = 9999;
            for (int k = i + 1; k <= j; k++)
            {
                int cost = c[i][k-1] + c[k][j];
                if (cost < minCost)
                {
                    minCost = cost;
                    r[i][j] = k;
                }
            }
            c[i][j] = w[i][j] + minCost;
        }
    }
}



void GS::display()
{

   cout<<"\nWeight Matrix W:\n";
   
   for(int i=0; i<=n; i++)
   {
     for(int j=0; j<=n; j++)
       cout<<w[i][j]<<" \t";
     cout<<endl;
   }
   
   cout<<"\nCost Matrix C:\n";
   
   for(int i=0; i<=n; i++)
   {
     for(int j=0; j<=n; j++)
       cout<<c[i][j]<<" \t";
     cout<<endl;
   }

   cout<<"\nRoot Matrix R:\n";
   
   for(int i=0; i<=n; i++)
   {
     for(int j=0; j<=n; j++)
       cout<<r[i][j]<<" \t";
     cout<<endl;
   }
}



void GS::print(int i, int j)
{
    if (i == j)
        return;

    int rootIndex = r[i][j];

    if (rootIndex == 0 || rootIndex > n)
        return;

    cout << "\nRoot: " << key[rootIndex];

    if (r[i][rootIndex - 1] != 0 && r[i][rootIndex - 1] <= n)
    {
        cout << "\nLeft child of " << key[rootIndex] << " is: " << key[r[i][rootIndex - 1]];
    }
    else
    {
        cout << "\n" << key[rootIndex] << " has no left child.";
    }

    if (r[rootIndex][j] != 0 && r[rootIndex][j] <= n)
    {
        cout << "\nRight child of " << key[rootIndex] << " is: " << key[r[rootIndex][j]];
    }
    else
    {
        cout << "\n" << key[rootIndex] << " has no right child.";
    }

    cout << "\n";

   
    print(i, rootIndex - 1);   
    print(rootIndex, j);      
}




int main()
{
    GS a;
    int ch; // No n here

    while (true)
    {
        cout << "\n\nMenu.\n1. Accept.\n2. Build OBST.\n3. Display Matrices and Structure.\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch)
        {
            case 1:
                a.accept();
                break;

            case 2:
                a.build();
                cout << "\nOBST Built Successfully.";
                break;

            case 3:
                a.display();
                cout<<"\n\nOptimal Binary Search Tree Structure:\n";
                a.print(0, n);
                break;

            case 4:
                return 0;

            default:
                cout << "\nWrong choice.";
        }
    }

    return 0;
}
 
