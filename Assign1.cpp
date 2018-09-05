#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <exception>
#include <map>

using namespace std;

map<char, int> GenerateMap(map<char, int> newMap){

}

void interpretLine(string line, int& letterCount, int& nameCount){

}

int main(int argc, char** argv){
    string fileName, buffer;
    map<char, int> startsWith;
    vector<vector<char>> names(1);
    int j = 0;
    double avg = 0, letterCount = 0, nameCount = 1;
    char letter = 'A';
    for(int i = 0; i < 26; i++){
        startsWith[letter] = 0;
        letter++;
    }

    if(argv[1] != NULL)
        fileName = argv[1];
    else{
        cout<<"no input file\n";
        return 0;
    }

    try{
        ifstream inputFile;
        inputFile.open(fileName);
        while(getline(inputFile, buffer)){
            for(int i = 0; i<buffer.size(); i++){
                if(buffer[i] == ',') {
                    i++;
                    j++;
                    names.resize(++nameCount);
                } else {
                    names[j].push_back(buffer[i]);

                }
            }
        }
        --nameCount;
        for(int i = 0; i < names.size(); i++){
            letterCount += names[i].size();
            startsWith[names[i][0]]++;
        }
        cout<<(letterCount / nameCount)<<endl;
        letter = 'A';
        for(int i = 0; i < 26; i++){
            if(letter]!=0){
                cout<<letter<<": "<<startsWith[letter]<<endl;
            }
            letter++;
        }
        inputFile.close();
    }
    catch(exception& e){
        cout<<"File not found\n";
    }
}