#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <list>
#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <sstream>
#include "tree.h"
#include "edge.h"
#include "vertex.h"
#include "graph.h"
#include "open_set.h"
#include "operator.h"
#include <utility>

using namespace std;


bool vertex_in_list(list <vertex>& v_ls, vertex& v){  //check if vertex is in a list or not
	list <vertex>::iterator it;
	for(it = v_ls.begin();it!= v_ls.end();++it){
		if(*it == v){
			return true;
		}
	}
	return false;
}

bool all_there(list < pair< vertex, bool > >& check_list){ //check if list of vertexes are all in mst 
	list < pair< vertex, bool > >::iterator it;
	for(it = check_list.begin();it!=check_list.end();++it){
		if(it->second == false){
			return false;
		}
	}
	return true;
}

bool is_in_mst(list < pair< vertex, bool > >& check_list, vertex& a){  //check if vertex is already present in mst
	list < pair< vertex, bool > >::iterator it;
	for(it = check_list.begin();it!=check_list.end();++it){
		if(it->first == a){
			if(it->second == true){
				return true;
			}else{
				return false;
			}
		}
	}
	//return false;
}

void add_to_MST(list < pair< vertex, bool > >& check_list, vertex& a){  // adding a vertex to mst or changing the second variable in pair to true
	list < pair< vertex, bool > >::iterator it;
	for(it = check_list.begin();it!=check_list.end();++it){
		//pair < vertex, bool > temp_pair = *it;
		//vertex b = temp_pair.first;
		if(it->first == a){
			it->second = true;
		}
	}
}



void PRIM_MST(graph& G, tree& T){    // implementation of prim for MST
	list < pair< vertex, bool > > vertex_in_tree; // initailizing a list of pairs
	open_set OP;
	int st_n = 0;
	vertex* node_star = G.get_vertex(st_n);     
	for(int i=0; i<G.total_vertex();i++){             // block is preparing a list of vertexes present in MST
		vertex temp_node = vertex(i);
		pair <vertex, bool> temp_pair (temp_node, false);
		vertex_in_tree.push_back(temp_pair);
	}
	vertex node = *node_star;

	add_to_MST(vertex_in_tree, node);
	bool all_in_MST = all_there(vertex_in_tree);              //checking if all the nodes are in MST
	while(!all_in_MST){                  
		list <vertex> nie = G.nieghbours(node);
		list <vertex>::iterator it1;
		for(it1 = nie.begin();it1!=nie.end();++it1){
			//cout<< "entered for loop"<<endl;
			if(!is_in_mst(vertex_in_tree,*it1)){
				//cout<< "entered for loop"<<endl;
				if(!OP.contains(*it1)){
					int cost_root = G.get_vertex_value(node);
					edge* temp = G.get_edge(*it1, node);
					int cost_edge = G.get_edge_value(*temp);
					//cout<<"node is inserted"<<endl;
					int ne_cost = cost_edge+cost_root;
					OP.insert(*it1);
					OP.chgcost(*it1, ne_cost);
					G.set_vertex_value(*it1, ne_cost);
					G.update_parent(*it1, node);
				}else{
					int cost_root = G.get_vertex_value(node);
					edge* temp = G.get_edge(*it1, node);
					int cost_edge = G.get_edge_value(*temp);
					int ne_cost = cost_edge+cost_root;
					int old_cost = G.get_vertex_value(*it1);
					if((cost_root+cost_edge)<old_cost){
						OP.chgcost(*it1, ne_cost);
						G.set_vertex_value(*it1, ne_cost);
						G.update_parent(*it1, node);
					}
				}				
			}
		}
		//cout<<"got out of for loop"<<endl;
		node = OP.min_cost();
		int temp_int = node.ver;
		vertex* node_from_graph = G.get_vertex(temp_int);
		vertex* parent = node_from_graph->parent;
		edge *edge_to_be_added = G.get_edge(node, *parent);
		T.add_edge(*edge_to_be_added);
		add_to_MST(vertex_in_tree, node);
		OP.pop_top();
		all_in_MST = all_there(vertex_in_tree); 
	}
}


void KRUSKAL_MST(graph& G, tree& T){            // implementation of kruskal for MST
	list < pair< vertex, bool > > vertex_in_tree;

	list <edge> sorted = G.sort_edges();
	int st_n = 0;
	vertex* node_star = G.get_vertex(st_n);
	for(int i=0; i<G.total_vertex();i++){
		vertex temp_node = vertex(i);
		pair <vertex, bool> temp_pair (temp_node, false);
		vertex_in_tree.push_back(temp_pair);
	}
	bool all_in_MST = all_there(vertex_in_tree);
	edge temp = sorted.front();
	while(!all_in_MST){
		bool temp_boo = T.is_connected(temp.v1, temp.v2);
		if(!temp_boo){
			T.add_edge(temp);
			add_to_MST(vertex_in_tree, temp.v1);
			add_to_MST(vertex_in_tree, temp.v2);
		}
		all_in_MST = all_there(vertex_in_tree);
		sorted.pop_front();
		temp = sorted.front();
	}
}
