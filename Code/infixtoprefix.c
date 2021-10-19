#include<stdio.h>
#include<conio.h>
#include<string.h>

char stack[100];
int size=100;
int top=0;

//Stack 

void push(char symbol){

	stack[top]=symbol;
	top++;
		
}

char pop(){
	if(top<=0){
		return 'x';
	}
	return stack[--top]; 
}

// Precedence Table of Operators
int precedence (char operator)
{
switch(operator)
{
    case '|':
        return 1;
    
    case '&':
        return 2;
    case '<':
    case '>':
    case '!':
    case '=':
        return 3;
    case '+':
    case '-':
        return 4;
    case '*':
    case '/':
        return 5;
    case '^':
        return 6;


}
    return 0;
}


// Operator Checker 

int isOperator(char value){

    if(value=='|' || value=='!' || value=='=' || value=='&' || value==' <' || value=='>'
    || value=='+' || value=='-' || value=='/' || value=='*' || value=='^'){
        return 1;
    }

    return 0;
}

// Operand Checker

int isOperand(char item){
	
	 if((item>='A' && item<='Z') || (item>='a' && item<='z') || (item>='1' && item<='9') ) {
		return 1;			
	}
	return 0;
}

// Checking either stack is empty or not
int isEmpty(){
	if(top>0){
		return 1;
	}
	
	return 0;
}


	
// Here the infix expression is converting in prefix

void InfixtoPrefix(char infix[]){

			
			
	char prefix[100];
    int i=0,j=0;
	char item,temp;
	
	int len=strlen(infix);
	
	//reversing the array
	strrev(infix);
	
	// loop will run until the i<len of expression
	while(i<len){
		item=infix[i];
				
				
		if(item==')'){ //if  item is ) then push it in stack 
			push(item);
		}else if(isOperand(item)==1){ //if item is operand then it will go into the prefix expression
			prefix[j]=item;
			j++;
		
		}else if(isOperator(item)==1){ // if item is operator then
			
			if(isEmpty()==0){ // if stack is empty the item will be push into stack 
				push(item);
			}else{ // if not 
			// then it will check the preccedence and after checking that the expression will evaluate
						
				temp=pop();
				while(precedence(item)<precedence(temp)){
						prefix[j]=temp;
						temp=pop();
						j++;
						if(isEmpty()==0){
							break;
						}
				}
				push(temp);
				push(item);			
			}
		}else if(item=='('){ // if item is ( then it will go into expression
		
			temp=pop();
			while(temp!=')'){
				prefix[j]=temp;
				temp=pop();
				j++;
				
			}
		}
		
		i++;
	}
	
	// this loop will run when some operators are there in stack
	
	while(isEmpty()==1){
		prefix[j]=pop();
		j++;
	}	
	
	strrev(prefix);	
	printf("Prefix Expression:");
	puts(prefix);
}


int main(int argc, char const *argv[])
{   

	char infix[100];
	printf("Enter an infix expression: ");
	gets(infix);		
	InfixtoPrefix(infix);
//	
//	
    return 0;
}
