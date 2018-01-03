#pragma once
//Assignment 7
//Farah Seif El-din 900160195

#ifndef PQmin_H
#define PQmin_H
using namespace std;

//edge object, u is 1st vertex, v is 2nd vertex, w is the distance between them
struct edge {
	int u;
	int v;
	int w;
};

class PQmin
{

private:

	edge *a;
	int maxs;
	int n;
	int min;

	void upheap(int k);
	void downheap(int k);

public:

	//constructor
	PQmin(int size);
	//destructor
	~PQmin();
	void insert(edge e);		
	edge remove();		
	bool isEmpty();

};
#endif 
#include "PQmin.cpp"

