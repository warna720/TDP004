#include <iostream>

#include "list.h"

Node::Node(int newValue, Node* newNext) : value(newValue), next(newNext){}

Node::~Node() {delete next;}

void Node::recursiveInsert(int newValue, Node*& startNode)
{
  if (startNode == nullptr || startNode->value > newValue)
  {
    startNode = new Node(newValue, startNode);
  }
  else
  {
    recursiveInsert(newValue, startNode->next);
  }
}

List::List() : start(nullptr) {}

List::List(List const& other) : start(nullptr)
{
  if (other.start != nullptr)
  {
    start = recursiveCopy(other.start);
  }
  else
  {
    start = nullptr;
  }
}

List::List(List&& other) : start(nullptr)
{
  start = other.start;
  other.start = nullptr;
}

List& List::operator=(List const& rhs)
{
  if (this != &rhs)
  {
    List copy(rhs);
    std::swap(start, copy.start);
  }
  return *this;
}

List& List::operator=(List&& rhs)
{
  if (this != &rhs)
  {
    std::swap(start, rhs.start);
  }
  return *this;
}

List::~List() {delete start;}

void List::insert(int value)
{
  if (start == nullptr)
  {
    start = new Node(value, nullptr);
  }
  else
  {
    start->recursiveInsert(value, start);
  }
}

void List::print() const
{
  Node* currentNode = start;
  while (currentNode != nullptr)
  {
    std::cout << currentNode->value << " ";
    currentNode = currentNode->next;
  }
  std::cout << std::endl;
}

void List::remove(int value)
{
  if (start->value == value)
  {
    Node* newBegin = start->next;
    start->next = nullptr;
    delete start;
    start = newBegin;
    return;
  }
  
  Node* l = start;
  Node* before = start;

  while (l->next != nullptr && value != l->value)
  {
    before = l;
    l = l->next;
  }
  
  if (value == l->value)
  {
    if (start->next == nullptr)
    {
      delete start;
      start = nullptr;
    }
    else
    {
      before->next = l->next;
      l->next = nullptr;
    }
    delete l;
  }
}

Node* List::recursiveCopy(Node* other)
{
  if (other->next != nullptr)
  {
    return new Node(other->value, recursiveCopy(other->next));
  }
  return new Node(other->value, nullptr);
}
