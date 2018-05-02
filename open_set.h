//open_set class defination
// author Anirudh Yadav




#ifndef OPEN_SET_H
#define OPEN_SET_H

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <list>
#include <bits/stdc++.h>
#include "vertex.h"
#include "edge.h"



using namespace std;


class open_set{
	public:
		void chgcost(vertex&, int& );//change cost of a vertex in the list
		vertex min_cost();              // gives vertex with minimum cost
		bool contains(vertex& a);		// check if a particular vertex is in the list
		int size();						// returns the size of the list	
		void insert(vertex& a);			// insert a vertex in the list
		void pop_top();					// delete the vertex with lowest cost
	private:
		list <vertex> PR;
};

#endif