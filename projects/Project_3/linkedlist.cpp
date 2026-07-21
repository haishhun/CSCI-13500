#include "linkedlist.hpp"

#include <iostream>
#include <stdexcept>

// @param: Takes in a const int parameter representing the value to insert.
// @return: Returns nothing.
void LinkedList::InsertNode(const int value) {
  // Create a Node object new_node.
  Node* new_node = new Node(value);

  // If head is empty then new node becomes head.
  if (head_ == nullptr) {
    head_ = new_node;
  } else {
    // Declare a pointer current pointing to head_.
    Node* current = head_;

    // Loop through the list.
    while (current->next != nullptr) {
      current = current->next;
    }

    // Insert node at the end.
    current->next = new_node;
  }

  // Increment size_ by 1 when node is added.
  size_++;
}

// @param: Takes in a const int parameter representing the value to insert.
// @return: Returns nothing.
void LinkedList::InsertNodeFront(const int value) {
  // Create a Node object new_node.
  Node* new_node = new Node(value);

  // Move new node's pointer to a previous head
  new_node->next = head_;

  // Make a new node - head_.
  head_ = new_node;

  // Increment size_ by 1 when node is added.
  size_++;
}

// @param: Takes in a const int target value.
// @return: Returns true if the value is found, false otherwise.
bool LinkedList::Contains(const int value) const {
  // Declare a pointer current pointing to head_.
  Node* current = head_;

  // Loop through the list to check if value exists in the list already.
  while (current) {
    if (current->value == value) {
      return true;
    }
    current = current->next;
  }

  // Return false if the value was not found.
  return false;
}

// @param: Takes in a const int representing the 1-based position to remove.
// @return: Returns true if successfully removed, false otherwis
bool LinkedList::Remove(const int position) {
  // Declare a pointer node_to_remove pointing to nullptr.
  Node* node_to_remove = nullptr;

  // Validate position is not out of range.
  if (position > size_ || position < 1) {
    std::cout << "Error: Node with this position does not exist" << std::endl;
    return false;
  }

  // if position is 1 then it is head_
  if (position == 1) {
    node_to_remove = head_;
    head_ = node_to_remove->next;
  } else {
    // Declare a pointer previous pointing to head_.
    Node* previous = head_;

    // Loop through the list to find target node at the position.
    // position -2 because we need to save previous node and use the pointer to
    // point on the next after the target node.
    for (int i = 0; i < position - 2; i++) {
      previous = previous->next;
    }
    node_to_remove = previous->next;
    previous->next = node_to_remove->next;
  }

  // Deleting node.
  delete node_to_remove;

  // Decrement size_ when node is deleted.
  size_--;

  // Return true in the end.
  return true;
}

void LinkedList::PrintValues() const {
  // Declare a pointer current pointing to head_.
  Node* current = head_;

  // Loop through the list with printing each value of nodes separated by "->".
  while (current) {
    std::cout << current->value << " -> ";
    current = current->next;
  }

  // Terminate the output with "nullptr" and a newline.
  std::cout << "nullptr" << std::endl;
}

void LinkedList::PrintAddresses() const {
  // Declare a pointer current pointing to head_.
  Node* current = head_;

  // Declare variable position.
  int position = 1;

  // Loop through the list with printing each address of nodes in a format
  // "position address".
  while (current) {
    std::cout << position << " " << current << std::endl;
    position++;
    current = current->next;
  }
}

// @param: Takes in a const int representing the 1-based position.
// @return: Returns the integer value at that position.
// @throws: std::out_of_range if the position is < 1 or > size_.
int LinkedList::GetValueAtPosition(const int position) const {
  // Declare a pointer current pointing to head_.
  Node* current = head_;

  // Validate the position and throw out_of_range if the position is < 1 or >
  // size_.
  if (position > size_ || position < 1) {
    throw std::out_of_range("Error: Node with this position does not exist");
  }

  // Loop through the list to find a target node.
  for (int i = 0; i < position - 1; i++) {
    current = current->next;
  }

  // Return its value.
  return current->value;
}

// @return: Returns a pointer to a new LinkedList containing the reversed
// nodes.
LinkedList* LinkedList::ReverseList() {
  // Create a LinkedList object reverse_list.
  LinkedList* reverse_list = new LinkedList();

  // Create 3 pointers - current, previous and next pointing to head_, nullptr
  // and nullptr.
  Node* current = head_;
  Node* previous = nullptr;
  Node* next = nullptr;

  // Loop through the list with reassigning nodes.
  while (current) {
    next = current->next;
    current->next = previous;
    previous = current;
    current = next;
  }

  // Make the last node - head_.
  reverse_list->head_ = previous;

  // Keep the size as an original one.
  reverse_list->size_ = size_;

  // Prevent dangling pointer head_ and make size_ = 0.
  head_ = nullptr;
  size_ = 0;

  // Return result list.
  return reverse_list;
}

// @param: value to insert, and the 1-based position where it should land.
// @return: Returns nothing.
// @throws: std::out_of_range if the position is invalid.
void LinkedList::InsertNodeAt(const int value, const int position) {
  // Validate the position and throw out_of_range if the position is < 1 or >
  // size_.
  if (position < 1 || position > size_ + 1) {
    throw std::out_of_range("Position is out of range");
  }

  // If position == 1, then it is the first item and we add to the front.
  if (position == 1) {
    InsertNodeFront(value);
    return;

    // If position == size_ + 1, then it is the last item and we add to the
    // back.
  } else if (position == size_ + 1) {
    InsertNode(value);
    return;
  }

  // Create a Node object new_node.
  Node* new_node = new Node(value);

  // Declare a pointer previous pointing to head_.
  Node* previous = head_;

  // Loop through the list to find the previous node (position - 1).
  for (int i = 0; i < position - 2; i++) {
    previous = previous->next;
  }

  // Assign new node's next pointer to the previous node's next pointer.
  new_node->next = previous->next;

  // Reassign previous node's next pointer to the new node.
  previous->next = new_node;

  // Increment size in the end.
  size_++;
}

// @return: Returns the current number of nodes in the list.
int LinkedList::GetSize() const {
  // Return the amount of nodes in the list.
  return size_;
}

// @param: Takes in a const reference to a second LinkedList.
// @return: Returns a dynamically allocated pointer to the new merged list.
LinkedList* LinkedList::MergeIntertwine(const LinkedList& second_list) const {
  // Create a new linked list.
  LinkedList* new_list = new LinkedList();

  // Declare a pointer current pointing to head_ and second_list_current
  // pointing to the second_list' head_.
  Node* current = head_;
  Node* second_list_current = second_list.head_;

  // Insert nodes in a new list while one of the lists has nodes left.
  while (current || second_list_current) {
    if (current) {
      new_list->InsertNode(current->value);
      current = current->next;
    }
    if (second_list_current) {
      new_list->InsertNode(second_list_current->value);
      second_list_current = second_list_current->next;
    }
  }

  // Return the result list in the end.
  return new_list;
}

// The destructor automatically runs when the LinkedList object is
// destroyed.
LinkedList::~LinkedList() {
  // Declare a pointer current pointing to head_.
  Node* current = head_;

  // Loop through the list with deleting nodes and decrementing size.
  while (current) {
    // Declare a pointer next_node pointing to the current->next.
    Node* next_node = current->next;
    delete current;
    current = next_node;
    size_--;
  }

  // size_ = 0;  // We can use this but I will keep my original idea.
}