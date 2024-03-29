#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void makeUser(char *name, char *family[]);
void printTree(char *family[]);
void addNode(char *child, char *parent, int father, char *family[]);
void deleteNode(char *name, char *family[]);
int exists(char *name, char *family[]);
void printAll(char *family[]);

int main() {
  //make array to hold strings for family so has 7 spots
  char *family[8]={NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL}; //root,user,mom,dad,moms mom,moms dad,dads mom,dads dad

  char name[13];
  printf("What is your name?\n");
  scanf("%s",name);

  //store name into root
  makeUser(name,family);

  //start running program until quits
  while(1){
    printf("Please specify whether to add or delete an entry, or print the tree\n");
    char input[7];
    scanf("%s", input);

    //Check to see what the string it
    //QUIT
    if(strcmp(input,"quit")==0){
      int i =2;
      for(i;i<8;i++){
        if(family[i]!=NULL){
          free(family[i]);
        }
      }
      printf("Program Terminating\n");
      exit(0);

    //PRINT
    }else if(strcmp(input,"print")==0){
      printTree(family);
      //printAll(family);
    //ADD
    }else if(strcmp(input,"add")==0){
      printf("Please specify a relation to add\n");
      char addInput[34];
      scanf("%s", addInput);

      if (addInput[(strlen(addInput)-1)]!=41){
        printf("invalid command\n");
        // continue;
      }else{
        char *parent=strtok(addInput,"(");
        char *parentName=strtok(NULL,",");
        char *childName=strtok(NULL,")");

        //FATHER
        if((strcmp(parent,"father")==0)&&(parentName!=NULL)&&(childName!=NULL)){
          // char *pF= (char *) malloc(sizeof(char)*13);
          // strcpy(pF,parentName);
          // addNode(childName,pF,1,family);
          addNode(childName,parentName,1,family);
        //MOTHER
        }else if((strcmp(parent,"mother")==0)&&(parentName!=NULL)&&(childName!=NULL)){
          // char *pM= (char *) malloc(sizeof(char)*13);
          // strcpy(pM,parentName);
          // addNode(childName,pM,0,family);
          addNode(childName,parentName,0,family);
        //NEITHER
        }else{
          printf("invalid relationship\n");
        }

      }


    //DELETE
    }else if(strcmp(strtok(input,"("),"delete")==0){
        printf("Please specify the name to delete\n");
        char deleteName[13];
        scanf("%s", deleteName);
        if(exists(deleteName,family)!=0){
          deleteNode(deleteName, family);
        }else{
          printf("name not found");
        }

      //INVALID COMMAND
      }else{
        printf("invalid command\n");
      }
    }
  }


////////////////METHODS//////////////////
void makeUser(char *name, char *family[])
{
  family[0] = "root";
  family[1] = name;
}

void printTree(char *family[])
{
  int index = 1;
  char *name = family[index];
  char *indexMom = family[index * 2];
  char *indexDad = family[index * 2 + 1];
  char *indexMomMom = family[(index * 2) * 2];
  char *indexMomDad = family[(index * 2) * 2 + 1];
  char *indexDadMom = family[(index * 2 + 1) * 2];
  char *indexDadDad = family[(index * 2 + 1) * 2 + 1];
  if (family[index] != NULL)
  {
    printf("%s\n", name);
    if (family[index * 2] != NULL)
    {
      printf("\t%s\n", indexMom);
      if (family[(index * 2) * 2] != NULL)
      {
        printf("\t\t%s\n", indexMomMom);
      }
      if (family[(index * 2) * 2 + 1] != NULL)
      {
        printf("\t\t%s\n", indexMomDad);
      }
    }
    if (family[index * 2 + 1] != NULL)
    {
      printf("\t%s\n", indexDad);
      if (family[(index * 2 + 1) * 2] != NULL)
      {
        printf("\t\t%s\n", indexDadMom);
      }
      if (family[(index * 2 + 1) * 2 + 1] != NULL)
      {
        printf("\t\t%s\n", indexDadDad);
      }
    }
  }
}

//addNode father=1 if father, 0 if mother
void addNode(char *child, char *parent, int father, char *family[])
{
  //check if child exists
  if (exists(child, family) != 0)
  {
    //if parent doesnt exist then check what type of parent
    if (exists(parent, family) == 0)
    {
      int childIndex = exists(child, family);
      //if its father
      if (father == 1)
      {
        int fatherIndex = childIndex * 2 + 1;
        if (family[fatherIndex] == NULL)
        {
          //can add
          char *pF= (char *) malloc(sizeof(char)*13);
          strcpy(pF,parent);
          family[fatherIndex] = pF;
        }
        else
        {
          printf("relationship already exists\n");
        }

        //if its mother
      }
      else if (father == 0)
      {
        int motherIndex = childIndex * 2;
        if (family[motherIndex] == NULL)
        {
          //can add
          char *pM= (char *) malloc(sizeof(char)*13);
          strcpy(pM,parent);
          family[motherIndex] = pM;
        }
        else
        {
          printf("relationship already exists\n");
        }
      }
    }
    else
    {
      printf("relationship already exists\n");
    }
  }
  else
  {
    printf("invalid relationship\n");
  }
}

//deleteNode (assume u don't delete root)
void deleteNode(char *name, char *family[])
{
  if (exists(name, family) != 0)
  {
    int nodeIndex = exists(name, family);
    if (nodeIndex == 2 || nodeIndex == 3)
    {

      //delete parents of nodeIndex and it
      int dadIndex = nodeIndex * 2 + 1;
      int momIndex = nodeIndex * 2;

      //free all the memory first
      free(family[nodeIndex]);
      if(family[dadIndex]!=NULL){
        free(family[dadIndex]);
      }
      if(family[momIndex]!=NULL){
        free(family[momIndex]);
      }

      family[nodeIndex] = NULL;
      family[dadIndex] = NULL;
      family[momIndex] = NULL;
    }
    else
    {
      //free memory first
      free(family[nodeIndex]);
      //delete that nodeIndex
      family[nodeIndex] = NULL;
    }
  }
  else
  {
    printf("name not found\n");
  }
}

int exists(char *name, char *family[])
{
  int index = 1;
  //iterates through array family
  for (index; index < 8; index++)
  {
    //if it matches the name wanted
    if (family[index] != NULL)
    {
      if (strcmp(name, family[index]) == 0)
      {
        return index;
      }
    }
  }
  return 0; //return 0/false if does not exist
}
