#include<stdio.h>
#include<conio.h>


int queue[10];
int count=0;

int main(int argc, char *argv[]) {

	Enqueue(10);
	Enqueue(20);
	Enqueue(30);
	Enqueue(40);
	printf("%d",Dequeue());
	printf("%d",Dequeue());
	printf("%d",Dequeue());
	printf("%d",Dequeue());
	printf("%d",Dequeue());
	
	
	return 0;

}


void enqueue(int v){
	if(count<=9){
		
		queue[count]=v;
		count++;
	}else{
		printf("Queue overl oad");
	}
}


int dequeue(){
	int v=queue[0];
	int i;
	
    for(i=0;i<10;i++){
		if(i==9){
			queue[i]=0;
		}else{
			queue[i]=queue[i+1];
		}
	}
	count--;
	return v;
}


struct Queue{
	int v;
	struct Queue *next;
	
}*start,*tail;



void Enqueue(int v){
	
	struct Queue *ptr=(struct Queue *)malloc(sizeof(struct Queue));
	ptr->v=v;
	ptr->next=NULL;
	
	if(start==NULL){
		start=ptr;
		tail=ptr;
	}else{
		
		tail->next=ptr;
		tail=ptr;
		
	}
}

int Dequeue(){
	int v=-1;
	if(start!=NULL){
		struct Queue *p=start;
		v=p->v;
		start=start->next;
		free(p);
	}
	return v;
}
