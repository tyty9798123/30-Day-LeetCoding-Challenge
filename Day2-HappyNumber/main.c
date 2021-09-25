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
	// ��ѼƦr�å���: 
	// n = squareAllDigits(n);
	
	
	// �קK¶��A�ư����X�{�L���i��
	unsigned int size = 10000;
	int history[size];
	int index = 0;
	while ( !contains( history, index, n ) ) {
		history[index++] = n;
		n = squareAllDigits(n);
	}
	// �p�G�O1�A�N�OHappyNumber�C
	return n == 1;
}

// �H�W�narray�A�|�ݭn�������Ŷ�����C
// �H�U�ĥΧֺC���w���覡�A�u�n��¶��A�L���[�N�|�l��A�l���A�P�_�O�_��1�CFloyd Cycle Detection Algorithm
bool isHappy2(int n) {
	int slow = n;
	int fast = n;
	
	do{
		slow = squareAllDigits(slow);                  //���@�� 
		fast = squareAllDigits(squareAllDigits(fast)); // ���⦸ 
	} while (slow != fast); //���@�˴N�~�� 
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
