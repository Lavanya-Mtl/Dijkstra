#include<iostream>
#include"minheap.h"
#include"graphnode.h"
using namespace std;
class Graph
{
private:
    GraphNode *vertices;
    int vertex_count;
public:
    Graph(int a[9][9],int vertex_count)
    {
        vertices = new GraphNode[vertex_count];
        this->vertex_count=vertex_count;
        for(int i=0;i<vertex_count;i++)
            vertices[i].vertex_number=i;
        
        for(int i=0; i<vertex_count; i++)
            for(int j=0; j<vertex_count; j++)
                if(a[i][j]!=0)
                    vertices[i].addNeighbour(&vertices[j],a[i][j]);
    }
    void dijkstra(int start_vertex)
    {
        
        Heap<GraphNode> h = Heap<GraphNode>();
        h.createheap(9);
        vertices[start_vertex].dijkstra_distance=0;
        h.heapify(vertices);
        GraphNode current_node;
        while(h.isEmpty()==false)
        {
            current_node = h.extractmin();
            int new_dijkstra_distance;
            //traverse all neighbours
            Neighbour *neighbour = vertices[current_node.vertex_number].neighbours;
            while (neighbour!=nullptr)
            {
                if(neighbour->n->visited==false)
                {
                    new_dijkstra_distance = current_node.dijkstra_distance + neighbour->distance;
                    if(new_dijkstra_distance<neighbour->n->dijkstra_distance)
                    {
                        neighbour->n->dijkstra_distance = new_dijkstra_distance;//this does not destroy heap property because heap holds copies, not references.
                        //To do: update heap and restore heap property.
                        h.dijkstra_decrease_vertex_distance(neighbour->n->vertex_number,new_dijkstra_distance);
                        //done
                        neighbour->n->prev = &vertices[current_node.vertex_number];
                    }
                }
                neighbour = neighbour->next;
            }
            vertices[current_node.vertex_number].visited=true;
        }
        displayDijkstraResult();
    }
    ~Graph()
    {
        for(int i=0;i<vertex_count;i++)
        {
            vertices[i].destructNeighboursList();
        }
        delete[] vertices;
    }
    void displayDijkstraResult()
    {
        for(int i=0;i<vertex_count;i++)
        {
            cout<<"vertex number: "<<i<<" is at distance "<<vertices[i].dijkstra_distance<<endl;
        }
    }
    void displayPathToVertex(int vertex_number)
    {
        cout<<"Vertex number "<<vertex_number<<endl;
        cout<<"\t^\n\t|\n\t"<<vertices[vertex_number].dijkstra_distance<<"\n\t|\n";
        GraphNode *ptr=vertices[vertex_number].prev;
        while(ptr!=nullptr)
        {
            cout<<"Vertex number "<<ptr->vertex_number<<endl;
            if(ptr->dijkstra_distance>0)
                cout<<"\t^\n\t|\n\t"<<ptr->dijkstra_distance<<"\n\t|\n";
            ptr=ptr->prev;
        }
        
    }
};

int main()
{
    int adjacencyMatrix[9][9]={
        {0,5,2,8,0,0,0,0,0},
        {5,0,0,0,0,0,0,0,0},
        {2,0,0,4,8,3,0,0,0},
        {8,0,4,0,0,0,0,0,0},
        {0,0,8,0,0,9,0,0,0},
        {0,0,3,0,9,0,1,12,10},
        {0,0,0,0,0,1,0,0,7},
        {0,0,0,0,0,12,0,0},
        {0,0,0,0,0,10,7,0,0}
    };
    Graph g=Graph(adjacencyMatrix,9);
    
    g.dijkstra(3);
    
    //g.displayDijkstraResult();
    cout<<endl;
    for(int i=0;i<9;i++)
    {
        cout<<"\n\n";
        g.displayPathToVertex(i);
    }
   Heap<GraphNode> h;
return 0;
}

