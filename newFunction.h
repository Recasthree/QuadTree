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
