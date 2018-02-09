#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void makeRoot(char* name, char *family[]);

int main() {
  //make array to hold strings for family so has 7 spots
  char family[7][13]; //strs[i] = malloc(strlen("foo") + 1);

  char name[12];
  printf("What is your name? ");
  scanf("%s",&name);
  printf("%s\n",name);

  //store name into root
  makeRoot(name,family);

  //start running program until quits
  while(1){
    char input[33];
    scanf("%s", &input);
    printf("%s",input);

    if(strcmp(input,"quit")==0){//if quit then quit program
      exit(0);
    }else if(1){//if father then addFather
      printf("father");
    }else if(1){//if mother then addMother
      printf("mother");
    }else if(1){//if print then print tree
      printf("print");
    }else if(1){//if delete then delete node
      printf("delete");
    }else{//if neither return an error message
      printf("Sorry, you put an invalid command!");
    }
  }

}

//methods
void makeRoot(char* name, char *family[]){
  family[0]=name;
}
//addNode father=1 if father, 0 if mother
void addNode(char* name, int father){
  //check if it can be placed there
  //if yes then allocate memory and place it there and add pointer

  //if not return an error message

}
//printTree
void printTree(){

}
//deleteNode
void deleteNode(char* name){
  //check to see if it can be deleted
  //if yes the delete it and free memory and remove pointer

  //if not then error message
}
