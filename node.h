//#include<stdio.h>
//#include<stdlib.h>
//#include<conio.h>


Node* newNode(int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->key = data;
	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;
	node->color = "black";
	
	return node;	
}

//Source: wiki
Node* RotateLeft(Node* n){
	Node* nnew = n->right;
	Node* p = getParent(n);
	assert(nnew != NULL);  // Since the leaves of a red-black tree are empty,
                            // they cannot become internal nodes.
  n->right = nnew->left;
  nnew->left = n;
  n->parent = nnew;
  // Handle other child/parent pointers.
  if (n->right != NULL) {
    n->right->parent = n;
  }

  // Initially n could be the root.
  if (p != NULL) {
    if (n == p->left) {
      p->left = nnew;
    } else if (n == p->right) {
      p->right = nnew;
    }
  }
  nnew->parent = p;
}

//Source: wiki
void RotateRight(Node* n) {
  Node* nnew = n->left;
  Node* p = getParent(n);
  assert(nnew != NULL);  // Since the leaves of a red-black tree are empty,
                            // they cannot become internal nodes.

  n->left = nnew->right;
  nnew->right = n;
  n->parent = nnew;

  // Handle other child/parent pointers.
  if (n->left != NULL) {
    n->left->parent = n;
  }

  // Initially n could be the root.
  if (p != NULL) {
    if (n == p->left) {
      p->left = nnew;
    } else if (n == p->right) {
      p->right = nnew;
    }
  }
  nnew->parent = p;
}


void InsertCase1(Node* n) {
  n->color = "black";
}

void InsertCase2(Node* n) {
  // Do nothing since tree is still valid.
  return;
}

void InsertCase3(Node* n) {
  getParent(n)->color = "black";
  getUncle(n)->color = "black";
  getGrandParent(n)->color = "red";
  InsertRepairTree(getGrandParent(n));
}

void InsertCase4Step2(Node* n) {
  Node* p = getParent(n);
  Node* g = getGrandParent(n);

  if (p!=NULL && n == p->left) {
    RotateRight(g);
  } else {
    RotateLeft(g);
  }
  p->color = "black";
  g->color = "red";
}

void InsertCase4(Node* n) {
	
  Node* p = getParent(n);
  Node* g = getGrandParent(n);

   if(p!=NULL && g!=NULL){
   		if (n == p->right && p == g->left) {
    		RotateLeft(p);
    		n = n->left;
  		} 
		else if (n == p->left && p == g->right) {
    		RotateRight(p);
    		n = n->right;
  		}	 	
   }

  InsertCase4Step2(n);
}



//Source : wiki 
void InsertRepairTree(Node* n) {
	
   Node* parent = getParent(n);
   Node* uncle = getUncle(n);
   
  if (parent == NULL) {
    InsertCase1(n);
  } else if (parent->color == "black") {
    InsertCase2(n);
  } else if (uncle != NULL && uncle->color == RED) {
    InsertCase3(n);
  } else {
    InsertCase4(n);
  }
}














//Source : wiki
void InsertRecurse(Node* root, Node* n) {
  // Recursively descend the tree until a leaf is found.
  if (root != NULL)
  {
    if (n->key < root->key) {
      if (root->left != NULL) {
        InsertRecurse(root->left, n);
        return;
      } else {
        root->left = n;
      }
    } else { // n->key >= root->key
      if (root->right != NULL) {
        InsertRecurse(root->right, n);
        return;
      } else {
        root->right = n;
      }
    }
  }

  // Insert new Node n.
  n->parent = root;
  n->left = NULL;
  n->right = NULL;
  n->color = "red";
}

Node* Insert(Node* root, Node* n) {
  // Insert new Node into the current tree.
  InsertRecurse(root, n);

  // Repair the tree in case any of the red-black properties have been violated.
  InsertRepairTree(n);

  // Find the new root to return.
  root = n;
  while (getParent(root) != NULL) {
    root = getParent(root);
  }
  n->parent = getParent(n);
  return root;
}







