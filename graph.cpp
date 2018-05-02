//graph class fuction implementation 
// author Anirudh Yadav




#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <list>
#include <bits/stdc++.h>
#include "graph.h"
#include "edge.h"
#include "vertex.h"
#include "operator.h"
#include <fstream>

using namespace std;



///////////////////////////functions for graph class
graph::graph(ifstream& in){
	string line;
	getline(in, line);
	istringstream iss(line);
	int size;
	iss >> size;
	for(int i =0;i<size;i++){
		vertex temp = vertex(i);
		add_vertex(temp);
	}
	while (getline(in, line)){
    	istringstream iss(line);
    	int a =0, b=0, c=0;
    	//cout<<a<<"  "<<b<<"   "<<c<<endl;
    	//cout<<(iss >> a >> b >>c)<<endl;
    	if (!(iss >> a >> b >> c)) { break; }
    	//cout<<a<<"  "<<b<<"   "<<c<<endl;
    	vertex* v1 = get_vertex(a);
    	vertex* v2 = get_vertex(b);
    	edge e = edge(*v1, *v2);
    	add_edge(e);
    	//edge* temp = get_edge(*v1,*v2);
    	set_edge_value(e, c);
	}
}

list <edge> graph::sort_edges(){
	list <edge> sorted;
	list <edge>::iterator it;
	for(it = E_list.begin();it!=E_list.end();++it){
		sorted.push_back(*it);
	}
	sorted.sort();
	return sorted;
}

edge* graph::get_edge(vertex& v1, vertex& v2){
	list <edge>::iterator it;
	for(it = E_list.begin();it!= E_list.end();++it){
		if((it->v1==v1 && it->v2==v2)||(it->v1==v2&&it->v2==v1)){
			return &(*it);
		}
	}
}
void graph::update_parent(vertex& node, vertex& parent){
	vertex* temp = get_vertex(parent.ver);
	list <vertex>::iterator it;
	for(it = V_list.begin(); it!=V_list.end();++it){
		if(*it == node){
			it->parent = temp;
		}
	}
}

int graph::total_vertex(){
	return V_list.size();
}

int graph::total_edge(){
	return E_list.size();
}

bool graph::is_adjacent(vertex& v1, vertex& v2){
	list <edge>::iterator it;
	for(it = E_list.begin();it!=E_list.end();++it){
		if((it->v1==v1 && it->v2==v2)||(it->v1==v2 && it->v2==v1)){
			return true;
		}
	}
	return false; 
}

list <vertex> graph::nieghbours(vertex& a){
	list <vertex> N_vertex_list;
	list <vertex>::iterator it;
	for(it = V_list.begin();it!=V_list.end();++it){
		bool temp = graph::is_adjacent(*it, a);
		if(temp){
			N_vertex_list.push_back(*it);
		}
	}
	return N_vertex_list;
}



void graph::add_vertex(vertex& a){
	V_list.push_back(a);
}


void graph::add_edge(edge& a){
	list <edge>::iterator it;
	int flag =0;
	for(it = E_list.begin();it!=E_list.end();++it){
		if ((it->v1 == a.v1 && it->v2 == a.v2)||(it->v1 == a.v2 && it->v2 == a.v1)){
			flag = 1;
		}
	}
	if(flag == 1){
		//cout<<"the edge ("<<a.v1.ver<<","<<a.v2.ver<<") already exists"<<endl;
	}else{
		E_list.push_back(a);
	}
}

void graph::set_vertex_value(vertex& a, int& cost){
	list <vertex>::iterator it;
	for(it = V_list.begin(); it != V_list.end(); ++it){
		if(*it == a){
			it->cost = cost;
		}
	}
}

void graph::set_edge_value(edge& e, int& cost){
	list <edge>::iterator it;
	for(it = E_list.begin();it!= E_list.end();++it){
		if(*it==e){
			it->cost = cost;
			return;
		}
	}
	cout<< "this vertex does not exist"<< endl; 
}

void graph::print_graph(){
	list <vertex> :: iterator it;
	for(it=V_list.begin();it!=V_list.end();++it){
		cout<<"vertex   "<<it->ver<<endl;
	}
	list <edge>::iterator id;
	for(id=E_list.begin();id!=E_list.end();++id){
		cout<<"edge   ("<<id->v1.ver<<","<<id->v2.ver<<")  cost "<<id->cost<<endl;
	}
}
vertex* graph::get_vertex(int& a){
	list <vertex>::iterator it;
	for(it = V_list.begin();it!= V_list.end();++it){
		if(it->ver == a){
			return &*it;
		}
	}
}
int graph::get_vertex_value(vertex& a){
	list <vertex>::iterator it;
	for(it = V_list.begin();it!=V_list.end();++it){
		if(*it==a){
			return it->cost;
		} 
	}
	cout<<"Vertex not present in the graph"<<endl;
}
int graph::get_edge_value(edge& e){
	list <edge>::iterator it;
	for(it = E_list.begin();it!=E_list.end();++it){
		if(*it==e){
			return it->cost;
		} 
	}
	cout<<"Vertex not present in the graph"<<endl;	
}

