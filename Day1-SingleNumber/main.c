#include <stdio.h>
#include <stdlib.h>
//https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/528/week-1/3283/
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int singleNumber(int *nums, int numsSize);
int singleNumber2(int *nums, int numsSize);
int main(int argc, char *argv[]) {
	
	int a[] = {2, 2, 3, 3, 4, 334, 5, 5, 4};
	int a_element1 = *(a + 1);
	// a[1] = *(a+1) �P�˪��覡�A���P���g�k 
	
	int result = singleNumber2(a, sizeof(a) / sizeof(int));
	printf("%d", result);
	
	return 0;
}

int singleNumber(int *nums, int numsSize) {
	// O(numsSize^2)
	int i, j;
	
	for (i = 0; i < numsSize; i++){
		int counter = 0;
		for (j = 0; j < numsSize; j++){
			if (nums[i] == nums[j]){
				counter++;
			}
		}
		if (counter == 1){
			return nums[i];
		}
	}
	return -1;
}

int singleNumber2(int *nums, int numsSize) {
	// O(numsSize^2)
	int i;
	// n = nums [0] ^ nums[1] // bitwise XOR ������ 
	
	// 1. A^A => 0
	// 2. A^0 => A
	// 3. A^B => B^A
	// �ۤv��ۤvXOR�|����0�A�ҥH�X�{�⦸���|������C��A^B=B^A�A�N��L���洫�v�C�ҥHA^0�N�|�O�ѤU���C
	 
	int n = *(nums);
	for (i = 1; i < numsSize; i++){
		n = n ^ nums[i];
	}
	return n;
}
