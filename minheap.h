template <typename T> class Heap
{
    T* arr;
    int size;
    int max_size;
    void siftup(int index);
    void siftdown(int index);
    T delete_key(int index);
public:
    Heap();//create-heap
    void createheap(int s);
    ~Heap();
    void heapify(const T* arr);
    void insert(T element);
    T extractmin();
    T peek() const;
    int getSize();
    bool isEmpty();  
    void decrease_key(int index, T newvalue);
    void dijkstra_decrease_vertex_distance(int vertex_number, int new_dijkstra_distance);
};
#include"minheap.tpp"