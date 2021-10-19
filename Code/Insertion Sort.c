
#include<stdio.h>
#include<conio.h>



void insertionSort(int arr[],int len){
	
	int hold,j;
	int i;
	for(i=1;i<len;i++){
		
		hold=arr[i];
		j=i;
		while(j!=0 && hold<arr[j-1]){
				arr[j]=arr[j-1];
				j--;
		}		
		arr[j]=hold;
	
	}
	
}

struct Node{
	int v;
	struct Node *prev;
	struct Node *next;
} *head,*tail;

void createList(){
	int lim,i;

	printf("Enter how many you want to insert= ");
	scanf("%d",&lim);
	for(i=0;i<lim;i++){
	

	struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
	printf("Enter value[%d]:",i);
	scanf("%d",&ptr->v);
	
	ptr->next=NULL;
	ptr->prev=NULL;
	if(head==NULL){
		head=ptr;
		tail=head;
	}else{
		
		ptr->prev=tail;
		tail->next=ptr;
		tail=ptr;
		
	}	
}
	
	
}



void print(){
	struct Node *curr=head;
	while(curr!=NULL){
		printf("%d\n",curr->v);
		curr=curr->next;
	}
}


void Sort(){
	
	struct Node *curr=head->next;
	while(curr!=NULL){
		struct Node *hold=curr;
		int value=hold->v;
		
		while(hold->prev!=NULL && value<hold->prev->v){
	
			hold->v=hold->prev->v;
			hold=hold->prev;
			
		}
		hold->v=value;
		curr=curr->next;
		
		
	}
	
}


int main(int argc, char *argv[]) {

	int i;
	int arr[]={90,30,10,20,15};
	insertionSort(arr,5);
	for(i=0;i<5;i++)
	printf("%d\n",arr[i]);

//	createList();
//	Sort();
//	print();
	return 0;

}

