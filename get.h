Node* getParent(Node* node)
{
	return (node==NULL)? NULL : node->parent;
}

Node* getGrandParent(Node* node)
{
 	return (node==NULL || node->parent==NULL)? NULL : getParent(node->parent);
}

Node* getUncle(Node* node)
{
	Node* result = getGrandParent(node);
	if(result==NULL)
		{return NULL;}
	else
		{return (node->parent==result->left)? result->right : result->left;}
return NULL;
}

Node* getSibling(Node* node)
{
	if(node==NULL || node->parent==NULL)
		{return(NULL);}
	else
		{return	(node==node->parent->left)? node->parent->right : node->parent->left;}
}
