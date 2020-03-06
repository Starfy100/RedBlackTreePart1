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
Nodes are placed left or right based on if their value is higher or lower than the root
Program will be able to add, remove and check nodes
The tree can also be printed

The add, remove and print functions can be called in any order

Start Date: 3/2/2020
 */
//TODO: remove nodes

bool search(Node* treehead, Node* current, char* numsearch){
  //checks to see if a value is present in the binary tree
  //cout << "What number do you want to search?" << endl;
  int converted = 0;
  //char* search = new char[10];

  //for (int c = 0; c < 10; c++){
  //search[c] = 0;
  //}

  //cin.getline(search, 10);
  
    for (int i = 0; i < 100; i++){
      if(numsearch[i] != 32 && numsearch[i] != 0){
	converted = (int)numsearch[i] - 48;
	while (numsearch[i+1] != 32 && numsearch[i+1] != 0){
	  int temp = (int)numsearch[i+1] - 48;
	  converted = (converted * 10) + temp;
	  i++;
	}
	//cout << "converted: " << converted << endl;
      }
    }
    
    while (current->getData() != converted /* && (current->getRight() == NULL || current->getLeft() == NULL) */ && converted != -1){
      //cout << "while loop, converted: " << converted << endl;
      //cout << "current: " << current->getData() << endl;
      /*
      if (current->getData() != converted && current->getRight() == NULL && current->getLeft() == NULL){
	cout << converted << " does not exist" << endl;
	
	converted = -1;
	//current->getData();
      }
    //*/

      if(converted < current->getData() && current->getLeft() != NULL){
	//if (current->getLeft() != NULL) {
	  //cout << "move left" << endl;
	  current = current->getLeft();
	  //}
      }
      
      else if (converted > current->getData() && current->getRight() != NULL){
	//if (current->getRight() != NULL) {
	  //cout << "move right" << endl;
	  current = current->getRight();
	  //}

      }

      ///*
      else if (current->getData() != converted){
	//cout << converted << " does not exist" << endl;
	
	converted = -1;
      }
      //*/
      
    }
    if (converted == current->getData()){
      //cout << converted << " does exist" << endl;
      return true;
    }
    return false;
}

