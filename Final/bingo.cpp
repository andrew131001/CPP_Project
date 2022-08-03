#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
using namespace std;

// declare variables 
int i,user,computer;
int arr[9];
int userArr[9];
int computerArr[9];
string userBingo,computerBingo;
char choice;
// define boolean variables for while loops
bool repeat = true;
bool goStop = true;

// shuffle elements for random order
void shuffle(int *arr, size_t n) {
  if (n > 1) {
    size_t i;
    srand(time(NULL));
    for (i = 0; i < n - 1; i++) {
      size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
      int t = arr[j];
      arr[j] = arr[i];
      arr[i] = t;
    }
  }
} // end function

// print out 3x3 bingo board 
void board(int a[]) {
cout << endl;
cout << "     |     |     " << endl;
cout << "  " << a[0] << "  |  " << a[1] << "  |  " << a[2] << endl;

cout << "_____|_____|_____" << endl;
cout << "     |     |     " << endl;

cout << "  " << a[3] << "  |  " << a[4] << "  |  " << a[5] << endl;

cout << "_____|_____|_____" << endl;
cout << "     |     |     " << endl;

cout << "  " << a[6] << "  |  " << a[7] << "  |  " << a[8] << endl;

cout << "     |     |     " << endl << endl;

}// end function

// check user's bingo board
void userBoard(int u) {
  // find the index value of element in arr by user's input
  int userIndex = distance(arr, find(arr, arr + 9, u));
  // assign the same value at the index of element in arr to the same index of element in userArr
  userArr[userIndex] = arr[userIndex];
  // print out to see the current status
  cout << "User's Bingo Board" << endl;
  board(userArr);
} // end function

// check computer's bingo board
void computerBoard() {
  // generate random number between 1 and 9
  computer = (rand() % 9) + 1;
  // find the index value of element in arr by generated random number
  int computerIndex = distance(arr, find(arr, arr + 9, computer));
  // assign the same value at the index of element in arr to the same index of element in userArr 
  computerArr[computerIndex] = arr[computerIndex];
  // print out to see the current status
  cout << "Computer's Bingo Board" << endl;
  board(computerArr);
} // end function

void checkWin() {
  // check if there is a bingo for user
  if (userArr[0] == arr[0] && userArr[1] == arr[1] && userArr[2] == arr[2] ||
  userArr[3] == arr[3] && userArr[4] == arr[4] && userArr[5] == arr[5] ||
  userArr[6] == arr[6] && userArr[7] == arr[7] && userArr[8] == arr[8] ||
  userArr[0] == arr[0] && userArr[3] == arr[3] && userArr[6] == arr[6] ||
  userArr[1] == arr[1] && userArr[4] == arr[4] && userArr[7] == arr[7] ||
  userArr[2] == arr[2] && userArr[5] == arr[5] && userArr[8] == arr[8] ||
  userArr[0] == arr[0] && userArr[4] == arr[4] && userArr[8] == arr[8] ||
  userArr[2] == arr[2] && userArr[4] == arr[4] && userArr[6] == arr[6]) {
    // print out if so
    cout << "User Bingo!" << endl;
    // assign the value to compare it with computer
    userBingo = "bingo";
  }
  // check if there is a bingo for computer
  if (computerArr[0] == arr[0] && computerArr[1] == arr[1] && computerArr[2] == arr[2] ||
  computerArr[3] == arr[3] && computerArr[4] == arr[4] && computerArr[5] == arr[5] ||
  computerArr[6] == arr[6] && computerArr[7] == arr[7] && computerArr[8] == arr[8] ||
  computerArr[0] == arr[0] && computerArr[3] == arr[3] && computerArr[6] == arr[6] ||
  computerArr[1] == arr[1] && computerArr[4] == arr[4] && computerArr[7] == arr[7] ||
  computerArr[2] == arr[2] && computerArr[5] == arr[5] && computerArr[8] == arr[8] ||
  computerArr[0] == arr[0] && computerArr[4] == arr[4] && computerArr[8] == arr[8] ||
  computerArr[2] == arr[2] && computerArr[4] == arr[4] && computerArr[6] == arr[6]) {
    // print out if so
    cout << "Computer Bingo!" << endl;
    // assign the value to compare it with user
    computerBingo = "bingo";
  }
} // end function

// determine whether user wants to do more or not
void go_or_stop(char a) {
  if (a == 'y') {
    goStop = true;
    // if so, re-create the array for play
    for (i=0; i<9; i++) {
    arr[i] = i+1;
    }
    // shuffle it
    shuffle(arr, 9);
    // make userArr be back to zero
    for (int i = 0; i < sizeof(userArr); i++) {
      userArr[i] = 0;
    }
    // make computerArr be back to zero
    for (int i = 0; i < sizeof(computerArr); i++) {
      computerArr[i] = 0;
    }
  } else {
    goStop = false; // user wants to play no more
  }
}

int main() {
  // create the array for game
  for (i=0; i<9; i++){
    arr[i] = i+1;
  }
  shuffle(arr, 9);

  // play game until user stops it
  while (goStop) {
    // repeat until there is a winner
    while (repeat) {
      // get user's input
      cout << "Enter random number between 1 and 9" << endl;
      cin >> user;
      // pass it as an argument to the function to put it on the board
      userBoard(user);
      // computer's board
      computerBoard();
      // check if there is a bingo for both user and computer
      checkWin();
      // to see who wins the game
      if (userBingo == "bingo" && computerBingo == "bingo") {
        cout << "It's tie." << endl;
        break;
      } else if (userBingo == "bingo") {
        cout << "User Win!" << endl;
        break;
      } else if (computerBingo == "bingo") {
        cout << "Computer Win!" << endl;
        break;
      }
    }// end while loop

    // check if user wants to play more
    cout << "Would you like to play one more round? (y/n)" << endl;
    cin >> choice;
    // call function by user's choice
    go_or_stop(choice);
  }
  return 0;
}// end main function