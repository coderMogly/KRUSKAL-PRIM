//open_set class function implementation
// author Anirudh Yadav

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <list>
#include <bits/stdc++.h>
#include "edge.h"
#include "vertex.h"
#include "open_set.h"
#include "operator.h"


using namespace std;



/////////operator overloading




void open_set::pop_top(){
	PR.pop_front();
}

void open_set::chgcost(vertex& a, int& cost){
	list <vertex>::iterator it;
	for(it = PR.begin();it!=PR.end();++it){
		if(*it==a){
			it->cost = cost;
		}
	}
	PR.sort();
}

vertex open_set::min_cost(){
	list <vertex>::iterator it;
	it = PR.begin();
	return (*it);
}

bool open_set::contains(vertex& a){
	list <vertex>::iterator it;
	for(it = PR.begin();it!=PR.end();++it){
		if(it->ver==a){
			return true;
		}
	}
	return false;
}

void open_set::insert(vertex& a){
	PR.push_back(a);
	PR.sort();
}

int open_set::size(){
	return PR.size();
}