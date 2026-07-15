#pragma once

struct Node {
  int value;
  Node* next;

  Node(int passed_value) : value(passed_value), next(nullptr) {};
};

class LinkedList {
 public:
  LinkedList() : size_(0), head_(nullptr) {}

  // Frees all nodes when the list is destroyed.
  ~LinkedList();

  // Inserts a new node with the input value at the end of the list.
  void InsertNode(const int value);

  // Inserts a new node with the input value at the front of the list.
  void InsertNodeFront(const int value);

  // Returns true if the value exists in the list, false if not.
  bool Contains(const int value) const;

  // Removes the node at the input position.
  bool Remove(const int position);

  // Prints each node's value, separated by "->".
  void PrintValues() const;

  // Prints each node's address in a format "position address".
  void PrintAddresses() const;

  // Returns the value stored at the input position.
  int GetValueAtPosition(const int position) const;

  // Reverses the list's node order and returns it as a new LinkedList.
  LinkedList* ReverseList();

  // Inserts a new node with the input value at the requested position.
  void InsertNodeAt(const int value, const int position);

  // Returns the current number of nodes in the list.
  int GetSize() const;

  // Returns a list that consists of nodes of two lists.
  LinkedList* MergeIntertwine(const LinkedList& second_list) const;

 private:
  int size_;
  Node* head_;
};