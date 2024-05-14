//linear hashing
class LinearProbing {
public:
    vector<int> hashTable;
    int curr_size, max_size;

    LinearProbing(int s) : max_size(s), curr_size(0), hashTable(vector<int>(s, -1)) {}

    int hashFunction(int key) {
        return key % max_size;
    }

    void insert(int key) {
        if (curr_size >= max_size)
            return;

        int index = hashFunction(key);
        while (hashTable[index] != -1) {
            index = (index + 1) % max_size;
        }
        hashTable[index] = key;
        curr_size++;
    }
};

//quadratic hashing
class QuadraticProbing {
public:
    vector<int> hashTable;
    int curr_size, max_size;

    QuadraticProbing(int s) : max_size(s), curr_size(0), hashTable(vector<int>(s, -1)) {}

    int hashFunction(int key) {
        return key % max_size;
    }

    void insert(int key) {
        if (curr_size >= max_size)
            return;

        int index = hashFunction(key);
        int i = 0;
        while (hashTable[(index + i*i) % max_size] != -1) {
            i++;
        }
        hashTable[(index + i*i) % max_size] = key;
        curr_size++;
    }
};
