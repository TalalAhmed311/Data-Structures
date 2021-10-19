#include <stdio.h>
#include <conio.h>

struct BSTNode{
	
	int value;
	struct BSTNode *left;
	struct BSTNode *right;
	
	
}*root=NULL;



// I implement this queue for level of order traversing.

struct Queue{
	
	struct BSTNode *data;
	struct Queue *next;

}*head=NULL,*tail=NULL;

void enqueue(struct BSTNode *node){
	
	struct Queue *temp=(struct Queue *)malloc(sizeof(struct Queue));
	temp->data=node;
	temp->next=NULL;
	
	if(head==NULL){
		
		head=temp;
		tail=head;
		
	}else{
		
		tail->next=temp;
		tail=temp;
		
	}
	
}


struct BSTNode* dequeue(){
	
	if(head!=NULL){
		struct Queue *temp=head;
		head=head->next;
		struct BSTNode *ptr=temp->data;
		free(temp);
		return ptr;
			
	}
	
	return NULL;
}

int isEmpty(){
	
	if(head==NULL){
		return 0;
	}
	
	return 1;
}


// Insertion in Tree  useing iterative method

void insert(int value){
	
	struct BSTNode *temp=(struct BSTNode *)malloc(sizeof(struct BSTNode));
	temp->value=value;
	temp->left=NULL;
	temp->right=NULL;
	
	if(root==NULL){
		root=temp;
	}else{
		
		struct BSTNode *curr=root;
		struct BSTNode *parent;
		
		while(curr!=NULL){
			
				parent=curr;
				
				if(curr->value>value){
				
					curr=curr->left;
				
				}else{
				
					curr=curr->right;
				}
		
			
		}
		
		if(parent->value>value){
			parent->left=temp;
		}else{
			parent->right=temp;
		}
	}
	
	
}


// recursive Insertion

struct BSTNode *Rinsert(struct BSTNode *node,int value){
	
	if(node==NULL){

		struct BSTNode *temp=(struct BSTNode *)malloc(sizeof(struct BSTNode));
		temp->value=value;
		temp->left=NULL;
		temp->right=NULL;
		return temp;
	
	}else if(node->value>value){
	
		node->left =Rinsert(node->left,value);
				
	}else{
		node->right=Rinsert(node->right,value);
	}
	
	return node;
	
}





//Leve of Order Traversing

void levelOfOrder(struct BSTNode *node){
	
	 enqueue(node);
	
	 while(isEmpty()){
	 	struct BSTNode *temp=dequeue();
	 	printf("%d\n",temp->value);
	 	
	 	if(temp->left!=NULL){
	 		enqueue(temp->left);
		 }
		
		if(temp->right!=NULL){
			enqueue(temp->right);
		}
	 }	
	 
}

// Inorder traversing

void inOrder(struct BSTNode *temp){
	
    if(temp!=NULL){
	
	    inOrder(temp->left);
     	printf("%d\n",temp->value);
	    inOrder(temp->right);
	
	}
}


// Post Order traversing

void postOrder(struct BSTNode *temp){
	if(temp!=NULL){
		postOrder(temp->left);
		postOrder(temp->right);
		printf("%d\n",temp->value);
	}
}

// PreOrder traversing

void preOrder(struct BSTNode *temp){
	
	if(temp!=NULL){
		
		printf("%d\n",temp->value);
		preOrder(temp->left);
		preOrder(temp->right);
	}
}


// Iterative Deletion


