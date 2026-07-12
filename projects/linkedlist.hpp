#pragma once

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