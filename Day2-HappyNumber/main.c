#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/528/week-1/3284/
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
bool contains(int *array, int size, int n);
bool isHappy(int n);
bool isHappy2(int n);
int squareAllDigits(int n);
int main(int argc, char *argv[]) {
	
	printf("%d", isHappy2(2));
	return 0;
}

bool isHappy(int n) {
	// 拆解數字並平方: 
	// n = squareAllDigits(n);
	
	
	// 避免繞圈，排除有出現過的可能
	unsigned int size = 10000;
	int history[size];
	int index = 0;
	while ( !contains( history, index, n ) ) {
		history[index++] = n;
		n = squareAllDigits(n);
	}
	// 如果是1，就是HappyNumber。
	return n == 1;
}

// 以上要array，會需要未知的空間限制。
// 以下採用快慢指針的方式，只要有繞圈，過不久就會追到，追到後再判斷是否為1。Floyd Cycle Detection Algorithm
bool isHappy2(int n) {
	int slow = n;
	int fast = n;
	
	do{
		slow = squareAllDigits(slow);                  //做一次 
		fast = squareAllDigits(squareAllDigits(fast)); // 做兩次 
	} while (slow != fast); //不一樣就繼續做 
	return fast == 1;
}

int squareAllDigits(int n){
	int sum = 0;
	while (n > 0){
		sum += (n%10) * (n%10);
		n /= 10;
	}
	return sum;
}

bool contains(int *array, int size, int n){
	int i = 0;
	for (i = 0; i < size; i++){
		if ( array[i] == n ){
			return true;
		}
	}
	return false;
}
