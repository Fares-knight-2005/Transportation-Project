#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H
#include <iostream>

using namespace std;

template<class Item>
struct Node{
     Item item;
     Node *next;
     Node(Item item,Node *next):item(item),next(next){}
};

template<class Item>
class SingleLinkedList{

Node<Item> *head,*tail;
int length;

public:
    SingleLinkedList():head(nullptr),tail(nullptr),length(0) {}

    ~SingleLinkedList(){
        Node<Item>* curr = head;
        while (curr != nullptr) {
            Node<Item>* next = curr->next;
            delete curr;
            curr = next;
        }
    }

    bool isEmpty(){
    return head==nullptr;
    }

    void addLast(Item item){
    if(isEmpty())
        tail=head=new Node<Item>(item,nullptr);
    else
        tail=tail->next=new Node<Item>(item,tail);
    ++length;
    }

    Item *removeFirst(){

    if(isEmpty())
        return nullptr;

    Item *removeItem=&head->item;
    head=head->next;
    --length;
    return removeItem;
    }

    int size(){
    return length;
    }
};

template<class Item>
class Queue{

SingleLinkedList<Item> singleLinkedList;

public:

    void enqueue(Item item){
    singleLinkedList.addLast(item);
    }

    Item *dequeue(){
    return singleLinkedList.removeFirst();
    }

    int size(){
    return singleLinkedList.size();
    }
};

template<class Item>
struct DoubleNode{
        Item item;
        DoubleNode* next;
        DoubleNode* previous;

        DoubleNode(Item item, DoubleNode* next, DoubleNode* previous):
            item(item), next(next), previous(previous) {}
};

template<class Item>
class DoubleLinkedList {
private:

    DoubleNode<Item>* head;
    DoubleNode<Item>* tail;
    int length;

public:
    DoubleLinkedList(): head(nullptr), tail(nullptr), length(0) {}

    ~DoubleLinkedList() {
        DoubleNode<Item>* curr = head;
        while (curr != nullptr) {
            DoubleNode<Item>* next = curr->next;
            delete curr;
            curr = next;
        }
    }

    bool isEmpty(){
        return head == nullptr;
    }

    int size(){
        return length;
    }

    void addFirst(Item item) {
        if (isEmpty())
            head = tail = new DoubleNode<Item>(item, nullptr, nullptr);
        else
            head=head->previous= new DoubleNode<Item>(item, head, nullptr);

        length++;
    }

    void addLast(Item item) {
        if (isEmpty())
            head = tail = new DoubleNode<Item>(item, nullptr, nullptr);
        else
            tail=tail->next = new DoubleNode<Item>(item, nullptr, tail);

        length++;
    }

    void add(int index, Item item) {
        if (index < 0 || index > length) {
            throw out_of_range("Index out of bounds");
        }

        if (index == 0) {
            addFirst(item);
            return;
        }

        if (index == length) {
            addLast(item);
            return;
        }

        DoubleNode<Item>* curr = head;
        for (int i = 0; i < index - 1; i++) {
            curr = curr->next;
        }

        DoubleNode<Item>* newNode = new Node<Item>(item, curr->next, curr);
        curr->next->previous = newNode;
        curr->next = newNode;
        length++;
    }

    void remove(int index) {

        DoubleNode<Item>* toDelete;
        if (index == 0) {
            toDelete = head;
            head = head->next;
            head->previous = nullptr;
            if(size()==1)
                tail=nullptr;
        } else if (index == length - 1) {
            toDelete = tail;
            tail = tail->previous;
            tail->next = nullptr;
            if(size()==1)
                head=nullptr;
        } else {
            DoubleNode<Item>* curr = head;
            for (int i = 0; i < index; i++) {
                curr = curr->next;
            }
            toDelete = curr;
            curr->previous->next = curr->next;
            curr->next->previous = curr->previous;
        }

        delete toDelete;
        length--;
    }

    void print(){
        DoubleNode<Item>* curr = head;
        while (curr != nullptr) {
            cout <<curr->item<<'\n';
            cout <<"---------------------\n";
            curr = curr->next;
        }
        cout<<endl;
    }

    Item* find(Item item){
    if(isEmpty())
        return nullptr;
    DoubleNode<Item>* curr=head;
    while(curr!=nullptr)
        {
        if(curr->item==item)
            return &curr->item;
        curr=curr->next;
        }
    return nullptr;
    }
};


#endif // DATASTRUCTURES_H
