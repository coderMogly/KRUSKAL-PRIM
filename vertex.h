//vertex class defination
// author Anirudh Yadav




#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <list>
#include <bits/stdc++.h>

using namespace std;

class vertex{
	public:
		vertex(int a, int cost=0);
		int ver;
		int cost;
		vertex* parent; 		// parent is used to remember the shortest path
		//vertex* next;
};

#endif