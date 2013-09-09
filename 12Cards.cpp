/*
 *  Created by forrest on 9/9/2013.
 *  
 */
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
//I have a deck of 12 cards. Every day I draw 3 without replacement, record them, and shuffle them back. How many days before I've drawn every card?

using namespace std;

int simulate(void)
{
    //this simulation goes through one "game" and reports how many days elapsed before the game was over
	int record[12];
	int i, j;
	for(i=0; i<12; i++){
		record[i]=0;}
	int sum_of_record=0;
	int day = 0;
	int card1, card2, card3;
	while(sum_of_record<12){
		card1=rand()%12;
		card2=rand()%11;
		if(card2==card1){
			card2++;}
		card3=rand()%10;
		while((card3==card2)+(card3==card1)>0){
		card3++;}
		if(record[card1]==0){
			record[card1]++;
			sum_of_record++;}
		if(record[card2]==0){
			record[card2]++;
			sum_of_record++;}
		if(record[card3]==0){
			record[card3]++;
			sum_of_record++;}
		day++;
	}
	return day;
}
		
int main ()
{
	srand((unsigned)time(0));
	int i;
	int days_hist[100];
	int simulation_output;
	for(i=0;i<100;i++){
		days_hist[i]=0;}
	for(i=0;i<10000000;i++){
		simulation_output=simulate();
		if(simulation_output<100){
		days_hist[simulation_output]++;}
	}
	for(i=0;i<100;i++){
	cout<<"days: "<<i<<" hits: "<<days_hist[i]<<endl;
	}
	return 0;
}
	
		
		
		
		
		
