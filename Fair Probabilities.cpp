/*Game: Pandora's Box
  Game made by: Mickey Holmes, Gabriel Sher, and John Phillips 
  Teacher: Ms. Asselstine's 
  Class: MDM4UR
  Program made by: John Phillips
  Completed on: Thursday June 16, 2016
*/

/* This program gives the probability of getting each roll outcome in the game Pandora's Box
It finds the probability for the fair rules, so the dice of 4, 6, 8, 10, 12, and 20 are used.
*/    

#include <iostream>
using namespace std;

//Labelling system for the indices of biggest[]
enum Biggest{
	//sixOAK defaults to 0, and each successive element is 1 larger
	sixOAK,
	fiveOAK,
	twoThreeOAK,
	fullHouse,
	threeTwoOAK,
	fourOAK,
	threeOAK,
	twoTwoOAK,
	twoOAK,
	nothing
};

void checkBiggest(int biggest[], int nOAK[]){
	//type uses the biggest enum to make the highest dice combination clear
	Biggest type;
	
	//Check all combinations in order of descending scores and break when one is found
	if (nOAK[6-1]){
		type = sixOAK;
	}
	else if (nOAK[5-1]){
		type = fiveOAK;
	}
	else if (nOAK[3-1] == 2){
		type = twoThreeOAK;
	}
	else if (nOAK[4-1] && nOAK[2-1]){
		type = fullHouse;
	}
	else if (nOAK[2-1] == 3){
		type = threeTwoOAK;
	}
	else if (nOAK[4-1]){
		type = fourOAK;
	}
	else if (nOAK[3-1]){
		type = threeOAK;
	}
	else if (nOAK[2-1] == 2){
		type = twoTwoOAK;
	}
	else if (nOAK[2-1]){
		type = twoOAK;
	}
	else{
		type = nothing;
	}
	
	//type was the highest combination, so that index of biggest[] is incremented
	biggest[type]++;
}

void reset(int outcome[], int nOAK[]){
	for (int i = 0; i < 12; i++){
		outcome[i] = 0;
	}
	for (int i = 0; i < 6; i++){
		nOAK[i] = 0;
	}
}

void checkOutcome(int outcome[], int biggest[], int d4, int d6, int d8, int d10, int d12, int d20, int nOAK[]){
	//reset the dice and multiples of numbers all to 0
	reset(outcome, nOAK);
	
	//increment the outcomes based off of the numbers on each die
	outcome[d4-1]++;
	outcome[d6-1]++;
	outcome[d8-1]++;
	outcome[d10-1]++;
	outcome[d12-1]++;
	if (d20 <= 12)
	   outcome[d20-1]++;
    
    //loop through each possible die number and increment largest n of a kind counter that applies
    for (int i = 0; i < 12; i++){
    	for (int j = 6; j > 1; j--){
    		if (outcome[i] == j){
  		        nOAK[j-1]++;
    			break;
	        }
		}
	}

	checkBiggest(biggest, nOAK);
}

void printResults(int biggest[]){
	//The number of outcomes is equal to all of the die values multiplied together
	int numOutcomes = 4*6*8*10*12*20;
	//Use biggest enum to label indices of biggest[]
	Biggest type;
	printf("Of %d outcomes: \n\n", numOutcomes);
	printf("Best combination\tOccurences\tProbability(%)\n");
	printf("sixOAK:\t\t\t%10d\t\t%6.3f\n", biggest[sixOAK], (double)biggest[sixOAK]/numOutcomes*100);
	printf("fiveOAK:\t\t%10d\t\t%6.3f\n", biggest[fiveOAK], (double)biggest[fiveOAK]/numOutcomes*100);
	printf("twoThreeOAK:\t\t%10d\t\t%6.3f\n", biggest[twoThreeOAK], (double)biggest[twoThreeOAK]/numOutcomes*100);
	printf("fullHouse:\t\t%10d\t\t%6.3f\n", biggest[fullHouse], (double)biggest[fullHouse]/numOutcomes*100);
	printf("threeTwoOAK:\t\t%10d\t\t%6.3f\n", biggest[threeTwoOAK], (double)biggest[threeTwoOAK]/numOutcomes*100);
	printf("fourOAK:\t\t%10d\t\t%6.3f\n", biggest[fourOAK], (double)biggest[fourOAK]/numOutcomes*100);
	printf("threeOAK:\t\t%10d\t\t%6.3f\n", biggest[threeOAK], (double)biggest[threeOAK]/numOutcomes*100);
	printf("twoTwoOAK:\t\t%10d\t\t%6.3f\n", biggest[twoTwoOAK], (double)biggest[twoTwoOAK]/numOutcomes*100);
	printf("twoOAK:\t\t\t%10d\t\t%6.3f\n", biggest[twoOAK], (double)biggest[twoOAK]/numOutcomes*100);
	printf("nothing:\t\t%10d\t\t%6.3f\n", biggest[nothing], (double)biggest[nothing]/numOutcomes*100);
}

int main(){
	//stores how many of each number were rolled (above 12 is not stored, because you cannot get multiples of numbers that only appear on one die)
	int outcome[12];
	//number of pairs, triples... up to sextuplets;
	int nOAK[6];
	//stores the number of instances of a certain combination as the highest scoring combination of a roll
	int biggest[10];
	for (int i = 0; i < 10; i++){
		biggest[i] = 0;
	}
	
	//loop through all possibilities
	for (int d4 = 1; d4 <= 4; d4++){
		for (int d6 = 1; d6 <= 6; d6++){
			for (int d8 = 1; d8 <= 8; d8++){
                for (int d10 = 1; d10 <= 10; d10++){
					for (int d12 = 1; d12 <= 12; d12++){
						for (int d20 = 1; d20 <= 20; d20++){
							checkOutcome(outcome, biggest, d4, d6, d8, d10, d12, d20, nOAK);
	                    }
	                }
	            }
	        }
	    }
	}
	
	printResults(biggest);
	system("pause");
	
	return 0;
}
