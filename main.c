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

double nodeValue( Node *node, double time );  //Task 3 original
double value( double x, double y, double time );  //Task 3 original
void flagSet( Node *node );  //Task 3
void flagCalculate( Node *parent );  //Task 3
void flagWrite( Node *parent );  //Task 3

void adapt( Node *node );  //Task 3 extended

void writeTree( Node *head );
void writeNode( FILE *fp, Node *node );
void printOut( FILE *fp, Node *node );

// main

int main( int argc, char **argv ) {

	Node *head;
	
	// make the head node
	head = makeNode( 0.0,0.0, 0 );
	
	// make a tree
	
	//Task 3(extended)  test 1
	int maxlevel = 6;	
	growTree( head );
	growTree( head );
	growTree( head );
	adapt( head );
	printf( "\nAfter the program, %i nodes were added and %i nodes were removed.\n",addCount,removeCount );
	
	// print the tree for Gnuplot
	writeTree( head );
	//printf("dd\n");
  return 0;
}
