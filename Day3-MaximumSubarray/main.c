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
	// 匡拒癬翴
	int i, j, k;
	int max = nums[0]; //ヘ玡ゎ程 or INT_MINぃ璶匡0琌场常琌璽 
	for (i = 0; i < numsSize; i++){
		//匡拒沧翴
		for (j = i; j < numsSize; j++){
			int sum = 0;
			//衡sum 
			for (k = i; k <= j; k++){
				sum += nums[k];
			}
			// 狦ゑセ程碞传奔 
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
	// 匡拒癬翴
	int i, j, k;
	int max = nums[0]; //ヘ玡ゎ程 or INT_MINぃ璶匡0琌场常琌璽 
	for (i = 0; i < numsSize; i++){
		//匡拒沧翴
		int sum = 0; //近sum穦单近sum[j]┮for 
		for (j = i; j < numsSize; j++){
			sum += nums[j];
			// 狦ゑセ程碞传奔 
			if (sum > max){
				max = sum;
			} 
			printf("%d, %d:%d\n", i, j, sum);
		} 
	} 
	return max;
}
// DP猭O(n)代刚Ω秆 
int maxSubArray3(int nums[], int numsSize){	
	int i, curSum = 0, maxSub = nums[0];
	// [-2, 1, -3, 4, -1, 2, 1, -5, 4]
	
	for (i = 0; i < numsSize; i++) {
		if (curSum < 0){ //狦琌璽计碞耴0菠玡 ||| 狦场常琌璽璶σ翴琌Τㄤい璽穦ネ程ぃ穦Τ璽癬Θ程┮maxSub蛤curSumゑ眔 
			curSum = 0;
		}
		curSum += nums[i];
		maxSub = maxSub > curSum ? maxSub: curSum; //for temp, 魁ヘ玡程SubArrayぇ 
	}
	return maxSub;
}
