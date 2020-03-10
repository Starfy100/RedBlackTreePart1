#include <iostream>
#include <string.h>
#include <fstream>
#include "node.h"

using namespace std;

/*
Written By: Starfy100
Binary Search Tree
Program will create a binary search tree
Inputs can be read in from a user or file
Nodes are placed right or left based on if their value is higher or lower than the root
Program will be able to add, remove and check nodes
The tree can also be printed

The add, remove and print functions can be called in any order

Start Date: 3/2/2020
 */


bool search(Node* treehead, Node* current, char* numsearch){
  //checks to see if a value is present in the binary tree
  int converted = 0;
   
    for (int i = 0; i < 100; i++){
      if(numsearch[i] != 32 && numsearch[i] != 0){
	converted = (int)numsearch[i] - 48;
	while (numsearch[i+1] != 32 && numsearch[i+1] != 0){
	  int temp = (int)numsearch[i+1] - 48;
	  converted = (converted * 10) + temp;
	  i++;
	}
      }
    }
    
    while (current->getData() != converted && converted != -1){
      if(converted < current->getData() && current->getLeft() != NULL){
	  current = current->getLeft();
      }
      
      else if (converted > current->getData() && current->getRight() != NULL){
	  current = current->getRight();
      }
     
      else if (current->getData() != converted){
	converted = -1;
      }      
    }
    if (converted == current->getData()){
      return true;
    }
    return false;
}

void print(Node* current, int layer){
  //prints the tree, tree will appear sideways
  
  if (current != NULL){

    if (current->getRight() != NULL) { //if right is not null 
      print((current->getRight()), layer+1);
    }
    for (int i = 0; i < layer; i++){
      cout << '\t';
    }
    cout << current->getData() << endl;
    
    if (current->getLeft() != NULL){
      print((current->getLeft()), layer+1);
    }
  }
  else {
    cout << "Nothing to print" << endl;
  }
  
}

void fparse(Node* current, Node* &treehead, char* userexp, int i){
  //turns file input into a linked list
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
      if (current == NULL){ //if the tree is empty, make new node
	Node* temp = new Node();
	temp->setData(converted);
	temp->setLeft(NULL);
	temp->setRight(NULL);
	treehead = temp;
	current = treehead;

      }
      
      
      else { //if the tree is not empty, place node
   	while ((current->getData() <= converted && current->getRight() != NULL) || (current->getData() > converted && current->getLeft() != NULL)) {
	  
	//while the left or right nodes are not null
    
	  if(current->getData() <= converted){
	    //if converted is greater/equal, go right	    
	    if (current->getRight() != NULL) { //if right is not null
	      current = current->getRight();
	    }
	    
	  }
	  
	  
	  else if (current->getData() > converted) {
	    //else if smaller, go left
	    if (current->getLeft() != NULL) {
	     
	      current = current->getLeft();
	    }
	  }
	}
	
	//create and place node
	if (current->getData() > converted){
	
	  Node* temp = new Node();
	  temp->setData(converted);
	  current->setLeft(temp);
	  temp->setParent(current);
	  current = treehead;

	}
	else if(current->getData() <= converted) {
	  //current data is lesser or equal, node placed rightl;
	  Node* temp = new Node();
	  temp->setData(converted);
	  current->setRight(temp);
	  temp->setParent(current);
	  current = treehead;

	}


      }
      
      
      i++;
    }

    else {
      i++;
    }
 
  }

  
}

