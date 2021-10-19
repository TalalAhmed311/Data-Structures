#include<stdio.h>
#include<conio.h>
#include<string.h>

//Name: Talal AHmed
//Roll: B18158059 

struct BSTNode{
	char data;
	struct BSTNode *left;
	struct BSTNode *right;
	
}*root=NULL;

struct Stack{
	struct BSTNode *node;
	struct Stack *next;
	struct Stack *prev;
	
}*start=NULL,*top=NULL;


// Operator Checker 
int isOperator(char value){

    if(value=='|' || value=='!' || value=='=' || value=='&' || value=='<' || value=='>'
    || value=='+' || value=='-' || value=='/' || value=='*' || value=='^' ){
        return 1;
    }

    return 0;
}

// Operand Checker

int isOperand(char item){
	
	 if((item>='A' && item<='Z') || (item>='a' && item<='z') || (item>='1' && item<='9') ) {
		return 1;			
	}
	return 0;
}

void push(struct BSTNode *item){
	
	struct Stack *temp=(struct Stack *)malloc(sizeof(struct Stack));
	temp->node=item;
	temp->next=NULL;
	temp->prev=NULL;
	
	if(start==NULL){
		start=temp;
		top=start;
		
	}else{
		
		temp->prev=top;
		top->next=temp;
		top=temp;
	}
	
}

struct BSTNode *pop(){
	
	struct BSTNode *temp=NULL;
	struct Stack *p;
	
	if(start==NULL){
		return NULL;
	}else if(top==start) {
		
		temp=top->node;
		p=top;
		top=NULL;
		start=top;
		free(p);
		
	}else{
		
		temp=top->node;
		p=top;
		top=top->prev;
		top->next=NULL;
		free(p);
		
		
	}
	
	return temp;
}

struct BSTNode *buildExpTree(char *postfix){
	
	int i=0;
//	printf("Start\n");
	while(postfix[i]!='\0'){
		
		if(isOperand(postfix[i])==1){
			struct BSTNode *node=(struct BSTNode *)malloc(sizeof(struct BSTNode));
			node->data=postfix[i];
			node->left=NULL;
			node->right=NULL;
	
			push(node);
			
		}else if(isOperator(postfix[i])==1){
			
			struct BSTNode *t1=pop();
			struct BSTNode *t2=pop();
					
			
			
			struct BSTNode *node=(struct BSTNode *)malloc(sizeof(struct BSTNode));
			node->data=postfix[i];
			node->left=t2;
			node->right=t1;
			push(node);
				
		}else{
			printf("Invalid Expression");
			break;
		}
		
		i++;
	}
	
	
//	printf("\nend\n");
	return top->node;
}

void inOrder(struct BSTNode *temp){
	
	if(temp!=NULL){
	
	 inOrder(temp->left);
	 printf("%c",temp->data);
	 inOrder(temp->right);

	}

}

void preOrder(struct BSTNode *temp){
	if(temp!=NULL){
		printf("%c",temp->data);
		preOrder(temp->left);
		preOrder(temp->right);
	}
}


int main(int argc, char const *argv[])
{   

	char arr[100];
	printf("Enter Postfix Expression: ");
	gets(arr);

	root=buildExpTree(arr);
	printf("\nInfix:");
	inOrder(root);	

	return 0;
}


