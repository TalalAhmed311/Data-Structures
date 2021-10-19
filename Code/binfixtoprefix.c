#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 100
char stack[size];
int top=-1;

void reverse(char infix[])
{
    int i,j;
	char rev[strlen(infix)];
	for (i=strlen(infix)-1,j=0;i+1!=0;--i,++j) {
		rev[j]=infix[i];

		if(infix[i]=='(')
        {
            rev[j]=')';
        }
        else if(infix[i]==')')
        {
            rev[j]='(';
        }
	}
	rev[j]='\0';
	strcpy(infix,rev);
	return infix;
}

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

void infixToPrefix(char infix[])
{
    reverse(infix);
    char prefix[100];
    int i=0,j=0;
    char temp,ch;

    while(infix[i]!='\0')
    {
      ch=infix[i];
	 
	   if(ch==')')
        {
            push(ch);
        }
        else if(isOperand(ch)==1)
        {
            prefix[j]=ch;
			j++;
        }
        else if(isOperator(ch)==1)
        {
            if (top==-1)
            {
                push(ch);

            }
            else
            {
                temp=pop();
                while(presedence(temp)>presedence(ch) )
                {
                    prefix[j]=temp;
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
        else if(ch=='(')
        {
            temp=pop();
            while(temp!=')')
            {
                prefix[j]=temp;
                j++;
                temp=pop();
            }
        }

        i++;

    }

    while(top!=-1)
    {
    	temp=pop();
        prefix[j]=temp;
        j++;
	}

    reverse(prefix);
    printf("\nPrefix expression is: ");
    puts(prefix);
}

int main()
{
    char infix[100];
    printf("Enter infix expression : ");
    gets(infix);

    infixToPrefix(infix);

    return 0;

}

