#include <iostream>
#include <vector>

using namespace std;

class Node {
    public:
    string key;
    int value;
    Node* next;

    Node(string key, int value) {
        this->key = key;
        this->value = value;
        next = nullptr;
    }
};

class HashTable {
    private:
    static const int SIZE = 7;
    Node* dataMap[SIZE];

    int hash(string key) {
        int hash = 0;
        for (int i = 0; i < key.length(); i++) {
            int asciiValue = int(key[i]);
            hash = (hash + asciiValue * 23) % SIZE;
        }
        return hash;
    }

    public:
    HashTable() {
        for (int i = 0; i < SIZE; i++) {
            dataMap[i] = nullptr;
        }
    }

    ~HashTable() {
        for (int i = 0; i < SIZE; i++) {
            Node* head = dataMap[i];
            while (head) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
        }
    }

    void printTable() {
        for (int i = 0; i < SIZE; i++) {
            cout << i << ":";
            if (dataMap[i]) {
                Node* temp = dataMap[i];
                while (temp) {
                    cout << " {" << temp->key << ", " << temp->value << "} ";
                    temp = temp->next;
                }
            }
            cout << endl;
        }
    }

    void set(string key, int value) {
        int index = hash(key);
        Node* newNode = new Node(key, value);
        if (dataMap[index] == nullptr) {
            dataMap[index] = newNode;
        } else {
            Node* temp = dataMap[index];
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    int get(string key) {
        int index = hash(key);
        Node* temp = dataMap[index];
        while (temp != nullptr) {
            if (temp->key == key) return temp->value;
            temp = temp->next;
        }
        return -1; // Return -1 if the key is not found
    }

    vector<string> keys() {
        vector<string> allKeys;
        for (int i = 0; i < SIZE; i++) {
            Node* temp = dataMap[i];
            while (temp != nullptr) {
                allKeys.push_back(temp->key);
                temp = temp->next;
            }
        }
        return allKeys;
    }
};

int main() {
    HashTable* myHashTable = new HashTable();

    myHashTable->set("paint", 20);
    myHashTable->set("bolts", 40);
    myHashTable->set("nails", 100);
    myHashTable->set("tile", 50);
    myHashTable->set("lumber", 80);

    vector<string> myKeys = myHashTable->keys();

    for (auto key : myKeys) {
        cout << key << " ";
    }
    cout << endl;

    delete myHashTable; // Clean up memory
    return 0;
}
