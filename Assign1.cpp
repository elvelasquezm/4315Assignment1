#include <ctype.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <exception>
#include <map>

using namespace std;

/**
 * Gets the name of the file sent through the command line
 *
 * @param commandLineInput  holds the command line arguments
 * @return fileName         string that holds the name of the file
 * @return exit(0)          exits program if no file was sent
 */
string GetFileName(char** commandLineInput){
    string fileName;

    //returns commandline argument as string if it exists
    //else exit program
    if(commandLineInput[1] != NULL) {
        fileName = commandLineInput[1];
        return fileName;
    } else {
        cout<<"No input file\n";
        exit(0);
    }
}

/**
 * Generates a map with alpha keys
 *
 * @return newAlphaMap  the generated map
 */
map<char, int> GenerateAlphaMap(){
    //map we are about to manipulate
    map<char, int> newAlphaMap;

    //iterates through alphabet and adds each letter as key for our map
    for(char c = 'A'; c <= 'Z'; c++)
        newAlphaMap[c] = 0;

    return newAlphaMap;
}

/**
 * Gets the number of names, and how many begin with each alpha letter,
 * as well as the total number of alpha letters
 *
 * @param inputFile     the file that we are reading from
 * @param namesCount    the number of names in the file
 * @param letterCount   the number of alpha letters in the file
 * @param startsWith    a map whose values represent the number of names
 *                      that begin with a specific alpha letter
 *                      (represented by the keys)
 */
void GetFileInfo(ifstream& inputFile, int& namesCount, int& letterCount, map<char, int>& startsWith){
    //buffer for holding each line in file
    string buffer;

    //iterates through each lines in file
    while(getline(inputFile, buffer))
        //iterates through each character in line
        for(int i =0; i < buffer.size(); i++){
            //if character is uppercase then new name has started
            //else name has more letters
            if(isupper(buffer[i])){
                namesCount++;
                startsWith[buffer[i]]++;
                letterCount++;
            } else if(islower(buffer[i]))
                letterCount++;
        }
}

/**
 * Prints the info obtained from the {@code GetInfo} fucntion
 * The parameters carry over the same meaning as in the {@code GetInfo} info
 *
 * @param letterCount
 * @param namesCount
 * @param startsWith
 */
void PrintInfo(int letterCount, int namesCount, map<char, int> startsWith){
    //print average number of letters per name
    cout<<"Average number of letters per name: "<<(double)(letterCount/namesCount)<<endl;

    //print number of names that begin wit each letter of the alphabet
    cout<<"Names starting with ___\n";
    for (char c = 'A'; c <= 'Z' ; c++)
        if(startsWith[c] != 0)
            cout<<c<<": "<<startsWith[c]<<endl;
}

/**
 * Main function
 */
int main(int argc, char** argv){

    //opens the input file to read
    ifstream inputFile;
    inputFile.open(GetFileName(argv));
    if(!inputFile){
        cout<<"File not found\n";
        return 0;
    }

    //instantiates variables for getting info from file
    int namesCount = 0, letterCount =0;
    map<char, int> startsWith = GenerateAlphaMap();

    //gets info from file and displays it
    GetFileInfo(inputFile, namesCount, letterCount, startsWith);
    PrintInfo(letterCount, namesCount, startsWith);

    //ends program
    inputFile.close();
    return 0;
}
