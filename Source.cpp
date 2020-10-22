#include <iostream> 
using namespace std;
#define INFINITY 9999 
#define n 5 
#define NILL -1 
int MinDistance(int*, int*);
void PrintPath(int*, int);









void Dijkstra(int Graph[n][n], int _n, int _s, int _d)
{

	int i, u, v, count;
	int dist[n];
	int Blackened[n] = { 0 };
	int pathlength[n] = { 0 };
	int parent[n];

	
	parent[_s] = NILL;


	for (i = 0; i < n; i++)
		dist[i] = INFINITY;

	dist[_s] = 0;
	for (count = 0; count < n - 1; count++) {
		u = MinDistance(dist, Blackened);

		
		if (u == INFINITY)
			break;
		else {

			
			Blackened[u] = 1;
			for (v = 0; v < n; v++) {
				if (!Blackened[v] && Graph[u][v]
					&& dist[u] + Graph[u][v] < dist[v]) {
					parent[v] = u;
					pathlength[v] = pathlength[parent[v]] + 1;
					dist[v] = dist[u] + Graph[u][v];
				}
				else if (!Blackened[v] && Graph[u][v]
					&& dist[u] + Graph[u][v] == dist[v]
					&& pathlength[u] + 1 < pathlength[v]) {
					parent[v] = u;
					pathlength[v] = pathlength[u] + 1;
				}
			}
		}
	}

	
	if (dist[_d] != INFINITY)
		PrintPath(parent, _d);
	else
		cout << "There is no path between vertex "
		<< _s << "to vertex " << _d;
}

int MinDistance(int* dist, int* Blackened)
{
	int min = INFINITY, min_index, v;
	for (v = 0; v < n; v++)
		if (!Blackened[v] && dist[v] < min)
		{
			min = dist[v];
			min_index = v;
		}
	return min == INFINITY ? INFINITY : min_index;
}













void PrintPath(int* parent, int _d)
{
	if (parent[_d] == NILL) {
		cout << _d;
		return;
	}
	PrintPath(parent, parent[_d]);
	cout << "->" << _d;
}












int main()
{
	


	int Graph[n][n] = { { 0,125,104,328,1000 },
						{ 125,0,36,245,989 },
						{ 104,36,0,278,1150},
						{ 328,245,278,0,1500},
						{ 1000,989,1150,1500,0} };
	//Dijkstra(Graph, n, 3, 4);
	
	int sel=99;
	do
	{
		cout << "\n**********Welcome to Programme**********";
		cout << "\n\t*****Cities Codes*****";
		cout << "\n0. Multan, 1. Burewala, 2. Vehari, 3. Lahore, 4. Karachi";
		cout << "\n\n1. To calculate distance";
		cout << "\n0. To Exit Programme";
		cout << "\nSelect: ";
		cin >> sel;
		switch (sel)
		{
		case 1: 
			int st;
			int en;
			cout << "\nEnter starting node: ";
			cin >> st;
			cout << "\nEnter ending node: ";
			cin >> en;
			Dijkstra(Graph, n, st, en);
			cin.ignore();
			cin.ignore();
			system("cls");
			break;
		default:
			cout << "**********Wrong input**********" ;
				cin.ignore();
			cin.ignore();


		}

	} while (sel != 0);
	
	
	/*
	cout << "\n**********Welcome to Programme**********";
	int sel;
	cout << "\n1. To calculate distance";
	cout << "\n2. To Exit Programme";
	*/
	
	system("pause");
	return 0;
}