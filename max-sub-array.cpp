#include <vector>
#include <iostream>

using namespace std;

int maxSubArray(const vector<int>& bets)
{
	int maxHere = 0;
	int maxSoFar = 0;
	for (int i = 0; i < bets.size(); i++)
	{
		int current = bets[i];
		maxHere = 0 < maxHere + bets[i] ? maxHere + bets[i] : 0;
		maxSoFar = maxSoFar < maxHere ? maxHere : maxSoFar;
	}
	return maxSoFar;
}

int main() 
{
	int n;
	cin >> n;
	while (n != 0)
	{
		vector<int> bets;
		for (int i = 0; i < n; i++)
		{
			int bet;
			cin >> bet;
			bets.push_back(bet);
		}
		int max = maxSubArray(bets);
		if (max > 0)
			cout << "The maximum winning streak is " << max << "." << endl;
		else
			cout << "Losing streak." << endl;
		cin >> n;
	}				
	return 0;
}
