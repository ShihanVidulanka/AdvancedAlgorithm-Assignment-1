#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include "BST.h"
#include "SplayTree.h"
#include "RBTree.h"
#include <vector>

using namespace std;
using namespace std::chrono;

// tree search 
template <typename TreeType>
void insertData(TreeType &tree, const string &setName, const string &fileName)
{
    // Construct the file path
    string filePath = "data/data/insert/" + setName + "/" + fileName + ".txt";

    // Open the data file for reading
    ifstream dataFile(filePath);

    // Check if the file opened successfully
    if (!dataFile.is_open())
    {
        cerr << "Error: Unable to open file " << filePath << endl;
        return;
    }

    // Start the timer

    // Read data from the file and insert into the tree
    string line;
    int count = 0;
    auto start = high_resolution_clock::now();
    
    while (getline(dataFile, line))
    {
        stringstream iss(line);
        string token;
        while (getline(iss, token, ','))
        {
            long long int num;
            try
            {
                    num = stoll(token); // Convert string to integer
            }
            catch (const std::out_of_range &e)
            {
                cerr << "Error: Integer out of range!" << endl;
                continue; // Skip this token
            }
            // Assuming the value is the same as the key
            tree.put(num, num);
            count++;
            // cout << "Number of Inputs : " << count << endl;
        }
    }
    cout << "Number of Inputs : " << count << endl;

    // Stop the timer
    auto stop = high_resolution_clock::now();

    // Calculate the elapsed time in milliseconds
    auto duration = duration_cast<microseconds>(stop - start);

    // Print the time taken
    cout << "Time taken to insert data from " << setName << "-" << fileName << ": " << duration.count() << " microseconds" << endl;

    // Close the file
    dataFile.close();
}

// tree search 
template <typename TreeType>
void searchData(TreeType &tree, const string &setName, const string &fileName)
{
    // Construct the file path
    string filePath = "data/data/search/" + setName + "/" + fileName + ".txt";

    // Open the data file for reading
    ifstream dataFile(filePath);

    // Check if the file opened successfully
    if (!dataFile.is_open())
    {
        cerr << "Error: Unable to open file " << filePath << endl;
        return;
    }

    // Start the timer

    // Read data from the file and search from the tree
    string line;
    int count = 0;
    auto start = high_resolution_clock::now();
    
    while (getline(dataFile, line))
    {
        stringstream iss(line);
        string token;
        while (getline(iss, token, ','))
        {
            long long int num;
            try
            {
                    num = stoll(token); // Convert string to integer
            }
            catch (const std::out_of_range &e)
            {
                cerr << "Error: Integer out of range!" << endl;
                continue; // Skip this token
            }
            // Assuming the value is the same as the key
            tree.contains(num);
            count++;
            // cout << "Number of Inputs : " << count << endl;
        }
    }
    cout << "Number of Searchs : " << count << endl;

    // Stop the timer
    auto stop = high_resolution_clock::now();

    // Calculate the elapsed time in milliseconds
    auto duration = duration_cast<microseconds>(stop - start);

    // Print the time taken
    cout << "Time taken to Search data from " << setName << "-" << fileName << ": " << duration.count() << " microseconds" << endl;

    // Close the file
    dataFile.close();
}

// delete tree 
template <typename TreeType>
void deleteData(TreeType &tree, const string &setName, const string &fileName)
{
    // Construct the file path
    string filePath = "data/data/delete/" + setName + "/" + fileName + ".txt";

    // Open the data file for reading
    ifstream dataFile(filePath);

    // Check if the file opened successfully
    if (!dataFile.is_open())
    {
        cerr << "Error: Unable to open file " << filePath << endl;
        return;
    }

    // Start the timer

    // Read data from the file and search from the tree
    string line;
    int count = 0;
    auto start = high_resolution_clock::now();
    
    while (getline(dataFile, line))
    {
        stringstream iss(line);
        string token;
        while (getline(iss, token, ','))
        {
            long long int num;
            try
            {
                    num = stoll(token); // Convert string to integer
            }
            catch (const std::out_of_range &e)
            {
                cerr << "Error: Integer out of range!" << endl;
                continue; // Skip this token
            }
            // Assuming the value is the same as the key
            tree.del(num);
            count++;
            // cout << "Number of Inputs : " << count << endl;
        }
    }
    cout << "Number of Deletes : " << count << endl;

    // Stop the timer
    auto stop = high_resolution_clock::now();

    // Calculate the elapsed time in milliseconds
    auto duration = duration_cast<microseconds>(stop - start);

    // Print the time taken
    cout << "Time taken to Delete data from " << setName << "-" << fileName << ": " << duration.count() << " microseconds" << endl;

    // Close the file
    dataFile.close();
}

int main() {
    // Define sets and data names
    vector<string> sets = {"set1", "set2"};
    vector<string> data = {"data_1", "data_2", "data_3"};

    // Iterate over each tree type
        // Iterate over each set
        for (const auto& setName : sets) {
            // Clear the tree before processing each set
            // Iterate over each data segment
            for (const auto& dataName : data) {

                cout << "Data - " << setName << " - " << dataName << "===============================" << endl;


                cout << "\nBST: " << endl;

                BST bst;
                insertData(bst, setName, dataName);
                searchData(bst, setName, dataName);
                deleteData(bst, setName, dataName);

                cout << "\nSplay Tree: " << endl;

                SplayTree splayTree;
                insertData(splayTree, setName, dataName);
                searchData(splayTree, setName, dataName);
                deleteData(splayTree, setName, dataName);
                
                RBTree rbTree;

                cout << "\nRed Black Tree: " << endl;

                insertData(rbTree, setName, dataName);
                searchData(rbTree, setName, dataName);
                deleteData(rbTree, setName, dataName);

                cout << "\n" << endl;


            }
        }

    return 0;
}