void BTdelete(struct BSTNode *node,int value){
	
	
	struct BSTNode *curr=root;
	struct BSTNode *parent=NULL;
	int flag=0;
	
	while(curr!=NULL){
		
		if(curr->value==value){
			flag=1;
			break;
		
		}else if(curr->value>value){
		
			parent=curr;		
			curr=curr->left;
	
		}else{
			parent=curr;
			curr=curr->right;		
		}
	}	

	
	if(flag==1){

	
		if(curr->left==NULL && curr->right==NULL){ // When both left and right node are null of the deleted node
			
			if(parent->left->value==curr->value){
				parent->left=NULL;
			
			}else if(parent->right->value==curr->value){
				parent->right=NULL;
			}
		
		}else if(curr->left!=NULL && curr->right!=NULL){ // When both left and right node are not null of the deleted node
			
			printf("cond2");
			
			struct BSTNode *temp=curr->left;

//			Find highest value from left side
			
			while(temp->right!=NULL){
				temp=temp->right;
			}	
			
//			Swap the values

			curr->value=temp->value;
	
			parent=curr;
			curr=curr->left;
			
			while(curr->right!=NULL){
				parent=curr;
				curr=curr->right;
				
			}			
			
			
			if(parent->right->value==curr->value){
				parent->right=curr->left;
			}else{
				parent->left=curr->left;
			}
			
		}else{ // When either left or right node are null of the deleted node
			
			
			
			if(parent->left->value==curr->value){
				
				if(curr->right!=NULL){
					parent->left=curr->right;
					
				}
				
				if(curr->left!=NULL){
					parent->left=curr->left;
				}
			}
			
			if(parent->right->value==curr->value){
				
				if(curr->left!=NULL){
					parent->right=curr->left;
				}
			
				if(curr->right!=NULL){
					parent->right=curr->right;
				}	
			}
			
		}

		
	}else{
		printf("Value does not exist...");
	}

}

// Recursive Deletion

struct BSTNode* BSTdelete(struct BSTNode *node,int value){
	
	
	if(node==NULL){
		return NULL;
	}
	
	if(node->value>value){
	
		node->left=BSTdelete(node->left,value);
		
	
	}else if(node->value<value){
	
		node->right= BSTdelete(node->right,value);
	
	}else{
	
		if(node->left==NULL){
			struct BSTNode *temp=node->right;
			free(node);
			return temp;
		}
	
		if(node->right==NULL){

			struct BSTNode *temp=node->left;
			free(node);
			return temp;
		}
		
		
		struct BSTNode *temp=node->left;
	
		while(temp->right!=NULL){
		
			temp=temp->right;
		
		}

		node->value=temp->value;
		node->left=BSTdelete(node->left,temp->value);

	}
	
	
	return node;
}


// Iterative search

void search(int value){
	
	struct BSTNode *temp=root;
	int flag=1;

	while(temp!=NULL){
		if(temp->value==value){
			printf("Found\n");
			flag=0;
			break;
		
		}else if(temp->value>value){
	
			temp=temp->left;			
		}else{
			
			temp=temp->right;
		}
	}
	
	if(flag==1){
		printf("Not found\n");
	}
}


// Recursive search

void Rsearch(struct BSTNode *node,int value){
	
	if(node==NULL){
		return;
	}
	
	if(node->value==value){
		
		printf("Found");
	
	}else if(node->value>value){
		
		Rsearch(node->left,value);
	}else{
	
		Rsearch(node->right,value);
	
	}
	
}




// Find maximum value iteratively

int MaxValue(struct BSTNode *node){
	
	if(node==NULL){
		return -1;
	}
	
	if(node->left==NULL && node->right==NULL){
		return node->value;
	
	}else if(node->right!=NULL){
		
		while(node->right!=NULL){
			node=node->right;
		}
		
		
	}	
		
	
	return node->value;
	
}


// Find minimum value iteratively

int MinValue(struct BSTNode *node){
	if(node==NULL){
		return -1;
	}
	
	if(node->left==NULL && node->right==NULL){
		return node->value;
	
	}else if(node->left!=NULL){
		
		while(node->left!=NULL){
			node=node->left;
		}
		
		
	}	
	
	return node->value;
}

// // Find maximum value recursively
 
int RmaxValue(struct BSTNode *node){
	
	if(node->right!=NULL){
		RmaxValue(node->right);
		
	}else{
		return node->value;		
	}


}

// Find minimum value recursively

int RminValue(struct BSTNode *node){
	if(node->left!=NULL){
		RminValue(node->left);
	}else{
		return node->value;
	}
}





