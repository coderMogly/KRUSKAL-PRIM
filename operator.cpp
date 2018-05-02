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






bool operator==(vertex a, vertex b){
	if(a.ver==b.ver){
		return true;
	}else{
		return false;
	}
}
bool operator<(vertex a, vertex b){
	if(a.cost<b.cost){
		return true;
	}else{
		return false;
	}
}
bool operator>(vertex a, vertex b){
	if(a.cost>b.cost){
		return true;
	}else{
		return false;
	}
}
bool operator<=(vertex a, vertex b){
	if(a.cost<=b.cost){
		return true;
	}else{
		return false;
	}
}
bool operator>=(vertex a, vertex b){
	if(a.cost>=b.cost){
		return true;
	}else{
		return false;
	}
}
bool operator!=(vertex a, vertex b){
	if(a.ver==b.ver){
		return false;
	}else{
		return true;
	}
}


bool operator==(edge a, edge b){
	if((a.v1==b.v1 && a.v2==b.v2)||(a.v2==b.v1 && a.v1==b.v2)){
		return true;
	}else{
		return false;
	}
}
bool operator<(edge a, edge b){
	if(a.cost<b.cost){
		return true;
	}else{
		return false;
	}
}
bool operator>(edge a, edge b){
	if(a.cost>b.cost){
		return true;
	}else{
		return false;
	}
}
bool operator<=(edge a, edge b){
	if(a.cost<=b.cost){
		return true;
	}else{
		return false;
	}
}
bool operator>=(edge a, edge b){
	if(a.cost>=b.cost){
		return true;
	}else{
		return false;
	}
}