#include <iostream>//cin,cout
#include <vector>  //vectors<>
#include <iomanip> //Format setw(),right
using namespace std;



//Global Constants Only, No Global Variables
const int COLMAX=2;

//Function Prototypes Here
void read(vector<int> &, vector<int> &);
void copy(vector<int>, vector<int>,int [][COLMAX]);
void prntVec(vector<int>, vector<int>,int);
void prntAry(const int [][COLMAX],int,int,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    const int ROW=80;
    int array[ROW][COLMAX];
    vector<int> even(0),odd(0);
    
    read(even,odd);
    
    // Vector Output
    cout << setw(10) << "Vector" << setw(10) << "Even" << setw(10) << "Odd" << endl;
    prntVec(even,odd,10);
    
    copy(even,odd,array);
    
    // Array Output
    cout << setw(10) << "Array" << setw(10) << "Even" << setw(10) << "Odd" << endl;
    prntAry(array,even.size(),odd.size(),10);
    
    return 0;
}

void read(vector<int> &even, vector<int> &odd) {
    int size, val;
    cout << "Input the number of integers to input." << endl;
    cin >> size;
    cout << "Input each number." << endl;
    for(int i = 0; i < size; i++) {
        cin >> val;
        if(val % 2 == 0) even.push_back(val);
        else odd.push_back(val);
    }
}

void copy(vector<int> even, vector<int> odd, int a[][COLMAX]) {
    // Initialize array with a sentinel or just rely on sizes
    for(int i = 0; i < even.size(); i++) a[i][0] = even[i];
    for(int i = 0; i < odd.size(); i++) a[i][1] = odd[i];
}

void prntVec(vector<int> even, vector<int> odd, int n) {
    int maxRows = (even.size() > odd.size()) ? even.size() : odd.size();
    for(int i = 0; i < maxRows; i++) {
        cout << setw(n) << ""; // Blank first column for "Vector" alignment
        if(i < even.size()) cout << setw(n) << even[i];
        else cout << setw(n) << "";
        
        if(i < odd.size()) cout << setw(n) << odd[i];
        else cout << setw(n) << "";
        cout << endl;
    }
}

void prntAry(const int a[][COLMAX], int eSize, int oSize, int n) {
    int maxRows = (eSize > oSize) ? eSize : oSize;
    for(int i = 0; i < maxRows; i++) {
        cout << setw(n) << ""; // Blank first column for "Array" alignment
        if(i < eSize) cout << setw(n) << a[i][0];
        else cout << setw(n) << "";
        
        if(i < oSize) cout << setw(n) << a[i][1];
        else cout << setw(n) << "";
        cout << endl;
    }
}