int main(int argc, char *argv[])
{
//
//	int flag=1;
//	while(flag){
//		printf("1)Insert Value:\n");
//		printf("2)Delete Value:\n");
//		printf("3)Traverse Tree:\n");
//		printf("4)Find Max Node from tree:\n");
//		printf("5)Find Min node from tree:\n");
//		printf("6)Search a value:\n\n");
//		printf("Select any Option:");
//		int opt,p,item;
//		scanf("%d",&opt);
//		
//		switch(opt){
//			
//			case 1:
//				printf("\n\n1)Recursive Insertion\n");
//				printf("2)Iterative Insertion\n");
//				printf("Select any technique for insertion.");
//				scanf("%d",&p);
//				printf("Enter the Value: ");
//				scnaf("%d",&item);
//				
//				if(p==1){
//				
//					//insert(item);
//				
//				}else if(p==2){
//					
//					if(root==NULL){
//					
//					root=Rinsert(root,item);
//						
//					}else{
//						Rinsert(root,item);
//					}
//				}else{
//					
//					printf("\nInvalid key:\n");	
//				}
//				break;
////			
////			case 2:
////				
////				printf("\n\n1)Recursive Deletion\n");
////				printf("2)Iterative Deletion\n");
////				printf("Select any technique for deletion:");
////				scanf("%d",&p);
////				printf("Enter the Value: ");
////				scnaf("%d",&item);
////				
////				if(p==1){
////				
////					BTdelete(root,item);
////				
////				}else if(p==2){
////					
////					BSTdelete(root,item);
////				}else{
////					
////					printf("\nInvalid key:\n");	
////				}
////				
////				
////				break;
////				
////			case 3:
////				printf("1)Inorder Traversing:\n");
////				printf("2)PreOrder Traversing:\n");
////				printf("3)PostOrder Traversing:\n");
////				printf("4)Level Of Order Traversing:\n");
////				printf("Select any technique:");
////				scanf("%d",&p);
////				if(p==1){
////					inOrder(root);
////					
////				}else if(p==2){
////			
////					preOrder(root);
////			
////				}else if(p==3){
////			
////					postOrder(root);
////			
////				}else if(p==4){
////	//				levelOfOrder(root);
////				}else{
////					printf("Invalid key:\n");
////				}
////				
////				break;	
////		
////			
////			case 4:
////				printf("1)Max Node through recusive technique:\n");
////				printf("2)Max Node through Iterative technique\n");
////				printf("Select any technique:");
////				scanf("%d",&p);
////				if(p==1){
////					printf("Max Node is: ",RmaxValue(root));
////				}else if(p==2){
////					printf("Max Node is: ",MaxValue(root));
////				}else{
////					printf("Invalid key.\n");
////				}
////				break;
////		
////			case 5:
////				printf("1)Min Node through recusive technique:\n");
////				printf("2)Min Node through Iterative technique\n");
////				printf("Select any technique:");
////				scanf("%d",&p);
////				if(p==1){
////					printf("Max Node is: ",RminValue(root));
////				}else if(p==2){
////					printf("Max Node is: ",MinValue(root));
////				}else{
////					printf("Invalid key.\n");
////				}
////				
////				break;
////	
////			case 6:
////				printf("1)Search Value through Recursive technique:\n");
////				printf("2)Search Value through Iterative technique:\n");
////				printf("Select any technique: ");
////				scanf("%d",&p);
////				printf("Enter the value for search: ");
////				scanf("%d",&item);
////				
////				if(p==1){
////					search(item);
////				}else if(p==2){
////					Rsearch(root,item);
////				}else{
////					printf("Invalid key.\n");
////				}
////				break;
////			 default:
////			 	flag=0;
////			 	printf("Process End.....");
////			 	break;		
//	
//		}	
	
		
	
//	}



	root=Rinsert(root,100);
	Rinsert(root,79);
	Rinsert(root,156);
	Rinsert(root,45);
	Rinsert(root,95);
	Rinsert(root,101);
	Rinsert(root,255);
	Rinsert(root,22);
	Rinsert(root,59);
	Rinsert(root,87);
	Rinsert(root,45);
	Rinsert(root,150);
	Rinsert(root,19);
	Rinsert(root,32);
	Rinsert(root,77);
	Rinsert(root,10);
	Rinsert(root,35);
	Rinsert(root,37);

	levelOfOrder(root);

	return 0;

}









