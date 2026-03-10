#include <iostream>  
#include <cstdlib>  
#include <ctime>     
using namespace std;


char rndDgit();
void prpLuhn(char[], int);
int  cnvrt(char);
char cnvrt(int);
void output(char[], int);
void Luhn(char[], int);

int main(int argc, char** argv) {
    
    srand(static_cast<unsigned int>(time(0)));

    int SIZE;

    cout << "Enter the length of the credit card number (10 - 30): ";
    cin >> SIZE;

    if(SIZE < 10 || SIZE > 30){
        cout << "Invalid length!" << endl;
        return 0;
    }

    SIZE += 1; 

    char crdCard[31]; 

    cout << "A random number created in Prep for Luhn Digit" << endl;

    prpLuhn(crdCard, SIZE-2);

    cout << crdCard << endl;

    output(crdCard, SIZE-2);

    Luhn(crdCard, SIZE);

    cout << "The random number with Luhn Encoding, Output Here!" << endl;
    cout << crdCard << endl;

    return 0;
}


void Luhn(char ccc[], int n){

    int sum = 0;

    for(int i = n - 3, pos = 0; i >= 0; i--, pos++){

        int digit = cnvrt(ccc[i]);

        if(pos % 2 == 0){
            digit *= 2;

            if(digit > 9){
                digit = digit/10 + digit%10;
            }
        }

        sum += digit;
    }

    int checkDigit = (sum * 9) % 10;

    ccc[n - 2] = cnvrt(checkDigit);
}


void output(char cc[], int n){
    cout << "The char array output as each integer digit" << endl;

    for(int i = 0; i < n; i++){
        cout << cnvrt(cc[i]);
    }

    cout << endl;
}


char cnvrt(int digit){

    if(digit < 0 || digit > 9){
        cout << "You don't know what you are doing" << endl;
        exit(0);
    }

    return digit + '0';
}


int cnvrt(char digit){

    if(digit < '0' || digit > '9'){
        cout << "You don't know what you are doing" << endl;
        exit(0);
    }

    return digit - '0';
}


void prpLuhn(char cc[], int n){

    for(int i = 0; i < n; i++){
        cc[i] = rndDgit();
    }

    for(int i = n; i <= n + 1; i++){
        cc[i] = '\0';
    }
}


char rndDgit(){
    return rand() % 10 + '0';
}