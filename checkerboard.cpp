#include <cmath>
#include <vector>
#include <iostream>

/*
edges need to have 4 values:
First end point
Second end point
Distance to this edge from the source (d). This is initialized to an over estimation.
Distance from this edge to the target (h). This is initialized to an under estimation.
*/

using namespace std;
//Given initial board state, determine distance to correct state
vector<int> finalState;
//finalState.resize(9);
void init()
{
	for (int i = 0; i < 9; i++)
	{
		finalState.push_back(i);
	}
}

void dumpState(vector<int> state)
{
	for (int i = 0; i < 3; i++)
	{
		cout << state[i * 3] << ' ' << state[(i * 3) + 1] << ' ' << state[(i * 3) + 2] << endl;
	}
}

vector< vector<int> > getReachable(vector<int> initialState)
{
	//vector<int> currentState = initialState; //safe?
	vector< vector<int> > reachables;
	for (int i = 0; i < 9; i++)
	{
		if (initialState[i] == 9)
		{
			vector<int> edge;	
			int colOfEmpty = i % 3;
			int rowOfEmpty = i / 3;
			//if we're not in the far right column, swap the empty index with the index to it's right. This is one reachable state.
			if (colOfEmpty != 2)
			{
				vector<int> currentState = initialState;
				currentState[i] = currentState[i + 1];
				currentState[i + 1] = 9;
				reachables.push_back(currentState);
			}
			if (colOfEmpty != 1)
			{
				vector<int> currentState = initialState;
				currentState[i] = currentState[i - 1];
				currentState[i - 1] = 9;
				reachables.push_back(currentState);
			}
			if (rowOfEmpty != 2)
			{
				vector<int> currentState = initialState;
				currentState[i] = currentState[i - 3];
				currentState[i - 3] = 9;
				reachables.push_back(currentState);
			}
			if (rowOfEmpty != 1)
			{
				vector<int> currentState = initialState;
				currentState[i] = currentState[i + 3];
				currentState[i + 3] = 9;
				reachables.push_back(currentState);
			}				
		}
	}
	return reachables;
}

int getWeight(vector<int> state)
{
	int total;
	for (int i = 0; i < 9; i++)
	{
		int currentVal = state[i];
		int col = i % 3;
		int row = i / 3;
		int targetCol = currentVal % 3;
		int targetRow = currentVal / 3;
		total += abs(col - targetCol) + abs(row - targetRow);
	}
	return total;
}

int main()
{	
	vector< int[9] > edges; //enpoint, endpoint, distance, h
	int currentStateId = 0;
	vector< vector<int> > reachables;
	vector<int> initialState;
	for (int i = 0; i < 9; i++)
	{
		int num;
		cin >> num;
		initialState.push_back(num);
	}
	bool finished = false;
	vector<int> currentState = initialState;
	while (!finished)
	{
		currentState.push_back(currentStateId);
		vector< vector<int> > newReachables = getReachable(currentState);
		//Now we need to make edges for all these states
		for (int i = 0; i < newReachables.size(); i++)
		{
			int edge[9];
		}
	} 

	return 0;
}
