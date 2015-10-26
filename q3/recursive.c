#include <stdio.h>
#include <stdlib.h>

typedef struct _Binary_Tree {
	int content;
	struct _Binary_Tree *leftNode;
	struct _Binary_Tree *rightNode;
} data;
void Init(data *root);
void print_tree(data *root);
void flattenTree(data *root);

int main()
{

	data *root;
	root = (data *)malloc(sizeof(data));
	root->content = 0;
	root->leftNode = NULL;
	root->rightNode = NULL;
	Init(root);
	print_tree(root);
	flattenTree(root);
	print_tree(root);
	return 0;
}

void Init(data *root)
{
	scanf("%d", &root->content);
	printf("left node exist?(Y/N)");
	char l, r;
	scanf("%s", &l);
	if (l == 'y' || l == 'Y') {
		data *ptrLeft;
		ptrLeft = (data *)malloc(sizeof(data));
		ptrLeft->rightNode = NULL;
		ptrLeft->leftNode = NULL;
		root->leftNode = ptrLeft;
		Init(root->leftNode);
	}
	printf("right node exist?(Y/N)");
	scanf("%s", &r);
	if (r == 'y' || r == 'Y' ) {
		data *ptrRight;
		ptrRight = (data *)malloc(sizeof(data));
		ptrRight->rightNode = NULL;
		ptrRight->leftNode = NULL;
		root->rightNode = ptrRight;
		Init(root->rightNode);
	}

	return ;
}

void print_tree(data *root)
{
	if ( !root ) return;
	printf( "%d\n", root->content );
	print_tree(root->rightNode);
	print_tree(root->leftNode);

}
void flattenTree(data *root)
{
	if (root->leftNode != NULL) {
		data *tmpPtr;
		tmpPtr = root->leftNode;
		while (tmpPtr->rightNode != NULL) {
			tmpPtr = tmpPtr->rightNode;
		}
		tmpPtr->rightNode = root->rightNode;
		root->rightNode = root->leftNode;
		root->leftNode = NULL;
	}
	if (root->rightNode != NULL ) {
		flattenTree(root->rightNode);
	}
	else return;
}