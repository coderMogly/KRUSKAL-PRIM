//closed_set class function implementation
// author Anirudh Yadav

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <list>
#include <bits/stdc++.h>
#include "closed_set.h"
#include "vertex.h"
#include "edge.h"
#include "operator.h"



using namespace std;


/////////operator overloading



void closed_set::insert(vertex& a){
	CS.push_front(a);
}

bool closed_set::contains(vertex& a){
	list <vertex>::iterator it;
	for(it = CS.begin();it!=CS.end();++it){
		if(*it == a){
			return true;
		}
	}
	return false;
}
int closed_set::size(){
	return CS.size();
}

vertex closed_set::return_top(){
	return CS.front();
}

