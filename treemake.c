#include <treemake.h>
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

      char *parent=strtok(addInput,"(");
      char *parentName=strtok(NULL,",");
      char *childName=strtok(NULL,")");

      //FATHER
      if((strcmp(parent,"father")==0)&&(parentName!=NULL)&&(childName!=NULL)){
        char *pF= (char *) malloc(sizeof(char)*13);
        strcpy(pF,parentName);
        addNode(childName,pF,1,family);

      //MOTHER
      }else if((strcmp(parent,"mother")==0)&&(parentName!=NULL)&&(childName!=NULL)){
        char *pM= (char *) malloc(sizeof(char)*13);
        strcpy(pM,parentName);
        addNode(childName,pM,0,family);

      //NEITHER
      }else{
        printf("invalid relationship\n");
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
