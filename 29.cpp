//
// Created by Manas Singh on 13-05-2024.
//
#include <vector>
#include <bitset>
#include <iostream>

#define MAX_SIZE 1000000ll
using namespace std;

class HashTable {
private:
    vector<int> hashTable;
    vector<short> occupied;
    bitset<MAX_SIZE> isNotPrime;
    int size, keyPresent, PRIME;

    void setStieve() {
        isNotPrime[0] = isNotPrime[1] = true;
        for (long long i = 2; i * i <= MAX_SIZE; i++)
            if (!isNotPrime[i])
                for (long long j = i * i; j < MAX_SIZE; j += i)
                    isNotPrime[j] = true;
    }

    int inline hash1(int value) const {
        return value % size;
    }

    int inline hash2(int value) const {
        return PRIME - (value % PRIME);
    }

public:
    explicit HashTable(int size) : keyPresent(0), size(size), hashTable(vector<int>(size)), occupied(vector<short>(size, 0)) {
        setStieve();
        PRIME = size - 1;
        while (isNotPrime[PRIME])
            PRIME--;
    }


    bool inline isFull() const {
        return keyPresent == size;
    }

    short insert(int value) {
        if (isFull()) {
            cout << "HashTable full." << endl;
            return -1;
        }
        int probe = hash1(value), offset = hash2(value);
        while (occupied[probe] == 1)
            probe = (probe + offset) % size;
        hashTable[probe] = value;
        occupied[probe]=1;
        keyPresent++;
        return 1;
    }

    bool search(int value) {
        int probe = hash1(value), offset = hash2(value), start = probe;
        do {
            if (occupied[probe] == 0)
                break;
            if (occupied[probe] == 1 && hashTable[probe] == value)
                return true;
            probe = (probe + offset) % size;
        } while (probe != start);
        return false;
    }

    short remove(int value) {
        if (!search(value))
            return -1;
        int probe = hash1(value), offset = hash2(value);
        while (occupied[probe] != 1 || hashTable[probe] != value)
            probe = (probe + offset) % size;
        occupied[probe] = -1;
        keyPresent--;
        return 1;
    }
};

int main() {
    int size, choice, value;
    cout << "Enter the size of the HashTable: ";
    cin >> size;
    HashTable hashTable(size);

    while (true) {
        cout << "\n1. Insert Key\n";
        cout << "2. Remove Key\n";
        cout << "3. Search Key\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> value;
                if (hashTable.insert(value) == -1)
                    cout << "Failed to insert value (table might be full).\n";
                else
                    cout << "Value inserted successfully.\n";
                break;
            case 2:
                cout << "Enter the value to remove: ";
                cin >> value;
                if (hashTable.remove(value) == -1)
                    cout << "Value not found or cannot be removed.\n";
                else
                    cout << "Value removed successfully.\n";
                break;
            case 3:
                cout << "Enter the value to search: ";
                cin >> value;
                if (hashTable.search(value))
                    cout << "Value found.\n";
                else
                    cout << "Value not found.\n";
                break;
            case 4:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice, please choose again.\n";
                break;
        }
    }
}