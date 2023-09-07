// question: Write a C program that produces the following output. The output
// must be exactly as shown:
//  C uses escape sequences for a variety of purposes.
//  Some common ones are:
//       to print ", use \"
//       to print \, use \\
//      to jump to a new line, use \n

#include <stdio.h>  //include standard input/output
int main() {
  printf("C uses escape sequences for a variety of purposes.\n");
  printf("Some common ones are:\n");
  printf("     to print \", use \\\"\n");
  printf("     to print \\, use \\\\\n");
  printf("     to jump to a new line, use \\n");
  return 0;
}
