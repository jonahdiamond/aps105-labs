#include <stdio.h>

void appendStatistics(int userChoice[], const int ChoicesNum, int histogram[]);
int frequentBox(int histogram[], const int BoxesNum);

int main(void) {
  const int BoxesNum = 20;
  const int ChoicesNum = 5;

  int userOne[ChoicesNum], userOneHisto[BoxesNum];

  for (int i = 0; i < BoxesNum; i++) {
    userOneHisto[i] = 0;
  }

  int numOfTimes = 0;
  while (numOfTimes <= 5) {
    printf("Enter choices: ");
    for (int i = 0; i < 5; i++) {
      scanf("%d", &userOne[i]);
    }
    appendStatistics(userOne, ChoicesNum, userOneHisto);
    numOfTimes++;
  }
  printf("The smallest and most frequently used box is: %d\n",
         frequentBox(userOneHisto, BoxesNum));
  return 0;
}

void appendStatistics(int userChoice[], const int ChoicesNum, int histogram[]) {
  // Fill in the histogram with the number of times each index was picked
  // Print the histogram
  for (int i = 0; i < ChoicesNum; i++){
    histogram[userChoice[i]]++;
  }
}

int frequentBox(int histogram[], const int BoxesNum) {
  // Return the index having the maximum number in histogram
  int highest = 0, mostFreqNum = 0, i = 0;
  for (i = 0; i < BoxesNum; i++){
    if (histogram[i] > highest){
        highest = histogram[i];
        mostFreqNum = i;
    } 
    
  }
  return mostFreqNum;
}
