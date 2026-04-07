/* * File:   main.cpp
 * Author: YOUR NAME HERE
 * Created on DATE AND TIME HERE
 * Purpose:  Sorting a 2-D array of characters with modified sort order
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <cstring> //strlen(),strcmp(),strcpy()
using namespace std;

//Global Constants Only, No Global Variables
const int COLMAX=80;

//Function Prototypes Here
int  read(char [][COLMAX],int &);
void sort(char [][COLMAX],int,int,const char[],const char[]);
void print(const char [][COLMAX],int,int);
int  strcmpCustom(char [],char [],const unsigned char []);

//Program Execution Begins Here
int main(int argc, char** argv) {
    const int ROW=30;
    char array[ROW][COLMAX];
    int colIn,colDet,rowIn,rowDet;
    char replace[COLMAX],with[COLMAX];
    
    cout<<"Modify the sort order by swapping these characters."<<endl;
    cin>>replace;
    cout<<"With the following characters"<<endl;
    cin>>with;
    cout<<"Read in a 2 dimensional array of characters and sort by Row"<<endl;
    cout<<"Input the number of rows <= 20"<<endl;
    cin>>rowIn;
    cout<<"Input the maximum number of columns <=20"<<endl;
    cin>>colIn;
    
    rowDet=rowIn;
    cout<<"Now input the array."<<endl;
    colDet=read(array,rowDet);
    
    sort(array,rowIn,colIn,replace,with);
    cout<<"The Sorted Array"<<endl;
    print(array,rowIn,colIn);
    
    return 0;
}

int read(char a[][COLMAX], int &rIn) {
    int maxLen = 0;
    int count = 0;
    for (int i = 0; i < rIn; i++) {
        if (!(cin >> a[i])) break;
        count++;
        int len = strlen(a[i]);
        if (len > maxLen) maxLen = len;
    }
    rIn = count;
    return maxLen;
}

// Optimized comparison using a pre-mapped translation table
int strcmpCustom(char a[], char b[], const unsigned char map[]) {
    int i = 0;
    while (true) {
        unsigned char charA = map[(unsigned char)a[i]];
        unsigned char charB = map[(unsigned char)b[i]];

        if (charA < charB) return -1;
        if (charA > charB) return 1;
        if (a[i] == '\0') return 0;
        i++;
    }
}

void sort(char a[][COLMAX], int r, int c, const char rep[], const char with[]) {
    // 1. Create the Translation Table
    unsigned char map[256];
    for (int i = 0; i < 256; i++) map[i] = (unsigned char)i;

    // 2. Apply Swaps to the Table
    for (int k = 0; rep[k] != '\0'; k++) {
        unsigned char rChar = (unsigned char)rep[k];
        unsigned char wChar = (unsigned char)with[k];
        // Perform a literal swap in the mapping table
        unsigned char temp = map[rChar];
        map[rChar] = map[wChar];
        map[wChar] = temp;
    }

    // 3. Bubble Sort using the custom map
    for (int i = 0; i < r - 1; i++) {
        for (int j = 0; j < r - i - 1; j++) {
            if (strcmpCustom(a[j], a[j + 1], map) > 0) {
                char temp[COLMAX];
                strcpy(temp, a[j]);
                strcpy(a[j], a[j + 1]);
                strcpy(a[j + 1], temp);
            }
        }
    }
}

void print(const char a[][COLMAX], int r, int c) {
    for (int i = 0; i < r; i++) {
        cout << a[i] << endl;
    }
}
