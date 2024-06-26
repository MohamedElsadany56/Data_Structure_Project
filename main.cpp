/*
project team members 

Abdullah Ismail
Mohamed Emad
Mohamed Goma

*Describtion*

Project: Integrated Inventory Management System
Description:
An Integrated Inventory Management System for a factory
that includes spare parts and their associated suppliers. 
The system has various data structures, including linked lists, stacks, queues, trees, 
to efficiently manage and organize inventory information.

*Complexity* 

Linked List
    Insertion       O(1)
    Deletion        O(n)
    Print           O(n)
    Is_empty()      O(1)
Spare Part
    Get_data()	O(1)
    Put_data()	O(1)
    Set, get	O(1)
    Modify()    O(1)
Supplier
    Get_data()	O(1)
    Put_data()	O(1)
    Set, get	O(1)
    Modify()    O(1)
Binary Tree

Process	            Set, get	Insert	    Delete	    Printing	Search
Average Complexity	O(1)	    O(log(n))	O(log(n))	O(n)	O(log(n))
Worst Complexity	O(1)	    O(n)	    O(n)	    O(n)	O(n)

Note: In the binary tree of type Supplier, all the time complexity is O(log(n)), because the tree is a full tree.
Generate code: O(log(n))
Min Node: O(log(n)) in average, O(n) in worst case
Queue

Operation	Enqueue	Dequeue	Peek	Display	Is_empty()
Complexity	O(1)	O(1)	O(1)	O(n)	O(1)







*/



#include <iostream>
using namespace std;
#include "DS_project.h"
#include "DS_project.cpp"

