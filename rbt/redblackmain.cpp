#include <iostream>
#include <string.h>
#include <fstream>

#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
//#define BLACK   "\033[30m"      /* Black */
//#define GREEN   "\033[32m"      /* Green */
//#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */

//#define MAGENTA "\033[35m"      /* Magenta */

#define CYAN    "\033[36m"      /* Cyan */

//#define WHITE   "\033[37m"      /* White */

#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */

//#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
//#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
//#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
//#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
//#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
//#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

#include "node.h"

using namespace std;
/*
Written By: Starfy100
Red-Black Tree
A self balancing tree where each node is either red or black (Program displays red or blue)
The root of the tree is always black and all leaves are black
Red node will always have two black child nodes, the opposite is not always true
Every path from a given node to a null leaf will pass through the same number of black nodes
The tree follows the same rules as a binary tree where left child nodes is smaller and right child nodes are larger

Start Date: 3/10/2020
End Date: 4/20/2020
 */
int siblingcolor(Node* current) { //gets the color value of the node's sibling
  //cout << "determining sibling color" << endl;
  if (current->getParent() != NULL){
    if (current->getData() < current->getParent()->getData() && current->getParent()->getRight() != NULL){ //parent a left node, return right node color
      if (current->getParent()->getRight()->getColor() == 0) {
	//cout << "sibling color red" << endl;
	return 0;
      }
      else if (current->getParent()->getRight()->getColor() == 1) {
	//cout << "sibling color blue" << endl;
	return 1;
      }
    }	
    else if (current->getData() > current->getParent()->getData() && current->getParent()->getLeft() != NULL){ //current is a right node, return left node color
      if (current->getParent()->getLeft()->getColor() == 0) {
	//cout << "sibling color red" << endl;
	return 0;
      }
      else if (current->getParent()->getLeft()->getColor() == 1) {
	//cout << "sibling color blue" << endl;
	return 1;
      }
    }    
  }
  
  //1 also means no parent/no sibling
  //cout << "no parent/no sibling" << endl;
  return 1; 
  
    
}

void insert (Node* &current, Node* &treehead, int converted){ //inserts node into tree
  //cout << "inserting node" << endl;
  if (current == NULL){ //if the tree is empty 
    //cout << "tree is empty" << endl;
    Node* temp = new Node();
    temp->setData(converted);
    temp->setLeft(NULL);
    temp->setRight(NULL);
    temp->setParent(NULL);
    temp->setColor(1); //node is colored black/blue
    treehead = temp;
    current = treehead;
  }
  else { //else the tree is not empty
    //cout << "tree is not empty" << endl;
    while ((current->getData() <= converted && current->getRight() != NULL) || (current->getData() > converted && current->getLeft() != NULL)) {

      if (converted >= current->getData()){
	//if converted is greater, move right
	if (current->getRight() != NULL) { //if right is not null
	  //cout << "move right" << endl;
	  current = current->getRight();
	}
      }
      else if (converted < current->getData()){
	//if converted is less, move left
	if (current->getLeft() != NULL) {
	  //cout << "move left" << endl;
	  current = current->getLeft();
	}
      }
      
    }


    if (current->getData() > converted){
      //current data is greater, node placed left;
      //cout << "node placed left" << endl;
      Node* temp = new Node();
      temp->setData(converted);
      current->setLeft(temp);
      temp->setParent(current);
      temp->setColor(0); //node is set to red

      current = temp;
      //current = treehead;
    }
    else if(current->getData() <= converted) {
      //current data is lesser or equal, node placed right;
      //cout << "node placed right" << endl;
      Node* temp = new Node();
      temp->setData(converted);
      current->setRight(temp);
      temp->setParent(current);
      temp->setColor(0); //node is set to red
      current = temp;
      //current = treehead;
    }

    
  }
 
}

/*
void case1(){

}
void case2(){

}
void case3(){

}

//*/

