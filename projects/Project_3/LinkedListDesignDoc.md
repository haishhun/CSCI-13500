# Program Design Document

## Program Name

Linked List (Project 3)

## Purpose

The program implements a linked list by creating a LinkedList struct and functions to manipulate with it.

---

## Inputs

* Value of a node
* Position of a node
* Second_list

---

## Outputs

* List of node values
* List of node addresses
* true/false
* Size of a list
* Position on a value
* Reversed list
* Merged list

---

## Variables

| Variable | Type      | Purpose                                                |
| -------- | --------- | ------------------------------------------------------ |
| head_    | Node*     | Points to the first node in the list                   |
| size_    | int       | Tracks the number of nodes                             |
| value    | int       | Value of a node                                        |
| next     | Node*     | Points to the next node in the list                    |
| current  | Node*     | Pointer used to iterate through a list                 |
| previous | Node*     | Pointer of a previous node.                            |
| position | int       | Index of a node                                        |

---

## Key Design Choices

* I used `position - 2` in `int i = 0; i < position - 2; i++` in `Remove` to store the previous node and then reassign its pointer to the next node after removal of a target one.
* I reused functions `InsertNodeFront` for the `position == 1 ` and `InsertNode` for the `position == size_ + 1` in `InsertNodeAt`.
* I reused `InsertNode` in `MergeIntertwine` for inserting node when merging lists.

---

## Program Steps (Algorithm)

### InsertNode
1. Create a pointer that points to a new Node with input value.
2. Check if `head_` exists, make a new node - head if it doesn't.
3. Otherwise create a new pointer `current` that points to `head_`.
4. Iterate to the last node and set its pointer to the new node.
5. Increment the number of nodes.

### InsertNodeFront
1. Create a pointer that points to a new Node with input value.
2. Assign new node's pointer to the next node = `head_`.
3. Make `head_` equal new node.
4. Increment the number of nodes.

### Contains
1. Create a pointer `current` that points to `head_`.
2. Iterate through the list and look for a target value.
3. If value is found then return `true`.
4. Otherwise return `false`.

### Remove
1. Create a pointer `node_to_remove` = nullptr.
2. Validate input value.
3. Check case with `position == 1`. If it's true, then the `node_to_remove` is `head_`
4. Otherwise create a new pointer `previous` that points to `head_`.
5. Iterate through the list to find the `previous` node of the target one.
6. Assign `node_to_remove` to the target node.
7. Reassign `previous->next` to the node after the target one.
8. Delete `node_to_remove`.
9. Decrement the number of nodes.
10. Return `true` in the end.

### PrintValues
1. Create a node `current` that points to `head_`.
2. Iterate through the list and print each value separated by `" -> "`
3. Terminate the output with "nullptr" and a newline.

### Print Addresses
1. Create a node `current` that points to `head_`.
2. Declare a variable `position` with starting value = 1
3. Iterate through the list and print each address in a format `"position address"`

### GetValueAtPosition
1. Create a node `current` that points to `head_`.
2. Validate input value.
3. Iterate through the loop to the target node.
4. Return target node's value.

### ReverseList
1. Create a pointer `reverse_list` that points to the new LinkedList object.
2. Create 3 pointers - `current`, `previous`, `next` that point to `head_`, `nullptr`, `nullptr`.
3. Iterate through the list with reassigning `next`, `current` and `previous` values.
4. Make `head_` of a reverse_list - the last node in the original list.
5. Reset the original list's `head_` to `nullptr` and `size_` to 0.
6. Return reversed list.

### InsertNodeAt
1. Validate input value `position`.
2. Check cases when `position == 1` and `position == size_ + 1` are first and the last node
3. Create a pointer `new_node` that points to the new node with input value.
4. Create a pointer `previous` that points to `head_`.
5. Iterate through the list to find a `previous` node before a target `position`.
6. Set `new_node->next` value to the `previous->next` value.
7. Set `previous->next` to `new_node` value.
8. Increment the number of nodes.

### GetSize
1. Return the number of nodes in a linked list.

### MergeIntertwine
1. Create a pointer `new_list` that points to the new LinkedList object.
2. Create a pointer `current` that points to the original list's `head_`.
3. Create a pointer `second_list_current` that points to the second list's `head_`.
4. Iterate through two lists while at least one of them has nodes and insert nodes 1 by 1.
5. Return merged list.

### ~LinkedList
1. Create a pointer `current` that points to `head_`.
2. Iterate through the list.
3. Create a pointer next_node and assign it to the `current` node's next node address.
4. Delete current node.
5. Reassign `current` to the `next_node`.
6. Decrement the number of nodes.

---

## Functions

### Function: InsertNode(value)
Purpose: Inserts a new node with the input value at the end of the list.

### Function: InsertNodeFront(value)
Purpose: Inserts a new node with the input value at the front of the list.

### Function: Contains(value)
Purpose: Returns true if the value exists in the list, false if not.

### Function: Remove(position)
Purpose: Removes the node at the input position.

### Function: PrintValues()
Purpose: Prints each node's value, separated by "->".

### Function: PrintAddresses()
Purpose: Prints each node's address in a format "position address".

### Function: GetValueAtPosition(position)
Purpose: Returns the value stored at the input position.

### Function: ReverseList()
Purpose: Reverses the list's node order and returns it as a new LinkedList.

### Function: InsertNodeAt(value, position)
Purpose: Inserts a new node with the input value at the requested position.

### Function: GetSize()
Purpose: Returns the current number of nodes in the list.

### Function: MergeIntertwine(second_list)
Purpose: Returns a list that consists of nodes of two lists.

### Function: ~LinkedList()
Purpose: Frees all nodes when the list is destroyed.

---

## Sample Input/Output
```
Input:
list.InsertNode(5);
list.InsertNode(10);
list.PrintValues();

Output:
5 -> 10 -> nullptr
```
---

## Testing

### Test Case 1

Input: 
list.InsertNode(1)
list.InsertNode(2)
list.InsertNode(3)
list.PrintValues()

Output:
1 -> 2 -> 3 -> nullptr

### Test Case 2

Input: 
list.InsertNode(1)
list.InsertNode(2)
list.InsertNode(3)
list.GetSize()

Output:
3

### Test Case 3

Input: 
list.InsertNode(1)
list.InsertNode(2)
list.InsertNode(3)
list.InsertNodeFront(0)
list.PrintValues()

Output:
0 -> 1 -> 2 -> 3 -> nullptr