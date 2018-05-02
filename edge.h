//edge class defination
// author Anirudh Yadav




#ifndef EDGE_H
#define EDGE_H

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <list>
#include <bits/stdc++.h>
#include "vertex.h"


using namespace std;

class edge{
	public:
		edge(vertex a, vertex b);
		vertex v1, v2;
		int cost;
		//edge* next;
};

#endif