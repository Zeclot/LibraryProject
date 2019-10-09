/*- - - - - - - - - - - - - - - - -
@Description: This projects intends to create a library for
text files containing information about what one learns when
working in software. It intends to keep the UI simple and give
unique features. Main learning topics are:
- File handling
- I/O
- GUI
@Author: Kasper Wikman
@Date: 9 October 2019
@Version: 1.0v
- - - - - - - - - - - - - - - - - */


// Includes
#include <iostream>
#include <fstream> // File stream for both I/O
#include <string> // String inclusions

// Setup namespace
using namespace std;

// Declare functions within file
void infoHelp(void);

int main() {
  // Variables
  string inp = ""; //User input variable

  // Welcome message in the program
  cout <<"--------------------------------------------"<<endl;
  cout <<"Welcome to the knowledge library!"<<endl;
  cout <<"This program will let you check all "<<endl;
  cout <<"the knowledge you acquired. Write 'help'"<<endl;
  cout <<"if you want a list of commands."<<endl;
  cout <<"--------------------------------------------"<<endl;


  // Main loop of the program
  while(true){
    cout << "User command: ";
    cin >> inp;

    if((inp == "Help") | (inp=="help")){
      infoHelp();
    }else if(inp == "exit" | inp == "Exit"){
      break;
    }else{
      cout<< "Command not recognised. Please try again."<<endl;
    }

    cout <<"--------------------------------------------"<<endl;
  }

  cout <<"System is turning off. See you next time!"<<endl;
  return 0;
}
/*
@Type: void
@Name: infoHelp
@Description: Give help information to user if requested.
*/
void infoHelp(){
  string info;
  ifstream file; // Reading from file only
  file.open("help_inf.txt"); // Open a file in reading mode

  if(file.is_open()){

    // Read from file until the end of file
    while(std::getline(file,info)){
      cout << info << "\n";
    }
    cout<< "\n";
    file.close(); // Closing the file. Good practice
  }else{
    cout << "Error, file not opening. Please check directory."<<endl;
  }
}
