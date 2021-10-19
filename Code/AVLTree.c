#include <stdio.h>
#include <conio.h>
#include<stdlib.h>


struct AVLNode{
	
	int value;
	int height;
	struct AVLNode *left;
	struct AVLNode *right;
	
	
}*root=NULL;



int max(int h1,int h2){
	return h1>h1?h1:h2;
}


int getheight(struct AVLNode *node){
	if(node==NULL){
		return 0;
	}
	
	return node->height;
}



struct AVLNode *rotateleft(struct AVLNode *node){
	
	
	struct AVLNode *temp=node;
	node=node->right;
	struct AVLNode *temp2=node->left;
	node->left=temp;
	temp->right=temp2;
	
	temp->height=max(getheight(temp->left),getheight(temp->right))+1;
	node->height=max(getheight(node->left),getheight(node->right))+1;
	
	return node;
}



struct AVLNode *rotateright(struct AVLNode *node){
	
	struct AVLNode *temp=node;
	node=node->left;
	struct AVLNode *temp2=node->right;
	node->right=temp;
	temp->left=temp2;
	
	temp->height=max(getheight(temp->left),getheight(temp->right))+1;
	node->height=max(getheight(node->left),getheight(node->right))+1;
	
	return node;
}





struct AVLNode *insert(struct AVLNode *node,int value){
	
	if(node==NULL){
	
		struct AVLNode *temp=(struct AVLNode *)malloc(sizeof(struct AVLNode));
		temp->value=value;
		temp->height=1;
		temp->left=NULL;
		temp->right=NULL;
		return temp;
	
	}else if(node->value>value){
	
		node->left =insert(node->left,value);
				
	}else{
		node->right=insert(node->right,value);
	}

	node->height=max(getheight(node->left),getheight(node->right))+1;


	if(getheight(node->left)-getheight(node->right)==-2){
		if(value>node->right->value) {
				node=rotateleft(node);
		}else{
		
			node->right=rotateright(node->right);
			node=rotateleft(node);
		
		}
	}
	
	
	if(getheight(node->left)-getheight(node->right)==2){
		if(value>node->left->value) {
	
			node=rotateright(node);
	
		}else{
		
			node->left=rotateleft(node->left);
			node=rotateright(node);
		
		}
	}
	
	
	
	return node;
	
}






void inOrder(struct AVLNode *temp){
	
    if(temp!=NULL){
	
	    inOrder(temp->left);
     	printf("DATA: %d, HEIGHT: %d\n",temp->value,temp->height);
	    inOrder(temp->right);
	
	}
}


int main(int argc, char *argv[])
{
		root=insert(root, 65);
		root=insert(root, 85);
		root=insert(root, 75);
		root=insert(root, 88);
		root=insert(root, 95);
		root=insert(root, 36);
		root=insert(root, 12);
		root=insert(root, 24);
		root=insert(root, 99);
		root=insert(root, 107);
		root=insert(root, 118);
		root=insert(root, 21);
		root=insert(root, 64);
		root=insert(root, 89);
		root=insert(root, 55);
		root=insert(root, 45);
		root=insert(root, 34);
		root=insert(root, 18);
		root=insert(root, 98);
		root=insert(root, 78);
		root=insert(root, 11);
	
	inOrder(root);	
	
	return 0;

}
