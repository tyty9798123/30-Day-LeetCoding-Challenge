#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int singleNumber(int *nums, int numsSize);
int singleNumber2(int *nums, int numsSize);
int main(int argc, char *argv[]) {
	
	int a[] = {2, 2, 3, 3, 4, 334, 5, 5, 4};
	int a_element1 = *(a + 1);
	// a[1] = *(a+1) 同樣的方式，不同的寫法 
	
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
	// n = nums [0] ^ nums[1] // bitwise XOR 互斥或 
	
	// 1. A^A => 0
	// 2. A^0 => A
	// 3. A^B => B^A
	// 自己跟自己XOR會等於0，所以出現兩次的會抵消掉。而A^B=B^A，代表他有交換率。所以A^0就會是剩下的。
	 
	int n = *(nums);
	for (i = 1; i < numsSize; i++){
		n = n ^ nums[i];
	}
	return n;
}
