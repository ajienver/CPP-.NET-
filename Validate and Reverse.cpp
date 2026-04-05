
//System Libraries Here
#include <iostream>//cin,cout,endl
#include <cstring> //strlen()
#include <climits> //SHRT_MAX, USHRT_MAX
using namespace std;

//Function Prototypes Here
bool  inRange(const char [], unsigned short &);
bool  reverse(unsigned short, signed short &);
short subtrct(signed short, int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    const int SIZE=80;
    char  digits[SIZE];
    unsigned short unShort;
    short snShort;
    
    cout<<"Reverse a number and subtract if possible."<<endl;
    cout<<"Input a number in the range of an unsigned short"<<endl;
    cin>>digits;
    
    if(!inRange(digits,unShort)){
        cout<<"No Conversion Possible"<<endl;
        return 0;
    }
    
    if(!reverse(unShort,snShort)){
        cout<<"No Conversion Possible"<<endl;
        return 0;
    }
    
    snShort=subtrct(snShort,999);
    cout<<snShort<<endl;
    
    return 0;
}

// Validates if input string is numeric and fits in unsigned short (0-65535)
bool inRange(const char d[], unsigned short &unShort) {
    int len = strlen(d);
    long val = 0;
    for (int i = 0; i < len; i++) {
        if (d[i] < '0' || d[i] > '9') return false;
        val = val * 10 + (d[i] - '0');
    }
    if (val > 65535) return false;
    unShort = static_cast<unsigned short>(val);
    return true;
}

// Reverses digits based on a 5-digit field and checks signed short range (up to 32767)
bool reverse(unsigned short unShort, signed short &snShort) {
    int d[5] = {0};
    unsigned short temp = unShort;
    
    // Extract 5 digits (including leading zeros for the 5-digit field)
    for (int i = 0; i < 5; i++) {
        d[i] = temp % 10;
        temp /= 10;
    }
    
    // The digits are extracted in reverse order already (ones, tens, etc.)
    // But the logic "321 (00321) -> 12300" means the last digit becomes the first.
    long revVal = 0;
    for (int i = 0; i < 5; i++) {
        revVal = revVal * 10 + d[i];
    }
    
    // Check if it fits in a signed short (max 32767)
    if (revVal > 32767) return false;
    
    snShort = static_cast<signed short>(revVal);
    return true;
}

// Subtracts the value only if the result remains non-negative
short subtrct(signed short snShort, int sub) {
    if (snShort - sub >= 0) {
        return snShort - sub;
    }
    return snShort;
}
