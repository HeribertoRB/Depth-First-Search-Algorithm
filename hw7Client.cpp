// ====   For the HW7 Client file ==================================
  //HW#: HW7 dgraph
  //Your name: Heriberto Bernal
  //Complier:  gcc compiler
  //File type: client program (tester)
  //===========================================================

#include "dgraph.h"
#include "stack.h"

//PURPOSE of the program: This program will create a graph and implement DFS
//Algorithm/Design: The program will read a text file and fill in an array. Then, it will visit each vertex by DFS.
int main()
{
  dgraph l1;
  stack stackV;
  slist s1;
  char ver = 'A';
  int counter = 0;

  //1.Fill Table
  l1.fillTable();

  //2.Display Table
  l1.displayGraph();

  
  counter++; //visit # is 1
  l1.visit(counter, ver);//vertex A will be the first visited
  s1 = l1.findAdjacency(ver);
  s1.deleteRear(ver);
  stackV.push(ver);//push adjacency in the stack
  s1.deleteRear(ver);
  stackV.push(ver);//push adjacency in the stack
  cout << "Stack is: " << endl;
  stackV.displayAll();//display the stack
  
  while(!stackV.isEmpty())//while the stack is not empty
    {
      stackV.pop(ver);//pop next vertex from stack
      cout << "The vertex is " << ver << endl;
      if(!l1.isMarked(ver))//if vertex has not be visited
	{
	  counter++;//visit #
	  l1.visit(counter, ver);
	  s1 = l1.findAdjacency(ver);
	  while(!s1.isEmpty())//put adjacencies in the stack
	    {
	      s1.deleteRear(ver);
	      stackV.push(ver);
	    }
	}
      cout << "Stack is: " << endl;
      stackV.displayAll();//display stack
    }

  l1.displayGraph(); //display the upgraded graph
}//end of program
