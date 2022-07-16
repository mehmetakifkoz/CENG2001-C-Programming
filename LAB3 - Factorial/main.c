#include "stdio.h"

int factorial(int n){  int result = 1;  for (int i = 1; i <= n; i++){    result *= i;  }  return result;}

int main(){
  int input;
  printf("Enter a number: ");
  scanf("%d",&input);
  int output = factorial(input);
  printf("Factorial of %d is %d.\n",input,output);
}
