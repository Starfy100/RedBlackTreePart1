#include <iostream>
#include <string.h>
#include "node.h"

using namespace std;

/*
Written BY: Starfy100
Binary Search Tree
Program will create a binary search tree
Inputs can be read in from a user or file
Nodes are placed left or right based on if their value is higher or lower than the root
Program will be able to add, remove and check nodes
The tree can also be printed

The add, remove and print functions can be called in any order

Start Date: 3/2/2020
 */
void search(){ //checks to see if a value is present in the binary tree

}

void print(Node* current, Node* treehead, int layer){ //prints the tree, tree will appear sideways
  if (current->getRight() != NULL) { //if right is not null 
    print(current->getRight(), treehead, layer+1);
  }
  for (int i = 0; i < layer; i++){
    cout << '\t' << endl;
  }
  cout << current->getData() << endl;
  if (current->getLeft() != NULL){
    print(current->getLeft(), treehead, layer+1);
  }
}


void parse(Node* current, Node* treehead, char* userexp, int i){ //turns user input into a linked list
  //sorts user input as it is being parsed
  

  for (i = 0; i < 100; i++){
    if(userexp[i] != 32 && userexp[i] != 0){
      int converted = (int)userexp[i] - 48;
      while (userexp[i+1] != 32 && userexp[i+1] != 0){
	int temp = (int)userexp[i+1] - 48;
	converted = (converted * 10) + temp;
	i++;
      }
      cout << "converted: " << converted << endl;
      
      
      if (current == NULL){ //if the tree is empty, make new node
	cout << "tree is empty, setting tree head" << endl;
	Node* temp = new Node();
	temp->setData(converted);
	temp->setLeft(NULL);
	temp->setRight(NULL);
	treehead = temp;
	current = treehead;
	cout << "treehead data: " << treehead->getData() << endl;
      }
      
      
      else { //if the tree is not empty, place node
	cout << "else, tree is not empty" << endl;
	//bool l = true;
	while ((current->getData() < converted && current->getRight() != NULL) || (current->getData() > converted && current->getLeft() != NULL)) {
	  
	//while the left or right nodes are not null
	//bool l = true;
	//while (l == true) {
       

	  //cout << "while loop" << endl;
	  //cout << "current data " << current->getData() << endl; 
	  if(current->getData() < converted){
	    //if greater, go right
	    cout << "current getRight Data: " << current->getRight()->getData() << endl;
	    //cout << "current getLeft Data: " << current->getLeft()->getData() << endl;
	    cout << "current getData: " << current->getData() << endl;
	    
	    if (current->getRight() != NULL) { //if right is not null
	      cout << "move right" << endl;
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
	    cout << "current getLeft Data: " << current->getLeft()->getData() << endl;
	    cout << "current getData: " << current->getData() << endl;
	    
	    if (current->getLeft() != NULL) {
	      cout << "move left" << endl;
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
	  cout << "current data is greater, node placed left " << endl;
	  Node* temp = new Node();
	  temp->setData(converted);
	  //temp->setLeft(NULL);
	  //temp->setRight(NULL);
	  current->setLeft(temp);
	  cout << "current data" << current->getData() << endl;
	  cout << "current left data" << current->getLeft()->getData() << endl;
	}
	else if(current->getData() < converted) {
	  cout << "current data is lesser, node placed right" << endl;
	  Node* temp = new Node();
	  temp->setData(converted);
	  //temp->setLeft(NULL);
	  //temp->setRight(NULL);
	  current->setRight(temp);
	  cout << "current data" << current->getData() << endl;
	  cout << "current right data" << current->getRight()->getData() << endl;
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

void remove(){ //removes a value from the binary tree
  //removal works on replacing the node to be removed with the next largest or next smallest node
}

void printtreehead(Node* treehead){
  cout << "treehead data: " << treehead->getData() << endl;
  cout << "treehead left data: " << treehead->getLeft()->getData() << endl;
  cout << "treehead right data: " << treehead->getRight()->getData() << endl;
}

int main(){

  bool running = true;
  char userinput;
  char* userexp = new char[100]; 
  for (int u = 0; u < 100; u++){
    //cout << "clearing userexp" << endl;
    userexp[u] = 0;
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
    cout << "What do you want to do? ('e', 'p', or 'q')" << endl;
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
	cout << "enter each number separated by a space" << endl;
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
	cout << "enter file name" << endl;
      }
      
      
    }
    
    else if (userinput == 'p'){
      cout << "entered 'p'" << endl;
      //printtreehead(treehead);
      //printlist();
      print(current, treehead, layer);
    }

    else if (userinput == 'r'){
      cout << "entered 'r'" << endl;
      cout << "what value do you want to remove?" << endl;
      
    }



    
  }
  return 0;
}
