#include <stdio.h>
#include <conio.h>


int main(int argc, char *argv[])
{
	
 	return 0;
}


int arr[5];
int front=-1;
int rear=-1;
int size=sizeof(arr)/4;
	
void enqueue(int value){
	
	if((rear==size-1 && front==0 ) || (front==rear+1)){
		
		printf("Queue is full");
	}else {
		if(front==-1){
			front=0;
		}
		
		rear=(rear+1)%size;
		arr[rear]=value;
		
	}	
	
	
}


int dequeue(){
	int v;
	if(front==-1 && rear==-1){
		printf("Queue is empty");
		
	}else{
		
		if(front==rear){
			front=rear=-1;
		}else{
			v=arr[front];
			arr[front]=0;
			front=(front+1)%size;		
		}
	}
	
	return v;
}

void printqueue(){
	int i;
	if((rear==-1 && front==-1) || (front==rear)){
		printf("Queue is empty");
		
	}else{
	
	for(i=front;i<=rear;i++){
		printf("%d\n",arr[i]);
	}	
	}
}