int main() {



    // Create a spare parts tree
     DataTree<SparePart, Supplier> sparePartsTree;


    // // Create a suppliers tree
     DataTree<Supplier, SparePart> suppliersTree;


    // Interaction stack for user history
    Stack<string> interactionsStack;

    // Queue for spare part processing
    Queue<string> sparePartProcessingQueue;

    // Queue for supplier processing
    Queue<string> supplierProcessingQueue;

    int option;
    do {
        // Display menu
        cout << "\n------ Integrated Inventory Management System ------\n";
        cout << "1. Input data for spare part\n";
        cout << "2. Input data for supplier\n";
        cout << "3. Display spare parts\n";
        cout << "4. Display suppliers\n";
        cout << "5. Modify spare part information\n";
        cout << "6. Modify supplier information\n";
        cout << "7. Search for spare part or supplier\n";
        cout << "8. Add spare part by supplier\n";
        cout << "9. Display the parts a certain supplier supplies\n";
        cout << "10. Display suppliers that supply a certain part\n";
        cout << "11. Delete Spare Part\n";
        cout << "12. Delete Supplier\n";
        cout << "13. Display History \n";
        cout << "14. Exit\n";
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
            case 1:
               { // Input data for spare part
                BinaryTreeNode<SparePart, Supplier> New_BTSparePart_Node;
                New_BTSparePart_Node.get_data()->get_data();
                if(sparePartsTree.search(sparePartsTree.get_root(), New_BTSparePart_Node.get_data()->get_identifier()))
                    cout << "Such part number already exists" << endl;
                else
                {
                    sparePartsTree.insert_recursive(New_BTSparePart_Node, sparePartsTree.get_root());
                    string str="Spare Part processing in progress";
                    interactionsStack.Push("User entered data for Spare Part");
                    sparePartProcessingQueue.enqueue(str);
                }
                break;}

            case 2:{
                // Input data for supplier

                BinaryTreeNode<Supplier, SparePart> New_BTSupplier_Node;
                New_BTSupplier_Node.get_data()->get_data();
                if(suppliersTree.search(suppliersTree.get_root(), New_BTSupplier_Node.get_data()->get_identifier()))
                    cout << "Such code already exists" << endl;

                else
                {
                    suppliersTree.insert_recursive(New_BTSupplier_Node, suppliersTree.get_root());
                    interactionsStack.Push("User entered data for Supplier");
                    supplierProcessingQueue.enqueue("Supplier processing in progress.");
                }

                break;}

            case 3:
            {
                // Display spare parts
                sparePartsTree.in_order_traversal(sparePartsTree.get_root());
                break;
            }

            case 4:
            {
                // Display suppliers
                suppliersTree.in_order_traversal(suppliersTree.get_root());
                break;
            }

            case 5:
                // Modify spare part information
                {int part_code;
                    cout << "Enter the code of the spare part:" << endl;
                    cin >> part_code;
                    BinaryTreeNode<SparePart, Supplier> *found_part = sparePartsTree.search(sparePartsTree.get_root(), part_code);
                    if(found_part == nullptr)
                        cout << "There is no such spare part" << endl;
                    else
                        found_part->get_data()->modifydata();
                break;
                }

            case 6://Modify supplier information
                {
                    int supplier_code;
                    cout << "Enter the code of the supplier:";
                    cin >> supplier_code;
                    BinaryTreeNode<Supplier, SparePart> *found_supplier = suppliersTree.search(suppliersTree.get_root(), supplier_code);
                    if(found_supplier == nullptr)
                        cout << "There is no such supplier" << endl;
                    else
                        found_supplier->get_data()->modifydata();
                break;}

            case 7://Search for spare part or supplier
                { 
                int searchOption;
                cout << "Search by:\n";
                cout << "1. Spare Part Number\n";
                cout << "2. Supplier Code\n";
                cout << "Enter your choice: ";
                cin >> searchOption;

                if (searchOption == 1) {
                    int part_code;
                    cout << "Enter the number of the spare part:" << endl;
                    cin >> part_code;
                    BinaryTreeNode<SparePart, Supplier> *found_part = sparePartsTree.search(sparePartsTree.get_root(), part_code);
                    if(found_part == nullptr)
                        cout << "There is no such spare part" << endl;
                    else
                        found_part->get_data()->put_data();

                } else if (searchOption == 2) {
                    int supplier_code;
                    cout << "Enter the code of the supplier:";
                    cin >> supplier_code;
                    BinaryTreeNode<Supplier, SparePart> *found_supplier = suppliersTree.search(suppliersTree.get_root(), supplier_code);
                    if(found_supplier == nullptr)
                        cout << "There is no such supplier" << endl;
                    else
                        found_supplier->get_data()->put_data();

                } else {
                    cout << "Invalid option\n";
                }
                break;
                }

            case 8:
            {
                int supplier_code;
                cout << "Enter the code of the supplier:";
                cin >> supplier_code;
                BinaryTreeNode<Supplier, SparePart> *found_supplier = suppliersTree.search(suppliersTree.get_root(), supplier_code);
                if(found_supplier == nullptr)
                    cout << "There is no such supplier" << endl;
                else
                {
                    int part_code;
                    cout << "Enter the code of the spare part:" << endl;
                    cin >> part_code;
                    BinaryTreeNode<SparePart, Supplier> *found_part = sparePartsTree.search(sparePartsTree.get_root(), part_code);
                    if(found_part == nullptr)
                        cout << "There is no such spare part" << endl;

                    else
                    {
                        found_part->get_connected_items()->addNode(*found_supplier->get_data());
                        found_supplier->get_connected_items()->addNode(*found_part->get_data());
                    }
                }

                break;
            }


            case 9: {
                int supplier_code;
                cout << "Enter the code of the supplier:";
                cin >> supplier_code;
                BinaryTreeNode<Supplier, SparePart> *found_supplier = suppliersTree.search(suppliersTree.get_root(),
                                                                                           supplier_code);
                if (found_supplier == nullptr)
                    cout << "There is no such supplier" << endl;
                else
                {
                    cout << "Supplier with name " << found_supplier->get_data()->get_name() << " and code " << found_supplier->get_data()->get_code() << " supplies:\n";
                    found_supplier->get_connected_items()->printNodes();
                }
                break;
            }

            case 10:
            {
                int part_code;
                cout << "Enter the code of the spare part:" << endl;
                cin >> part_code;
                BinaryTreeNode<SparePart, Supplier> *found_part = sparePartsTree.search(sparePartsTree.get_root(), part_code);
                if(found_part == nullptr)
                    cout << "There is no such spare part" << endl;
                else
                {
                    cout << "Supplier who provide this part are:\n";
                    found_part->get_connected_items()->printNodes();
                }
                break;
            }

            case 11:
            {
                int part_code;
                cout << "Enter the code of the spare part:" << endl;
                cin >> part_code;
                BinaryTreeNode<SparePart, Supplier> *found_part = sparePartsTree.search(sparePartsTree.get_root(), part_code);
                Node<Supplier> *current = found_part->get_connected_items()->head;
                while(current)
                {
                    BinaryTreeNode<Supplier, SparePart> *found_supplier = suppliersTree.search(suppliersTree.get_root(),current->get_data().get_identifier());
                    found_supplier->get_connected_items()->deleteNode(part_code);
                    current = current->get_next();
                }

                sparePartsTree.set_root(sparePartsTree.delete_node(sparePartsTree.get_root(), part_code));
                break;
            }

            case 12:
            {
                int supplier_code;
                cout << "Enter the code of the supplier:" << endl;
                cin >> supplier_code;
                BinaryTreeNode<Supplier, SparePart> *found_supplier = suppliersTree.search(suppliersTree.get_root(), supplier_code);
                Node<SparePart> *current = found_supplier->get_connected_items()->head;
                while(current)
                {
                    BinaryTreeNode<SparePart, Supplier> *found_part = sparePartsTree.search(sparePartsTree.get_root(),current->get_data().get_identifier());
                    found_part->get_connected_items()->deleteNode(supplier_code);
                    current = current->get_next();
                }

                suppliersTree.set_root(suppliersTree.delete_node(suppliersTree.get_root(), supplier_code));
                break;
            }
            case 13:
                {
                    cout << " --------History Interaction ----------\n";
                    interactionsStack.displayStack();
                    break;
                }

            case 14:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid Order \n";
        }
    } while (option != 14);

    return 0;
}
