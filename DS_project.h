#ifndef DS_PROJECT_H
#define DS_PROJECT_H
#include <iostream>
#include <string>
#include <set>
#include <queue>
using namespace std;

int parts_created;
// ------------------------------------- Spare Parts -------------------------------------
class SparePart{
// data members
private:
    string part_name;               // variable to hold the name of the part
    int part_number;                // variable to hold the number of the part
    double cost;                    // variable to hold the cost of the part
    int existing_parts;             // variable to hold the number of existing parts of this part
    int part_order;                 // variable to hold the order of the part       e.g. 0, 1, 2, 3, 4, 5...

// methods
public:
    SparePart();                    // default constructor

    // setters
    void set_part_name(string);     // name setter
    void set_part_number(int);      // part's number setter
    void set_cost(double);          // cost's setter
    void set_existing_parts(int);   // existing parts setter

    // getters
    string get_part_name();         // name's getter
    int get_part_number();          // part's number getter
    double get_cost();              // cost getter
    int get_existing_parts();       // existing parts getter
    int get_identifier();           // unique identifier getter (part number)

    // data visualisation and manipulation
    void get_data();                // a method to input all the data members of the object
    void put_data();                // a method to output all the data members of the object
    void modifydata();               //a method to modify data members

};

// ------------------------------------- Linked List Node -------------------------------------

template <class T>
class Node {
private:
    T data;
    Node<T> *next;

public:
    Node(T new_data) : data(new_data), next(nullptr) {}

    Node(T new_data, Node<T>* new_next) : data(new_data), next(new_next) {}

    void set_data(T new_data);
    void set_next(Node<T> *new_next);

    T get_data();
    Node<T> *get_next();

};

// ------------------------------------- Linked List -------------------------------------

template <class T>
class LinkedList{
public:
    Node<T> * head;
    Node<T> * tail;

    LinkedList();

    void addNode(T new_data);
    void deleteNode(int identifier);
    void printNodes();
    int is_empty();

};


// ------------------------------------- Supplier -------------------------------------
class Supplier {
private:
    string name;
    int code;
    string address;
    string phone_number;
    string email;

public:
    void set_name(string new_name);
    void set_code(int new_code);
    void set_address(string new_address);
    void set_phone(string new_phone);
    void set_email(string new_email);
    

    string get_name();
    int get_code();
    string get_address();
    string get_number();
    string get_email();
    int get_identifier();

    void get_data();
    void put_data();
    void modifydata();

};


// ------------------------------------- Binary Tree Node -------------------------------------

template <class T, class F>
class BinaryTreeNode{
// data members
private:
    T *data;                             // an object that contains the data of the supplier or the spare part
    LinkedList<F> *connected_items;      // a linked list to store the connected suppliers - if it's a spare part
                                        // or the connected spare parts - if it's a supplier
    BinaryTreeNode<T, F> *left;            // a pointer to the left child in the tree
    BinaryTreeNode<T, F> *right;           // a pointer to the right child in the tree

// methods
public:
    // default constructor
    BinaryTreeNode();

    // setters
    void set_left(BinaryTreeNode<T, F> *new_left);         // a method to set the value of the left pointer
    void set_right(BinaryTreeNode<T, F> *new_right);       // a method to set the value of the right pointer
    void set_data(T * new_data);                          // a method to set the whole data in the list
    void set_connected_items(LinkedList<F> * new_connected_items);  // a method to set the whole parts in the linked list


    // getters
    BinaryTreeNode<T, F> * get_left();                     // a method to return the value of the left pointer
    BinaryTreeNode<T, F> * get_right();                    // a method to return the value of the right pointer
    T * get_data();                                       // a method to return the object that contains the data
                                                        // of the supplier or the spare part
    LinkedList<F> * get_connected_items();                // a method to return the value of the list of connected items
};


// ------------------------------------- Binary Tree -------------------------------------
template <class T, class F>
class DataTree{
private:
    BinaryTreeNode<T, F> * root;                                                           // a variable to hold the value of the root

public:
    DataTree();                                                                         // a default constructor

    BinaryTreeNode<T, F> * get_root();                                                     // root getter

    void set_root(BinaryTreeNode<T, F> *new_root);                                         // root setter

    bool insert_recursive(BinaryTreeNode<T, F> new_data, BinaryTreeNode<T, F> *start);        // a method to insert a new node in the tree
    BinaryTreeNode<T, F> * delete_node(BinaryTreeNode<T, F> *root, int identifier);           // a method to delete a node with certain identifier
    void in_order_traversal(BinaryTreeNode<T, F>*root);                                    // a method to print the content of all nodes
    BinaryTreeNode<T, F> * search(BinaryTreeNode<T, F> * root, int identifier);                // a method to search for a specific item in the Tree
};
//----------------------------------------Queue-----------------------------
template <class T>
class Q_Node {
public:
    T data;
    Q_Node<T>* next;

    Q_Node(T value );
};

template <class T>
class Queue {
private:
    Q_Node<T>* front;
    Q_Node<T>* rear;

public:
    Queue();

    void enqueue(T value);

    // Getter: Dequeue (remove) the front element from the queue
    T dequeue() ;

    // Getter: Get the front element without removing it
    T peek();
//Display: display all elements in the queue 
    void Display();

    // Getter: Check if the queue is empty
    bool isEmpty();
   


};
//--------------------------------------Stack---------------------------------------------

template <class T>
class S_Node {
public:
    T data;
    S_Node <T>* next;

 S_Node (T value) ;
};

template <class T>
class Stack 
{
private:

 S_Node<T>* Top;
public:
Stack ();


void Push (T data);



void pop();


void peek();
void displayStack();
};




#endif