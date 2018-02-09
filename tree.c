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
  printf("What is your name? ");
  scanf("%s",&name);
  printf("%s\n",name);

  //store name into root
  makeRoot(name,family);
  //printf("%s\n",family[0]);

  //start running program until quits
  while(1){
    char input[33];
    scanf("%s", &input);
    //printf("%s",input);

    if(strcmp(input,"quit")==0){//if quit then quit program
      exit(0);
    }else if(strstr("father",input)!= NULL){//if father then addFather
      //extract name from string

      //extract father name from string

      //char child[12];
      //char parent[12];
      //addNode(child, parent, 1);
      printf("father");

    }else if(strstr("mother",input)!= NULL){//if mother then addMother
      //extract name from string

      //extract father name from string

      //char child[12];
      //char parent[12];
      //addNode(child, parent, 0);
      printf("mother");

    }else if(strcmp(input,"print")==0){//if print then print tree
      printTree();

    }else if(strstr("delete",input)!= NULL){//if delete then delete node
      //extract name from string
      //char delName[12];
      //deleteNode(delName);
      printf("delete");
    }else{//if neither return an error message
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
  //check to see if it can be deleted
  //if yes the delete it and free memory and remove pointer
  //if not then error message
  printf("TODO");
}
