#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int maxProfit(int prices[], int pricesSize){
	//[7, 1, 5, 3, 6, 4]
	if (pricesSize <= 1) return 0;
	
	int profit;
	int max = 0;
	
	// 1) 假設決定不賣:
	// [7 1 5 3 6 4] => maxProfit([7 1 5 3 6 4], 6)
	// [7 1 5 3 6] => maxProfit([7 1 5 3 6 4], 5)
	profit = maxProfit(prices, pricesSize - 1);
	
	if (profit > max) {
		max = profit;
	}
	
	// 2) 假設決定最後一天要賣:
	// max(
	//	[7 1 5 3 6] + (6, 4)   	=>  maxProfit([7 1 5 3 6 4], 5) + (prices[5]-prices[4])
	//	[7 1 5 3] + (3, 4))   	=>  maxProfit([7 1 5 3 6 4], 4) + (prices[5]-prices[3])
	//	[7 1 5] + (5, 4))   	=>  maxProfit([7 1 5 3 6 4], 3) + (prices[5]-prices[2])
	//	[7 1] + (1, 4))   		=>  maxProfit([7 1 5 3 6 4], 2) + (prices[5]-prices[1])
	//	[7] + (7, 4))   		=>  maxProfit([7 1 5 3 6 4], 1) + (prices[5]-prices[0])
	// ) 
	int i;
	for (i = 1; i <= pricesSize - 1; i++){
		profit = maxProfit(prices, i) + prices[pricesSize - 1] - prices[i-1];
		if (profit > max){
			max = profit;
		} 
	}
	return max;
}
// 會重複運算，所以先存起來 
int maxProfit2(int prices[], int pricesSize){
	if (pricesSize <= 1) return 0;
	int profits[pricesSize+1]; // profits[i] = maxProfit(prices, i)
	
	
	profits[1] = 0; //一天不用算
	
	
	int k;
	
	// k = 天 
	for (int k = 2; k <= pricesSize; k++){
		//一天要不要賣？ 
		int profit;
		int max = 0;
		profit = profits[k-1];
		// 不賣 
		if (profit > max) {
			max = profit;
		}
		// k天時，最後一天要賣 
		int i;
		for (i = 1; i <= k - 1; i++){
			profit = profits[i] + prices[k - 1] - prices[i-1];
			if (profit > max){
				max = profit;
			} 
		}
		profits[k] = max;
	}
	return profits[pricesSize];
}
int maxProfit3(int *prices, int pricesSize){
	// Greedy Algorithm
	//{7, 1, 5, 3, 6, 4}
	// 
	// 4 
	
	//{1, 2, 3, 4, 5}
	//
	//
	int i, j, sum = 0;
	
	for (i = 0; i < pricesSize-1; i++){
		if ( prices[i] < prices[i+1] ){
			sum += prices[i+1] - prices[i];
		}
	}
	return sum;
}

int main(int argc, char** argv) {
	int data[] = {1, 2, 3, 4, 5};
	printf("%d",
		maxProfit3(data, 6)
	);
	
	return 0;
}


