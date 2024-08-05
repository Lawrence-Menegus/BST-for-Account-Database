// Name: Lawrence Menegus
// Date: 11/12/23 
// Course:  Data Structures and Algorithms
// Description: This program will import the database file: account.dat we will use this information to create a Binary
// Search Tree. Then we can retrieve the record that is in the data base by searching for the 
// Account ID and the Record Number Then print out the results. We will check if a number is 
// in the database or not and printout the outcome. 


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Define the structure for an index entry
struct IndexEntry
{
    // Account identifier (key)
    int acctID;

    // Record number
    long recNum;

    // First and Last name along with Balance
    string first;
    string last;
    double balance;

    // For Binary Search Tree
    IndexEntry* left;
    IndexEntry* right;
};

// Function prototypes
void insert(IndexEntry*& node, int ID, long num, const string& firstName, const string& lastName, double balanced);
IndexEntry* treeSearch(IndexEntry* node, int target);
void printTree(IndexEntry* node);

// Main function
int main()
{
    cout << "Enter Account ID: ";
    int input;
    cin >> input;

    // Set root to null
    IndexEntry* root = nullptr;

    // Opens file
    ifstream file("accounts.dat");

    // Runs if File can not be found
    if (!file)
    {
        cout << "Error Opening File " << endl;
        return 1;
    }

    // Removes the string part of the data file
    string removal;
    getline(file, removal);

    long id;
    int recNum;
    string first, last;
    double balance;

    // If file exists, import values into Binary Search Tree
    while (file) {
        file >> recNum >> id >> first >> last >> balance;
        insert(root, id, recNum, first, last, balance);
    }

    // Creates a new node from the user's input
    IndexEntry* newishNode = treeSearch(root, input);

    // If the node is not found in Binary search tree, print out this
    if (!newishNode)
    {
        cout << "Matched Record Number is -1" << endl;
        cout << "\n Corresponding account Record from the database file: \n " << endl;
        cout << "\t\tAccount ID is not in Data \n" << endl;
    }

    // If found, print out this
    else
    {
        cout << "Matched Record Number is " << newishNode->recNum << endl;
        cout << "\n  Corresponding account Record from the database file: \n " << endl;
        printTree(newishNode);
    }

    // Pauses the program until the user continues it
    system("pause");

}

// Insert Function
void insert(IndexEntry*& node, int ID, long num, const string& firstName, const string& lastName, double balanced)
{
    // Compares if the node is Null
    if (node == nullptr)
    {
        // Creates a new node
        node = new IndexEntry;

        // Creates a new node from struct
        node->acctID = ID;
        node->recNum = num;
        node->first = firstName;
        node->last = lastName;
        node->balance = balanced;

        // Sets left and right nodes to null pointers
        node->left = nullptr;
        node->right = nullptr;
    }

    // If account ID is less than node account ID, insert in the left part of the binary tree
    else if (ID < node->acctID)
    {
        insert(node->left, ID, num, firstName, lastName, balanced);
    }

    // If not less than, insert in the right part of the binary tree.
    else
    {
        insert(node->right, ID, num, firstName, lastName, balanced);
    }
}

// Binary Search Function
IndexEntry* treeSearch(IndexEntry* node, int target)
{
    // Compares if the node is equal to null, then returns the node
    if (node == nullptr)
    {
        return node;
    }

    // Compares if the target is equal to the node's account ID, then returns the node
    else if (target == node->acctID)
    {
        return node;
    }

    // If the target is less than the account ID value, search in the left of the binary tree
    else if (target < node->acctID)
    {
        return treeSearch(node->left, target);
    }

    // Search in the right of the binary tree to reach the target value
    return treeSearch(node->right, target);
}

// Print the results Function
void printTree(IndexEntry* node)
{
    printf("%-12s%-12s%-12s%-12s%-12s\n", "Record#", "AccountID", "FirstName", "LastName", "Balance");
    printf("%-12ld%-12d%-12s%-12s%-12.2f\n", node->recNum, node->acctID, node->first.c_str(), node->last.c_str(), node->balance);
    cout << endl;
}