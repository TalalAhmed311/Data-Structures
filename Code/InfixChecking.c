	#include<stdio.h>
#include<conio.h>
#include<string.h>


int isOperator(char value){

    if(value=='|' || value=='!' || value=='=' || value=='&' || value==' <' || value=='>'
    || value=='+' || value=='-' || value=='/' || value=='*' || value=='^'){
    	return 1;
	}

    return 0;
}


int isOperand(char item){
	
	 if((item>='A' && item<='Z') || (item>='a' && item<='z') || (item>='1' && item<='9') ) {
		return 1;
	}
	return 0;
}

int check_brackets_operand(char item1,char item2){

	if(item1=='(' && item2==')'){
		return 1;
	}else if(isOperand(item1)==1 && isOperand(item2)==1){
		return 1;
	}
		
	return 0;
}

void infixcheck(char infix[]){
	
	int icount=0,jcount=0;
	int i=0;
	int j=strlen(infix);
	char item;
	int flag=0;
	if(j>2){
		
		if(check_brackets_operand(infix[i],infix[j-1])==1){
		
			i++;
			while(i<j-1){
				item=infix[i];
				if(item=='('){
					icount++;
					
					if(isOperand(infix[i+1])==0){
						
						printf("After ( there must be an operand");
						flag=1;
						break;		
					}
			
				}else if(item==')'){
					jcount++;		
				
				}else if(isOperand(item)==1){
						
					if(isOperator(infix[i+1])==0){
						printf("There must be an operator after an operand. ");
						flag=1;
						break;
					}
					
				}else if(isOperator(item)==1 ){
					
					if(isOperand(infix[i+1])==0){
						printf("There must be an operand after an operator");
						flag=1;
						break;
					}
					
				}else{
					printf("Expression is wrong");
					flag=1;
					break;
				}
				
				i++;
			}
			
			if(icount!=jcount){
				printf("Error:brackets are missing..");
		
			}else if(flag==0){
				printf("Expression is valid....");
			}
			
	}else{
		printf("Expression must start and end with Brackets or Opearands ");
	}
		
	}else{
		printf("Expression length must be greater than 2");
	}
	
	
}

int main(int argc, char const *argv[])
{   

	char infix[100];
	printf("Enter infix Expression: ");
	gets(infix);   	
	infixcheck(infix);

	return 0;
}
