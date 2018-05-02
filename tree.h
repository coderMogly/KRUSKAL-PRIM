//tree class 
//Author Anirudh Yadav


#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <list>
#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <sstream>
#include "edge.h"
#include "vertex.h"

class tree{
	private:
		list <edge> tree_list;
	public:
		//tree();
		void add_edge(edge&);
		int total_edges();
		void print();
		bool is_connected(vertex&, vertex&);
		list <vertex> nieghbours(vertex& a);
};


#endif