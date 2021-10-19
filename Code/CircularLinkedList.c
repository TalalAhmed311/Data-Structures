#include<stdio.h>
#include<conio.h>

struct Node{
	int value;
	struct Node *next;
} *head,*tail;


void insert(int value){
	struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
	ptr->value=value;
	if(head==NULL){
		head=ptr;
		tail=head;
	}else{
		tail->next=ptr;
		tail=ptr;
		tail->next=head;
	}
	
}


void traverse(){
	struct Node *curr=head;
if(head==NULL){
	printf("List is empty");
}else{
	do{
		printf("%d\n",curr->value);
		curr=curr->next;
		
	}while(curr!=head);
	
}
	
}

void Delete(int value){
	
	int flag=0;
	if(head==NULL){
		
		printf("List is empty");
		flag=1;
	}else if(head->value==value){
	
			struct Node *temp=head;
			head=head->next;
			tail->next=head;
			free(temp);
			flag=1;
	}else{
		struct Node *temp=head->next;
		struct Node *prev=head;
		while(temp!=head){
			if(temp->value==value){
				prev->next=temp->next;
				free(temp);
				flag=1;
				break;
			}
			prev=temp;
			temp=temp->next;
		}
	}
	
	if(flag==0){
		printf("Value not exist.\n");
	}
	
}

void search(int value){
	int flag=0;
		
	if(head==NULL){
		
		printf("List is empty.");
		
	}else{
	
	if(head->value=value){
		printf("found\n");
		flag=1;
	}else{
		struct Node *temp=head->next;
		while(temp!=head){
			
			if(temp->value==value){
				printf("Found\n");
				flag=1;
				break;
			}
			temp=temp->next;
		}
		

	}	
	if(flag==0){
			printf("Not found.");
	}
	}
}


int main(int argc, char *argv[]) {
			
	head=NULL;
	insert(10);
	insert(20);
	insert(30);
	insert(40);
	return 0;
	
}

