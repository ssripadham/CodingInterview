#include <string>
#include <iostream>
using namespace std;

void printParen( string  strBuild, int leftRem, int rightRem) {

  //Reached end state
  if (rightRem == 0) {
    cout<<strBuild<<endl;
    return;
  }

  if (leftRem > 0) {
    //Note the state is changed to next recursive call
    printParen(strBuild+"(",leftRem - 1, rightRem);
    //cout<<"Here "<<strBuild<<endl;
    if (leftRem < rightRem) 
      printParen(strBuild+")", leftRem, rightRem - 1);
  } else {
    printParen(strBuild+")", leftRem, rightRem - 1);
  }
  return;
}

int main() {
  printParen("",3,3);
}