
//Assignment 7 - CS 210
//Farah Seif El-din 900160195

#include <iostream>
using namespace std;

//constructor
PQmin::PQmin(int size)
{
	a = new edge[size + 1]; 	
	n = 0;
	maxs = size; 
	min = -32767; 
	a[0].w = min;
}
//destructor
PQmin::~PQmin()
{
	delete[] a;
}


//uphead
void PQmin::upheap(int k)
{
	edge e = a[k];
	while (e.w <= a[k / 2].w)
	{
		a[k] = a[k / 2];   k = k / 2;
	}
	a[k] = e;
}

// downheap 
void PQmin::downheap(int k)
{
	int j = 2 * k;    
	edge e = a[k];
	while (j <= n) {
		if ((j < n) && (a[j + 1].w < a[j].w)) 
			j++;
		if (e.w <= a[j].w) 
			break;

		a[j / 2] = a[j];     
		j *= 2;
	}

	a[j / 2] = e;
}

//insert element into heap
void PQmin::insert(edge e)
{
	a[++n] = e;    
	upheap(n);
}

//remove lowest element from heap
edge PQmin::remove()
{
	edge e = a[1];
	a[1] = a[n--];
	downheap(1);

	return e;
}

//returns true if heap is empty, else
//return false
bool PQmin::isEmpty() {
	return n == 0;
}