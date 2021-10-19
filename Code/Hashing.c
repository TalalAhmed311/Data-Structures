
#include <stdio.h>
#include <conio.h>


int main(int argc, char *argv[])
{
	int i=0;
	while(i<size){
		int value;
		printf("Enter the Value: ");
		sccanf("%d",&value);
		Probe(value);
		i++;
	}	
	
	print();		
 	return 0;
}

int arr[10];
int count=0;
int size=10;


int hash1(int value){
	return value%size;
}

int hash2(int value){
	
	return ((2*value)+3)%size;
}


void Probe(int value){
	
	int ndex=hash1(value);
	
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


//Linear Hashing
void linsert(int value){
	int index=value%10;
	
		if(count==size){
		printf("array is full.\n");
		
	}else if(arr[index]==0){
		arr[index]=value;
		count++;
	}else{
		
				
		int start=index+1;
		int i;
		if(index==size-1){
			start=0;
		}
		for(i=start;i!=index;i++){
			if(arr[i]==0){
				arr[i]=value;
				count++;
				break;
		}else if(i==size-1){
				i=-1;
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


void qprobing(int value){
	int index=value%10;
	if(count==size){
		printf("array is full.\n");
		
	}else if(arr[index]==0){
		arr[index]=value;
		count++;

	}else{
		
						
		int i;
		
		for(i=1;i<size;i++){
			
			int x=(index+(i*i))%10;
			if(arr[x]==0){
				arr[x]=value;
				count++;
				break;
			}
		}	

	}
	
}
