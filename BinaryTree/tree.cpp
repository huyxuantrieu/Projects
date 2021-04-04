#include "tree.h"

tree::tree()
{
	root = nullptr;
}

tree::~tree()
{
	destroyTree(root);
}

void tree::destroyTree(Node* parent)
{
	if(parent != nullptr)
	{
		if(parent->left != nullptr)
		{
			destroyTree(parent->left);
		}
		if(parent->right != nullptr)
		{
			destroyTree(parent->right);
		}
		std::cout << parent->data.getBoxNum() << " " << parent->data.getSeed() << std::endl;
		delete parent;
	}
}
void tree::createLeaf(int num, char* name)
{
	plantType newData(num, name);
	Node * newNode = new Node;

	newNode->data = newData;
	newNode->left = nullptr;
	newNode->right = nullptr;
	insertLeaf(root, newNode);
}

void tree::insertLeaf(Node *& root, Node* newNode)
{
	if(!root)
	{
		root = newNode;
	//	std::cout << root->data.getBoxNum() << " " << root->data.getSeed() <<  std::endl;
		return;
	}	
	
	else if(root->data.getBoxNum() > newNode->data.getBoxNum())
	{
		insertLeaf(root->left, newNode);
	}
	
	else
	{
		insertLeaf(root->right, newNode);
	}
}

void tree::traversalPrinting(char* name, int start, int stop)
{
	recurseTraversal(name, start, stop, root);
}

void tree::recurseTraversal(char*name, int low, int high, Node *root)
{
	if(!root)
	{
		return;
	}
	//if it is greater than the low range, then go left on the tree.	
	if(root->data.getBoxNum() > low)
	{
		recurseTraversal(name, low, high, root->left);
	}
	// if the root is between the range then check the name. if it isnt corect, then check the right and left nodes ni the 'else'. 
	if(root->data.getBoxNum() <= high && root->data.getBoxNum() >= low )
	{
		if(strcmp(name, root->data.getSeed()) == 0)
		{
			std::cout << root->data.getBoxNum() << " ";

		}		
	}
	//if it is lower than the current node, then go left.
	if(root->data.getBoxNum() < high)
	{
		recurseTraversal(name, low, high, root->right);
	}
};

void tree::removeNode(int num)
{
	//goes to a private function to access root.
	removeNodePrivate(num, root);		
}


Node* tree::removeNodePrivate(int num, Node* parent)
{
	if(parent == nullptr)
	{
		return parent;
	}
	
	else if(num < parent->data.getBoxNum())
	{
		parent->left = removeNodePrivate(num, parent->left);
	}
	
	else if(num > parent->data.getBoxNum())
	{
		parent->right = removeNodePrivate(num, parent->right);
	}
	
	else
	{
		if(parent->left == nullptr) 
		{
			Node*temp = parent->right;
			delete parent;
			return temp;
		}
		
		else if(parent->right == nullptr)
		{
			Node* temp = parent->left;
			delete parent;
			return temp;
		}

		else
		{
			Node* temp = getMinNode(parent->right);
			parent->data.setBoxNum(temp->data.getBoxNum());
			parent->data.setSeed(temp->data.getSeed());
			parent->right = removeNodePrivate(temp->data.getBoxNum(), parent->right);
		}
		
	}
	return parent;
}
Node* tree::getMinNode(Node* parentRight)
{
	Node* current = parentRight;
	while(current->left != nullptr)
	{
		current = current->left;
	}
	return current;
}









