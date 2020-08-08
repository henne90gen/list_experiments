#pragma once

template <typename T> struct Node {
  T value;
  Node<T> *next = nullptr;
};

template <typename T> class LinkedList {
public:
  ~LinkedList() {
    auto currentNode = head;
    while (currentNode != nullptr) {
      auto tmp = currentNode->next;
      std::free(currentNode);
      currentNode = tmp;
    }
  }

  void add(T value) {
    auto *newNode = new Node<T>();
    newNode->value = value;
    if (head == nullptr) {
      head = newNode;
    }
    if (tail != nullptr) {
      tail->next = newNode;
    }
    tail = newNode;
    currentSize++;
  }

  size_t size() { return currentSize; }

  T operator[](size_t index) const {
    size_t currentIndex = 0;
    auto currentNode = head;
    while (currentIndex != index) {
      currentNode = currentNode->next;
      currentIndex++;
    }
    return currentNode->value;
  }

  T &operator[](size_t index) {
    size_t currentIndex = 0;
    auto currentNode = head;
    while (currentIndex != index) {
      currentNode = currentNode->next;
      currentIndex++;
    }
    return currentNode->value;
  }

private:
  Node<T> *head = nullptr;
  Node<T> *tail = nullptr;
  size_t currentSize = 0;
};
