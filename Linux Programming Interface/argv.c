#include <stdio.h>

int main(int argc, char *argv[]){
  printf("Argument count is %d\n", argc);
  for(int i=0; i<argc; i++){
    printf("Argument %d is %s\n", i, argv[i]);
  }
}
