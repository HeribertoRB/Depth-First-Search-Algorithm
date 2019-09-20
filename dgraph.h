// =======================================================
// HW#: HW7 dgraph
// Your name: Heriberto Bernal
// Compiler:  g++
// File type: headher file
//=======================================================

#include <iostream>
#include <string>
#include "slist.h"

using namespace std;

//-----  globally setting up an alias ---------------------
const int SIZE = 20;   // for the size of the graph table

// this will be in each GTable slot
struct Gvertex
{
  char vertexName;      //the vertex Name
  int outDegree;	//the Out degree
  slist adjacentOnes;   //the adjecent vertices in an slist
  int visit;            // This will hold the visit number in HW7 
}; 

class dgraph
{

private:
  Gvertex Gtable[SIZE];  // a table representing a dgraph
  int  countUsed; // how many slots of the Gtable are actually used

public:

  class BadVertex{};  // thrown when the vertex is not in the graph
 
  dgraph();    // initialize vertexName (blank) and visit numbers (0)
               // initialize countUsed to be 0
  ~dgraph(); 

 //PURPOSE: read from the input file table.txt and fill GTable
 void fillTable();  

 //PURPOSE: displays in an easy to read format 
  void displayGraph(); 

//PURPOSE: returns the out degree of a given vertex - may throw BadVertex
//PARAMETER: pass the character that will show its degree
  int findOutDegree(char);  
	
//PURPOSE: returns the adjacency list of a given vertex - may throw BadVertexx
//PARAMETER: pass the character that will show its adjacency
  slist findAdjacency(char);  

  //PURPOSE: It will give a vertex a visit number
  //PARAMETER: pass the visit number and the given vertex
  void visit(int, char);

  //PURPOSE: It will check if a vertex is already marked
  //PARAMETER: pass the vertex that will check if is marked
  bool isMarked(char);
};


