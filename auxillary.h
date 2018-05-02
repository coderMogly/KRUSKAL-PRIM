#ifndef AUXILLARY_H
#define AUXILLARY_H

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <list>
#include <bits/stdc++.h>
#include "vertex.h"
#include "edge.h"
#include "graph.h"
#include <utility>



using namespace std;

bool all_there(list < pair< vertex, bool > >&);
bool is_in_mst(list < pair< vertex, bool > >&, vertex&);
void add_to_MST(list < pair< vertex, bool > >&, vertex&);
void PRIM_MST(graph&, tree&);
void KRUSKAL_MST(graph&, tree&);
bool vertex_in_list(list <vertex>&, vertex&);


#endif