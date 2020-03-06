#include <iostream>
#include "node.h"

Node::Node(){
  right = NULL;
  left = NULL;
  parent = NULL;
  data = 0;
}
Node::~Node(){
  right = NULL;
  left = NULL;
  parent = NULL;
  data = 0;
}


/*
void Node::setNext(Node* user){ //set the next node, for use in stack/queue
  next = user;
}
Node* Node::getNext(){ //gets the next node
  return next;
}
//*/
void Node::setParent(Node* user){ //sets "parent" node
  parent = user;
}
Node* Node::getParent(){ //gets "parent" node
  return parent;
}

void Node::setLeft(Node* user){ //sets "left" node
  left = user;
}
Node* Node::getLeft(){ //gets the "left" node
  return left;
}

void Node::setRight(Node* user){ //sets "right" node
  right = user;
}
Node* Node::getRight(){ //gets the "right" node
  return right;
}

void Node::setData(int user){ //sets an integer data value
  data = user;
}
int Node::getData(){ //gets an integer data value
  return data;
}
