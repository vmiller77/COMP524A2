#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void makeUser(char *name, char *family[]);
void printTree();
<<<<<<< HEAD
void addNode(char* child, char* parent, int father, char *family[]);
void deleteNode(char* name, char *family[]);
int exists(char* name, char *family[]);
void printAll(char *family[]);
=======
void addNode(char *child, char *parent, int father, char *family[]);
void deleteNode(char *name, char *family[]);
int exists(char *name, char *family[]);
>>>>>>> 595e09586900e4d3aed60870c4381f8a97191793


int main(){
  //make array to hold strings for family so has 7 spots
  char *family[8] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}; 
  //root,user,mom,dad,moms mom,moms dad,dads mom,dads dad

  char name[12];
  printf("What is your name?\n");
  scanf("%s", &name);

  //store name into root
  makeUser(name, family);

  //start running program until quits
  while (1){
    printf("Please specify whether to add or delete an entry, or print the tree\n");
    char input[7];
    scanf("%s", &input);

    //Check to see what the string it
    //QUIT
    if (strcmp(input, "quit") == 0){
      exit(0);

      //PRINT
    }else if (strcmp(input, "print") == 0){
      printTree(family);

<<<<<<< HEAD
    //ADD
    }else if(strcmp(input,"add")==0){
      printAll(family);
      //ADD
    }else if (strcmp(input, "add") == 0){
=======
      //ADD
    }
    else if (strcmp(input, "add") == 0)
    {
>>>>>>> 595e09586900e4d3aed60870c4381f8a97191793
      printf("Please specify a relation to add\n");
      char addInput[34];
      scanf("%s", &addInput);

      char *parent;
      parent = strtok(addInput, "(");

      //FATHER
      if (strcmp(parent, "father") == 0){
        char *father;
        char *child;

        father = strtok(NULL, ",");
        child = strtok(NULL, ")");

<<<<<<< HEAD
        printf("Father: %s\n",father);
        printf("Child: %s\n",child);
        printf("Right after token");
        printAll(family);

=======
>>>>>>> 595e09586900e4d3aed60870c4381f8a97191793
        printf("Father: %s\n", father);
        printf("Child: %s\n", child);

        addNode(child, father, 1, family);

        //MOTHER
      }else if (strcmp(parent, "mother") == 0){
        char *mother;
        char *child;

        mother = strtok(NULL, ",");
        child = strtok(NULL, ")");

<<<<<<< HEAD

        printf("Mother: %s\n",mother);
        printf("Child: %s\n",child);
        printf("Right after token");
        printAll(family);
        addNode(child, mother, 0, family);

        printf("Mother: %s\n", mother);
        printf("Child: %s\n", child);

        addNode(child, parent, 0, family);
=======
        printf("Mother: %s\n", mother);
        printf("Child: %s\n", child);

        addNode(child, mother, 0, family);
>>>>>>> 595e09586900e4d3aed60870c4381f8a97191793

        //NEITHER
      }else{
        printf("Sorry, you put an invalid command!\n");
      }

      //DELETE
    }else if (strcmp(strtok(input, "("), "delete") == 0){
      printf("Please specify the name to delete\n");
      char deleteName[13];
      scanf("%s", &deleteName);
      printf("Delete name: %s\n", deleteName);
      deleteNode(deleteName, family);

      //INVALID COMMAND
    }else{
      printf("Sorry, you put an invalid command!\n");
    }
  }
}

//METHODS
void makeUser(char *name, char *family[]){
  family[0] = "root";
  family[1] = name;
}

void printTree(char *family[]){
  int index = 1;
  for (index; index < 8; index++)  {
    if (index == 1)    {
      printf("%s\n", family[index]);
      if (family[2] != NULL)      {
        printf("%s\n", family[2]);
      }
      // if(exists(family[index+2], family) != 0){
      //   printf("%s\n", family[index+2]);
      // }
    }
  }
}

//addNode father=1 if father, 0 if mother
<<<<<<< HEAD
void addNode(char* child, char* parent, int father, char *family[]){
    printf("Mom or dad?: %d",father);

  printf("Adding a parent!!!\n");
   //check if child exists
   if(exists(child, family)!=0){
       printAll(family);
       printf("Right after seeing if child exists");
=======
void addNode(char *child, char *parent, int father, char *family[])
{
  
  //check if child exists
  if (exists(child, family) != 0)
  {
>>>>>>> 595e09586900e4d3aed60870c4381f8a97191793
    //if parent doesnt exist then check what type of parent
    if (exists(parent, family) == 0){
      int childIndex = exists(child, family);
      //if its father
<<<<<<< HEAD
  		if (father==1){
            int fatherIndex=childIndex*2+1;
            if(family[fatherIndex]==NULL){
              //can add
              printf("This father can be added\n");
              family[fatherIndex]=parent;
            }else{
              printf("Sorry a father already exists for that child\n");
            }

        //if its mother
  		}else if (father == 0){
            int motherIndex=childIndex*2;
            if(family[motherIndex]==NULL){
              //can add
              printf("This mother can be added\n");
              family[motherIndex]=parent;
            }else{
              printf("Sorry a mother already exists for that child\n");
            }
  		}
  	}else{
=======
      if (father == 1)
      {
        int fatherIndex = childIndex * 2 + 1;
        if (family[fatherIndex] == NULL)
        {
          //can add
          printf("This father can be added\n");
          family[fatherIndex] = parent;
        }
        else
        {
          printf("Sorry a father already exists for that child\n");
        }

        //if its mother
      }
      else if (father == 0)
      {
        int motherIndex = childIndex * 2;
        if (family[motherIndex] == NULL)
        {
          //can add
          printf("This mother can be added\n");
          family[motherIndex] = parent;
        }
        else
        {
          printf("Sorry a mother already exists for that child\n");
        }
      }
    }
    else
    {
>>>>>>> 595e09586900e4d3aed60870c4381f8a97191793
      printf("Sorry that parent already exists in the tree.");
    }
  }
  else
  {
    printf("Sorry that child does not exist.\n");
  }
}

//deleteNode
void deleteNode(char *name, char *family[])
{
  if (exists(name, family) != 0)
  {
    //delete it and free memory?
  }
  else
  {
    printf("Sorry that person is not in the family tree.\n");
  }
}

int exists(char *name, char *family[])
{
  int index = 1;
<<<<<<< HEAD
  //iterates through array family
  for (index; index<8; index++) {
    // printf("Index: %d, exists here %s\n",index, family[index]);
            //if it matches the name wanted
        if(family[index]!=NULL){
           if(strcmp(name,family[index])==0){
                return index;
            }
        }
=======
  //check to see if the name exists
  //if exists return the index at which it exists
  for (index; index < 8; index++)
  {
    printf("Index: %d\n", index);
    if (family[index] != NULL)
    {
      printf("exists here %s\n", family[index]);
      if (strcmp(name, family[index]) == 0)
      {
        return index;
      }
    }
    else
    {
      printf("Does not exist here!\n");
    }
>>>>>>> 595e09586900e4d3aed60870c4381f8a97191793
  }
  return 0; //return 0/false if does not exist
}
