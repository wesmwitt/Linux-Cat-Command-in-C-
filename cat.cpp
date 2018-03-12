#include <cstdlib>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#define BUFFSIZE 256

using namespace std;

int main(int argc, char** argv){
  
  //if there is no input
  if (argc == 1){
    string userText;
    getline(cin,userText);
    cout << userText << endl;
    exit(0);
  }

  //cout << argc << endl; //TEST CODE REMOVE LATE

  //opening files
  for(int i = 1; i < argc; i++) { //change 1 to argc
    
    //cout << argv[i] << endl; //TEST CODE REMOVE LATE

    if ((argv[i])[0] == '-'){
      string userText;
      getline(cin,userText);
      cout << userText << endl;
      continue;
    }

    char buff [BUFFSIZE];
    int fd = open(argv[i], O_RDONLY);

    //exiting if there is an error
    if (fd < 1){
      perror("error opening input file");
      exit(EXIT_FAILURE);
    }

    int numRead = read(fd, buff, BUFFSIZE);

    write(STDOUT_FILENO, buff, numRead);

    close(fd);
  }//for
      
  exit(0);

}//main
