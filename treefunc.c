#include <stdio.h>
#include <treemake.h>

////////////////METHODS//////////////////
void makeUser(char* name, char *family[]){
  family[0]="root";
  family[1]=name;
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
void addNode(char* child, char* parent, int father, char *family[]){

   //check if child exists
   if(exists(child, family)!=0){
    //if parent doesnt exist then check what type of parent
    if(exists(parent, family)==0){
      int childIndex=exists(child, family);
      //if its father
  		if (father==1){
            int fatherIndex=childIndex*2+1;
            if(family[fatherIndex]==NULL){
              //can add
              family[fatherIndex]=parent;
            }else{
              printf("relationship already exists\n");
            }

        //if its mother
  		}else if (father == 0){
            int motherIndex=childIndex*2;
            if(family[motherIndex]==NULL){
              //can add
              family[motherIndex]=parent;
            }else{
              printf("relationship already exists\n");
            }
  		}
  	}else{
      printf("relationship already exists\n");
    }
  }else{
		printf("invalid relationship\n");
	}
}

//deleteNode (assume u don't delete root)
void deleteNode(char* name, char *family[]){
  if(exists(name, family)!=0){
    int nodeIndex=exists(name,family);
    if(nodeIndex==2||nodeIndex==3){
        //delete parents of nodeIndex and it
        int dadIndex=nodeIndex*2+1;
        int momIndex=nodeIndex*2;
        family[nodeIndex]=NULL;
        family[dadIndex]=NULL;
        family[momIndex]=NULL;
    }else{
        //delete that nodeIndex
        family[nodeIndex]=NULL;
    }
  }else{
    printf("name not found\n");
  }
}

int exists(char* name, char *family[]){
  int index = 1;
  //iterates through array family
  for (index; index<8; index++) {
    // printf("Index: %d, exists here %s\n",index, family[index]);
            //if it matches the name wanted
        if(family[index]!=NULL){
           if(strcmp(name,family[index])==0){
                return index;
            }
        }
  }
 //printf("Does not exist: %s\n",name);
 return 0;//return 0/false if does not exist
}

void printAll(char *family[]){
  int index = 0;
  for (index; index<8; index++) {
      if(family[index]==NULL){
          printf("null\n");
      }else{
      printf("%s\n",family[index]);
  }}
}
