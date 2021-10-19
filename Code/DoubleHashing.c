#include <stdio.h>
#include <conio.h>


int arr[10];
int count=0;
int size=10;

//This is the first hash func in which i am just taking mod of value

int hash1(int value){
	return value%size;
}

//This is second fun in which i am multipying the value by 2 then add 3 in that result and taking mod of the result. 
int hash2(int value){
	
	return ((2*value)+3)%size;
}

//Here i apply Double hashing technique
void Probe(int value){
	
	int index=hash1(value);
	
	if(count==size){
		printf("Array is Full...");
	}else if(arr[index]==0){
		arr[index]=value;
		count++;
	}else{
		
		int index2=hash2(value);
		
		int i;
		for(i=1;i<size;i++){
			
			int Index=(index+(i*index2))%size;
			if(arr[Index]==0){
				arr[Index]=value;
				count++;
				break;
			}
			
		}
		
	}
}


void print(){
	int i;
	for(i=0;i<size;i++){
		printf("arr[%d]: %d\n",i,arr[i]);
	}

}

int main(int argc, char *argv[])
{
	
	
	int i=0;
	while(i<size){
		int value;
		printf("Enter the Value: ");
		scanf("%d",&value);
		Probe(value);
		i++;
	}	
	
	print();	
	return 0;
}
