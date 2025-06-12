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

    void addFirst(Item item){
     if(isEmpty())
        tail=head=new Node<Item>(item,nullptr);
    else
        head=new Node<Item>(item,head);

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

    template<class Variable>
    Item* find(Variable variable){
    if(isEmpty())
        return nullptr;
    Node<Item> *curr=head;

    while(curr!=nullptr)
    {
        if(curr->item==variable)
            return &curr->item;
        curr=curr->next;
    }
    return nullptr;
    }

    template<class Variable>
    bool remove(Variable variable) {
    if (isEmpty()) {
        return false;
    }

    if (head->item==variable)
        return removeFirst();

    Node<Item>* prev = head;
    Node<Item>* curr = head->next;

    while (curr != nullptr) {
        if (curr->item==variable){
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

    void push(Item item){
    singleLinkedList.addFirst(item);
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

    template<class Variable>
    bool remove(Variable variable) {
    if (isEmpty()) {
        return false;
    }

    if (head->item==variable) {
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
        if (curr->item==variable) {
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

    template<class Variable>
    Item* find(Variable variable){
    if(isEmpty())
        return nullptr;
    DoubleNode<Item>* curr=head;
    while(curr!=nullptr)
        {
        if(curr->item==variable)
            return &curr->item;
        curr=curr->next;
        }
    return nullptr;
    }
};

template<class Key,class Item>
struct HashNode{
Key key;
Item item;

HashNode(Key key,Item item):key(key),item(item) {}

bool operator==(Key key){
return this->key==key;
}

};

template<class Key,class Item>
class OpenHash{

int capacity,length;
SingleLinkedList<HashNode<Key,Item>> *array;

   int hashCode(int key){
       return key%capacity;
   }

   int hashCode(string key){
       int count=0;

       for (char c : key)
           count+=c;

       return count%capacity;
    }


public:
    OpenHash(int capacity=20):capacity(capacity),length(0) {array=new SingleLinkedList<HashNode<Key,Item>>[capacity]; }
     ~OpenHash()     {delete[] array;}

    void insert(Key key,Item item){
       int index=hashCode(key);
       array[index].addLast(HashNode<Key,Item>(key,item));
       length++;
    }

    void print(){
    for(int i=0;i<size;i++)
        if(!array[i].isEmpty())
            array[i].print();
    }


    Item* operator[](Key key){
    int index=hashCode(key);
    return &array[index].find(key)->item;
    }


    bool remove(Key key){
    int index=hashCode(key);
    bool result=array[index].remove(key);
    if(result)
        length--;
    return result;
    }

    int size(){
    return length;     
    }

    bool isEmpty(){
    return length==0;
    }

};






//Making Tree DataStructure 
//
//template <typename T> class TreeNode
//{
//public:
//
//    T* Data;
//    TreeNode <T>* FChild;
//    TreeNode <T>* Sibling;
//
//
//    TreeNode(T Data, TreeNode <T>* FChild, TreeNode <T>* Sibling)
//    {
//        this->Data = Data;
//        this->FChild = FChild;
//        this->Sibling = Sibling;
//    }
//
//    TreeNode()
//    {
//        this->Data = nullptr;
//        this->FChild = nullptr;
//        this->Sibling = nullptr;
//
//    }
//
//};
//
//template <typename T> class Tree
//{
//public:
//
//    TreeNode <T>* Root;
//
//
//    Tree(TreeNode <T>* Root)
//    {
//        this->Root = Root;
//    }
//
//    Tree()
//    {
//        this->Root = nullptr;
//    }
//
//    void AddToParent(TreeNode <T>* Parent, T Value)
//    {
//        if (Parent == nullptr)
//            return;
//
//        TreeNode <T>* NewNode = new TreeNode<T>();
//
//        if (Parent->FChild == nullptr)
//        {
//            Parent->FChild = NewNode;
//            NewNode->Data = Value;
//            return;
//        }
//
//        TreeNode <T>* Temp = Parent.FChild;
//
//        while (Temp->Sibling != nullptr)
//        {
//            Temp = Temp->Sibling;
//        }
//
//        Temp->Sibling = NewNode;
//        NewNode->Data = Value;
//
//    }
//
//    TreeNode Search(TreeNode <T>* Parent, T Value)
//    {
//        if (Parent == nullptr)
//            return nullptr;
//
//        if (Parent->Data == Value)
//        {
//            return Parent;
//        }
//
//        TreeNode <T>* ChildResult = Search(Parent->FChild, Value);
//
//        if (ChildResult != nullptr)
//            return ChildResult;
//
//        return Search(Parent->Sibling, Value);
//
//    }
//
//
//    TreeNode Print(TreeNode <T>* Parent)
//    {
//        if (Parent == nullptr)
//            return nullptr;
//
//        TreeNode <T>* ChildResult = Print(Parent->FChild, Value);
//
//        if (ChildResult != nullptr)
//            return ChildResult;
//
//        return Search(Parent->Sibling, Value);
//
//    }
//
//
//
//
//};



//Making Closed Hashing DataStructure


template <typename Key, typename Item>
class KeyItemNode
{
public:

    Key* key;
    Item* item;


    KeyItemNode(Key k, Item i)
    {
        this->key = k;
        this->item = i;
    }


    KeyItemNode()
    {
        this->key = nullptr;
        this->item = nullptr;
    }

    bool isEmpty()
    {
        return this->item == nullptr;
    }

};



template <typename Key, typename Item>
class ClosedHash
{
    int Size;
    KeyItemNode<Key, Item>* array;

    int Hash(Key key)
    {
        int Count = 0;

        if (typeid(key) == typeid(string))
        {
            for (char c : key)
                Count += (short)c;
        }

        else Count = key;

        return Count % this->Size;
    }

public:

    int Size()
    {
        return this->Size;
    }

    ClosedHash(int Size)
    {
        this->Size = Size;
        Array = new KeyItemNode <Key, Item>[Size];
    }

    ~ClosedHash()
    {
        delete[]array;
    }

    void Add(Key key, Item item)
    {
        int Index = Hash(Key);


        while (!array[Index].isEmpty())
        {
            if (Index == Size - 1)
                Index = -1;
            Index = Index + 1;
        }

        array[Index] = new KeyItemNode <Key, Item>(key, item);
    }


    Item* Find(Key key) {
        int index = Hash(key);

        while (!(key == array[index].key))
        {

            if (Index == Size - 1)
                Index = -1;

            index++;
        }

        return array[index].item;
    }


    KeyItemNode <Key, Item>* Find(Key key) {
        int index = Hash(key);

        while (!(key == array[index].key))
        {

            if (Index == Size - 1)
                Index = -1;

            index++;
        }

        return array[index];
    }


    bool remove(Key key) {
        int index = Hash(key);

        KeyItemNode <Key, Item>* Itm = Find(key);

        if (Itm->isEmpty())
        {
            return false;
        }

        Itm->item = nullptr;
        Itm->key = nullptr;

        return true;
    }


};

















#endif // DATASTRUCTURES_H
