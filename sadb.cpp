#include <bits/stdc++.h> 
#define MARKER '.' 
using namespace std; 

//structure of tree
struct node 
{ 
	char key; 
	struct node *left, *right; 
}; 

//------------------------------------------------------------------------------------------

// creates new nodes
struct node *newNode(int item) 
{ 
	struct node *temp = (struct node *)malloc(sizeof(struct node)); 
	temp->key = item; 
	temp->left = temp->right = NULL; 
	return temp; 
} 


//------------------------------------------------------------------------------------------

void serialize(node *root, FILE *yfile) 
{ 
    //wherever node is null -1 is given to those
    if (root == NULL) 
    { 
        fprintf(yfile, "%c ", MARKER); 
        return; 
    } 
    //otherwise storage is done
    //done in preorder form
    fprintf(yfile, "%c ", root->key); 
    serialize(root->left, yfile); 
    serialize(root->right, yfile); 
} 

//------------------------------------------------------------------------------------------

void deserialize(node *&root, FILE *yfiles) 
{ 
    //searching for end of file or empty node '.'
    char val; 
    if ( !fscanf(yfiles, "%c ", &val) || val == MARKER) 
       return; 
  
    //otherwise create node
    root = newNode(val); 
    deserialize(root->left, yfiles); 
    deserialize(root->right, yfiles); 
} 

//------------------------------------------------------------------------------------------

void preorder(struct node *root) 
{ 
	if (root != NULL) 
	{ 
		cout<<root->key<<"  "; 
		preorder(root->left); 
		preorder(root->right); 
	} 
} 

//------------------------------------------------------------------------------------------

//creating tree
struct node* insert(struct node* node, char key) 
{ 
	//if no node is there
	if (node == NULL) return newNode(key); 

	//constructing left subtree
	if (key <= node->key) 
		node->left = insert(node->left, key); 

	////constructing right subtree
	else if (key >= node->key) 
		node->right = insert(node->right, key); 

	return node; 
} 

//------------------------------------------------------------------------------------------

//reading arguments from terminal in argv
int main(int argc, char** argv) 
{ 
	struct node *root = NULL; 

	//if create command is given
	string s=argv[1];
	if(s.compare("create")==0)
	{
		ifstream myfile (argv[2]);
  		string line;
  		
  		while(getline(myfile, line))
		{
			for(int j=0; j<line.size(); j++)
				root = insert(root, line[j]);
		}

		cout<<"tree constructed successfully\nPreorder traversal : \n";
		preorder(root);
		cout<<"\n";

		//now opening file given in argument and serialising tree
		FILE *yfile = fopen(argv[3], "w"); 
    	if (yfile == NULL) 
    	{ 
        	puts("Could not open file"); 
        	return 0; 
   		} 
    	serialize(root, yfile); 
	}


	//if load argument is passed then csv file is loaded
	if(s.compare("load")==0)
	{
		node *root1 = NULL; 
    FILE *yfiles = fopen(argv[2], "r"); 
    deserialize(root1, yfiles); 
  	
  	cout<<"Preorder traversal after deserialisation : \n";
    preorder(root1); 
    cout<<"\n";
	}
  }