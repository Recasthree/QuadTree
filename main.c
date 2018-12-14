#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "treeStructure.h"
#include "buildTree.h"
#include "newFunction.h"

// function definitions

Node *makeNode( double x, double y, int level );
void makeChildren( Node *node );

void destroyTree( Node *node );  //Task 1
void growTree( Node *node );  //Task 1

void removeChildren( Node *parent );  //Task 2

void writeTree( Node *head );
void writeNode( FILE *fp, Node *node );
void printOut( FILE *fp, Node *node );

// main

int main( int argc, char **argv ) {

	Node *head;
	
	// make the head node
	head = makeNode( 0.0,0.0, 0 );
	
	// make a tree
	
	//Task 2  test 1	
	/*growTree( head );
	growTree( head );
	removeChildren( head->child[0] );
	//destroyTree( head );*/

	//Task 2  test 1	
	/*growTree( head );
	makeChildren( head->child[0] );
	makeChildren( head->child[1] );
	removeChildren( head->child[0] );
	//destroyTree( head );*/
	
	// print the tree for Gnuplot
	writeTree( head );
	//printf("dd\n");
  return 0;
}
