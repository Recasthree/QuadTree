//The global variable

int addCount = 0,removeCount = 0;

//free the leaf nodes         ( Task 1 )

void destroyTree( Node *node ) {
	
	int i;
	if( node->child[0] == NULL && node->child[1] == NULL && node->child[2] == NULL && node->child[3] == NULL ) {
		free( node );
	}
	else{
		for( i=0;i<4;++i ) {
			if ( node->child[i] != NULL ) {
				destroyTree( node->child[i] );
				node->child[i] = NULL;
			}
		}	
		free( node );
		node = NULL;
	}
	
}

//grow the tree with the level         ( Task 1 )

void growTree( Node *node ) {
	
	int i;
	if( node != NULL ) {
		if ( node->child[0] == NULL && node->child[1] == NULL && node->child[2] == NULL && node->child[3] == NULL ) {
			makeChildren( node );
		}
		else{
			for( i=0;i<4;++i ) {
				if ( node->child[i] != NULL )
					growTree( node->child[i] );
			}
		}
	}
}

//remove all children of the parent node         ( Task 2 )

void removeChildren( Node *parent ) {
	
	int i;
	if( parent != NULL ) {
		for( i=0;i<4;++i ) {
			if ( parent->child[i] != NULL ) {
				free( parent->child[i] );
				parent->child[i] = NULL;
			}
		}
	}
}

//Let all flag of the node to be 0         ( Task 3 )

void flagSet( Node *node ) {
	
	int i;
	if( node != NULL ) {
		for( i=0;i<4;++i ) {
			if ( node->child[i] != NULL ) {
				flagSet( node->child[i] );
			}
		node->flag = 0;
		}
	}
}

//calculate the value(x,y,t) to get the flag of the node         ( Task 3 )

void flagCalculate( Node *parent ) {
	
	int result,i;
	double value;
	if( parent->child[0] == NULL && parent->child[1] == NULL && parent->child[2] == NULL && parent->child[3] == NULL ) {
		value = nodeValue( parent, 0.0 );
			if( value > 0.5 ) {
				result = 1;
			}
			if( value < -0.5 ) {
				result = -1;
			}
			if( value <= 0.5 && value >= -0.5 ) {
				result = 0;
			}
		parent->flag = result;
	}
	else{
		for( i=0;i<4;++i ) {
			if ( parent->child[i] != NULL ) {
				flagCalculate( parent->child[i] );
			}
		}
	}
}

//According to the flag, adding and removing the leaf node         ( Task 3 )

void flagWrite( Node *parent ) {

	int i;
	if( parent->child[0] == NULL ) {
		if ( parent->flag == 1 ) {
			makeChildren( parent );
			addCount += 4;
		}
	}
	else {
		if ( parent->child[0]->flag == -1 && parent->child[1]->flag == -1 && parent->child[2]->flag == -1 && parent->child[3]->flag == -1 ) {
			removeChildren( parent );
			removeCount += 4;
		}
		else {
			for( i=0;i<4;++i ) {
				flagWrite( parent->child[i] );
			}
		}		
	}
}

