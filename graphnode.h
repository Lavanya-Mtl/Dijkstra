class GraphNode;
class Graph;
class Neighbour
{
private:
    GraphNode *n;//the identity of this neighbour
    const int distance;//distance from node to this neighbour
    Neighbour *next;//the one that makes it an adjacency list
public:
    friend class GraphNode;
    friend class Graph;
    Neighbour(int d, GraphNode* g);
    void setNext(Neighbour* n);
    Neighbour* getNext();
};
class GraphNode
{
private:
    int vertex_number; 
    GraphNode* prev;//just the previous node from which we got the dijkstra distance
    Neighbour* neighbours;//an adjacency list
    bool visited;
public:
    friend class Graph;
    int dijkstra_distance;
    GraphNode(int v);
    GraphNode();
    void addNeighbour(GraphNode* node, int d);//node is the neighbour of this GraphNode at distance d
    void destructNeighboursList();
    int getNeighbourDistance(int neighbour_vertex_number);
    
    //opertors to heapify a GraphNode array
    bool operator < (const GraphNode &gn);
    bool operator > (const GraphNode &gn);
    
    int get_vertex_number();
   
};
