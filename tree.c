#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void makeRoot(char* name, char *family[]);
void addNode(char* child, char* parent, int father);
void printTree();
void deleteNode(char* name);

int main() {
  //make array to hold strings for family so has 7 spots
  char *family[7]; //strs[i] = malloc(strlen("foo") + 1);

  char name[12];
  printf("What is your name?\n");
  scanf("%s",&name);
  //printf("%s\n",name);

  //store name into root
  makeRoot(name,family);
  //printf("%s\n",family[0]);

  //start running program until quits
  while(1){
    printf("Please specify whether to add or delete an entry, or print the tree\n");
    char input[33];
    scanf("%s", &input);

    //Check to see what the string it
    //QUIT
    if(strcmp(input,"quit")==0){
      exit(0);

    //PRINT
    }else if(strcmp(input,"print")==0){
      printTree();

//ADD
}else if(strcmp(input,"add")==0){
  printf("Please specify a relation to add\n");
  char addInput[34];
  scanf("%s", &addInput);

  char *parent;
  parent=strtok(addInput,"(");

  //FATHER - this doesnt work right now, I can get the dads name but not the childs
  // update - need to remove the last ) in child
  if(strcmp(parent,"father")==0){
    char *father;
    char *child;

    father=strtok(NULL,",");
    child=strtok(NULL,"");

    printf("Father: %s\n",father);
    printf("Child: %s\n",child);

    //addNode(child, parent, 1);

  //MOTHER
}else if(strcmp(parent,"mother")==0){
  char *mother;
  char *child;

  mother=strtok(NULL,"");
  child=strtok(NULL,"");

  printf("Mother: %s\n",mother);
  printf("Child: %s\n",child);

  //addNode(child, parent, 0);

  //NEITHER
  }else{
    printf("Sorry, you put an invalid command!\n");
  }
  //DELETE
  }else if(strcmp(strtok(input,"("),"delete")==0){
    printf("Please specify the name to delete\n");
    char deleteName[13];
    scanf("%s", &deleteName);
    printf("Delete name: %s\n", deleteName);
    deleteNode(deleteName);

    //INVALID COMMAND
    }else{
      printf("Sorry, you put an invalid command!\n");
    }
  }
}

//methods
void makeRoot(char* name, char *family[]){
  family[0]=name;
}
void printTree(){
  printf("TODO");
}
//addNode father=1 if father, 0 if mother
void addNode(char* child, char* parent, int father){
  //check if it can be placed there
  //if yes then place there
  //if not return an error message
}

//deleteNode
void deleteNode(char* name){
  if(exists(name)==1){
    //delete it and free memory?
  }else{
    printf("Sorry that person is not in the family tree.\n");
  }
}

int exists(char* name){
  //check to see if the name exists
  return 0;//return 0/false if does not exist
}
