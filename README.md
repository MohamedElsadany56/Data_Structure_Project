# 🏭 Integrated Inventory Management System

## 📋 Project Overview

This project involves designing and implementing an **Integrated Inventory Management System** for a factory that handles **spare parts** and their associated **suppliers**. The system leverages multiple **data structures** such as **linked lists**, **stacks**, **queues**, and **binary trees** to manage and organize inventory efficiently.

---

## 🚀 Features

- Manage spare parts and their associated suppliers  
- Prevent duplicate entries (unique part numbers and supplier codes)  
- Perform searches and deletions using efficient tree structures  
- Maintain a log of user interactions using stacks  
- Queue-based processing for updates and additions  
- Support up to 100 spare parts and 20 suppliers  
- Command-line interface for interactive management  

---

## 🧱 Classes

### 1. `SparePart` Class
- **Attributes**: `partName`, `partNumber`, `cost`, `existingParts`
- **Functions**:
  - `getdata()` – Input spare part details  
  - `putdata()` – Display spare part data  
  - `modifydata()` – Modify existing data  

### 2. `Supplier` Class
- **Attributes**: `supplierName`, `supplierCode`, `address`, `telephone`, `email`
- **Functions**:
  - `getdata()` – Input supplier details  
  - `putdata()` – Display supplier data  
  - `modifydata()` – Modify existing data  

---

## 🗂 Data Structures Used

| Structure       | Purpose                               | Example Usage                                  | Time Complexity     |
|----------------|----------------------------------------|------------------------------------------------|---------------------|
| **Linked List** | Associate suppliers with parts         | Dynamic connection between parts and suppliers | O(N) traversal      |
| **Stack**       | Track user interactions                | LIFO logging of actions                        | O(1) push/pop       |
| **Queue**       | Process updates sequentially           | Update order for parts/suppliers               | O(1) enqueue/dequeue|
| **Binary Tree** | Efficient search and deletion          | Organize parts and suppliers by IDs            | O(log N) avg case   |

---

## 🔍 Search & Delete

Efficient **binary search trees** (BSTs) are used for fast lookup and deletion of:
- Spare Parts (by `partNumber`)
- Suppliers (by `supplierCode`)

---

## 💻 Main Program Features

- Input and store up to **100 spare parts** and **20 suppliers**  
- Choose data structure and operation to perform  
- Display all current inventory and supplier details  
- Interactive prompts to manage inventory  

---
### Interaction Stack Log (LIFO)
User entered data for Spare Part number 5
User modified data for Spare Part number 2