void parse(Node* current, Node* &treehead, char* userexp, int i){ //turns user input into a linked list
  //sorts user input as it is being parsed
  

  for (i = 0; i < 100; i++){
    if(userexp[i] != 32 && userexp[i] != 0){
      int converted = (int)userexp[i] - 48;
      while (userexp[i+1] != 32 && userexp[i+1] != 0){
	int temp = (int)userexp[i+1] - 48;
	converted = (converted * 10) + temp;
	i++;
      }
      
      
      if (current == NULL){ //if the tree is empty, make new node
	
	Node* temp = new Node();
	temp->setData(converted);
	temp->setLeft(NULL);
	temp->setRight(NULL);
	treehead = temp;
	current = treehead;
	
      }
      
      
      else { //if the tree is not empty, place node
	while ((current->getData() <= converted && current->getRight() != NULL) || (current->getData() > converted && current->getLeft() != NULL)) {
	  
	//while the left or right nodes are not null
	
   
	  if(current->getData() <= converted){
	    //if greater, go right
	    
	    
	    if (current->getRight() != NULL) { //if right is not null
	
	      current = current->getRight();
	    }
	    
	  }
	  
	  
	  else if (current->getData() > converted) {
	    //else if smaller, go left
	 
	    
	    if (current->getLeft() != NULL) {
	   
	      current = current->getLeft();
	    }
	  
	  }
	  
	  }
	
	
	//create and place node
	if (current->getData() > converted){
	  Node* temp = new Node();
	  temp->setData(converted);
	  current->setLeft(temp);
	  temp->setParent(current);
	  current = treehead;
	
	}
	else if(current->getData() <= converted) {	
	  Node* temp = new Node();
	  temp->setData(converted);
	  current->setRight(temp);
	  temp->setParent(current);
	  current = treehead;
	 
	}
	

      }
      
      
      i++;
    }

    else {
      i++;
    }
 
  }
 
}

void remove(Node* &treehead, Node* current, char* numsearch){ //removes a value from the binary tree
  //removal works on replacing the node to be removed with the next largest or next smallest node
  cout << "What number do you want to remove?" << endl;
  
  if(search(treehead, current, numsearch) == false){
    cout << numsearch << " does not exist" << endl;
  }
  else {
    //once the desired node is reached, and if the node had two children
    //go left or right once and then the opposite direction as far as you can
    //once you cannot go farther, replace the first node with the second node
    //delete the second node
    
    //if the node has one children, move the child into the parent spot
    
    
    int converted = 0;
    for (int i = 0; i < 100; i++){
      if(numsearch[i] != 32 && numsearch[i] != 0){
        converted = (int)numsearch[i] - 48;
	while (numsearch[i+1] != 32 && numsearch[i+1] != 0){
	  int temp = (int)numsearch[i+1] - 48;
	  converted = (converted * 10) + temp;
	  i++;
	}
      }
    }
    while(current->getData() != converted){
      if (converted >= current->getData()){
	if(current->getRight() != NULL){
	  current = current->getRight();
	}	
      }
      else{
	if (current->getLeft() != NULL){ 
	  current = current->getLeft();
	}
      }
    }
    
    Node* curtem = new Node(); //curtem is the next largest item
    curtem = current;
    if(curtem->getLeft() != NULL){
      curtem = curtem->getLeft();
      while (curtem->getRight() != NULL){
	curtem = curtem->getRight();
      }
    }
    //once curtem is found, proceed to node deletion
    if(current->getData() == treehead->getData() && current->getLeft() == NULL && current->getRight() == NULL) {
      //current is only node
      treehead = NULL;
    }
    else if (current->getData() == treehead->getData() && (current->getLeft() == NULL || current->getRight() == NULL) ){
      if (current->getLeft() != NULL){
	current->setData(current->getLeft()->getData());
	current->setLeft(NULL);
      }
      else if (current->getRight() !=NULL){
	current->setData(current->getRight()->getData());
	current->setRight(NULL);
      }
    }
    else if (current->getLeft() != NULL && current->getRight() != NULL){
      //current has 2 children, replace with next smallest item
      int temp = curtem->getData(); 
      if (curtem->getData() >= curtem->getParent()->getData()){
	//if curtem is a right child
	curtem->getParent()->setRight(curtem->getLeft());
	if (curtem->getLeft() != NULL){
	  curtem->getLeft()->setParent(curtem->getParent());
	}
      }
      else if (curtem->getData() < curtem->getParent()->getData()){
	//if curtem is a left child
	curtem->getParent()->setLeft(curtem->getLeft());
	if (curtem->getLeft() != NULL){
	  curtem->getLeft()->setParent(curtem->getParent());
	}
      }
      current->setData(temp);
    }
    
    else if ( (current->getLeft() != NULL && current->getRight() == NULL) || (current->getLeft() == NULL && current->getRight() != NULL) ){
      //current only has one child, move child into current spot
      if (current->getRight() != NULL){
	if (current->getData() >= current->getParent()->getData()){
	  current->getParent()->setRight(current->getRight());
	  current->getRight()->setParent(current->getParent());
	}
	else if (current->getData() < current->getParent()->getData()) {
	  current->getParent()->setLeft(current->getRight());
	  current->getRight()->setParent(current->getParent());
	}
      }
      else if (current->getLeft() != NULL){
	if (current->getData() >= current->getParent()->getData()){
	  current->getParent()->setRight(current->getLeft());
	  current->getLeft()->setParent(current->getParent());
	}
	else if (current->getData() < current->getParent()->getData()) {
	  current->getParent()->setLeft(current->getLeft());
	  current->getLeft()->setParent(current->getParent());
	}
      }
    }
    else if (current->getLeft() == NULL && current->getRight() == NULL){
      //if current has no child	
      if (current->getData() < current->getParent()->getData()){
	curtem->getParent()->setLeft(NULL);
      }
      else {
	curtem->getParent()->setRight(NULL);
      }
    } 
  }  
}

