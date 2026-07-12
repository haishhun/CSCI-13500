#include "Snake.h"

#include <iostream>

Snake::Snake() {
  head_ = nullptr;
  tail_ = nullptr;
  length_ = 0;
  id_ = 0;

  // Loop the amount of STARTING_LENGTH times.
  for (int i = 0; i < STARTING_LENGTH; i++) {
    // Create a new Node.
    Node* newNode = new Node;
    newNode->body_part_ = id_;
    newNode->next_ = nullptr;
    id_++;

    // Validate if snake is empty then the first item becomes head and tail.
    // Otherwise we add the node in the end.
    if (head_ == nullptr) {
      head_ = newNode;
      tail_ = newNode;
    } else {
      tail_->next_ = newNode;
      tail_ = newNode;
    }

    // Increment lenght_ in the end.
    length_++;
  }
}

Snake::~Snake() {
  // Declare a pointer current pointing to head_.
  Node* current = head_;

  // Loop through the list with deleting nodes.
  while (current) {
    // Declare a pointer next_node pointing to the current->next.
    Node* next_node = current->next_;
    delete current;
    current = next_node;
  }
}

int Snake::Kill(int count) {
  // Create a pointer current pointing to head_.
  Node* current = head_;

  // Declare variable for counting killed parts.
  int killed_parts = 0;

  // Loop through snake and kill parts from the front
  for (int i = 0; i < count && current; i++) {
    Node* next_node = current->next_;
    delete current;
    current = next_node;
    killed_parts++;
  }

  // Reassign head_ to the first part that left after deleting.
  head_ = current;

  // Decrement length_ after deleting parts.
  length_ = length_ - killed_parts;

  // Validate if Snake is empty.
  if (head_ == nullptr) {
    tail_ = nullptr;
  }

  // Return the amount of deleted parts.
  return killed_parts;
}

void Snake::Regenerate(int count) {
  // Loop count times and add new nodes.
  for (int i = 0; i < count; i++) {
    Node* newNode = new Node;
    newNode->body_part_ = id_;
    newNode->next_ = nullptr;
    id_++;

    // Validate if Snake is empty.
    if (head_ == nullptr) {
      head_ = newNode;
      tail_ = newNode;
    } else {
      tail_->next_ = newNode;
      tail_ = newNode;
    }

    length_++;
  }
}

void Snake::PrintSnake() const {
  // Create a pointer current pointing to head_.
  const Node* current = head_;

  // Validate if Snake is empty.
  if (head_ == nullptr) {
    std::cout << "Snake: (dead)." << std::endl;
    return;
  }

  // Print all snake parts.
  std::cout << "Snake: ";
  while (current) {
    std::cout << "[" << current->body_part_ << "]";
    if (current->next_) {
      std::cout << " -> ";
    }
    current = current->next_;
  }
  std::cout << "\n";
}

int Snake::GetLength() const {
  // Return the length of a snake
  return length_;
}
