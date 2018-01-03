//Assignment 7 - CS 210
//Farah Seif El-din 900160195

#include <iostream>
#include <string>
#include <fstream>
#include "set.h"
#include "PQmin.h"
#include <vector>
#include <iomanip>
using namespace std;

void displayGraph(edge ** graph, int size) {

	int cnte = 0;
	cout << endl;
	cout << "Graph" << endl;
	cout << "       ";
	for (int i = 0; i < size; i++)
		cout <<  setw(3) <<(char)(i + 65) << "  ";
	cout << endl;

	cout << "       ";
	cout << "________________________________" << endl;

	for (int i = 0; i < size; i++) {
		cout << (char)(i + 65) << "  | ";
		for (int j = 0; j < size; j++) {
			if (graph[i][j].w != 0 && i!=j) cnte++;
			cout << setw(5) << graph[i][j].w;
		}
		cout << endl;
	}
	
	cout << "Number of vertices: " << size << endl;
	cout << "Number of non-zero edges: " << cnte/2 << endl;
}

//returns a vector with all the nonzero edges in the graph
void getNonZeroEdges(vector <edge> &e, edge ** graph, int size) {

	//checks the top right diagonal of the 2d representation of the graph
	//adds the edge to the vector if its w is not 0
	for (int i = 0; i < size; i++)
		for (int j = i + 1; j < size; j++)
			if (graph[i][j].w != 0)
				e.push_back(graph[i][j]);
}

//read text file and fill a 2d array with the graph in the text file
bool fillGraph(string filename, edge ** & graph, int &size) {

	ifstream inp;
	int n;
	inp.open(filename);
	if (!inp.is_open())
		return false;
	else {
		inp >> n;
		graph = new edge*[n];
		for (int i = 0; i < n; i++)
			graph[i] = new edge[n];
		size = n; //get number of vertices
		for(int i=0;i<size;i++)
			for (int j = 0; j < size; j++) {
				inp >> n;
				graph[i][j].w = n;
				graph[i][j].u = i;
				graph[i][j].v = j;
			}

	}
}

edge* MST(int size, vector<edge> ed) {

	//min heap priority queue
	PQmin p(size*size);
	//insert all nonzero edges in the PQ
	for (int i = 0; i < size; i++)
		p.insert(ed[i]);
		
	Set s(size);
	int i = 0;
	int j, k;
	edge e;
	//MST array with the edges
	edge * MST = new edge[size];

	while (i < size - 1 && !p.isEmpty()) {
		//remove edge with least w
		e = p.remove();

		//get the parent of each vertex in the edge
		j=s.Find(e.u);
		k = s.Find(e.v);
		//if they do not belong to the same set, then we can add them to the MST
		if (j != k) {
			i++;  
			MST[i] = e;
			//join the 2 vertices together in the big set
			s.Union(j, k);
		}
	}
	return MST;
}

void printEdge(edge e) {
	//prints the details of the edge, the 2 vertices and w
	cout << (char)(e.u + 65) << " " << (char)(e.v + 65) << " " << e.w << endl;
}

//display nonzero edges
void printNonZeroEdges(vector <edge> e) {
	cout << "These edges are " << endl;
	for (int i = 0; i < e.size(); i++)
		printEdge(e[i]);
}

void findMST() {

	//get file name from user
	cout << "File name of graph: ";
	string filename;
	cin >> filename;

	edge ** graph;
	vector <edge> nzedges;
	int size;

	//read the file and fill the 2d array with the graph
	if (fillGraph(filename, graph, size)) {
		displayGraph(graph, size);

		//get nonzero edges
		getNonZeroEdges(nzedges, graph, size);
		//display these edges
		printNonZeroEdges(nzedges);
		cout << endl;
		cout << " ---------------" << endl;

		//1d array with the mst edges
		edge * kruskal = MST(size, nzedges);
		cout << "The Minimum Spanning Tree is " << endl;
		//display the mst edges
		for (int i = 1; i < size - 1; i++)
			printEdge(kruskal[i]);
	}
	else
		cout << "Error loading file" << endl;
}

int main() {
	
findMST();

system("pause");
return 0;
}
