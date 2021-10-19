#include<stdio.h>
#include<conio.h>



struct Value{
	int value;
	struct Value *next;
};




struct Value *arr[10];

void create(){
	
	
	int lim,i;
	
	for(i=0;i<10;i++){
		arr[i]=NULL;
		
	}
	
	printf("How many values you want to insert: ");
	scanf("%d",&lim);
	
	for(i=1;i<=lim;i++){
		
		struct Value *ptr=(struct Value*)malloc(sizeof(struct Value));
		ptr->next=NULL;
		
		printf("Enter Value[%d]: ",i);
		scanf("%d",&ptr->value);
		
		int index=(ptr->value)%10;
		
		if(arr[index]==NULL){
			arr[index]=ptr;	
			
		}else{
			struct Value *curr=arr[index];
			while(curr->next!=NULL){
				
				curr=curr->next;
			}
			
			curr->next=ptr;
		}
		
	}
	

}


void print(){
	int i;
	for(i=0;i<10;i++){
		printf("\nChain[%d]",i);
		struct Value *curr=arr[i];
		while(curr!=NULL){
			printf("->%d",curr->value);
			curr=curr->next;
		}
	}
	
}


int main(int argc, char *argv[])
{
	create();
	print();	
	return 0;
}



