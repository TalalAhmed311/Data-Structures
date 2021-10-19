#include<stdio.h>
#include<conio.h>

struct Node{
	int value;
	struct Node *next;
	struct Node *prev;
} *head,*tail;

void insert(int value){
	
	struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
	ptr->value=value;
	ptr->next=NULL;
	if(head==NULL){
		head=ptr;
		tail=head;
	}else{
		
		ptr->prev=tail;
		tail->next=ptr;
		tail=ptr;
		
	}
}


void print(){
	struct Node *curr=head;
	while(curr!=NULL){
		printf("%d",curr->value);
		curr=curr->next;
	}
}

void search(int value){
	if(head==NULL){
		printf("List is empty.");
	}else{
		
		int flag=0;
		struct Node *temp=head;
		while(temp!=NULL){
			if(temp->value==value){
				printf("Found.");
				flag=1;
				break;
			}
			temp=temp->next;
		}
		
		if(flag==0){
			printf("Not Found");
		}
	}
	

}

void Delete(int value){
	if(head==NULL){
		printf("List is empty.");
		
	}else{
		int flag=0;
		if(head->value==value){
			struct Node *temp=head;
			head=head->next;
			head->prev=NULL;
			flag=1;
			free(temp);
		}else{
			
			struct Node *temp=head;
		
		}
		
	}
}

int main(int argc, char *argv[]) {
			
	head=NULL;
	insert(20);
	insert(30);
	insert(10);
		
	return 0;
}

