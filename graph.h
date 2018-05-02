//graph class defination 
// author Anirudh Yadav


#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <list>
#include <bits/stdc++.h>
#include "edge.h"
#include "vertex.h"
#include <fstream>


using namespace std;

class graph{
	public:
		graph(ifstream&);
		int total_vertex();                // gives total number of vertex in the graph
		int total_edge();					//gives total number of edges in the graph
		bool is_adjacent(vertex& a, vertex& b);   //tells whether two vertices are adjacent 
		list <vertex> nieghbours(vertex&);			// gives the list of adjacent vertices
		void add_vertex(vertex& a);					// adds a vertex to the graph
		void add_edge(edge& a);						// adds a edge to the graoh
		void set_edge_value(edge& e, int& cost);	//  sets the cost of edge
		void set_vertex_value(vertex& a, int& cost); //sets the cost of vertex
		void print_graph();								//print the graph	
		vertex* get_vertex(int& a);						// gives pointer to the vertex in graph which is represented by int value a
		edge* get_edge(vertex&, vertex&);				// gives pointer to the edge in graph which connects vertex v1 and v2 
		void update_parent(vertex& a,vertex& b);		//updates the parent vertex of the given vertex
		int get_vertex_value(vertex&);					// gives the value of the vertex
		int get_edge_value(edge&);						// gives the value of the edge
		list <edge> sort_edges();
	private:
		list <vertex> V_list;
		list <edge> E_list;
};

#endif