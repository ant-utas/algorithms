#include<stdlib.h>
#include<stdio.h>


int euclid_v2(int m, int n);
int main() {
  int m;
  int n;
  int result;

  //prompt user for m, n
  printf("Input positive integer value for \"m\"");
  scanf("%d",&m);
  printf("Input positive integer value for \"n\"");
  scanf("%d",&n); 
  result = euclid_v2(m,n);
  printf("%d",result);
}

int euclid_v2(int m, int n) {
  int r;
  do{
    r = m % n;
    if(r==0)return n;
    m = n % r;
    if(m==0)return r;
    n = r % m;
    if(n==0)return m;
  }while(m!=1&&n!=1&&r!=1);
  return 0;
}
