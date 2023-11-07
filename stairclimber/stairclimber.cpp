/*******************************************************************************
 * Name        : stairclimber.cpp
 * Author      : Ronin Deschamps
 * Date        : 10/07/2023
 * Description : Lists the number of ways to climb n stairs.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System
 ******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <cctype>

using namespace std;




vector<vector<int>> get_ways(int num_stairs) {

    vector<vector<int>> ways;


    if (num_stairs <= 0) {
        return vector<vector<int>>{{}};
    }

    for (int i = 1; i <= 3; i++) {
        if (num_stairs >= i) {
            vector<vector<int>> result = get_ways(num_stairs - i);
            for (size_t j = 0; j < result.size(); j++) {
                result[j].insert(result[j].begin(), i);
            }
            ways.insert(ways.end(), result.begin(), result.end());
        }
    }
    return ways;
}

void display_ways(const vector<vector<int>>& ways, const int in) {



    int size = ways.size();
    string numStr = to_string(size);
    int length = numStr.length();

    if(ways.size()==1){
        cout << ways.size() << " way to climb " << in << " stair." << endl;
        cout << "1. [1]" << endl;
    }
    else{
    cout << ways.size() << " ways to climb " << in << " stairs." << endl;

    for (int i = 0; i < size; i++) {
        cout << setw(length) << i+1  << ". [";
        for (size_t j = 0; j < ways[i].size(); j++) {
            if(j == ways[i].size() - 1){
                cout << ways[i][j];
                break;
            }
            cout << ways[i][j] << ", ";
        }
        cout << "]" << endl;
    }
    }
}

int main(int argc, char* const argv[]) {

    if (argc != 2) {
        cout << "Usage: ./stairclimber <number of stairs>" << endl;
        return 1;
    }

    stringstream iss;
    int input;
    iss.str(argv[1]);

    if (!(iss >> input) || input < 1) {
        cerr << "Error: Number of stairs must be a positive integer." << endl;
        return 1;
    }
    
    display_ways(get_ways(input), input);
    return 0;
}

