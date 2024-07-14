#include<stdlib.h>
#include<stdio.h>
//in this program, i am going to remake Euclid's algorithm for computing
//the greatest common divisor between two values "m" and "n"
int euclids(int m, int n);
int main() {
  int m;
  int n;  
  do{
    printf("Please give positive integer value for \"m\":");
    scanf("%d",&m);
    printf("Please give positive integer value for \"n\":");
    scanf("%d",&n);
    int result = euclids(m,n);
    printf("%d\n",result);
  }while(1);
}

int euclids(int m, int n) {
  int r = 0;
  if(m < n) {
    int swap = m;
    m = n;
    n = swap;
  }
  do {
    r = m%n;
    if(r==0) {
      return n;
    }
    m = n;
    n = r;
  }while(r!=0);
  return n;
}