void print(Node* current, /*Node* treehead,*/ int layer){
  //prints the tree, tree will appear sideways
  //cout << "printing" << endl;
  //cout << "current data" << current->getData() << endl;
  if (current->getRight() != NULL) { //if right is not null 
    //cout << "current right is not null" << endl;
    print((current->getRight()), /*treehead,*/ layer+1);
  }
  
  for (int i = 0; i < layer; i++){
    cout << '\t';
  }
  
  cout << current->getData() << endl;

  if (current->getLeft() != NULL){
    //cout << "current left is not null" << endl;
    print((current->getLeft()), /*treehead,*/ layer+1);
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
      //cout << "converted: " << converted << endl;
      
      
      if (current == NULL){ //if the tree is empty, make new node
	//cout << "tree is empty, setting tree head" << endl;
	Node* temp = new Node();
	temp->setData(converted);
	temp->setLeft(NULL);
	temp->setRight(NULL);
	treehead = temp;
	current = treehead;
	//cout << "treehead data: " << treehead->getData() << endl;
      }
      
      
      else { //if the tree is not empty, place node
	//cout << "else, tree is not empty" << endl;
	//bool l = true;
	while ((current->getData() < converted && current->getRight() != NULL) || (current->getData() > converted && current->getLeft() != NULL)) {
	  
	//while the left or right nodes are not null
	//bool l = true;
	//while (l == true) {
       

	  //cout << "while loop" << endl;
	  //cout << "current data " << current->getData() << endl; 

	  if(current->getData() < converted){
	    //if greater, go right
	    //cout << "current getRight Data: " << current->getRight()->getData() << endl;
	    //cout << "current getLeft Data: " << current->getLeft()->getData() << endl;
	    //cout << "current getData: " << current->getData() << endl;
	    
	    if (current->getRight() != NULL) { //if right is not null
	      //cout << "move right" << endl;
	      current = current->getRight();
	    }
	    /*
	    else {
	      l = false;
	    }
	    //*/
	  }
	  
	  
	  else if (current->getData() > converted) {
	    //else if smaller, go left
	    //cout << "current getRight Data: " << current->getRight()->getData() << endl;
	    //cout << "current getLeft Data: " << current->getLeft()->getData() << endl;
	    //cout << "current getData: " << current->getData() << endl;
	    
	    if (current->getLeft() != NULL) {
	      //cout << "move left" << endl;
	      current = current->getLeft();
	    }
	    /*
	    else {
	      l = false;
	    }
	    //*/
	  }
	  
	  }
	
	///*
	//create and place node
	if (current->getData() > converted){
	  //cout << "current data is greater, node placed left " << endl;
	  Node* temp = new Node();
	  temp->setData(converted);
	  //temp->setLeft(NULL);
	  //temp->setRight(NULL);
	  current->setLeft(temp);
	  temp->setParent(current);
	  current = treehead;
	  //cout << "current data" << current->getData() << endl;
	  //cout << "current left data" << current->getLeft()->getData() << endl;
	}
	else if(current->getData() < converted) {
	  //cout << "current data is lesser, node placed right" << endl;
	  Node* temp = new Node();
	  temp->setData(converted);
	  //temp->setLeft(NULL);
	  //temp->setRight(NULL);
	  current->setRight(temp);
	  temp->setParent(current);
	  current = treehead;
	  //cout << "current data" << current->getData() << endl;
	  //cout << "current right data" << current->getRight()->getData() << endl;
	}
	//*/

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
      //cout << "converted: " << converted << endl;
      
      
      if (current == NULL){ //if the tree is empty, make new node
	//cout << "tree is empty, setting tree head" << endl;
	Node* temp = new Node();
	temp->setData(converted);
	temp->setLeft(NULL);
	temp->setRight(NULL);
	treehead = temp;
	current = treehead;
	//cout << "treehead data: " << treehead->getData() << endl;
      }
      
      
      else { //if the tree is not empty, place node
	//cout << "else, tree is not empty" << endl;
	//bool l = true;
	while ((current->getData() < converted && current->getRight() != NULL) || (current->getData() > converted && current->getLeft() != NULL)) {
	  
	//while the left or right nodes are not null
	//bool l = true;
	//while (l == true) {
       

	  //cout << "while loop" << endl;
	  //cout << "current data " << current->getData() << endl; 

	  if(current->getData() < converted){
	    //if greater, go right
	    //cout << "current getRight Data: " << current->getRight()->getData() << endl;
	    //cout << "current getLeft Data: " << current->getLeft()->getData() << endl;
	    //cout << "current getData: " << current->getData() << endl;
	    
	    if (current->getRight() != NULL) { //if right is not null
	      //cout << "move right" << endl;
	      current = current->getRight();
	    }
	    /*
	    else {
	      l = false;
	    }
	    //*/
	  }
	  
	  
	  else if (current->getData() > converted) {
	    //else if smaller, go left
	    //cout << "current getRight Data: " << current->getRight()->getData() << endl;
	    //cout << "current getLeft Data: " << current->getLeft()->getData() << endl;
	    //cout << "current getData: " << current->getData() << endl;
	    
	    if (current->getLeft() != NULL) {
	      //cout << "move left" << endl;
	      current = current->getLeft();
	    }
	    /*
	    else {
	      l = false;
	    }
	    //*/
	  }
	  
	  }
	
	///*
	//create and place node
	if (current->getData() > converted){
	  //cout << "current data is greater, node placed left " << endl;
	  Node* temp = new Node();
	  temp->setData(converted);
	  //temp->setLeft(NULL);
	  //temp->setRight(NULL);
	  current->setLeft(temp);
	  temp->setParent(current);
	  current = treehead;
	  //cout << "current data" << current->getData() << endl;
	  //cout << "current left data" << current->getLeft()->getData() << endl;
	}
	else if(current->getData() < converted) {
	  //cout << "current data is lesser, node placed right" << endl;
	  Node* temp = new Node();
	  temp->setData(converted);
	  //temp->setLeft(NULL);
	  //temp->setRight(NULL);
	  current->setRight(temp);
	  temp->setParent(current);
	  current = treehead;
	  //cout << "current data" << current->getData() << endl;
	  //cout << "current right data" << current->getRight()->getData() << endl;
	}
	//*/

      }
      
      
      i++;
    }

    else {
      i++;
    }
 
  }
 
}

