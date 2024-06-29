#include"graphnode.h"
#include<iostream>
using namespace std;

Neighbour::Neighbour(int d, GraphNode* g):distance(d)
{
    next = nullptr;
    n = g;
}
void Neighbour::setNext(Neighbour* n)
{
    next=n;
}
Neighbour* Neighbour::getNext()
{
    return next;
}


GraphNode::GraphNode(int v): vertex_number(v)
{
    dijkstra_distance = 9999;
    prev = nullptr;
    neighbours = nullptr;
    visited = false;
}
GraphNode::GraphNode()
{
    dijkstra_distance = 9999;
    prev = nullptr;
    neighbours = nullptr;
    visited = false;
    vertex_number = -1;
}
void GraphNode::addNeighbour(GraphNode* node, int d)//node is the neighbour of this GraphNode at distance d
{
    Neighbour *n = new Neighbour(d,node);

    n->setNext(neighbours);
    neighbours = n;
}
void GraphNode::destructNeighboursList()
{
    Neighbour *ptr=neighbours,*todelete;
    while(ptr!=nullptr)
    {
        todelete = ptr;
        ptr=ptr->getNext();
        delete todelete;
    }
}
int GraphNode::getNeighbourDistance(int neighbour_vertex_number)
{
    Neighbour *ptr=neighbours;
    while(ptr!=nullptr)
    {
        if (ptr->n->vertex_number==neighbour_vertex_number)
        {
            return ptr->distance;
        }
        ptr = ptr->next;
    }
    return -1;//error: no such neighbour
}
//opertors to heapify a GraphNode array
bool GraphNode::operator < (const GraphNode &gn)
{
    return dijkstra_distance<gn.dijkstra_distance;
}
bool GraphNode::operator > (const GraphNode &gn)
{
    return dijkstra_distance>gn.dijkstra_distance;
}
int GraphNode::get_vertex_number()
{
    return vertex_number;
}
