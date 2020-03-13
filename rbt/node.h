#include <iostream>

using namespace std;

class Node {

 public:
  Node();
  ~Node();
  void setParent(Node* user); //sets the parent node
  Node* getParent(); //returns the parent node
  
  void setLeft(Node* user); //sets the left node
  Node* getLeft(); //returns the left node

  void setRight(Node* user); //sets the right node
  Node* getRight(); //returns the right node

  void setData(int user); //sets data value
  int getData(); //returns data value
  
  void setColor(int user); //sets color value
  int getColor(); //returns color value
  //0 = Red, 1 = Black, Default is Red
 private:
  Node* parent;
  Node* left;
  Node* right;
  int data;
  int color;
};
