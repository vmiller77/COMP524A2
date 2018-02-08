#include <stdio.h>
#include <string.h>

int main() {
  //allocate space for the root

  printf("What is your name? ");
  fgets(name,12,stdin);
  //store name into root


  //start running program until quits
  while(1){
    fgets(input,33,stdin);

    if(strcmp(input,"quit")==0){//if quit then quit program
      return;
    }else{//if father then addFather

    }else{//if mother then addMother

    }else{//if print then print tree

    }else{//if delete then delete node

    }else{//if neither return an error message
      printf("Sorry, you put an invalid command!");
    }
  }
  
}

//methods
void makeRoot(){

}
//addNode

//printTree

//deleteNode
