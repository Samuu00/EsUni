#include <iostream>
using namespace std;

//es2
class PriorityQueue {
    private:
        int* heap;     
        int capacita;  
        int size;      

        void heapifyUp(int index){
            int parent = (index - 1) / 2;

            while(index > 0 && heap[index] < heap[parent]){
                swap(heap[index], heap[parent]);

                index = parentIndex;
                parentIndex = (index - 1) / 2;
            }
        }

        void heapifyDown(int index) {
            int leftChild = 2 * index + 1;
            
            while (leftChild < size) {

                int smallerChild = leftChild;
                int rightChild = 2 * index + 2;

                if (rightChild < size && heap[rightChild] < heap[leftChild]) {
                    smallerChild = rightChild;
                }

                if (heap[index] <= heap[smallerChild]) {
                    break; 
                }

                swap(heap[index], heap[smallerChild]);
                
                index = smallerChild;
                leftChild = 2 * index + 1;
            }
        }
        
        void resize(){
            if(size == capacita){
                int newSize = this->capacita * 2;
                this->capacita = newSize;
                int newHeap* = new int[newSize];

                for(int i = 0; i < size; i++){
                    newHeap[i] = heap[i];
                }

                delete[] heap;
                heap = newHeap;
            }
        }

    public:
        PriorityQueue(): size(0), capacita(10){
            this->heap = new int[this->capacita];
        }
        
        ~PriorityQueue(){
            delete[] heap;
        }
        
        void push(int valore){
            if(size == capacita) resize();

            heap[size] = valore;
            size++;
            heapifyUp(size - 1);
        }
        
        int pop(){
            int min = top();
            
            heap[0] = heap[size - 1];
            size--;
            
            heapifyDown(0);

            return min;
        }
        
        int top() const{
            if(empty()) throw runtime_error("coda vuota");
            return heap[0];
        }
        
        bool empty() const{
            return size == 0;
        }
};


//es3
enum Direzione { SIN, DES };
class AlberoB {
    private:
        int info;  
        AlberoB* p;          
        AlberoB* sx;          
        AlberoB* dx;                 

    public:
        
        AlberoB(int valore) : info(valore),  p(nullptr), sx(nullptr), dx(nullptr) {}

        ~AlberoB() {
            delete sx; 
            delete dx;
        }

        AlberoB* figlio(Direzione dir) {
            if (dir == SIN) {
                return this->sx;
            }
            return this->dx;
        }

        AlberoB* padre() {
            return this->p;
        }

        int radice() {
            return this->info;
        }

        bool foglia() {
            return (this->sx == nullptr && this->dx == nullptr);
        }

        static bool nullo(AlberoB* a, float pred) {
            return a == nullptr;
        }

        int trovaLCA(AlberoB* a, int nodo1, int nodo2){
            if(nullo(a)) return -1;

            if(a.radice() == nodo1 || a.radice() == nodo2) return a.radice();

            int sin = trovaLCA(a.figlio(SIN), nodo1, nodo2);
            int des = trovaLCA(a.figlio(DES), nodo1, nodo2);

            if(sin != -1 && des != -1) return a.radice();

            return (sin != -1) ? sin : des;
        }
};