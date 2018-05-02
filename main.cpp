//this file includes the main function as well as the function implementing graph creation and Dijstra shortest path 
// it also has a few other functions that are needed in the main function.
// author ANIRUDH YADAV



#include <iostream>
#include <utility>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <list>
#include <bits/stdc++.h>
#include <fstream>
#include "graph.h"
#include "edge.h"
#include "vertex.h"
#include "open_set.h"
#include "closed_set.h"
#include "operator.h"
#include "tree.h"
#include "auxillary.h"
using namespace std;







////////////////////////helper functions



float prob(){
    //srand(time(0));
    return static_cast<float> (rand()/static_cast<float>(RAND_MAX));   
};

int random_cost_generator(){
	int cost = rand() % 10 + 1;        // generates a random number between 1 to 10 
	return cost;
};



void graph_creation(graph& G, int& size, float& density){
	//graph G;
	for(int i = 1; i<=size; i++){
		vertex v = vertex(i);
		G.add_vertex(v);	
	}
	for(int i = 1; i<=size; i++){
		for (int j = i; j<=size; j++){
			if(i==j){
			}else{
				if(prob()>density){
					int cost = random_cost_generator();					
					vertex* vi=G.get_vertex(i);
					vertex* vj=G.get_vertex(j);
					edge e= edge(*vi,*vj);					
					G.add_edge(e);
					G.set_edge_value(e,cost);
				}			
			}
		}
	}
};


bool Dijstra(graph& G, vertex& st_node, vertex& end_node){
	open_set OP;
	closed_set CL;
	OP.insert(st_node);
	int start_cost = 0;
	OP.chgcost(st_node, start_cost);
	G.set_vertex_value(st_node, start_cost);
	while(OP.min_cost()!=end_node && OP.size()!=0){
		vertex  root_node= OP.min_cost();
		list <vertex> niegh = G.nieghbours(root_node);
		list <vertex>::iterator it;
		for(it = niegh.begin(); it!= niegh.end();++it){
			bool in_open = OP.contains(*it);
			bool in_close = CL.contains(*it);
			if(!in_close){
				if(!in_open){
					//vertex  root_node= OP.min_cost();
					int cost_root = G.get_vertex_value(root_node);
					edge* temp = G.get_edge(*it, root_node);
					int cost_edge = G.get_edge_value(*temp);
					int ne_cost = cost_edge+cost_root;
					OP.insert(*it);
					OP.chgcost(*it, ne_cost);
					G.set_vertex_value(*it, ne_cost);
					G.update_parent(*it, root_node);
				}else{
					//vertex root_node= OP.min_cost();
					int cost_root = G.get_vertex_value(root_node);
					edge* temp = G.get_edge(*it, root_node);
					int cost_edge = G.get_edge_value(*temp);
					int ne_cost = cost_edge+cost_root;
					int old_cost = G.get_vertex_value(*it);
					if((cost_root+cost_edge)<old_cost){
						OP.chgcost(*it, ne_cost);
						G.set_vertex_value(*it, ne_cost);
						G.update_parent(*it, root_node);
					}
				}
			}
		}
		CL.insert(root_node);
		OP.pop_top();
	}
	if(OP.size()==0 && CL.return_top()!=end_node){
		return false;
	}else{
		return true;
	}
};

void print_shortest_path(graph G, vertex& st_node, vertex& end_node){
	vertex* end = G.get_vertex(end_node.ver);
	vertex* start = G.get_vertex(st_node.ver);
	vertex* temp = end;
	cout<<"shortest path is"<<endl;
	while(temp->ver!=start->ver){
		cout<<temp->ver<<endl;
		temp = temp->parent;
	}
	cout<<temp->ver<<endl; 
};



int main(){
	srand(time(0));
	ifstream in("test_data.txt");
	graph G = graph(in);
	//G.print_graph();
	tree T;
	KRUSKAL_MST(G,T);
	T.print();
}