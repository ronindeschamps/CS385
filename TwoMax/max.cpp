#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

int max(int m, int n) {
return m > n ? m : n;
}

int main(int argc, char* argv[]) {
    int n, m;
    istringstream iss;

    //check if user entered the correct amount of integers
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <int> <int>" << endl;
        return 1;
    }
        //turn input charecters into integers
    iss.str(argv[1]);
    if (!(iss >> n)) {
        cerr << "Err: first argument must be an int " << endl;
        return 1;
    } //stored int as n

    iss.clear(); //clears object iss before next translation

    iss.str(argv[2]);
    if (!(iss >> m)) {
        cerr << "Err: first argument must be an int " << endl;
        return 1;
    } //stored int as n

    cout << "n is "  << n << endl;
    cout << "m is " << m << endl;
    cout << "max is: " << max(n, m) << endl;

    return 0;

}
