

//System Libraries Here
#include <iostream>//cin,cout,getline()
#include <cstring> //strlen()
using namespace std;



//Function Prototypes
int  srch1(const char [],const char [],int);
void srchAll(const char [],const char [],int []);
void print(const char []);
void print(const int []);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int LINE=81;               //Size of sentence or pattern to find
    char sntnce[LINE],pattern[LINE]; //80 + null terminator
    int match[LINE];                 //Index array where pattern was found
    
    //Input a sentence and a pattern to match
    cout<<"Match a pattern in a sentence."<<endl;
    cout<<"Input a sentence"<<endl;
    cin.getline(sntnce,LINE);
    cout<<"Input a pattern."<<endl;
    cin.getline(pattern,LINE);
    
    //Search for the pattern
    srchAll(sntnce,pattern,match);
    
    //Display the inputs and the Outputs
    cout<<endl<<"The sentence and the pattern"<<endl;
    print(sntnce);
    print(pattern);
    cout<<"The positions where the pattern matched"<<endl;
    print(match);
    
    //Exit
    return 0;
}

// Search for 1 occurrence starting from a specific index
int srch1(const char s[], const char p[], int start) {
    int sLen = strlen(s);
    int pLen = strlen(p);
    
    for (int i = start; i <= sLen - pLen; i++) {
        bool found = true;
        for (int j = 0; j < pLen; j++) {
            if (s[i + j] != p[j]) {
                found = false;
                break;
            }
        }
        if (found) return i;
    }
    return -1;
}

// Search for all occurrences and store in match array
void srchAll(const char s[], const char p[], int match[]) {
    int count = 0;
    int pos = srch1(s, p, 0);
    
    while (pos != -1) {
        match[count++] = pos;
        pos = srch1(s, p, pos + 1);
    }
    match[count] = -1; // Sentinel to mark end of matches
}

// Print character array
void print(const char c[]) {
    cout << c << endl;
}

// Print integer array of matches
void print(const int m[]) {
    if (m[0] == -1) {
        cout << "None" << endl;
    } else {
        for (int i = 0; m[i] != -1; i++) {
            cout << m[i] << endl;
        }
    }
}
