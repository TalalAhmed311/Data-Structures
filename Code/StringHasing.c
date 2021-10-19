#include <stdio.h>
#include <conio.h>
#include<string.h>

char data[10][20];
int size=10;
int count=0;

// Here i am finding the hash value of the string by spliting the string into char array 
//then execute a loop in which the hash func is ruuning in which i am just casting the char value and then sum the values in a varibale
// then after that i am taking the mode of the value

int Hash(char arr[]){
	
	int hashvalue=0;
	int i;
	
	for(i=0;i<arr[i]!=NULL;i++){
		hashvalue=hashvalue+(int)arr[i];
	}	
	hashvalue=hashvalue%size;
	return hashvalue;	
}

//In this i am acheiving the same concept by using Quadratic Probing.

void QuadraticProbe(char value[]){
	
	int index=Hash(value);

    if(data[index][0]==NULL){
    	
		strcpy(data[index],value);
		printf("Value:%s\n",value);
		printf("Value[%d]:%s\n",index,data[index]);
		count++;
	}else{
	
		int i;
		for(i=1;i<size;i++){
			
			int x=(index+(i*i))%10;
			if(data[x][0]==NULL){
				strcpy(data[x],value);
				printf("Value:%s\n",value);
				printf("Value[%d]:%s\n",x,data[x]);
				count++;
				break;
			}
		}	

	}	
	
	
}


void LinearProbe(char value[]){
	
	//here i am finding the index of that particular string
		
	int index=Hash(value);
	
	//then applying linear probing for their indexing.
	
	if(data[index][0]==NULL){
		strcpy(data[index],value);
		count++;
	}else{
		int start=index+1;
		int i;
		if(index==size-1){
			start=0;
		}
		for(i=start;i!=index;i++){
		
			if(data[i][0]==NULL){
				strcpy(data[i],value);
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
		printf("Value[%d]:%s\n",i,data[i]);
		
	}
}

//In this method i am executing the code by linear probing
void linear(){
	
	char value[20];

	int i=0;
	
			while(i<size){
		
			printf("\nEnter a String: ");
			gets(value);
			printf("%d\n",Hash(value));
			LinearProbe(value);
			i++;
			}

			
}


//In this method i am executing the code by Quadratic probing
void quadratic(){
	char value[20];

	int i=0;
	
			while(i<size){
		
			printf("\nEnter a String: ");
			gets(value);
			printf("%d\n",Hash(value));
			QuadraticProbe(value);
			i++;
			}

	
	
}
int main(int argc, char *argv[])
{
	quadratic();
	print();	
	return 0;
}




