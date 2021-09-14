#include <iostream>
using namespace std;

#include "funciones.h"
#include "desarrollo.h"
int main(){
    int A[10]= {123, -6, 13, -33, -98, 333, 23, -5, 0, -100};
    cout<<endl<<"Elementos originales"<<endl;
    
    for(int i=0;i<10;i++){
            cout<<"["<<A[i]<<"]";
        }
        
    cout<<endl<<"\nElementos ordenados"<<endl;
    ordenar(A,0,9);
    
    for(int i=0;i<10;i++){
            cout<<"["<<A[i]<<"]";
        }
}



