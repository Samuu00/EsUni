#include <iostream>
using namespace std;

//es1
class RingBuffer {
    private:
        int* buffer;    
        int capacity; 
        int head;  
        int count;          

    public:
        RingBuffer(int cap): capacity(cap), head(0), count(0){
            this->buffer = new int[this->capacity];
        }

        ~RingBuffer(){
            delete[] buffer;
        }
        
        void add(int val){
            buffer[head] = val;
            head = (head + 1) % capacity;

            if(count < capacity) count++;
        }
        
        int get(int i) const{
            if(i < 0 || i >= count) throw out_of_range("Fuori");

            int start = 0;
            if(count == capacity) start = head;

            int index = (start + i) % capacity;
            return buffer[index];
        }
        
        double getAverage() const{
            if(count == 0) return 0.0;

            double media = 0.0;
            for(int i = 0; i < count; i++){

                media += get(i);
            }

            return media / count;
        }
        
        void resize(int newCap){
            int* newBuffer = new int[newCap];

            for(int i = 0; i < count; i++){

                newBuffer[i] = get(i);
            }

            this->capacity = newCap;
            delete[] buffer;
            buffer = newBuffer;

            head = count % capacity;
        }
};