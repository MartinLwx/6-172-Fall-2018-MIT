// Copyright (c) 2012 MIT License by 6.172 Staff

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char * argv[]) {  // What is the type of argv?  A: char **
  int i = 5;
  // The & operator here gets the address of i and stores it into pi
  int * pi = &i;
  // The * operator here dereferences pi and stores the value -- 5 --
  // into j.
  int j = *pi;

  char c[] = "6.172";
  char * pc = c;  // Valid assignment: c acts like a pointer to c[0] here.
  char d = *pc;
  printf("char d = %c\n", d);  // What does this print?  A: char d = 6, %c = 1 char 

  // compound types are read right to left in C.
  // pcp is a pointer to a pointer to a char, meaning that
  // pcp stores the address of a char pointer.
  char ** pcp;
  pcp = argv;  // Why is this assignment valid?. A: The type of argv is also char **, which is also a pointer

  const char * pcc = c;  // pcc is a pointer to char constant
  char const * pcc2 = c;  // What is the type of pcc2?. A: A constant pointer to a char

  // For each of the following, why is the assignment:
  // *pcc = '7';  // invalid? A: We can't change the value of the char const
  pcc = *pcp;     // valid? A: *pcp is still a pointer
  pcc = argv[0];  // valid? A: we can
  // A: The two are both valid, we changed what them point to (the edge, recall that the pointer IS NOT CONSTANT)
  // , rather than the value them originally point to (the value inside, recall that the char IS CONSTANS)
  // e.g. pcc -> "6.172" becomes pcc -> "7"     (NOT OK)
  // e.g. pcc -> "6.172" becomes pcc    "6.172"
  //                                 -> argv[0] (OK)

  char * const cp = c;         // cp is a const pointer to char
  // For each of the following, why is the assignment:
  // cp = *pcp;   // invalid?  A: The pointer is constant so we can't change what it points to (the edge)
  // cp = *argv;  // invalid?A A: The same as aforementioned
  *cp = '!';   // valid?    A: It's ok, the char inside is not constant

  const char * const cpc = c;  // cpc is a const pointer to char const
  // For each of the following, why is the assignment:
  // cpc = *pcp;  // invalid?
  // cpc = argv[0];  // invalid?
  // *cpc = '@';  // invalid?
  // A: Both of the pointer and the constant ARE CONSTANT
  // , so we can't change either


  return 0;
}
