/*******************************************************************************
 * Filename: Sqrt.cpp
 * Author  : Ronin Deschamps
 * Version : 1.0
 * Date    : 9/10/2023
 * Description: Computes the squareroot of a number.
 * Pledge  : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

#include <iostream>
#include <sstream>
#include <limits>
#include <iomanip>
using namespace std;

double sqrt(double num, double epsilon){


    double lastguess = num;
    double nextguess = (lastguess+num/lastguess)/2;;

    if(num==0 || num==1){
        cout << fixed << setprecision(8) << num << endl;
    return 1;}
    
    while(abs(lastguess-nextguess) >= epsilon){
            lastguess = nextguess;
            nextguess = (lastguess+num/lastguess)/2;}
 
    cout << fixed << setprecision(8) << nextguess << endl;
    return 1;
}

int main(int argc, char* argv[]) {
    
    double num, epsilon = 0.0000001;
    istringstream iss;


    //check if user entered the correct amount of integers
    if (argc != 2 && argc != 3) {
        cerr << "Usage: ./sqrt <value> [epsilon]"<< endl;
        return 1;
    }
        //turn input charecters into integers
    iss.str(argv[1]);
    if (!(iss >> num)) {
        cerr << "Error: Value argument must be a double." << endl;
        return 1;
    } //stored int as n

    iss.clear(); //clears object iss before next translation

    if(argc == 3){
        iss.clear();
        iss.str(argv[2]);
        if ((!(iss >> epsilon))|| epsilon <= 0) {
        cerr << "Error: Epsilon argument must be a positive double." << endl;
        return 1;
    }}

    iss.clear();

        if(num < 0.0){
        cout << numeric_limits<double>::quiet_NaN() << endl;
        return 0;}

   sqrt(num, epsilon);
    return 1;
}