void remove(Node* treehead, Node* current, char* numsearch){ //removes a value from the binary tree
  //removal works on replacing the node to be removed with the next largest or next smallest node
  cout << "What number do you want to remove?" << endl;

  if(search(treehead, current, numsearch) == false){
    cout << numsearch << "number does not exist" << endl;
  }
  else {
    //once the desired node is reached, go left or right once and then the opposite direction for as far as you can go
    //once you cannot go farther, replace the first node with the second node
    //delete the second node
    cout << "deleting" << endl;
    int converted = 0;
    for (int i = 0; i < 100; i++){
      if(numsearch[i] != 32 && numsearch[i] != 0){
        converted = (int)numsearch[i] - 48;
	while (numsearch[i+1] != 32 && numsearch[i+1] != 0){
	  int temp = (int)numsearch[i+1] - 48;
	  converted = (converted * 10) + temp;
	  i++;
	}
	cout << "converted: " << converted << endl;
      }
    }

    
    
    while(current->getData() != converted){
      //cout << "while loop" << endl;
      cout << "converted " << converted << "  current data " << current->getData() << endl;
 
      if (converted > current->getData()){
	//move left
	if(current->getRight() != NULL){
	  cout << "m right" << endl;
	  current = current->getRight();
	}	
      }


      else{
	if (current->getLeft() != NULL){
	  cout << "m left" << endl;
	  current = current->getLeft();
	}
      }
      
    }
    
    cout << "current data: " << current->getData() << endl;
    Node* curtem = new Node();
    curtem = current;
    cout << "find next largest or smallest" << endl;
    //find the next largest or smallest
    //if (current->getLeft() != NULL){
      if(curtem->getLeft() != NULL){
	cout << "mm left" << endl;
	curtem = curtem->getLeft();
	cout << "curtem " << curtem->getData() << endl;
      }
      while (curtem->getRight() != NULL){
	cout << "mm right" << endl;
	curtem = curtem->getRight();
	cout << "curtem " << curtem->getData() << endl;
      }

      cout << "current data: " << current->getData() << endl;
      cout << "curtem data: " << curtem->getData() << endl;
      cout << "replacing data" << endl;


      if (current->getLeft() == NULL && current->getRight() == NULL){
	//current->setData(current->getRight()->getData());
	cout << "current left and right are null" << endl;
	if (current->getData() < current->getParent()->getData()){
	  current->getParent()->setLeft(NULL);
	}
	else {
	  current->getParent()->setRight(NULL);
	}
      }
      
      else if (current->getRight() == NULL){
	cout << "current right is null" << endl;

	if (curtem->getData() != current->getData()){
	  current->setData(curtem->getData());
	  curtem->getParent()->setRight(NULL);
	}
	else{
	  current->setData(current->getLeft()->getData());
	  current->setLeft(curtem->getLeft());
	}


      }
      else if(current->getLeft() == NULL){
	cout << "current left is null" << endl;
	
	current->setData(current->getRight()->getData());
	current->setRight(curtem->getRight());
      }
      else if (current->getLeft() != NULL && current->getRight() != NULL){
	cout << "current left and right is not null" << endl;
	current->setData(curtem->getData());

	if(curtem->getRight() == NULL){
	current->setLeft(curtem->getLeft());
	}
	else{
	  current->setRight(curtem->getRight());
	}

	
      }
  

      
      //current->setData(curtem->getData());


      //current->setLeft(curtem->getLeft());
      
      //cout << "current data: " << current->getData() << endl;
      //}
      
      //else {
      //cout << "current is now deleted" << endl;
      //delete current;
      //current = NULL;
      //current->setLeft(NULL);
      //current->setRight(NULL);
      //current->getParent()->setRight(NULL);
      //}

  }



  
}

void printtreehead(Node* treehead){
  if(treehead->getData() != 0){
    cout << "treehead data: " << treehead->getData() << endl;
  }
  if(treehead->getLeft() != NULL){
    cout << "treehead left data: " << treehead->getLeft()->getData() << endl;
  }
  if(treehead->getRight() != NULL){
    cout << "treehead right data: " << treehead->getRight()->getData() << endl;
  }
}

int main(){

  bool running = true;
  char userinput;
  char* userexp = new char[100]; 
  char* numsearch = new char[100];
  for (int u = 0; u < 100; u++){
    //cout << "clearing userexp" << endl;
    userexp[u] = 0;
    numsearch[u] = 0;
  }
  //char* search = new char[100];
  
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
	  //cout << "clearing userexp" << endl;
	  userexp[u] = 0;
	}
	
	cin.getline(userexp, 100);

	parse(current, treehead, userexp, i);
      }
      else if (userinput == 'f'){
	cout << "entered f" << endl;
	//cout << "enter file name" << endl;
	current = treehead;
	fparse(current, treehead, userexp, i);
      }
      
      
    }
    
    else if (userinput == 'p'){
      cout << "entered 'p'" << endl;
      //printtreehead(treehead);
      //printlist();
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
	cout << numsearch << " number does exist" << endl;

      }

      else{
	cout << numsearch << " number does not exist" << endl;
      }
    }


    
  }
  return 0;
}
