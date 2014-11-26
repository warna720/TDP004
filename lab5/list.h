#ifndef _LIST_H_
#define _LIST_H_

#include <algorithm>

class Node
{
  friend class List;

private:
  int value;
  Node* next;

  Node(int newValue, Node* newNext = nullptr);
  Node(Node const& other) = delete;
  Node& operator=(Node const& rhs) = delete;
  Node& operator=(Node&& rhs) = delete;
  ~Node();
  void recursiveInsert(int newValue, Node*& startNode);
};

class List
{
public:
  List();
  List(List const& other);
  List(List&& other);
  List& operator=(List const& rhs);
  List& operator=(List&& rhs);
  ~List();
  void insert(int value);
  void print() const;
  void remove(int value);
private:
  Node* start;

  Node* recursiveCopy(Node* other);
};

#endif
