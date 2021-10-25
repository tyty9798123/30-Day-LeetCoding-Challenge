#include <stdio.h>
#include <stdlib.h>

void moveZeroes(int* nums, int numsSize){
	int i, next = 0;
	for (i = 0; i < numsSize; i++){
		if (nums[i] != 0){
            nums[next++] = nums[i];
		}
	}
	for (i = next; i < numsSize; i++){
		nums[i] = 0;
	}
}


int main(int argc, char *argv[]) {
	int arr[3] = {0, 0, 1};
	moveZeroes(arr, 3);
	int i;

	for (i = 0; i < 3; i++){
		printf("%d ", arr[i]);
	}
	return 0;
}
