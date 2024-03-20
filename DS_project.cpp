#include "DS_project.h"

//Generating code function O(Log (n))
queue<int>numbers_waiting{{500}};
set<int>numbers_used{1, 1000};

int generate_code()
{
    int current = numbers_waiting.front();                                      // the current code to be returned
    // before returning it, we have to first insert its children to the queue
    auto after = numbers_used.upper_bound(current);               // getting the position of the number just greater than it in the set
    int upper = *after, lower = *--after;                                       // upper (number greater than current) will be the value at position called "after"
                                                                                // lower (number less than it) will be the value at the position before "after"
    int right_child = (current + upper)/2, left_child = (lower + current)/2;    // right child will be the value in the middle of "current" and "upper"
                                                                                // left child will be the value in the middle of "current" and "lower"
    numbers_waiting.push(right_child);                                       // inserting the left and right child at the queue to be processed later
    numbers_waiting.push(left_child);
    numbers_waiting.pop();                                                      // deleting "current" from the queue because we are done with it
    numbers_used.emplace(current);                                           // inserting "current" at the set because we used this code in order to avoid duplicates

    return current;                                                             // returning "current" to be the code
}


// ------------------------------------- Helper functions -------------------------------------
template <class T, class F>
// this function returns the node with the mini identifier in the whole tree
BinaryTreeNode<T, F> min_node(BinaryTreeNode<T, F> *root)
{
    if(root->get_left() == nullptr)
        return *root;                                  // if the left of the currently inspected node is null, then this node (root) is our target, so it will be returned
    return min_node(root->get_left());            // otherwise, we will search in the left branch of it, because the minimum is always on the left
}

// ------------------------------------- Spare Part -------------------------------------

SparePart::SparePart() {part_order = ++parts_created;}

void SparePart::set_part_name(string new_part_name){part_name = new_part_name;}
void SparePart::set_part_number(int new_part_number){part_number = new_part_number;}
void SparePart::set_cost(double new_cost){cost = new_cost;}
void SparePart::set_existing_parts(int new_existing_parts){existing_parts = new_existing_parts;}

string SparePart::get_part_name(){return part_name;}
int SparePart::get_part_number(){return part_number;}
double SparePart::get_cost(){return cost;}
int SparePart::get_existing_parts(){return existing_parts;}
int SparePart::get_identifier(){return part_number;}

void SparePart::get_data()
{
    cout << "Enter the part name: ";
    cin >> this->part_name;

    cout << "Enter the part number: ";
    cin >> this->part_number;

    cout << "Enter the part cost: ";
    cin >> this->cost;

    cout << "Enter the number of parts of it: ";
    cin >> this->existing_parts;
}

void SparePart::put_data()
{
    cout << "Spare Part Number " << part_order << " Info:\n";
    cout << "Part Name\t Part Number\t Part Cost\t Number of Parts" << endl;
    cout << this->part_name << "\t\t " << this->part_number << "\t\t " << this->cost << "\t\t " << this->existing_parts << endl;
}
void SparePart::modifydata() {
    cout << "Choose the part you want to edit." << endl;
    cout << "1. Part Name" << endl;
    cout << "2. Cost" << endl;
    cout << "3. Existing Parts" << endl;
    cout << "4. Part name" << endl;

    int opt;
    cin >> opt;
 if (opt == 1) {
        string new_name;
        cout << "Enter the new name:";
        cin >> new_name;
        this->set_part_name(new_name);
    }
else if (opt == 2) {
    double new_cost;
     cout << "Enter the new cost:";
        cin >> new_cost;
        this->set_cost(new_cost);
    }
    else if (opt == 3) {
        int new_parts;
     cout << "Enter the new number of parts:";
        cin >> new_parts;
        this->set_existing_parts(new_parts);
    }

else {
        cout << "This option is out of service." << endl;
    }
}


// ------------------------------------- Binary Tree Node -------------------------------------

template <class T, class F>
BinaryTreeNode<T, F>::BinaryTreeNode()
{
    left = right = nullptr;
    connected_items = new LinkedList<F>;
    data = new T;
}

