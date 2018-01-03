//Assignment 7 - CS 210
//Farah Seif El-din 900160195

#pragma once
#ifndef SET_H
#define SET_H
#include <iostream>
using namespace std;

class Set
{
private:
	int *p, *c, n;

public:
	//constructor
	Set(int size);

	~Set(); // destructor 

	//join two sets together
	void Union(int i, int j);

	// find the parent set of subset i
	int Find(int i);




};
#include "set.cpp"
#endif