#include <iostream>
using namespace std;
template<typename T>
class smartArray{
private:
    T*data = nullptr;
    int arraySize=0;
    int capacity=0;
    int lastIndex=0;

    //copy function that implement deep copy
    void copy(const smartArray&array){
        data = new T[array.capacity];

        for(int i=0 ; i<array.size() ;i++)
            data[i] = array[i];

        arraySize = array.arraySize;
        capacity = array.capacity;
     }

    //allocate the data into smart array
    void allocate(int newCapacity){

        T*temp = new T[newCapacity];

        for(int i=0 ; i<arraySize ; i++)
            temp[i] = data[i];

        delete[] data;
        capacity = newCapacity;
        data = temp;
    }

public:
    //constructor initialize smart array initially with capacity 1
    smartArray(){
        allocate(5);
    }

    smartArray(int size){
        allocate(5);
        arraySize = size;
        allocate(2*size);
    }

    //copy constructor
    smartArray(const smartArray& array){
        copy(array);
    }

    //push inputs to a=smart array
    void Push(T input){
        if(arraySize>=capacity)
            allocate(2*capacity);

        data[lastIndex]=input;
        lastIndex++;
        arraySize = lastIndex;
    }

   //getter that return size of smart array
    int size()const{
       return arraySize;
    }

    //overloading []
    T& operator[](int k) const{
        if(k<0 || k>arraySize){
            cout<<"not valid index\n";
            exit(0);
        }

        else
            return data[k];
    }

    //assignment operator overloading
    smartArray& operator = (const smartArray& arr){
        if(this != &arr) {
            delete[] data;
            copy(arr);
        }
        return *this;
    }

    //print method
    void print(){
        for(int i=0 ; i<arraySize ; i++)
            cout<<data[i]<<" ";
    }

    //destructor to free data from the heap
    ~smartArray(){
        delete[] data;
    }
};

int main() {
    cout<<"enter you smartArray size: ";
    int Size;
    cin>>Size;
    cout<<'\n';

    cout<<"enter your smartArray Type: ";
    string type;
    cin>>type;
    cout<<'\n';

    if(type=="string"){
        smartArray<string>x(Size);
        cout<<"enter smartArray elements : ";
        for(int i=0 ; i<Size ; i++){
            string s;
            cin>>s;
            x.Push(s);
        }

        x.print();
    }


    if(type=="int"){
        smartArray<int>x(Size);

        cout<<"enter smartArray elements : ";
        for(int i=0 ; i<Size ; i++){
            cin>>x[i];
        }

        x.print();
    }


    if(type=="double"){
        smartArray<double>x(Size);

        cout<<"enter smartArray elements : ";
        for(int i=0 ; i<Size ; i++){
            cin>>x[i];
        }

        x.print();
    }

    return 0;
}

