/*******************************************************************************
 * Name        : sieve.cpp
 * Author      : Ronin Deschamps
 * Date        : 9/18/2023
 * Description : Sieve of Eratosthenes
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System
 ******************************************************************************/
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

class PrimesSieve {
public:
    PrimesSieve(int limit);

    ~PrimesSieve() {
        delete [] is_prime_;
    }

    void display_primes() const;

    int num_primes() const {
        return num_primes_;
    }

private:
    // Instance variables
    bool * const is_prime_;
    const int limit_;
    int num_primes_, max_prime_;

    // Method declarations
    void sieve();
    static int num_digits(int num);
};

PrimesSieve::PrimesSieve(int limit) :

        is_prime_{new bool[limit + 1]}, limit_{limit} {

            for(int i=0; i<=limit; i++){

                is_prime_[i]= true;
            }
    sieve();
}

void PrimesSieve::display_primes() const {
    //code to display the primes in the format specified


    const int max_prime_width = num_digits(max_prime_),
        primes_per_row = 80 / (max_prime_width + 1);

    int primes_on_current_row = 0;

    if(max_prime_ < 100){
        cout << 2;
        for (int i = 3; i <= limit_; i++) {
            if (is_prime_[i]==true){
                cout << " ";
                cout << i;
            }

    }
    }
    else{

    for (int i = 2; i <= limit_; i++) {
        
        if (is_prime_[i]==true && primes_on_current_row < primes_per_row-1) {

            cout << setw(max_prime_width) << i;
            primes_on_current_row++;
            if(i != max_prime_){
                cout << " ";
            }
           
        }
         else if (is_prime_[i]==true && primes_on_current_row == primes_per_row -1) {
            cout << setw(max_prime_width) << i << endl;
                primes_on_current_row = 0;

            }
    }

    cout << endl;
}}

void PrimesSieve::sieve() {
    
  for(int i=2; i <= sqrt(limit_); i++){
  
        if(is_prime_[i] == true){

            for(int j = i*i; j <= limit_; j += i){
                is_prime_[j] = false;
        }
    }
  } 
    num_primes_ = 0;
    for (int k = 2; k <= limit_; k++) {
        if (is_prime_[k]) {
            num_primes_++;
            max_prime_ = k;}}
  }


int PrimesSieve::num_digits(int num) {
    //code to determine how many digits are in an integer
    int count = 0;
    while(num != 0){

        num = num/10;
        count++;
    }
    return count;
}

int main() {
    cout << "**************************** " <<  "Sieve of Eratosthenes" <<
            " ****************************" << endl;
    cout << "Search for primes up to: ";
    string limit_str;
    cin >> limit_str;
    int limit;
    

    // Use stringstream for conversion. Don't forget to #include <sstream>
    istringstream iss(limit_str);

    // Check for error.
    if ( !(iss >> limit) ) {
        cerr << "Error: Input is not an integer." << endl;
        return 1;
    }
    if (limit < 2) {
        cerr << "Error: Input must be an integer >= 2." << endl;
        return 1;
    }

    // TODO: write code that uses your class to produce the desired output.
    
    cout << endl;
    PrimesSieve Sieve(limit);
    cout << "Number of primes found: " << Sieve.num_primes() << endl;
    cout << "Primes up to " << limit << ":" << endl;
    Sieve.display_primes();

    return 0;
}
