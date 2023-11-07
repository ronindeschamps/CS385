/*******************************************************************************
* Name : unique.cpp
* Author : Ronin Deschamps
* Date : 09/30/2023
* Description : Determining uniqueness of chars with int as bit vector.
* Pledge : I pledge my honor that I have abided by the Stevens Honor System.
*******************************************************************************/
#include <iostream>
#include <cctype>

using namespace std;

bool is_all_lowercase(const string &s){

        for(char a : s){

            if(!islower(a)){
                cout << "Error: String must contain only lowercase letters." << endl;
                return false;
            }
        }

        return true;
    }

bool all_unique_letters(const string &s) {

// TODO: returns true if all letters in string are unique, that is
// no duplicates are found; false otherwise.
// You MUST use only single unsigned integers and work with bitwise
// and bitshifting operators only. Using any other kind of solution
// will automatically result in a grade of ZERO for the whole assignment.
    
    unsigned int vector = 0;
    unsigned int setter;

    for(size_t i = 0; i < s.length(); i++){
        setter = 1 << (s[i]-'a');
        if(setter & vector){
            cout<<"Duplicate letters found."<<endl;
            return false;
        }
        else{
            vector = vector | setter;
        }
    }
    
cout<<"All letters are unique."<<endl;
return true;

}
int main(int argc, char * const argv[]) {
// TODO: reads and parses command line arguments.
// Calls other functions to produce correct output.
    if (argc < 2){
        cout << "Usage: ./unique <string>" << endl;
        return 0;
    }
    if (argc > 2){
        cout << "Usage: ./unique <string>" << endl;
        return 0;
    }


    string userinput = argv[1];

    if(is_all_lowercase(userinput)){
        all_unique_letters(userinput);
    }
    

    return 0;
}