int main(){
  bool running = true;
  char userinput;
  char* userexp = new char[100]; 
  char* numsearch = new char[100];
  for (int u = 0; u < 100; u++){
    userexp[u] = 0;
    numsearch[u] = 0;
  }
  int layer = 0; //keeps track of tree layers
  int i = 0; //keeps track of position in userexp array
  Node* treehead = NULL; //root node for the binary tree
  Node* current = treehead; //keeps track of current position in a list

  /* 
      /\
     /__\
    /\  /\
   /__\/__\
  */

  while (running == true){
    cout << "What do you want to do? ('e', 'p', 's', 'r', or 'q')" << endl;
    cout << "(Enter, Print, Search, Remove, Quit)" << endl;
    cin >> userinput;
    cin.get();
    if (userinput == 'q'){
      running = false;
    }
    else if (userinput == 'e'){
      cout << "entered 'e'" << endl;
      cout << "read in from user or file? ('u' or 'f')" << endl;
      cin >> userinput;
      cin.get();
      
      if (userinput == 'u'){
	cout << "entered u" << endl;
	cout << "enter each number separated by a space (max 100 characters)" << endl;
	current = treehead;
	for (int u = 0; u < 100; u++){
	  userexp[u] = 0;
	}	
	cin.getline(userexp, 100);
	parse(current, treehead, userexp, i);
      }
      else if (userinput == 'f'){
	cout << "entered f" << endl;
	current = treehead;
	fparse(current, treehead, userexp, i);
      }       
    }
    else if (userinput == 'p'){
      cout << "entered 'p'" << endl;
      current = treehead;
      print(treehead, layer);
    }
    else if (userinput == 'r'){
      cout << "entered 'r'" << endl;
      cout << "what value do you want to remove?" << endl;
      current = treehead;
      cin.getline(numsearch , 100);
      remove(treehead, current, numsearch);
    }
    else if (userinput == 's'){
      cout << "entered 's'" << endl;
      cout << "what value do you want to search?" << endl;
      current = treehead;
      cin.getline(numsearch , 100);
      if (search(treehead, current, numsearch) == true){
	cout << numsearch << " does exist" << endl;
      }
      else{
	cout << numsearch << " does not exist" << endl;
      }
    }
  }
  return 0;
}
