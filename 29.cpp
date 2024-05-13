//
// Created by Manas Singh on 13-05-2024.
//
#include <vector>

using namespace std;

class HashTable {
private:
    vector<int> hashTable;
    vector<bool> occupied;
    int n;
public:
    HashTable(int n) {
        hashTable.resize(n);
        occupied.resize(n, false);
    }
    insert(int key){

    }
};