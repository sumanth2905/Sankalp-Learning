#include<ctype.h>
#include<stdio.h>
#define size 50 // Size of stack.
char s[size];
int top=-1; // global declaration.
void push(char elem) { //Fonction to push operation
  s[++top]=elem;
}
char pop() { //Funtion for pop operation.
  return(s[top--]);
}
int pr(char elem) { //Funtion for precedence.
  switch(elem) {
    case '#': return 0;
    case '(': return 1;
    case '+':
    case '-': return 2;
    case '*': 
    case '/':
    case '%': return 3;
    case '^': return 4;
  }
}
void main() { //Main Program
  char infx[50],pofx[50],ch,elem;
  int i=0,k=0;
  printf("\n\nEnter the infix expression ");
  scanf("%s",infx);
  push('#');
  while((ch=infx[i++])!='\0') {
    if(ch=='(')
      push(ch);
    else if(isalnum(ch))
      pofx[k++]=ch;
    else if(ch==')') {
      while(s[top]!='(') {
        pofx[k++]=pop();
      }
      elem=pop(); //remove (
    }
    else { //operator
      while(pr(s[top])>=pr(ch)) {
        pofx[k++]=pop();
      }
      push(ch);
    }
  }
  while(s[top]!='#') { //pop from stack till empty
    pofx[k++]=pop();
  }
  pofx[k]='\0'; // Make pofx as valid string
  printf("\n\nGiven infix expression: %s \n postfix expression is: %s\n",infx,pofx);
}
