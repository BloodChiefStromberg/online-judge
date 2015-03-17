#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

#include <vector>
#include <map>
#include <iostream>
#include <string>

using namespace std;

vector<int> pset(1000);

void initSet (int _size) 
{
	pset.resize(_size); 
	REP (i, 0, _size) pset[i] = i; 
}
int findSet (int i) 
{ 
	return (pset[i] == i) ? i : (pset[i] = findSet(pset[i]));
}
void unionSet (int i, int j) 
{ 
	pset[findSet(i)] = findSet(j); 
}
bool isSameSet (int i, int j) 
{ 
	return findSet(i) == findSet(j); 
}

void displayPset()
{
	REP (i, 0, pset.size())
		cout << "[" << i << "]: " << pset[i] << endl;
}

int main()
{
	map<string, int> m;

	string name;
	string name2;
	int c;
	int r;
	while (1)
	{
		cin >> c >> r;
		if (c == 0 && r == 0) //maybe use bitwise operations here?
			break;
		initSet(c);
		REP (i, 0, c)
		{
			cin >>  name;
			m[name] = i;
		}
		REP (i, 0, r)
		{
			cin >> name >> name2;
			//cout << "Before:" << endl;
			//displayPset();
			unionSet(m[name2], m[name]);
			//cout << endl << endl << "After:" << endl;	
			//pset[m[name2]] = m[name];
			//displayPset();
		}
		REP (i, 0, c)
		{
			findSet(i);
		}
		//displayPset();
		REP (i, 0, pset.size())
		{
			if (pset[i] >= 0)
			{
				if (pset[pset[i]] < 0)
					pset[pset[i]]--;
				else
					pset[pset[i]] = -1;
			}
			else
				pset[i]--;
		}
		//displayPset();
		int min = pset[0];
		int temp = 0;
		REP (i, 1, pset.size())
		{
			if (pset[i] < min)
				min = pset[i];
		}
		cout << (-1 * min) << endl;
	}
}