template <class T, class F>
void BinaryTreeNode<T, F>::set_left(BinaryTreeNode<T, F> *new_left){left = new_left;}
template <class T, class F>
void BinaryTreeNode<T, F>::set_right(BinaryTreeNode<T, F> *new_right){right = new_right;}
template <class T, class F>
void BinaryTreeNode<T, F>::set_data(T * new_data){data = new_data;}
template <class T, class F>
void BinaryTreeNode<T, F>::set_connected_items(LinkedList<F> * new_connected_items){connected_items = new_connected_items;}

template <class T, class F>
BinaryTreeNode<T, F> * BinaryTreeNode<T, F>::get_left(){return left;}
template <class T, class F>
BinaryTreeNode<T, F> * BinaryTreeNode<T, F>::get_right(){return right;}
template <class T, class F>
T * BinaryTreeNode<T, F>::get_data(){return data;}
template <class T, class F>
LinkedList<F> * BinaryTreeNode<T, F>::get_connected_items(){return connected_items;}


// ------------------------------------- Binary Tree -------------------------------------
template <class T, class F>
DataTree<T, F>::DataTree() {root = nullptr;}
template <class T, class F>
BinaryTreeNode<T, F> * DataTree<T, F>::get_root(){return root;};
template <class T, class F>
void DataTree<T, F>::set_root(BinaryTreeNode<T, F> *new_root){root = new_root;};

template <class T, class F>
bool DataTree<T, F>::insert_recursive(BinaryTreeNode<T, F> new_data, BinaryTreeNode<T, F> *start)
{
    if(root == nullptr)
    {
        this->set_root(new BinaryTreeNode<T, F>);                  // if the root is empty, we will create a new node
        this->get_root()->set_data(new_data.get_data());                // and then copy the value of the given data into it
        this->get_root()->set_connected_items(new_data.get_connected_items());
        return true;                                                    // return true to end the insertion
    }

    else if(start == nullptr)
        return false;                                                   // a base case means that this node is empty

    else if(start->get_data()->get_identifier() > new_data.get_data()->get_identifier())
    {
        // if the identifier of the node being inserted is less than the identifier of the current node, we will head to the left of it
        if(!insert_recursive(new_data, start->get_left()))
        {
            start->set_left(new BinaryTreeNode<T, F>);             // if the left of the current node is empty we will create a new node on the left
            start->get_left()->set_data(new_data.get_data());           // then we copy the data given to the new node
            start->get_left()->set_connected_items(new_data.get_connected_items());
        }

        return true;                                                    // returning true to end the insertion
    }

    else
    {
        // otherwise the node will head to the right because the identifier of it is greater than the identifier of the current node
        if (!insert_recursive(new_data, start->get_right()))
        {
            start->set_right(new BinaryTreeNode<T, F>);           // if the right of the current node is empty we will create a new node on the right
            start->get_right()->set_data(new_data.get_data());          // then we copy the data given to the new node
            start->get_right()->set_connected_items(new_data.get_connected_items());
        }
        return true;                                                    // returning true to end the insertion
    }
}

template <class T, class F>
BinaryTreeNode<T, F> * DataTree<T, F>::delete_node(BinaryTreeNode<T, F> *root, int identifier)
{
    if(root == nullptr)
        return root;                                        // if the tree is empty, there is nothing to delete so we end the deletion

    if(root->get_data()->get_identifier() > identifier)      // if our target's identifier is less than the current node's identifier, we head to the left
        root->set_left(delete_node(root->get_left(), identifier));

    else if(root->get_data()->get_identifier() < identifier) // if our target's identifier is greater than the current node's identifier, we head to the right
        root->set_right(delete_node(root->get_right(), identifier));

    else                                                    // otherwise the target is found so we start deleting
    {
        if(root->get_left() == nullptr && root->get_right() == nullptr)
            return nullptr;                                 // if the node has no children we simply return null to its parent
        else if(root->get_left() == nullptr)
            return root->get_right();                       // if the node has only one child and it's on the right, we return its right to its parent
        else if(root->get_right() == nullptr)
            return root->get_left();                        // if the node has only one child and it's on the left, we return its left to its parent

        // otherwise, it has two children
        BinaryTreeNode<T, F> minimum_node = min_node(root->get_right());               // we look for the node with the minimum identifier on the right branch
        root->set_right(delete_node(root->get_right(), minimum_node.get_data()->get_identifier()));      // we delete this minimum node
        root->set_data(minimum_node.get_data());                                // finally copying the content of the minimum node to the to-be-deleted node
        root->set_connected_items(minimum_node.get_connected_items());
    }

    return root;
}

