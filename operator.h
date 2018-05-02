//open_set class defination
// author Anirudh Yadav




#ifndef OPERATOR_H
#define OPERATOR_H

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <list>
#include <bits/stdc++.h>
#include "vertex.h"
#include "edge.h"



using namespace std;

bool operator==(vertex, vertex);
bool operator<(vertex, vertex);
bool operator>(vertex, vertex);
bool operator<=(vertex, vertex);
bool operator>=(vertex, vertex);
bool operator!=(vertex, vertex);
bool operator==(edge, edge);
bool operator<(edge, edge);
bool operator>(edge, edge);
bool operator<=(edge, edge);
bool operator>=(edge, edge);
bool operator!=(edge, edge);


#endif