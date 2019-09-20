// ====================================================
//HW#: HW7 dgraph
//Your name: Heriberto Bernal
//Complier:  gcc compiler
//File type: dgraph implementation file
//=====================================================

#include <fstream>
#include "dgraph.h"

//PURPOSE: initialize variables of the dgraph
dgraph::dgraph()
{
  Gtable[0].vertexName = ' ';
  Gtable[0].outDegree = 0;
  Gtable[0].adjacentOnes;
  Gtable[0].visit = 0;
  countUsed = 0;
}

dgraph::~dgraph()
{
}

//PURPOSE: read from the input file table.txt and fill GTable
void dgraph::fillTable()
{
  //Set up fin stream to read from table.txt
  char x;
  ifstream fin;
  fin.open("table.txt", ios::in);
    while (fin >> Gtable[countUsed].vertexName)  // if I can read the name
      { fin >> Gtable[countUsed].outDegree;
	// Then for the outDegree times do the following: (use a for-loop)
	Gtable[countUsed].visit = 0;

	for(int i=0; i<Gtable[countUsed].outDegree; i++)
	  {
	    fin >> x;
	    (Gtable[countUsed].adjacentOnes).addRear(x);
	  }//end of for
	countUsed++;// increment the countUsed
      }//end of while
  fin.close();//close fin
}

//PURPOSE: displays in an easy to read format
void dgraph::displayGraph()
{
  for (int i = 0; i < countUsed; i++)
  {  
    cout << Gtable[i].vertexName << " ";
    cout << Gtable[i].outDegree << " ";
    cout << Gtable[i].visit << " ";
    (Gtable[i].adjacentOnes).displayAll();
  }  
}

//PURPOSE: returns the out degree of a given vertex - may throw BadVertex
//PARAMETER: pass the character that will show its degree
int dgraph::findOutDegree(char vertex)
{
  for(int i=0; i<countUsed; i++)
    {
      if(Gtable[i].vertexName == vertex)
	return Gtable[i].outDegree;
    }
  throw BadVertex{};
}

//PURPOSE: returns the adjacency list of a given vertex - may throw BadVertexx
//PARAMETER: pass the character that will show its adjacency
slist dgraph::findAdjacency(char vertex)
{
  for(int i=0; i<countUsed; i++)
    {
      if(Gtable[i].vertexName == vertex)
	{
	  return Gtable[i].adjacentOnes;
	}
    }
  throw BadVertex{};
}

//PURPOSE: It will give a vertex a visit number
//PARAMETER: pass the visit number and the given vertex
void dgraph::visit(int visitNum, char vertex)
{
  int v;
  v = (int)vertex - 65;
  Gtable[v].visit = visitNum;
  cout << vertex << " Visited" << endl;
}

//PURPOSE: It will check if a vertex is already marked
//PARAMETER: pass the vertex that will check if is marked
bool dgraph::isMarked(char vertex)
{
  int v;
  v = (int)vertex - 65;
  if(Gtable[v].visit > 0)
    return true;
  else
    return false;
}
