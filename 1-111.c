#include<stdlib.h>
#include<stdio.h>
//will repeat euclid's algorithm this time attepmting to use recursive function

void euclid_recursive(int m, int n, int* r);
int main() {
  int m, n, r;
  printf("Enter positive integer value for \"m\":");
  scanf("%d", &m);
  printf("Enter positive integer value for \"n\":");
  scanf("%d", &n);
  //m<n check
  if( m < n ) {
    r = m;
    m = n; 
    n = r;
  }
  euclid_recursive(m, n, &r);
  printf("\n%d", r);
}
void euclid_recursive(int m, int n, int* r) {
  *r = m % n;
  printf("\n%d mod %d = %d", m, n, *r);
  if(*r != 0)euclid_recursive(n, *r, r);
  else *r = n;
}
/*
sample execution -
./a.out     
Enter positive integer value for "m":544
Enter positive integer value for "n":119

544 mod 119 = 68
119 mod 68 = 51
68 mod 51 = 17
51 mod 17 = 0
17%
*/
