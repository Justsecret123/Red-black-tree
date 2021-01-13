void DeleteNode(Node *n){
	
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
