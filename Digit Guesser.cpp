#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <chrono>
using namespace std;

int bullcount(vector<int> a, vector<int> b);
int cowcount(vector<int> a, vector<int> b);
vector<int> shuffle(vector<int>& a);

int main(){
  int guess, bull = 0, tries = 0;
  vector<int> game_number, guess_vec, ranvec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  shuffle(ranvec);
  game_number.push_back(ranvec[0]);
  game_number.push_back(ranvec[1]);
  game_number.push_back(ranvec[2]);
  game_number.push_back(ranvec[3]);

  /*for(int i = 0; i < 4; i ++){
    cout << game_number[i];
  }
  cout << endl;*/   //Print program number
  auto start = chrono::steady_clock::now();
  while(bull < 4){
    guess_vec.clear();
    cout << "Enter a 4 digit number(unique digits): ";
    cin >> guess;

    guess_vec.push_back(guess / 1000); //thousands
    guess_vec.push_back((guess % 1000) / 100); //hundreds
    guess_vec.push_back(((guess % 1000) % 100) / 10); //tens
    guess_vec.push_back(((guess % 1000) % 100) % 10); //ones
    
    bull = bullcount(guess_vec, game_number);
    cout << "bulls = " << bull << " and cows = " << cowcount(guess_vec, game_number) << endl;
    
    tries ++;
  }
  auto end = chrono::steady_clock::now();
  int seconds = chrono::duration_cast<chrono::seconds>(end - start).count();
  int minutes = seconds / 60;
  
  cout << "You guessed it in " << tries << " tries, taking " << minutes << " minutes and " << seconds % 60 << " seconds" << endl;
  return 0;
}

int bullcount(vector<int> a, vector<int> b){
  int bull = 0;
  for(int i = 0; i < a.size(); i++){
    if(a[i] == b[i])
      bull ++;
  }
  return bull;
}
int cowcount(vector<int> a, vector<int> b){
  int cow = 0;
  for(int i = 0; i < a.size(); i++){
    for(int j = 0; j < a.size(); j++){
      if(a[i] == b[j] && a[i] != b[i])
        cow ++;
    }
  }
  return cow;
}
vector<int> shuffle(vector<int>& a){
  srand(time(0));
  for(int i = 0; i < a.size(); i++){ 
    int j = rand() % 10;
    vector<int> temp = a;
    a[i] = a[j];
    a[j] = temp[i];
  }
  return a;
}


