#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 100
char stack[size];
int top=-1;

int presedence(char operators)
{
    switch(operators)
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

char pop()
{
    return stack[top--];
}

void push(char value)
{
    stack[++top]=value;
}

int isOperator(char value)
{
    if (value=='|' || value=='&' || value=='<' || value=='>' || value=='=' || value=='+' || value=='-' || value=='*' ||
        value=='/' || value=='^' || value=='!' )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isOperand(char value)
{
    if((value>='A' && value<='Z') || (value>='a' && value<='z') || (value>='1' && value<='9'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void infixToPostfix(char infix[])
{
	char postfix[100];
    int i=0,j=0;
    char temp,ch;
    while(infix[i]!='\0')
    {	
        ch=infix[i];
	    if(ch=='(')
        {
            push(ch);
        }
        else if(isOperand(ch)==1)
        {
            postfix[j]=ch;
            printf("Operand:%c\n",ch);
			j++;
        }
        else if(isOperator(ch)==1)
        {
            if (top==-1)
            {
            	printf("Operator:%c\n",ch);
                push(ch);
                
            }
            else
            {
                temp=pop();
                while(presedence(temp)>=presedence(ch) && temp!='(')
                {
                    postfix[j]=temp;
                    j++;
                    temp=pop();

                    if(top==-1)
                    {
                        break;
                    }
                }
                push(temp);
                push(ch);
            }
        }
        else if(ch==')')
        {
            temp=pop();
            while(temp!='(')
            {
                postfix[j]=temp;
                j++;
                temp=pop();
            }
        }

        i++;

    }

    while(top!=-1)
    {
    	temp=pop();
        postfix[j]=temp;
        j++;
	}
	
    printf("Postfix expression is: ");
    puts(postfix);
}

int main()
{

    char infix[100];
    printf("\nEnter infix expression: ");
    gets(infix);
	infixToPostfix(infix);

    return 0;
}
