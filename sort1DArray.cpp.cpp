//System Libraries Here
#include <iostream>//cout,cin
#include <cstring> //strlen()
    using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int  read(char arr[]) {
    cin >> arr;              // read as a string (no spaces)
    return strlen(arr);      // return detected size
}
void sort(char arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void print(const char arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i];
    }
    cout << endl;
}

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE = 80;//Larger than needed
    char array[SIZE]; //Character array larger than needed
    int sizeIn, sizeDet;//Number of characters to be read, check against length

    //Input the size of the array you are sorting
    cout << "Read in a 1 dimensional array of characters and sort" << endl;
    cout << "Input the array size where size <= 20" << endl;
    cin >> sizeIn;

    //Now read in the array of characters and determine it's size
    cout << "Now read the Array" << endl;
    sizeDet = read(array);//Determine it's size

    //Compare the size input vs. size detected and sort if same
    //Else output different size to sort
    if (sizeDet == sizeIn) {
        sort(array, sizeIn); //Sort the array
        print(array, sizeIn);//Print the array
    }
    else {
        cout << (sizeDet < sizeIn ? "Input size less than specified." :
            "Input size greater than specified.") << endl;
    }

    //Exit
    return 0;
}
