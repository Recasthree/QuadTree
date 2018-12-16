// function definitions

void destroyTree( Node *node );  //Task 1
void growTree( Node *node );  //Task 1

void removeChildren( Node *parent );  //Task 2

double nodeValue( Node *node, double time );  //Task 3 original
double value( double x, double y, double time );  //Task 3 original
void flagSet( Node *node );  //Task 3
void flagCalculate( Node *parent );  //Task 3
void flagWrite( Node *parent );  //Task 3

void adapt( Node *node );  //Task 3 extended
