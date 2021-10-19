#include<stdio.h>
#include<conio.h>


struct Node{
	int value;
	struct Node *next;
} *start;

int main(int argc, char *argv[]) {
			
	start=NULL;
	insert(60);
	insert(70);
	insert(30);
	insert(40);
	insert(50);
	insert(90);
	
	readAll();
	
	return 0;

}

void swapNodes(){
	int v1,v2;
	printf("\nEnter two node1:");
	scanf("%d",&v1);
	printf("\nEnter two node2:");
	scanf("%d",&v2);
	struct Node *curr=start->next,*prev=start;
	struct Node *p1,*p2,*n1,*n2,*s1,*s2;
	while(curr!=NULL){
		
		if(curr->value==v1){
			p1=prev;
			n1=curr->next;
			s1=curr;
		}else if(curr->value==v2){
			p2=prev;
			n2=curr->next;
			s2=curr;
		}	
		prev=curr;
		curr=curr->next;
	}
	p1->next=s2;
	p2->next=s1;
	s1->next=n2;
	s2->next=n1;
	
}

void insert(int v){
	struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
	ptr->value=v;
	ptr->next=NULL;
	if(start==NULL){
		
		start=ptr;
	}else{
		
    	struct Node *curr;
		curr=start;
		while(curr->next!=NULL){
			curr=curr->next;
		}
		curr->next=ptr;
		
	}
	
}


void readAll(){
	
	struct Node *curr=start;
	while(curr!=NULL){
		printf("%d\n",curr->value);
		curr=curr->next;
	}
	
}


void search(int v){
	
	int flag=0;
	struct Node *curr;
	curr=start;
	while(curr!=NULL){
		
		if(v==curr->value){
			printf("Found");
			flag=1;
			break;	
		}
		curr=curr->next;
	}
	
	
	if(flag==0){
		printf("Not Found");
	}
}

void Delete(int v){
	
	
	if(start->value==v){
		struct Node *temp=start;
		start=start->next;
		free(temp);
			
	}else{
		struct Node *curr=start->next;
		struct Node *prev=start;
		
		while(curr!=NULL){
			if(v==curr->value){
				prev->next=curr->next;
				free(curr);
				break;
			}else{

			prev=curr;
			curr=curr->next;
		
			}
		}
	}
	
	
	



}







