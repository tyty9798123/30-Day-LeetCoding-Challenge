#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int maxSubArray(int nums[], int numsSize); 
int maxSubArray2(int nums[], int numsSize); 
int maxSubArray3(int nums[], int numsSize); 

int main(int argc, char** argv) {
	int array[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	
	maxSubArray3(array, sizeof(array)/sizeof(int));
	printf("%d", maxSubArray3(array, sizeof(array)/sizeof(int)));
	return 0;
}

// O(n^3)
int maxSubArray(int nums[], int numsSize){	
	// ��ܰ_�I
	int i, j, k;
	int max = nums[0]; //�ثe����̤j�� or INT_MIN�A���n��0�A�H�K�O�������O�t�� 
	for (i = 0; i < numsSize; i++){
		//��ܲ��I
		for (j = i; j < numsSize; j++){
			int sum = 0;
			//��Xsum 
			for (k = i; k <= j; k++){
				sum += nums[k];
			}
			// �p�G��쥻���̤j�Ȥj�A�N���� 
			if (sum > max){
				max = sum;
			} 
			printf("%d, %d:%d\n", i, j, sum);
		} 
	} 
	return max;
}
// O(n^2)
int maxSubArray2(int nums[], int numsSize){	
	// ��ܰ_�I
	int i, j, k;
	int max = nums[0]; //�ثe����̤j�� or INT_MIN�A���n��0�A�H�K�O�������O�t�� 
	for (i = 0; i < numsSize; i++){
		//��ܲ��I
		int sum = 0; //�U�@����sum�|����W�@�����W�[sum[j]�A�ҥH�i�H�٥h�@��for 
		for (j = i; j < numsSize; j++){
			sum += nums[j];
			// �p�G��쥻���̤j�Ȥj�A�N���� 
			if (sum > max){
				max = sum;
			} 
			printf("%d, %d:%d\n", i, j, sum);
		} 
	} 
	return max;
}
// DP�k�AO(n)�A���դ@���Y�F�� 
int maxSubArray3(int nums[], int numsSize){	
	int i, curSum = 0, maxSub = nums[0];
	// [-2, 1, -3, 4, -1, 2, 1, -5, 4]
	
	for (i = 0; i < numsSize; i++) {
		if (curSum < 0){ //�p�G�O�t�ơA�N�k0�A�ٲ��e���� ||| �p�G�������O�t�ȡA�n��Ҫ��I�O�A�u���䤤�@�ӭt�Ȥ~�|�ͥX�̤j�ȡA���|���ܦh�t�ȥ[�A�@�_�����̤j�ȡA�ҥH�i�H��maxSub��curSum��A�Y�i�o���C 
			curSum = 0;
		}
		curSum += nums[i];
		maxSub = maxSub > curSum ? maxSub: curSum; //for temp, �����ثe�̤j��SubArray���� 
	}
	return maxSub;
}
