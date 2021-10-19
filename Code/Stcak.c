#include<stdio.h>
#include<conio.h>


int stack[10];
int count=0;

int main(int argc, char *argv[]) {

	char v=p();	
	printf("%c",v);
	return 0;

}


void push(int v){
	
	if(count<=9){
	
	stack[count]=v;
	count++;	
	}else{
		printf("stack overload");
	}	
}

int pop(){
	
	if(count<=0){
		return -1;
	}
	count--;
	int v=stack[count];
	stack[count]=0;
	return v;
}


struct Stack{
	int v;
	struct Stack *next;
	 
}*stkstart,*top;

void Push(int v){
	struct Stack *ptr=(struct Stack *)malloc(sizeof(struct Stack));
	ptr->v=v;
	ptr->next=NULL;
	
	if(stkstart==NULL){
		stkstart=ptr;
		top=stkstart;
	}else{
		top->next=ptr;
		top=ptr;
	}
}


int Pop(){
	int v;
	if(stkstart==NULL){
		return -1;
	}
	struct Stack *temp=NULL;
	if(top==stkstart){
		temp=top;
		v=temp->v;
		stkstart=stkstart->next;
		top=stkstart;
		free(temp);
	}else{
		
		temp=stkstart;
		while(temp->next!=top){
			temp=temp->next;
		}
		struct Stack *p=temp->next;
		v=p->v;
		temp->next=NULL;
		top=temp;
		free(p);
		
		
	}
	
	return v;


}

char p(){

	return 't';
}
