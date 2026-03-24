
#include <iostream>//cin,cout
using namespace std;

//Function Prototypes Here
void read(int [],int);
int  stat(const int [],int,int &,int &);
void print(const int [],int,int,int,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;
    int array[SIZE];
    int sizeIn,sum,min,max;
    
    //Input the size of the array you are sorting
    //Adjusted string to match Expected Output exactly
    cout<<"Read in a 1 dimensional array of integers find sum/min/max"<<endl;
    cout<<"Input the array size where size <= 20"<<endl;
    cin>>sizeIn;
    
    //Now read in the array of integers
    cout<<"Now read the Array"<<endl;
    read(array,sizeIn);
    
    //Find the sum, min, and max
    sum=stat(array,sizeIn,max,min);
    
    //Print the results
    print(array,sizeIn,sum,max,min);
    
    //Exit
    return 0;
}

void read(int arr[],int size){
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
}

int stat(const int arr[],int size,int &max,int &min){
    int sum=0;
    if(size > 0) {
        max=min=arr[0];
        for(int i=0;i<size;i++){
            sum+=arr[i];
            if(arr[i]>max)max=arr[i];
            if(arr[i]<min)min=arr[i];
        }
    }
    return sum;
}

void print(const int arr[],int size,int sum,int max,int min){
    for(int i=0;i<size;i++){
        cout<<"a["<<i<<"] = "<<arr[i]<<endl;
    }
    // Added an extra space before the '=' to match "Min  ="
    cout<<"Min  = "<<min<<endl;
    cout<<"Max  = "<<max<<endl;
    cout<<"Sum  = "<<sum<<endl;
}
