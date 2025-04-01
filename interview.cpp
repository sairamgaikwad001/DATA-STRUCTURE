// Assignment No. 4

/*   You are a job seeker preparing for a interview in different location. You have a list of cities where interviews are schedule. Objective is to minimize the 
     total travel distance and time which ensuring you to reach each interview location on time.
     Use appropriate data structure and algorithm to implement it.

      - You want to find the shortest path to visit all interview location.
      - Starting from your current location.   

     */
     

#include <iostream>
#include <climits>  
using namespace std;

#define INF 999  // Large value for no direct path

class MST 
{
    int v;
    string city[10];       // Stores city names
    int adj[10][10];       // Adjacency matrix
    int parent[10];        // Stores MST parent nodes
    int totalDist;         // Stores total minimum distance

public:
    void create();
    void findMST();
    void shortestPath();
} e;

void MST::create() 
{
    cout << "Enter the number of cities: ";
    cin >> v;
    
    
    cout << "\nEnter the names of the cities:\n";
    for (int i = 0; i < v; i++) 
    {
        cout << "  Enter city " << (i + 1) << " name: ";
        cin >> city[i];
    }

    cout << "\nEnter adjacency matrix \n(distance between cities, 0 for same city, 999 if no direct path):\n";
    for (int i = 0; i < v; i++) 
    {
        for (int j = 0; j < v; j++) 
        {
            cin >> adj[i][j];
            if (i != j && adj[i][j] == 0) 
            {
                adj[i][j] = INF;  // No direct path
            }
        }
    }
}

// Function to find the Minimum Spanning Tree using Prim’s Algorithm

void MST::findMST() 
{
    int key[10];       // Stores minimum edge weights
    bool visited[10];  
    totalDist = 0;     // Initialize total distance to 0

    for (int i = 0; i < v; i++) 
    {
        key[i] = INF;
        visited[i] = false;
        parent[i] = -1;
    }

    key[0] = 0; // Start from the first city

    for (int count = 0; count < v - 1; count++) 
    {
        int min = INF, u = -1;

        for (int i = 0; i < v; i++) 
        {
            if (!visited[i] && key[i] < min) 
            {
                min = key[i];
                u = i;
            }
        }

        visited[u] = true;

        for (int j = 0; j < v; j++) 
        {
            if (adj[u][j] != INF && !visited[j] && adj[u][j] < key[j]) 
            {
                parent[j] = u;
                key[j] = adj[u][j];
            }
        }
    }
    
    cout << "\nEdge \t\tWeight\n";
    for (int i = 1; i < v; i++) {
        cout << city[parent[i]] << " - " << city[i] << " \t" << adj[parent[i]][i] << " km\n";
    }

    // Calculate the total distance
    for (int i = 1; i < v; i++) 
    {
        totalDist += adj[parent[i]][i];
    }
}

// Function to display the shortest travel path using the MST

void MST::shortestPath() 
{
    cout << "\nFinal Interview Travel Path (Shortest Path):\n\n";
    cout << city[0]; // Start from first city

    for (int i = 1; i < v; i++) 
    {
        cout << " -> " << city[i];
    }

    cout << "\n\nTotal Minimum Distance: " << totalDist << " km.\n";
}

int main() 
{
    MST obj;
    obj.create();
    obj.findMST();
    obj.shortestPath();
    return 0;
}
