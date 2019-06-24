#include<iostream>
using namespace std;
template<typename T>
class DVector{
private:
    int len;
    T *arr;
public:
    DVector()len(0){}
    DVector(int l,T*cur){
        len = l;
        arr = new T[l];
        for (int i = 0; i < l;i++)
            arr[i] = cur[i];
    }
    DVector(int l){
        len = l;
        arr = new T[l];
    }
    DVector(DVector &b){
            len = b.len;
            arr = new T[len];
            for (int i = 0; i < len;i++)
                arr[i] = b.arr[i];
    }
    DVector operator=(DVector&b){
        

    }
    ~DVector(){
        delete[] arr;
    }

};