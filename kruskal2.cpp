#include<vector>
#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

vector<int> pset(1000);

void initSet (int _size) //set every one to their own parent (disjoint set of trees!)
{
	pset.resize(_size); 
	for (int i= 0; i < _size; i++) 
		pset[i] = i; 
}
int findSet (int i) //find the parent of i
{ 
	return (pset[i] == i) ? i : (pset[i] = findSet(pset[i]));
}
void unionSet (int i, int j) //set parent of i to parent of j (make j the main root)
{ 
	pset[findSet(i)] = findSet(j); 
}
bool isSameSet (int i, int j) 
{ 
	return findSet(i) == findSet(j); 
}


void displayVec(const vector<int>& vec)
{
	for (int i = 0; i < vec.size(); i++)
		cout << "[" << i << "]: " << vec[i] << endl;
}


int main()
{
	int numOfIntersections, numOfRoads;
	cin >> numOfIntersections >> numOfRoads;
	while (numOfIntersections != 0 && numOfRoads != 0)
	{
		if (numOfRoads == 0)
		{
			cout << 0 << endl; //no roads, no savings!
			return 0;
		}
		initSet(numOfIntersections);

		vector< vector<int> > edges;
		/*int longest = 0;
		int longestIndex = 0;
		bool needSecondLongest = numOfRoads > 1;
		int secondLongest = 0; 
		int secondLongestIndex = 0; */

		for (int i = 0; i < numOfRoads; i++)
		{
			int start, end, weight;
			cin >> start >> end >> weight;
			/*if (weight > secondLongest)
			{
				if (weight > longest)
				{
					longest = weight;
					longestIndex = i;
				}
				else
				{
					secondLongest = weight;
					secondLongestIndex = i;
				}
			}*/
			vector<int> edge;
			edge.push_back(start);
			edge.push_back(end);
			edge.push_back(weight);
			edges.push_back(edge);
			
		}	
		/*edges[longestIndex][2] = 0 - edges[longestIndex][2];
		if (needSecondLongest)
			edges[secondLongestIndex][2] = 0 - edges[secondLongestIndex][2];*/
		
		std::sort(edges.begin(), edges.end(), //thanks stackoverflow and c++ 11!
			[](const vector<int>& first, const vector<int>& second){
				return first[2] < second[2];
			});
		
		vector<int> acceptedWeights;
		for (int i = 0; i < edges.size(); i++)
		{
			if (!isSameSet(edges[i][0], edges[i][1]))
			{
				acceptedWeights.push_back(edges[i][2]);
				unionSet(edges[i][0], edges[i][1]);
			}
			if (acceptedWeights.size() == pset.size() - 1) //short-circuit
				break;
		}

		int ourCost = 0;
		for (int i = 0; i < acceptedWeights.size(); i++)
		{	
			int weight = acceptedWeights[i];
			ourCost += weight;
		}
		int theirCost = 0;
		for (int i = 0; i < edges.size(); i++)
		{
			theirCost += edges[i][2];
		}
		cout << theirCost - ourCost << endl;
		/*cout << acceptedWeights.size() << endl;
		cout << edges.size() << endl;
		cout << ourCost << endl;
		cout << theirCost << endl;*/

		cin >> numOfIntersections >> numOfRoads;
	}
	return 0;
}

/*
TODO: possible improvements in efficiency.
1. None my code is perfect.
*/