template <class T, class F>
void DataTree<T, F>::in_order_traversal(BinaryTreeNode<T, F>* root)
{
    if(root == nullptr)
        return;                                  // returning to the parent if the child is empty, because there is nothing to print
    in_order_traversal(root->get_left());   // printing the content on the left first
    root->get_data()->put_data();                 // printing the content of the parent after it
    in_order_traversal(root->get_right());  // finally printing the content on the right
}

template <class T, class F>
BinaryTreeNode<T, F> * DataTree<T, F>::search(BinaryTreeNode<T, F> * root, int identifier)
{
    BinaryTreeNode<T, F> *temp = root;
    while(temp != nullptr && temp->get_data()->get_identifier() != identifier)
    {
        if(temp->get_data()->get_identifier() > identifier)
            temp = temp->get_left();
        else
            temp = temp->get_right();
    }
    return temp;
}

// ------------------------------------- Linked List Node -------------------------------------

template <class T>
void Node<T>::set_data(T new_data){data = new_data;}
template <class T>
void Node<T>::set_next(Node<T> *new_next){next = new_next;}
template <class T>
T Node<T>::get_data(){return data;}
template <class T>
Node<T> * Node<T>::get_next(){return next;}

// ------------------------------------- Linked List -------------------------------------
template <class T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    tail =nullptr;
}

template <class T>
void LinkedList<T>::addNode(T new_data)
{
    Node<T> * newNode = new Node<T>(new_data);
    if (head == nullptr)
    {
        head =tail= newNode;
    }

    else {
        tail->set_next(newNode);
        tail=newNode;
    }
}

template <class T>
void LinkedList<T>::deleteNode(int identifier) {
    Node<T> *current = head;
    Node<T> *previous = nullptr;

    while (current != nullptr && identifier != current->get_data().get_identifier()) {
        previous = current;
        current = current->get_next();
    }

    if (current == nullptr) {
        cout << "Node with such identifier doesn't exist" << endl;
        return;
    }

    if (previous == nullptr)
        head = head->get_next();


    else
        previous->set_next(current->get_next());

    delete current;
    cout << "Node with identifier " << identifier << " deleted successfully." << endl;
}

template <class T>
void LinkedList<T>::printNodes()
{
    Node<T> * current = head;
    while (current != nullptr) {
        current->get_data().put_data();
        current = current->get_next();
    }
}

template <class T>
int LinkedList<T>::is_empty() {return head == nullptr;}


// ------------------------------------- Supplier -------------------------------------

void Supplier::set_name(string new_name){name = new_name;}
void Supplier::set_code(int new_code){code = new_code;}
void Supplier::set_address(string new_address){address = new_address;}
void Supplier::set_phone(string new_phone){phone_number = new_phone;}
void Supplier::set_email(string new_email){email = new_email;}

string Supplier::get_name(){return name;}
int Supplier::get_code(){return code;}
string Supplier::get_address(){return address;}
string Supplier::get_number(){return phone_number;}
string Supplier::get_email(){return email;}
int Supplier::get_identifier(){return code;}

void Supplier::get_data()
{

    cout << "Enter the supplier name: ";
    cin >> this->name;

    this->code = generate_code();
    cout << "This supplier's code is " << get_code()<<"\n";

    cout << "Enter the supplier address: ";
    cin >> this->address;

    cout << "Enter supplier phone number: ";
    cin >> this->phone_number;

    cout << "Enter supplier email: ";
    cin >> this->email;

}

