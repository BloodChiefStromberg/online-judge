#include<vector>
#include<math.h>
#include<iostream>

using namespace std;

void getPrimeNumbers(vector<bool>& vNotPrimes)
{
	int n = vNotPrimes.size();	
	for (int i = 2; i < sqrt(n); i++)
	{
		if (!vNotPrimes[i])
		{
			for (int j = i*i; j < n; j += i)
			{
				vNotPrimes[j] = true;
			}
		}
	}
}

void printAnswer(vector<bool>& vNotPrimes, int iTest)
{
	for (int a = 2; a < vNotPrimes.size(); a++)
	{
		if (!vNotPrimes[a]) //if it is a prime
		{
			int b = iTest - a;
			if (!vNotPrimes[b])
			{
				cout << iTest << " = " << a << " + " << b << endl;
				return;
			}
		}
	}
}

int main()
{
	vector<bool> notPrimes;
	notPrimes.resize(1000000);
	getPrimeNumbers(notPrimes);
	int iTest;
	vector<int> vNums;
	cin >> iTest;
	while (iTest != 0)
	{	
		vNums.push_back(iTest);
		cin >> iTest;
	}
	for (int i = 0; i < vNums.size(); i++)
	{
		/*vector<bool> vNotPrimes;
		vNotPrimes.resize(vNums[i]);
		getPrimeNumbers(vNotPrimes);*/
		printAnswer(notPrimes, vNums[i]);
	}
}
