
#include <iostream>
#include <sstream>
using namespace std;

// Struct to represent state of water in the jugs.
struct State {
int a, b, c;
string directions;
State *parent;

State(int _a, int _b, int _c, string _directions) :
a{_a}, b{_b}, c{_c}, directions{_directions}, parent{nullptr} { }

// String representation of state in tuple form.
string to_string() {
ostringstream oss;
oss << "(" << a << ", " << b << ", " << c << ")";
return oss.str();
}
};


int main(int argc, char* const argv[]) {

    if (argc != 7) {
        cout << "Usage: ./waterjugpuzzle <cap A> <cap B> <cap C> <goal A> <goal B> <goal C>" << endl;
        return 1;
    }

    char jugs[] = {'E', 'A', 'B', 'C', 'A', 'B', 'C'};


    for(int i=1; i < argc; i++){

        stringstream iss;
        int input;
        iss.str(argv[i]);

        if ((i < 4 && !(iss >> input)) || i < 4 && input < 0) {
            cerr << "Error: Invalid capacity '" << argv[i] << "' for jug " << jugs[i] << "." << endl;
        return 1;}

        if ((i >= 4 && !(iss >> input)) || i >= 4 && input < 0) {
            cerr << "Error: Invalid goal '" << argv[i] << "' for jug " << jugs[i] << "." << endl;
        return 1;}
    }

    for (int i = 1; i < argc - 3; i++) {
        int capacity, goal;
        stringstream capstream(argv[i]);
        stringstream goalstream(argv[i + 3]);
        capstream >> capacity;
        goalstream >> goal;

        if (goal > capacity) {
        cerr << "Error: Goal cannot exceed capacity of jug " << jugs[i] << "." << endl;
        return 1;
        }
    }
    
    stringstream goalAS(argv[5]);
    stringstream goalBS(argv[6]);
    stringstream goalCS(argv[7]);
    stringstream capCS(argv[4]);
    int goalA, goalB, goalC, capC;
    goalAS >> goalA;
    goalBS >> goalB;
    goalCS >> goalC;
    capCS >> capC;

    if(goalA+goalB+goalC!=capC){
        cerr << "Error: Total gallons in goal state must be equal to the capacity of jug C." << endl;
    }


State state(0, 0, capC, "Initial state.");

return 0;

}
