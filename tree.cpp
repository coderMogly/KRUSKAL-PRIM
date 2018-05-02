//tree class 
//Author Anirudh Yadav



#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <list>
#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <sstream>
#include "vertex.h"
#include "edge.h"
#include "tree.h"
#include "auxillary.h"
#include "operator.h"

//void tree::tree():tree_list(0){}
void tree::add_edge(edge& e){
	tree_list.push_back(e);
}

int tree::total_edges(){
	return tree_list.size();
}
void tree::print(){
	list <edge>::iterator it;
	cout<<"the mst is "<<endl;
	for(it = tree_list.begin();it!= tree_list.end();++it){
		cout<<"edge ("<<it->v1.ver<<","<<it->v2.ver<<")"<<endl;
	}
}

bool tree::is_connected(vertex& a, vertex& b){
	list <edge>::iterator it;
	list <vertex> reachable;
	list <vertex> next_reachable;
	for(it = tree_list.begin();it!=tree_list.end();++it){
		if(it->v1 == a){
			next_reachable.push_back(it->v2);
		}
		if(it->v2 == a){
			next_reachable.push_back(it->v1);
		}
	}
	//list <vertex> next_reachable;
	while(!next_reachable.empty()){
		reachable.insert(reachable.end(), next_reachable.begin(), next_reachable.end());
		list <vertex> temp;
		list <vertex>::iterator it;
		for(it = next_reachable.begin();it!= next_reachable.end();++it){
			list <vertex> nie = nieghbours(*it);
			list <vertex>::iterator it1;
			for(it1 = nie.begin();it1 != nie.end();++it1){
				bool temp_boo = vertex_in_list(reachable, *it1);
				if(!temp_boo){
					temp.push_back(*it1);
				}
			}
		}
		next_reachable = temp;
	}
	bool final_call = vertex_in_list(reachable, b);
	return final_call;
}

list <vertex> tree::nieghbours(vertex& a){
	list <edge>::iterator it;
	//list <vertex> reachable;
	list <vertex> next_reachable;
	for(it = tree_list.begin();it!=tree_list.end();++it){
		if(it->v1 == a){
			next_reachable.push_back(it->v2);
		}
		if(it->v2 == a){
			next_reachable.push_back(it->v1);
		}
	}
	return next_reachable;
}