//Binomial expantion
#include<stdio.h>
#include<math.h>
int n;

int fact(int a) {
  if (a == 0)
    return 1;
  else
    return(a * fact(a-1));
}

int combi(int r) {
  return fact(n)/(fact(r)*fact(n-r));
}

void main() {
  int a=1,b=1,i,j,constant;
  printf("This program is applicable for the binomial expression of the form [(ax+by)^n]\nWhere a, b are the constants and x, y are variables and n is the power.\nEnter  two conatants of the expression\n(By default a=b=1 )\n");
  scanf("%d%d",&a,&b);
  printf("Enter the power of binomial expression\n");
  scanf("%d",&n);
  printf("	y= ");
  for(i=0,j=n;i<=n;i++,j--) {
    constant= combi(i)* pow(a,j) * pow(b,i);
    printf("+ ( %d (x^%d) (y^%d) ) ",constant, j, i);
  }
  printf("\n");
}