void lflip(Node* current){ //left rotation of the passed-in node
  Node* temp =  new Node();
  temp = current->getRight();
  cout << "left flip" << endl;
  cout << "current data: " << current->getData() << endl;
  if (current->getRight()->getLeft() != NULL) {
    cout << "getright->getleft is not null" << endl;
    current->setRight(current->getRight()->getLeft());
    current->getParent()->setRight(temp);
    temp->setParent(current->getParent());
    current->setParent(temp);
    temp->setLeft(current);
  }
  else {
    cout << "getright->getleft is null" << endl;
    current->setRight(NULL);
    current->getParent()->setRight(temp);
    temp->setParent(current->getParent());
    current->setParent(temp);
    temp->setLeft(current);
  
  }
  
  //current->setParent(temp);
}
void rflip(Node* current){ //right rotation of the passed-in node
  Node* temp =  new Node();
  temp = current->getLeft();
  cout << "right flip" << endl;
  cout << "current data: " << current->getData() << endl;
  //if (current->getLeft() != NULL){
    if (current->getLeft()->getRight() != NULL){
      
      cout << "getleft->getright is not null" << endl;
      current->setLeft(current->getLeft()->getRight());
      current->getParent()->setLeft(temp);
      temp->setParent(current->getParent());
      current->setParent(temp);
      temp->setRight(current);
      
    }
    else {
      cout << "getleft->getright is null" << endl;
      current->setLeft(NULL);
      current->getParent()->setLeft(temp);
      temp->setParent(current->getParent());
      current->setParent(temp);
      temp->setRight(current);
    }

    //}
//else if (current->getLeft() == NULL) {
//    cout << "current left is null" << endl;
      
//  }


    //current->setParent(temp);
}

void case4(Node* current){
  cout << "case 4 part 2" << endl;
  if (current == current->getParent()->getLeft()){
    cout << "current parent parent data " << current->getParent()->getParent()->getData() << endl;
    rflip(current->getParent()->getParent());
  }
  else {
    cout << "current parent parent data " << current->getParent()->getParent()->getData() << endl;
    lflip(current->getParent()->getParent());
  }
  cout << "changing parent and sibling color" << endl;
  current->getParent()->setColor(1);
  
  if (current == current->getParent()->getRight()){
    cout << "set parent left red" << endl;
    current->getParent()->getLeft()->setColor(0);
  }
  else {
    cout << "set parent right red" << endl;
    current->getParent()->getRight()->setColor(0);
  }
  //current->getParent()->getParent()->setColor(0);

}



