#include <stdio.h>

void printPattern(int n){
  for(int i=0; i<n; i++){
    for(int j=0; j<i; j++){
      printf("%c ",(97+(j%26)));
    }
    printf("\n");
  }
}

int main() {
  int n;
  printf("Enter the size: ");
  scanf("%d", &n);
  printPattern(n);
  return 0;
}
