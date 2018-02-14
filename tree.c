#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void makeUser(char* name, char *family[]);
void printTree();
void addNode(char* child, char* parent, int father, char *family[]);
void deleteNode(char* name, char *family[]);
int exists(char* name, char *family[]);

int main() {
  //make array to hold strings for family so has 7 spots
  char family[8][12]; //root,user,mom,dad,moms mom,moms dad,dads mom,dads dad

  char name[12];
  printf("What is your name?\n");
  scanf("%s",&name);
  //printf("%s\n",name);

  //store name into root
  makeUser(name,family);

  //start running program until quits
  while(1){
    printf("Please specify whether to add or delete an entry, or print the tree\n");
    char input[7];
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

      //FATHER
      if(strcmp(parent,"father")==0){
        char *father;
        char *child;

        father=strtok(NULL,",");
        child=strtok(NULL,")");

        printf("Father: %s\n",father);
        printf("Child: %s\n",child);

        addNode(child, parent, 1, family);

        //MOTHER
      }else if(strcmp(parent,"mother")==0){
        char *mother;
        char *child;

        mother=strtok(NULL,",");
        child=strtok(NULL,")");

        printf("Mother: %s\n",mother);
        printf("Child: %s\n",child);

        addNode(child, parent, 0, family);

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
        deleteNode(deleteName, family);

      //INVALID COMMAND
      }else{
        printf("Sorry, you put an invalid command!\n");
      }
    }
  }

//METHODS
void makeUser(char* name, char *family[]){
  family[0]="root";
  family[1]=name;
}

void printTree(){
  printf("TODO");
}

//addNode father=1 if father, 0 if mother
void addNode(char* child, char* parent, int father, char *family[]){

  printf("Adding a parent!!!"); //NEED TO FIX THE ISH BELOW
  // //check if child exists
   if(exists(child, family)!=0){
     printf("adding");
    // //if parent doesnt exist then check what type of parent
    // if(exists(parent, family)==0){
    //   int childIndex=exists(child, family);
    //   //if its father
  	// 	if (father==1){
    //     int fatherIndex=childIndex*2+1;
    //     if(family[fatherIndex]==NULL){
    //       //can add
    //       printf("This father can be added\n");
    //       //family[fatherIndex]=parent;
    //     }else{
    //       printf("Sorry a father already exists for that child\n");
    //     }
    //
    //   //if its mother
  	// 	}else if (father == 0){
    //     int motherIndex=childIndex*2;
    //     if(family[motherIndex]==NULL){
    //       //can add
    //       printf("This mother can be added\n");
    //       //family[motherIndex]=parent;
    //     }else{
    //       printf("Sorry a mother already exists for that child\n");
    //     }
  	// 	}
  	// }else{
    //   printf("Sorry that parent already exists in the tree.");
    // }
  }else{
		printf("Sorry that child does not exist.\n");
	}
}

//deleteNode
void deleteNode(char* name, char *family[]){
  if(exists(name, family)!=0){
    //delete it and free memory?
  }else{
    printf("Sorry that person is not in the family tree.\n");
  }
}

int exists(char* name, char *family[]){
  int index = 1;
  //check to see if the name exists
  //if exists return the index at which it exists
  for (index; index<9; index++) {
    printf("Index: %d\n",index);
     if(family[index]!=NULL){
         printf("Not Null at Index: %d\n",index);
         printf("exists here %s\n",family[index]);
    //  printf("family index: %s",family[index]);
  //         if(strcmp(name,family[index])==0){
  //              return index;
  //          }
     }
  }
 return 0;//return 0/false if does not exist
}
