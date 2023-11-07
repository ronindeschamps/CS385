/*******************************************************************************
 * Name        : inversioncounter.cpp
 * Author      : Ronin Deschamps
 * Version     : 1.0
 * Date        : 11/04/2023
 * Description : Counts the number of inversions in an array.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System
 ******************************************************************************/
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cstring>

using namespace std;

// Function prototype.
//static long mergesort(int array[], int scratch[], int low, int high);

/**
 * Counts the number of inversions in an array in Theta(n^2) time using two nested loops.
 */
long count_inversions_slow(int array[], int length) {
    long count = 0;
    for(int i=0; i<length-1; i++){
        for(int j=i+1; j < length; j++){
            if(array[j] < array[i]){
                count++;
            }
        }
    }
    return count;
}



long merge(int array[], int scratch[], int low, int mid, int high){
    long count = 0;
    int i1 = low;
    int i2 = mid+1;
    int i = low;

    while(i1 <= mid && i2 <= high){
        if(array[i1]<=array[i2]){
            scratch[i++] = array[i1++];
        }
        else{
            scratch[i++] = array[i2++];
                        count += mid-i1+1;
        }
    }

    while(i1<=mid){
        scratch[i++] = array[i1++];
    }
    while(i2<=high){
        scratch[i++] = array[i2++];
    }

    for (i = low; i <= high; i++) {
        array[i] = scratch[i]; 
    }

    return count;
}

long mergesort(int array[], int scratch[], int low, int high) {
    long count = 0;
    if(low<high){
        int mid = low + (high - low)/2;
        count += mergesort(array, scratch, low, mid);
        count += mergesort(array, scratch, mid+1, high);
        count += merge(array, scratch, low, mid, high);
    }
    return count;
}

/**
 * Counts the number of inversions in an array in Theta(n lg n) time.
 */
long count_inversions_fast(int array[], int length) {
    int* scratch = new int[length];
    // TODO
    // Hint: Use mergesort!
    long count = mergesort(array, scratch, 0, length-1);
    delete[] scratch;
    return count;
}


int main(int argc, char *argv[]) {

    if (argc > 2) {
    cerr << "Usage: ./inversioncounter [slow]" << endl;
    return 1;
}

 if (argc > 1) {
    if (argv[1][0] != '\0') {
        string userinput = argv[1];
        if (userinput != "slow") {
            cerr << "Error: Unrecognized option '" << userinput << "'." << endl;
            return 1;
        }
    }
 }


    istringstream iss;
    int value, index = 0;
    vector<int> values;
    string str;
    str.reserve(11);
    char c;
    while (true) {
        c = getchar();
        const bool eoln = c == '\r' || c == '\n';
        if (isspace(c) || eoln) {
            if (str.length() > 0) {
                iss.str(str);
                if (iss >> value) {
                    values.push_back(value);
                } else {
                    cerr << "Enter sequence of integers, each followed by a space: " << "Error: Non-integer value '" << str
                         << "' received at index " << index << "." << endl;
                    return 1;
                }
                iss.clear();
                ++index;
            }
            if (eoln) {
                break;
            }
            str.clear();
        } else {
            str += c;
        }
    }

    if(values.size() == 0){
       cerr << "Enter sequence of integers, each followed by a space: Error: Sequence of integers not received." << endl;
    }
    
    int vectorLength = static_cast<int>(values.size());

    if (argc > 1) {
        if (argv[1][0] != '\0') {
            cout << "Enter sequence of integers, each followed by a space: Number of inversions (slow): "<< count_inversions_slow(&values[0], vectorLength) << endl;
        } 
    }
    if (argc < 2 && values.size() != 0) {
            cout << "Enter sequence of integers, each followed by a space: Number of inversions (fast): "<< count_inversions_fast(&values[0], vectorLength) << endl;
    }

    return 0;
}
