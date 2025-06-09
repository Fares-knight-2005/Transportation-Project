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
        tail=tail->next=new Node<Item>(item,nullptr);

    ++length;
    }

    bool removeFirst(){

    if(isEmpty())
        return false;

    Node<Item> *temp=head;
    head=head->next;
    delete temp;
    --length;
    return true;
    }

    void print(){
    Node<Item> *curr=head;

    while(curr!=nullptr)
    {
    cout<<curr->item<<endl;
    cout<<"--------------------\n";
    curr=curr->next;
    }

    }

    template<class Value>
    Item* find(Value value){
    if(isEmpty())
        return nullptr;
    Node<Item> *curr=head;

    while(curr!=nullptr)
    {
        if(curr->item==value)
            return &curr->item;
        curr=curr->next;
    }
    return nullptr;
    }

    template<class Value>
    bool remove(Value value) {
    if (isEmpty()) {
        return false;
    }

    if (head->item==value)
        return removeFirst();

    Node<Item>* prev = head;
    Node<Item>* curr = head->next;

    while (curr != nullptr) {
        if (curr->item==value){
            prev->next=curr->next;

            if (curr==tail)
                tail=prev;
            delete curr;
            length--;
            return true;
        }

        prev = curr;
        curr = curr->next;
    }

    return false;
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

    bool dequeue(){
    return singleLinkedList.removeFirst();
    }

    bool isEmpty(){
    return singleLinkedList.isEmpty();
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
            head=tail=new DoubleNode<Item>(item, nullptr, nullptr);
        else
            head=head->previous=new DoubleNode<Item>(item, head, nullptr);

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

        DoubleNode<Item>* newNode =new DoubleNode<Item>(item, curr->next, curr);
        curr->next->previous = newNode;
        curr->next = newNode;
        length++;
    }

    template<class Value>
    bool remove(Value value) {
    if (isEmpty()) {
        return false;
    }

    if (head->item==value) {
        DoubleNode<Item>* temp=head;
        head=head->next;

        if (head!=nullptr)
            head->previous=nullptr;
        else
            tail=nullptr;

        delete temp;
        length--;
        return true;
    }

    DoubleNode<Item>* curr=head;

    while (curr!=nullptr) {
        if (curr->item==value) {
            curr->previous->next=curr->next;

            if (curr->next!=nullptr)
                curr->next->previous=curr->previous;
            else
                tail=curr->previous;

            delete curr;
            length--;
            return true;
        }
        curr=curr->next;
    }

    return false;
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

    template<class Value>
    Item* find(Value value){
    if(isEmpty())
        return nullptr;
    DoubleNode<Item>* curr=head;
    while(curr!=nullptr)
        {
        if(curr->item==value)
            return &curr->item;
        curr=curr->next;
        }
    return nullptr;
    }
};

template<class Key,class Item>
class OpenHash{

int size;
SingleLinkedList<Item> *array;

   int hashCode(int key){
       return key%size;
   }

   int hashCode(string key){
       int count=0;

       for (char c : key)
           count+=c;

       return count%size;
    }


public:
    OpenHash(int size=20):size(size) {array=new SingleLinkedList<Item>[size]; }

    void insert(Key key,Item item){
       int index=hashCode(key);
       array[index].addLast(item);
    }

    void print(){
    for(int i=0;i<size;i++)
        if(!array[i].isEmpty())
            array[i].print();
    }

    template<class Value>
    Item* find(Key key,Value value){
    int index=hashCode(key);
    return array[index].find(value);
    }

    template<class Value>
    bool remove(Key key,Value value){
    int index=hashCode(key);
    bool result=array[index].remove(value);
    if(result)
        size--;
    return result;
    }

};

#endif // DATASTRUCTURES_H
