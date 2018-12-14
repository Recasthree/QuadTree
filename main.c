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

void writeTree( Node *head );
void writeNode( FILE *fp, Node *node );
void printOut( FILE *fp, Node *node );

// main

int main( int argc, char **argv ) {

	Node *head;
	
	// make the head node
	head = makeNode( 0.0,0.0, 0 );
	
	// make a tree
	
	//Task 1  test 1
	/*growTree( head );
	growTree( head );
	destroyTree( head );*/
	
	//Task 1  test 2
	/*growTree( head );
	makeChildren( head->child[1] );
	destroyTree( head );*/
	
	// print the tree for Gnuplot
	writeTree( head );
	//printf("dd\n");
  return 0;
}
