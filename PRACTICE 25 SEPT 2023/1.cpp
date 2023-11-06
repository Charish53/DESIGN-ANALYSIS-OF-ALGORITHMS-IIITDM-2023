/*QUESTIONN 1 : Implement COIN CHANGE - Brute Force, Greedy (if applicable), DP ; (i) R1,R3,R5 (ii) R1,R3,R4 (iii) Ra, Rb, Rc (iv) R1,R2,...,Rk
brute force */
  #include <bits/stdc++.h>
using namespace std;
int count(int coins[], int n, int sum)
{
	if (sum == 0)
		return 1;
	if (sum < 0)
		return 0;
	if (n <= 0)
		return 0;
	return count(coins, n, sum - coins[n - 1])
		+ count(coins, n - 1, sum);
}
int main()
{
	int i, j;
	int coins[] = { 1, 2, 3 };
	int n = sizeof(coins) / sizeof(coins[0]);
	int sum = 5;
	cout << " " << count(coins, n, sum);
	return 0;
}



