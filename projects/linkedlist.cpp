#include <iostream>
#include <stdexcept>

struct Node {
  int value;
  Node* next;

  Node(int passed_value) : value(passed_value), next(nullptr) {};
};

class LinkedList {
 public:
  LinkedList() : size_(0), head_(nullptr) {}
  ~LinkedList();

  void InsertNode(const int value);
  void InsertNodeFront(const int value);
  bool Contains(const int value) const;
  bool Remove(const int position);
  void PrintValues() const;
  void PrintAddresses() const;
  int GetValueAtPosition(const int position) const;
  LinkedList* ReverseList();
  void InsertNodeAt(const int value, const int position);
  int GetSize() const;
  LinkedList* MergeIntertwine(const LinkedList& second_list) const;

 private:
  int size_;
  Node* head_;
};

// @param: Takes in a const int parameter representing the value to insert.
// @return: Returns nothing.
void LinkedList::InsertNode(const int value) {
  // Insert the provided value as a new node at the end of the list.
  // Ensure that the list's tracking variables are updated accordingly.
  Node* new_node = new Node(value);

  if (head_ == nullptr) {
    head_ = new_node;
  } else {
    Node* current = head_;
    while (current->next != nullptr) {
      current = current->next;
    }
    current->next = new_node;
  }

  size_++;
}

// @param: Takes in a const int parameter representing the value to insert.
// @return: Returns nothing.
void LinkedList::InsertNodeFront(const int value) {
  // Insert the provided value as a new node at the beginning of the list.
  // Ensure that the list's tracking variables are updated accordingly.
  Node* new_node = new Node(value);
  new_node->next = head_;
  head_ = new_node;

  size_++;
}

// @param: Takes in a const int target value.
// @return: Returns true if the value is found, false otherwise.
bool LinkedList::Contains(const int value) const {
  // Return true if the target value exists within any node in the list.
  // Otherwise, return false.
  Node* current = head_;
  while (current) {
    if (current->value == value) return true;
    current = current->next;
  }
  return false;
}

// @param: Takes in a const int representing the 1-based position to remove.
// @return: Returns true if successfully removed, false otherwis
bool LinkedList::Remove(const int position) {
  // Validate the position. If valid, remove the node at that 1-based
  // position, carefully bypassing it in the chain. Prevent memory leaks by
  // freeing the removed node, update the list's size, and return true.
  Node* node_to_remove = nullptr;

  if (position > size_ || position < 1) {
    std::cout << ("Error: Node with this position does not exist") << std::endl;
    return false;
  }
  if (position == 1) {
    node_to_remove = head_;
    head_ = node_to_remove->next;
  } else {
    Node* previous = head_;
    for (int i = 0; i < position - 2; i++) {
      previous = previous->next;
    }
    node_to_remove = previous->next;
    previous->next = node_to_remove->next;
  }

  delete node_to_remove;
  size_--;
  return true;
}

void LinkedList::PrintValues() const {
  // Print all values sequentially, separated by " -> ",
  // and terminate the output with "nullptr" and a newline.
  Node* current = head_;
  while (current) {
    std::cout << current->value << " -> ";
    current = current->next;
  }
  std::cout << "nullptr" << std::endl;
}

void LinkedList::PrintAddresses() const {
  // Print the 1-based position, a space, and the node's memory address
  // for every node in the list.
  Node* current = head_;
  int position = 1;
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
  // Validate the position, throwing an exception if it is out of bounds.
  // Otherwise, navigate to the correct node and return its value.
  Node* current = head_;
  if (position > size_ || position < 1) {
    throw std::out_of_range("Error: Node with this position does not exist");
  }

  for (int i = 0; i < position - 1; i++) {
    current = current->next;
  }
  return current->value;
}

// @return: Returns a pointer to a new LinkedList containing the reversed
// nodes.
LinkedList* LinkedList::ReverseList() {
  // Reverse the nodes of the current list.
  // Allocate a new LinkedList dynamically, give it ownership of the
  // reversed nodes, and reset the current (original) list to an empty
  // state. Return the pointer to the newly created list.
  LinkedList* reverse_list = new LinkedList();

  Node* current = head_;
  Node* previous = nullptr;
  Node* next = nullptr;

  while (current) {
    next = current->next;
    current->next = previous;
    previous = current;
    current = next;
  }
  reverse_list->head_ = previous;
  reverse_list->size_ = size_;

  head_ = nullptr;
  size_ = 0;

  return reverse_list;
}

// @param: value to insert, and the 1-based position where it should land.
// @return: Returns nothing.
// @throws: std::out_of_range if the position is invalid.
void LinkedList::InsertNodeAt(const int value, const int position) {
  // Check if the position is valid (allowing insertions at the very end).
  // If invalid, throw std::out_of_range.
  // Otherwise, insert the new node at the correct spot and update list
  // properties.
  if (position < 1 || position > size_ + 1) {
    throw std::out_of_range("Position is out of range");
  }
  if (position == 1) {
    InsertNodeFront(value);
    return;
  } else if (position == size_ + 1) {
    InsertNode(value);
    return;
  }
  Node* new_node = new Node(value);
  Node* previous = head_;
  for (int i = 0; i < position - 2; i++) {
    previous = previous->next;
  }

  new_node->next = previous->next;
  previous->next = new_node;
  size_++;
}

// @return: Returns the current number of nodes in the list.
int LinkedList::GetSize() const {
  // Return the appropriate member variable.
  return size_;
}

// @param: Takes in a const reference to a second LinkedList.
// @return: Returns a dynamically allocated pointer to the new merged list.
LinkedList* LinkedList::MergeIntertwine(const LinkedList& second_list) const {
  // Create a new LinkedList on the heap.
  // Populate it by alternating nodes from THIS list and the second_list.
  // If one list is longer, append the remaining nodes from the longer list.
  // Do not alter the original lists. Return the new merged list.
  LinkedList* new_list = new LinkedList();

  Node* current = head_;
  Node* second_list_current = second_list.head_;

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
  return new_list;
}

// The destructor automatically runs when the LinkedList object is
// destroyed.
LinkedList::~LinkedList() {
  // Free all dynamically allocated memory used by the list's nodes.
  // Ensure no orphaned memory is left behind upon object destruction.
  Node* current = head_;
  while (current) {
    Node* next_node = current->next;
    delete current;
    current = next_node;
    size_--;
  }
}