void Supplier::put_data()
{
    cout << "Supplier Information:\n";
    cout << "Supplier Name\t Supplier Code\t Address\t Phone Number\t Email" << endl;
    cout << this->name << "\t\t " << this->code << "\t\t " << this->address << "\t\t " << this->phone_number << "\t\t" << this->email << endl;
}

void Supplier::modifydata()
{
    int input;
    cin >> input;
    cout << "1. Modify Name\n"
         << "2. Modify Adress\n"
         << "3. Modify Phone Number\n"
         << "4. Modify Email\n"
         << "Enter the number of the operation:";

    switch(input)
    {
        case 1:
        {
            cout << "Enter the new name:";
            cin >> name;
            break;
        }

        case 2:
        {
            cout << "Enter the new Address:";
            cin >> address;
            break;
        }

        case 3:
        {
            cout << "Enter the new phone number:";
            cin >> phone_number;
            break;
        }

        case 4:
        {
            cout << "Enter the new email:";
            cin >> email;
            break;
        }

        default:
            cout << "Invalid Input\n";
    }
}

//------------------------------------------------Queue-------------------------------------
template <class T>
 Q_Node<T> ::Q_Node(   T value ) 
   
	 {
          data=value;
          next=nullptr;
   	 }


template <class T>
Queue<T>::Queue()
    {
        front=rear=nullptr;
    }
template <class T>
    void Queue<T>::enqueue(T value) 
	 {
        	Q_Node<T>* newNode = new Q_Node<T>(value);

        	if (isEmpty()) 
		 {
            front = rear = newNode;
       	 } else 
		{
            rear->next = newNode;
            rear = newNode;
       	 }
   	 }

    // Getter: Dequeue (remove) the front element from the queue
template <class T>
    T Queue<T>::dequeue() {
        if (isEmpty()) {
            cout<<"Queue is empty";
        }

        T frontData = front->data;
        Q_Node<T>* temp = front;

        if (front == rear) {
            // Only one element in the queue
            front = rear = nullptr;
        } else {
            front = front->next;
        }

        delete temp;
        return frontData;
    }

    // Getter: Get the front element without removing it
    template <class T>
    T Queue<T>:: peek() {
        if (isEmpty()) {
            cout<<"Queue is empty";
        }

        return front->data;
    }
//Display: display all elements in the queue 
template <class T>
    void Queue<T>:: Display() //O(N)
    {
    Q_Node<T>* temp = front;
   if ((front == NULL) && (rear == NULL)) {
      cout<<"Queue is empty"<<endl;
      return;
   }
   cout<<"Queue elements are: ";
   while (temp != NULL) {
      cout<<temp->data<<" ";
      temp = temp->next;
   }
   cout<<endl;
    }

    // Getter: Check if the queue is empty
    template <class T>
    bool Queue<T>::isEmpty()  {
        return front == nullptr;
    }

    

//-----------------------------------Stack--------------------------------
template <class T>

 S_Node<T> :: S_Node (T value) 
    {
    data=value ;next=nullptr;
    }


template <class T>

Stack<T>::Stack () {Top = nullptr;}

template <class T>
void Stack<T>::Push (T data)
{

S_Node <T> *Ndata = new S_Node (data);
Ndata -> next = Top;
Top = Ndata;
}

template <class T>
void Stack<T>::pop(){

    S_Node<T>*t=Top;

if (Top == NULL) 
{cout << "the stack is empty you cannot add ";} 
else if(t->next==NULL)
{
    delete t;
}
else
{
    Top=Top->next;
    delete t;
}
}

template <class T>
void Stack<T>:: peek()
{
    if (Top == NULL) 
{cout << "the stack is empty";} 
    else{
        cout<<Top->data;
    }
}
template <typename T>
void Stack<T>:: displayStack() {
    if(Top==nullptr)
    {
    cout<<"No Operation Has been done";
    return;
    }
    while (Top!=nullptr) {
   cout<<Top->data<<"\n";
   Top=Top->next;
    }

    cout << "\n";
}
