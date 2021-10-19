#include<stdio.h>
#include<conio.h>


float data[10];
int count=0;
int size=sizeof(data)/4;

void FLinearProbe(float value){
	
	
	//first i am taking the value and then cast it into int 
	//then mode that value with the size of array
	
	int temp=value;
	int index=temp%size;
	
	// If float value is less than 1 then we find the index by this algorithm
	//In this i am taking the the float value in an array e.g 0.123
	//Then after that i am creating another Temporary array in which i am storing 2 values after decimal 
	//and then convert it into int with the help of atoi function and then finding the index 
	//This algorithm is also sets the values which are less than 1 but just taking mpre time 
	//So for saving the time i include this logic in this algorithm
	
	if(value<1){
		char arr[4];
		gcvt(value,2,arr);
		int i,j=0;
		char temp[2];
	
		for(i=2;i<4;i++){
			temp[j]=arr[i];
			j++;
		}
		int v=atoi(temp);
		index=v%10;
	}
	
	if(count==size){
		printf("Array is full.\n");
		
	}else if(data[index]==0){
		data[index]=value;
		count++;
	}else{
		
		//Here i am doing Linear Probing for Indexing 			
		int start=index+1;
		int i;
		if(index==size-1){
			start=0;
		}
		for(i=start;i!=index;i++){
			if(data[i]==0){
				data[i]=value;
				count++;
				break;
				
			}else if(i==size-1){
				i=-1;		
			}
		
		
	}
		
}
}

//here i use quadratic probing for same purpose.

void FQuadraticProbe(float value){
	
	int temp=value;
	int index=temp%size;
	
	
	if(value<1){
		char arr[4];
		gcvt(value,2,arr);
		int i,j=0;
		char temp[2];
	
		for(i=2;i<4;i++){
			temp[j]=arr[i];
			j++;
		}
		int v=atoi(temp);
		index=v%10;
	}
	
	
	
	if(count==size){
		printf("Array is full.\n");
		
	}else if(data[index]==0){
		data[index]=value;
		count++;

	}else{
		
						
		int i;
		
		for(i=1;i<size;i++){
			
			int x=(index+(i*i))%10;
			if(data[x]==0){
				data[x]=value;
				count++;
				break;
			}
		}	

	}

}

void print(){
	int i;
	for(i=0;i<size;i++){
		printf("Value[%d]: %f\n",i,data[i]);
	}
}

int main(int argc, char *argv[])
{
	
	
	int i;
	
	for(i=0;i<size;i++){
		data[i]=0.0;
	}
	
	float value;		
	for(i=0;i<size;i++){
		
	printf("Enter Value[%d]:",i);
	scanf("%f",&value);
	FLinearProbe(value);	

	}
	
	print();
	return 0;
}