void repair(Node* &current, Node* &treehead){ //fixes the tree if any rules are broken
  //repair is recursive and only repairs the local nodes
  //there multiple cases for correction
  //case 1: the node being inserted is the root, it is painted black (blue)

  //Note: case 1 is built into the insert function
  

  cout << "entered repair" << endl;

  if (current->getParent() != NULL ){
    //case 2: if the node being inserted will have a black parent, the node remains red, no extra steps

    if (current->getParent()->getColor() == 1){
      //if parent color if black, do nothing
      cout << "the parent is blue, insert a red node" << endl;
      cout << current->getData() << endl;
      current->setColor(0); //node set to red
      current = treehead;
      
    }
    //case 3: if the parent and uncle (sibling to parent) are both red, they are recolored black and the node is inserted
    
    

    //cout << "2nd if statement" << endl;
    //cout << current->getData() << endl;
    //cout << "sibling color value: " << siblingcolor(current->getParent()) << endl;

    
    else if (current->getParent()->getColor() == 0  && siblingcolor(current->getParent()) == 0 ){
      cout << "2nd if statement" << endl;
      cout << current->getData() << endl;
      cout << "parent and uncle are both red, setting parent and uncle to blue" << endl << "no changes to inserted node" << endl;

      if (current->getParent()->getData() > current->getParent()->getParent()->getData()){ //if the current's parent is larger (parent is a right child) 
	current->getParent()->getParent()->getLeft()->setColor(1);
	cout << current->getParent()->getParent()->getLeft()->getColor() << endl;
      }
      else if (current->getParent()->getData() < current->getParent()->getParent()->getData()) { //if the current's parent is lesser (parent is a left child)
	current->getParent()->getParent()->getRight()->setColor(1);
	cout << current->getParent()->getParent()->getRight()->getColor() << endl;

      }
      current->setColor(0);
      current->getParent()->setColor(1);
      
      if (current->getParent()->getParent() != treehead){
      current->getParent()->getParent()->setColor(0);
      }
      
      current = treehead;
      //repair(current, treehead);
    }
    
    ///*
    //cout << "checking case 4" << endl;
    else if (current->getParent()->getColor() == 0 && siblingcolor(current->getParent()) == 1) {
      cout << "parent is red and uncle is blue" << endl;
      cout << "current data: " << current->getData() << endl;
      cout << "current parent data: " << current->getParent()->getData() << endl;
      if (current == current->getParent()->getRight() && current->getParent() == current->getParent()->getParent()->getLeft()) {

	cout << "rotating left" << endl;
	cout << "current data: " << current->getData() << endl;
	lflip(current->getParent());
	cout << "after left flip" << endl;
	cout << "current data: " << current->getData() << endl;
	current = current->getLeft();
	cout << "current data: " << current->getData() << endl;
      }
      
      
      else if (current == current->getParent()->getLeft() && current->getParent() == current->getParent()->getParent()->getRight()){
	cout << "rotating right" << endl;
	cout << "current data: " << current->getData() << endl;
	rflip(current->getParent());
	cout << "after right flip" << endl;
	cout << "current data: " << current->getData() << endl;
	current = current->getRight();
	cout << "current data: " << current->getData() << endl;
      }
      cout << "before case 4 part 2" << endl;
      cout << "current data: " << current->getData() << endl;
      cout << "current parent data: " << current->getParent()->getData() << endl;
      cout << "current parent parent data: " << current->getParent()->getParent()->getData() << endl;
      case4(current);
      current = treehead;
    }
  
    //*/
    
    //case 4: backflip, if the parent is red but the uncle is black perform a leftflip on parent, then rightflip and colorflip the parent and grandparent
  }

  
  else {
    cout << "current has no parent" << endl;
    cout << current->getData() << endl;
  }
  
  
}

void uparse(Node* current, Node* &treehead, char* userexp, int i){ //reads input from user

  for (i = 0; i < 100; i++){
    if(userexp[i] != 32 && userexp[i] != 0){
      int converted = (int)userexp[i] - 48;
      while (userexp[i+1] != 32 && userexp[i+1] != 0){
	int temp = (int)userexp[i+1] - 48;
	converted = (converted * 10) + temp;
	i++;
	//insert(current, treehead, converted);
      }
      //cout << "Converted: " << converted << endl;
      // cout << RED << "Converted: " << converted << RESET <<endl;
      // cout << BOLDRED << "Converted: " << converted << RESET <<endl;
      //cout << GREEN << "Converted: " << converted << RESET <<endl;
      //cout << BOLDGREEN << "Converted: " << converted << RESET <<endl;
      //cout << YELLOW << "Converted: " << converted << RESET <<endl;
      //cout << BOLDYELLOW << "Converted: " << converted << RESET <<endl;
      // cout << BLUE << "Converted: " << converted << RESET <<endl;
      //cout << BOLDBLUE << "Converted: " << converted << RESET <<endl;     
      //cout << MAGENTA << "Converted: " << converted << RESET <<endl;
      //cout << BOLDMAGENTA << "Converted: " << converted << RESET <<endl;     
      // cout << CYAN << "Converted: " << converted << RESET <<endl;
      //cout << BOLDCYAN << "Converted: " << converted << RESET <<endl;    
      //cout << WHITE << "Converted: " << converted << RESET <<endl;
      //cout << BOLDWHITE << "Converted: " << converted << RESET <<endl;
      //cout << BLACK << "Converted: " << converted << RESET <<endl;
      
      //place node into tree
      //cout << "before insert" << endl;
      insert(current, treehead, converted);
      cout << "after insert, before repair" << endl;
      repair(current, treehead);
      cout << "after repair" << endl;
 
      i++;
    } 
    else {
      i++;
    }
  }     
}

