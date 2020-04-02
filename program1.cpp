#include <iostream>
#include <string>

using namespace std;

string insertionSort(string *arr, int size);
void swap(string *arr, int i, int j);
void lexicographic(string *arr, int n);
void reverse(string *arr, int i, int n);

int main(){
    string userInput[100];  //array of strings
    int size = 0;  //as the user inputs strings, size will increment
    bool boolVar = 1;  //boolean for while loop


   while(boolVar){  //loops until user hits max amount of strings or the enter "quit"
        for(int i = 0; i <= 100; i++){
            cout << "Enter a string or type quit: ";
            cin >> userInput[i];
            size++;

            if(userInput[i] == "quit"){
                size--;
                boolVar = 0;
                break;
            }
        }

    }

    cout << endl;

    cout << "The size of your array is " << size << " elements.\n" << endl;

    cout << "Sorting the array with the Insertion Sort algorithm.\n" << endl;

    insertionSort(userInput, size);

   //prints out sorted strings
    for (int i = 0; i < size; i++){
        cout << userInput[i] << " ";
    }

    cout << "\nLEXICOGRAPHIC ALGORITHM:\n" << endl;

    lexicographic(userInput, size);

    return 0;
}
//takes in array of strings that are entered in by user and returns them sorted by insertion sort
string insertionSort(string *arr, int n){
    string key;
    int j;
    for (int i = 1; i < n; i++){
        key = arr[i];
        j = i;
        while(j > 0 && arr[j - 1] > key){
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = key;
    }
    return *arr;
}

//function to swap indexes within array sent to it
void swap(string *arr, int i , int j){
  string temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

//function that prints out all possible permutations of array sent to it
void lexicographic(string *arr, int n){
  int largestI;
  int largestJ;
  int perms = 1;
  bool p = 1;

  //outputs first permutation
  cout << perms << ". ";
  for(int x = 0; x < n; x++){
    cout << arr[x] << " ";
  }

  cout << endl;
  
    while(p == 1){
      largestI = -1;
      largestJ = -1;

      //finds correct i where arr[i] < arr[i+1]
      for(int i = 0; i < n - 1; i++){
        if(arr[i] < arr[i + 1]){
          largestI = i;
        }
      }

      //finds correct j where arr[i] < arr[j]
      for (int j = 0; j < n; j++){
        if(arr[largestI] < arr[j]){
          largestJ = j;
        }
      }

      //swap and reverse array at specified indexes
      swap(arr, largestI, largestJ);
      reverse(arr, largestI + 1, n);

      //prints out the rest of the permutations as long as largestI & largestJ are > -1
      if(largestI > -1 && largestJ > -1){
        perms++;
        cout << perms << ". ";
        for(int y = 0; y < n; y++){
          cout << arr[y] << " ";
        }
        cout << endl;
      }

      if(largestI == -1 ){
        p = 0;
      }
      else if(largestJ == -1){
        p = 0;
      }
    }

    cout << "\nEND!" << endl;
  
}

//function that reverses array at specified index to the end of the array
void reverse(string *arr, int i, int n){
  string temp;
  int j = n - 1;

  while (i < j){
    swap(arr, i, j);
    i++;
    j--;
  }
}