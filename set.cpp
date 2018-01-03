//Assignment 7 - CS 210
//Farah Seif El-din 900160195

#include <iostream>
using namespace std;

Set ::Set(int size) // constructor 
{
	n = size;
	p = new int[n + 1]; c = new int[n + 1];
	for (int i = 0; i <= n; i++) { p[i] = -1; c[i] = 1; }
}

Set::~Set()// destructor 
{
	delete[] p; delete[] c;
}

//join two sets together
void Set::Union(int i, int j)
{
	int sum = c[i] + c[j];
	if (c[i] > c[j]) { p[j] = i; c[i] = sum; }
	else { p[i] = j; c[j] = sum; }
}

// find the parent set of subset i
int Set::Find(int i)
{
	while (p[i] >= 0) i = p[i];
	return i;
}