void fparse(Node* current, Node* &treehead, char* userexp, int i){ //reads inputs from a file

  cout << "enter file name" << endl;
  string line;
  char* filename = new char[100];
  char* filedata = new char[505];
 
  cin >> filename;
  cin.get();
  cout << "reading " << endl;
  ifstream myfile (filename);
  if (myfile.is_open()) {
    while (getline (myfile, line)) {
      int j = 0;
      while(line[j] != 0){
	filedata[j] = line[j];
	j++;
      }    
    }
    myfile.close();
  }
  else {
    cout << "unable to open file" << endl;
  }
  
  for (i = 0; i < 100; i++){
    if(filedata[i] != 32 && filedata[i] != 0){
      int converted = (int)filedata[i] - 48;
      while (filedata[i+1] != 32 && filedata[i+1] != 0){
	int temp = (int)filedata[i+1] - 48;
	converted = (converted * 10) + temp;
	i++;
      } 

      cout << RED << "Converted: " << converted << RESET <<endl;
      //cout << BOLDRED << "Converted: " << converted << RESET <<endl;
      //cout << BLUE << "Converted: " << converted << RESET <<endl;
      //cout << CYAN << "Converted: " << converted << RESET <<endl;

      //cout << "before file insert" << endl;
      insert(current, treehead, converted);
      cout << "after insert, before repair" << endl;
      repair(current, treehead);
      cout << "after repair" << endl;
            

      i++;
    }
    else {
      i++;
    }
  }
}

void print(Node* current, int layer){ //prints the tree
 if (current != NULL){

    if (current->getRight() != NULL) { //if right is not null 
      print((current->getRight()), layer+1);
    }
    for (int i = 0; i < layer; i++){
      cout << '\t';
    }
    
    if(current->getColor() == 0){      
      cout << RED << current->getData() << RESET << endl;
    }
    else if (current->getColor() == 1){
      cout << BLUE << current->getData() << RESET << endl;
    }
    
    if (current->getLeft() != NULL){
      print((current->getLeft()), layer+1);
    }
  }
  else {
    cout << "Nothing to print" << endl;
  }
  
}





//NOT REQUIRED FOR PART 1
/*
void remove(){ //removes a node the tree

}

void search(){ //searches the tree for a particular node

}
//*/

int main(){
  bool running = true;
  Node* treehead = NULL; //root node for the red-black tree
  Node* current = treehead; //keeps track of current position in a list/tree
  int i = 0; //keeps track of position in userexp array
  int layer = 0; //keeps track of tree layers
  char userinput;
  char* userexp = new char[100]; 
  char* numsearch = new char[100];
  for (int u = 0; u < 100; u++){
    userexp[u] = 0;
    numsearch[u] = 0;
  }
  
 
 while (running == true){
   cout << "What do you want to do? ('e', 'p', or 'q')" << endl;
   cout << "(Enter, Print, Quit)" << endl;
   cin >> userinput;
   cin.get();

   if (userinput == 'q'){ //quits the program
     cout << "entered 'q'" << endl;
     cout << "quitting" << endl;
     running = false;
   }
   
   else if (userinput == 'e'){ //triggers enter
     cout << "entered 'e'" << endl;
     cout << "read in from user or file? ('u' or 'f')" << endl;
     cin >> userinput;
     cin.get();
     
     if (userinput == 'u'){
       cout << "entered 'u'" << endl;
       cout << "enter each number separated by a space (max 100 characters)" << endl;
       current = treehead;
       cin.getline(userexp, 100);
       uparse(current, treehead, userexp, i);
       //repair(current, treehead);
     }
     else if (userinput == 'f'){
       cout << "entered 'f'" << endl;
       current = treehead;
       fparse(current, treehead, userexp, i);
       //repair(current, treehead);
     }
     else {
       cout << "Not a valid command" << endl;
     }
   }

   else if (userinput == 'p'){ //triggers print
     cout << "entered 'p'" << endl; 
     current = treehead;
     print(treehead, layer);
   }

   
   //NOT REQUIRED FOR PART 1 vvv
   /*
     else if (userinput == 'r'){ //triggers remove
       cout << "entered 'r'" << endl; 
       remove();
     }
   
   else if (userinput == 's'){ //triggers search
     cout << "entered 's'" << endl; 
     search();
   }
   //*/
   
   else {
     cout << "Not a valid command" << endl;
   }
   
 }
 return 0;
}
