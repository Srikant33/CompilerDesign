#include<stdio.h>
#include<conio.h>
char stack[20];
int top=-1;
void push(char x)
{
stack[++top]=x;
}
char pop()
{
if(top==-1){
return -1;
}
Else
{
return stack[top--];
}
}
//Check the priority of the operator.
int priority(char x)
{
if(x == ‘(‘)
return 0;
if(x == ‘+’ || x == ‘-‘)
return 1;
if(x == ‘*’ || x == ‘/’)
return 2;
}
main()
{
char exp[20];
char *e , x;
clrscr();
printf(“Ënter the expression:”);
scanf(“%s”,&exp);
e = exp ;
while(*e != ‘\0’)
{
if(isalnum(*e))
printf(“%c”,*e);
else if(*e == ‘(‘)
push(*e);
else if(*e == ‘)’ )
{
while(( x =pop() ) != ‘( ‘ )
printf(“%c”,x);
}
else
{
//check greater priority operator.
while(priority(stack[top]) >= priority(*e) )
printf(“%c”, pop());
push(*e);
}
e++;
}
while(top != -1)
{
printf(“%c”,pop());
}
}