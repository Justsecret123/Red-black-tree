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
	assert(nnew != NULL);  // Since the leaves of a "red"-black tree are empty,
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
  assert(nnew != NULL);  // Since the leaves of a "red"-black tree are empty,
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
  } else if (uncle != NULL && uncle->color == "red") {
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

  // Repair the tree in case any of the "red"-black properties have been violated.
  InsertRepairTree(n);

  // Find the new root to return.
  root = n;
  while (getParent(root) != NULL) {
    root = getParent(root);
  }
  n->parent = getParent(n);
  return root;
}

void ReplaceNode(Node* n, Node* child) {
  child->parent = n->parent;
  if (n == n->parent->left) {
    n->parent->left = child;
  } else {
    n->parent->right = child;
  }
}

void DeleteOneChild(Node* n) {
  // Precondition: n has at most one non-leaf child.
  Node* child = (n->right == NULL) ? n->left : n->right;
  assert(child);

  ReplaceNode(n, child);
  if (n->color == "black") {
    if (child->color == "red") {
      child->color = "black";
    } else {
      DeleteCase1(child);
    }
  }
  free(n);
}

Node* delete(Node* root, Node* n){
	
}

void DeleteCase1(Node* n) {
  if (n->parent != NULL) {
    DeleteCase2(n);
  }
}

void DeleteCase2(Node* n) {
  Node* s = getSibling(n);

  if (s->color == "red") {
    n->parent->color = "red";
    s->color = "black";
    if (n == n->parent->left) {
      RotateLeft(n->parent);
    } else {
      RotateRight(n->parent);
    }
  }
  DeleteCase3(n);
}

void DeleteCase3(Node* n) {
  Node* s = getSibling(n);

  if ((n->parent->color == "black") && (s->color == "black") &&
      (s->left->color == "black") && (s->right->color == "black")) {
    s->color = "red";
    DeleteCase1(n->parent);
  } else {
    DeleteCase4(n);
  }
}

void DeleteCase4(Node* n) {
  Node* s = getSibling(n);

  if ((n->parent->color == "red") && (s->color == "black") &&
      (s->left->color == "black") && (s->right->color == "black")) {
    s->color = "red";
    n->parent->color = "red";
  } else {
    DeleteCase5(n);
  }
}

void DeleteCase5(Node* n) {
  Node* s = getSibling(n);

  // This if statement is trivial, due to case 2 (even though case 2 changed
  // the sibling to a sibling's child, the sibling's child can't be "red", since
  // no "red" parent can have a "red" child).
  if (s->color == "black") {
    // The following statements just force the "red" to be on the left of the
    // left of the parent, or right of the right, so case six will rotate
    // correctly.
    if ((n == n->parent->left) && (s->right->color == "black" && (s->left->color == "red"))) {
      // This last test is trivial too due to cases 2-4.
      s->color = "red";
      s->left->color = "black";
      RotateRight(s);
    } else if ((n == n->parent->right) && (s->left->color == "black" && (s->right->color == "red"))) {
      // This last test is trivial too due to cases 2-4.
      s->color = "red";
      s->right->color = "black";
      RotateLeft(s);
    }
  }
  DeleteCase6(n);
}

void DeleteCase6(Node* n) {
  Node* s = getSibling(n);

  s->color = n->parent->color;
  n->parent->color = "black";

  if (n == n->parent->left) {
    s->right->color = "black";
    RotateLeft(n->parent);
  } else {
    s->left->color = "black";
    RotateRight(n->parent);
  }
}
