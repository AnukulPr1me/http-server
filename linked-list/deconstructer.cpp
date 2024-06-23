#include <iostream>

using namespace std;


class Node {
  public:
    int value;
    Node* next;

    Node(int value) {
      this->value = value;
      next = nullptr;
    }

};


class LinkedList {
  private:
    Node* head;
    Node* tail;
    int length;

  public:

  LinkedList(int value) {
    Node* newNode = new Node(value);
    head = newNode;
    tail = newNode;
    length = 1;
  }
    //deconstructer
  ~LinkedList() {
    Node* temp = head;
    head = head->next;
    delete temp;
    temp = head;
    
  }

  void printList() {
    Node* temp = head;
    while(temp) {
      cout << temp->value;
      temp = temp->next;
    }
  }
  void getHead() {
    cout << "Head of LinkedList: " << head->value << endl;
  }
  void getTail() {
    cout << "Tail of LinkedList: " << tail->value << endl;
  }
  void getLength() {
    cout << "Length: " << length << endl;
  }
};

int main() {
  LinkedList* myLinkedList = new LinkedList(4);

  myLinkedList->getHead();
  myLinkedList->getTail();
  myLinkedList->getLength();
  myLinkedList->printList();
}

