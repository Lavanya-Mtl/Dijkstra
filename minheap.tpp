
#include<iostream>
using namespace std;
template<class T>
Heap<T>::Heap()//create-heap
{
    arr = nullptr;
    size=0;
    max_size=0;
}

template<class T>
void Heap<T>::createheap(int s)
{
    arr=new T[s+5];size=s;max_size=s+5;
}

template<class T>
Heap<T>::~Heap()
{
    delete[] arr;
}
template<class T>
T Heap<T>::peek() const
{
    return arr[0];
}

template<class T>
int Heap<T>::getSize()
{
    return size;
}

template<class T>
bool Heap<T>::isEmpty()
{
    return size==0;
}

template <class T>
T Heap<T>::delete_key(int index)
{
    T key=arr[index];
    arr[index]=arr[--size];
    siftdown(index);
return key;
}

template <class T>
void Heap<T>::heapify(const T *arr)
{
    int i,lower,temp;
    //copy array
    for(i=0;i<size;i++){this->arr[i]=arr[i];}
    for(i=1;i<size;i++)
    {
        if (this->arr[i]<this->arr[(i-1)/2])
        {
            siftup(i);
        }
    }
}

template <class T>
void Heap<T>::siftup(int index)
{
    int i;
    T temp;
    /*temp = arr[index];
    arr[index]=arr[(index-1)/2];
    arr[(index-1)/2]=temp;*/
    for(i=index;i>0;i=(i-1)/2)
    {
        if(arr[i]<arr[(i-1)/2])
        {
            temp=arr[i];
            arr[i]=arr[(i-1)/2];
            arr[(i-1)/2]=temp;
        }
    }
}

template <class T>
void Heap<T>::insert(T element)
{
    if (size==max_size) 
    {
        //overflow:increase size of heap
        T* a = new T[size+5];
        for(int i=0;i<size;i++){a[i]=arr[i];}
        delete[] arr;
        arr = a;
        max_size=size+5;
    }
    arr[size] = element;
    siftup(size);
    size=size+1;
}

template <class T>
T Heap<T>::extractmin()
{
    T min=arr[0];
    arr[0]=arr[--size];
    siftdown(0);
return min;
}

template <class T>
void Heap<T>::decrease_key(int index,T newvalue)
{
    arr[index]=newvalue;
    siftup(index);
}


template<class T>
void Heap<T>::dijkstra_decrease_vertex_distance(int vertex_number, int new_dijkstra_distance)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i].get_vertex_number()==vertex_number)
        {
            arr[i].dijkstra_distance=new_dijkstra_distance;
            siftup(i);
            return;
        }
    }
}

template <class T>
void Heap<T>::siftdown(int index)
{
    int i=index,lower;
    T temp;
    while(i*2+1<=size)
    {
        if(i*2+2==size)
        {
            if(arr[i]>arr[i*2+1]){
                temp=arr[i];
                arr[i]=arr[i*2+1];
                arr[i*2+1]=temp;
            }
            break;
        }
        else
        {
            lower = arr[2*i+1]<arr[2*i+2]?2*i+1:2*i+2;
            if(arr[lower]<arr[i])
            {
                temp=arr[i];
                arr[i]=arr[lower];
                arr[lower]=temp;
                i = lower;
            }
            else
                break;
        }

    }
}

