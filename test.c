#include <stdio.h>
#include <string.h>

int main() {
  printf("What is your name? ");
  fgets(name,12,stdin);
  //store name into root
  makeRoot(name);

  //start running program until quits
  while(1){
    fgets(input,33,stdin);

    if(strcmp(input,"quit")==0){//if quit then quit program
      return;
    }else if(1){//if father then addFather

    }else if(1){//if mother then addMother

    }else if(1){//if print then print tree

    }else if(1){//if delete then delete node

    }else{//if neither return an error message
      printf("Sorry, you put an invalid command!");
    }
  }

}
