
#include <fstream>
#include <ctime>                                 
#include <cstdlib>
#include "funciones.h"  
using namespace std;
int n;
void archivo(int A[], int n){
  ofstream archivo;
  archivo.open("ejercicio1.txt",ios::app);

  for(int i=0 ; i<n ; i++){
    A[i]=(rand()%65)+15;
    cout << "[" << A[i] << "] ";
    archivo << "[" << A[i] << "] ";
  }
  cout << endl;
  archivo << endl << "El menor elemento es: ";
  archivo << menorElemento(A,n);
  archivo << endl << "El mayor elemento es: ";
  archivo << mayorElemento(A,n) << endl;

  int repetido=0;
  for(int i=0 ; i<n ; i++){
      repetido=0;
      for(int j=0 ; j<n ; j++){ 
        if(A[i]==A[j]){
          repetido++;
        }
      }
    
    if(repetido!=1){
      cout << "Numero " << A[i] << " repetido " << repetido << " veces" << endl;
      archivo << "Numero " << A[i] << " repetido " << repetido << " veces" << endl;
    }
  }
  archivo.close();
}
int menorElemento(int A[], int n){
  int b;
  b= A[0];
  for(int i=0 ; i<n ; i++){
    if(b>A[i]){
      b=A[i];
    }
  }
  return b;
}
int mayorElemento(int A[], int n){
  int b;
  b= A[0];
  for(int i=0 ; i<n ; i++){
    if(b<A[i]){
      b=A[i];
    }
  }
  return b;
}
void ejercicio1(){
    int n;
    srand(time(NULL));
    cout << "Digite cuanto elementos desea ingresar al arreglo: ";
    cin >> n;
    int A[n];
    archivo(A, n);
    cout << "El elemento menor es: " << menorElemento(A, n) << endl;
    ;
    cout << "El elemento mayor es: " << mayorElemento(A, n) << endl;
}
int menubanco()
{
    int op;
    cout << "\t\t\t\t--------------------" << endl;
    cout << "\t\t\t\t|BANCO DEL PACIFICO|" << endl;
    cout << "\t\t\t\t--------------------" << endl;
    cout << "\t\t1.-MOSTRAR TRANSACCIONES." << endl;
    cout << "\t\t2.-BUSCAR TRANSACCION" << endl;
    cout << "\t\t0.-SALIR" << endl;
    cout << "\t\tSELECCIONA: ";
    cin >> op;
    return op;
}
void datosbanco(float a[])
{
    cout << "\t\t\t\t--------------------" << endl;
    cout << "\t\t\t\t|BANCO DEL PACIFICO|" << endl;
    cout << "\t\t\t\t--------------------" << endl;
    cout << "\t\tINGRESA EL NUMERO DE TRANSACCIONES A REALIZAR: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        do
        {
            cout << "\t\tTRANSACCION " << i + 1 << ": ";
            cin >> a[i];
            if (a[i] < 1)
            {
                cout << "\t\t\t\tNGRESA CANTIDADES REALES DE DINERO. " << endl;
            }
        } while (a[i] < 1);
    }
}
void mostrar(float a[])
{
    ofstream archivo;
    archivo.open("ejercicio2.txt", ios::out);
    archivo << "\t\t-----------------------------------" << endl;
    archivo << "\t\t|TRANSACCIONES REALIZADAS EN ORDEN| " << endl;
    archivo << "\t\t-----------------------------------" << endl;
    cout << "\t\tTRANSACCIONES REALIZADAS: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "\t\t\t" << i + 1 << ".-|" << a[i] << "|usd" << endl;
        archivo << "\t\t\t" << i + 1 << ".-|" << a[i] << "|usd" << endl;
    }
    archivo.close();
}
void busqueda(float a[], float buscar)
{
    cout << "AAAA" << buscar << endl;
    bool ax = false;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == buscar)
        {
            cout << "\t\tPOSICION DE LA TRANSACCION: [" << i + 1 << "]" << endl;
            ax = true;
        }
    }
    if (ax == false)
    {
        cout << "\t\tTRANSACCION INEXISTENTE." << endl;
    }
    mostrar(a);
}
void div(float a[], int inicial, int fina)
{

    if (inicial >= fina)
    {
        return;
    }
    int m = inicial + (fina - inicial) / 2;
    div(a, inicial, m);

    div(a, m + 1, fina);

    fusionar(a, inicial, m, fina);
}
void fusionar(float a[], int ini, int medio, int fin)
{
    int n1 = medio - ini + 1;
    int n2 = fin - medio;

    float iz[n1], de[n2];

    for (int i = 0; i < n1; i++)
        iz[i] = a[ini + i];
    for (int j = 0; j < n2; j++)
        de[j] = a[medio + 1 + j];

    int i = 0;

    int j = 0;

    int k = ini;

    while (i < n1 && j < n2)
    {
        if (iz[i] <= de[j])
        {
            a[k] = iz[i];
            i++;
        }
        else
        {
            a[k] = de[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = iz[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        a[k] = de[j];
        j++;
        k++;
    }
}
void ejercicio2()
{
    float lista[MAX];
    int op1;
    datosbanco(lista);
    div(lista, 0, n - 1);
    do
    {
        op1 = menubanco();
        switch (op1)
        {
        case 1:
        {
            mostrar(lista);
            break;
        }
        case 2:
        {
            float buscar;
            cout << endl
                 << "\t\t\tINGRESA LA TRASACCION A BUSCAR: ";
            cin >> buscar;
            busqueda(lista, buscar);
            break;
        }
        }
    } while (op1 != 0);
}
void ejercicio3()
{
    string nombreProduc;
    string ciudad, nombre, codigo, estado;
    int telefono, cantidad;
    int total_cantidad = 0;
    int total_produc = 0;
    double precio, total_precio = 0;
    char r;
    ofstream archivoprueba;
    archivoprueba.open("Productos.txt", ios::out);
    archivoprueba << " \t*** DATOS DE LA SUCURSAL***" << endl;
    archivoprueba << "CODIGO \t\tNOMBRE \t\tCIUDAD \t\tTELEFONO " << endl;
    cout << "Ingrese el código de la sucursal: ";
    cin >> codigo;
    cout << "Nombre: ";
    cin.ignore();
    getline(cin, nombre);
    cout << "Cuidad: ";
    cin >> ciudad;
    cout << "Telefono: ";
    cin >> telefono;
    archivoprueba << codigo << "\t\t" << nombre << "\t\t" << ciudad << "  \t" << telefono << endl;
    archivoprueba << " ***INVENTARIO ALMACEN AKI ****" << endl;
    archivoprueba << "NOMBRE \t\tPRECIO \t\tCANTIDAD \t\tESTADO " << endl;
    do
    {
        cout << "Ingrese el nombre del producto : ";
        cin.ignore();
        getline(cin, nombreProduc);
        total_produc++;
        cout << "Ingrese el precio : ";
        cin >> precio;
        cout << "Ingrese la cantidad : ";
        cin >> cantidad;
        total_cantidad += cantidad;
        total_precio = precio * cantidad;
        cout << "Ingrese el estado : ";
        cin >> estado;
        archivoprueba << nombreProduc << "\t" << precio << "\t\t\t" << cantidad << "\t\t\t\t" << estado << endl;
        cout << "--Ingrese * si dese dejar de ingresar--" << endl;
        cout << "--Caso contrario ingresar cualquier caracter--";
        cin >> r;
        cin.ignore();
    } while (r != '*');
    archivoprueba << "Numero total de productos ingresados :" << total_produc << endl;
    archivoprueba << "Cantidad de productos ingresados :" << total_cantidad << endl;
    archivoprueba << "El valor total de los productos :" << total_precio << endl;
    cout << "\t Sus datos se han guardado correctamente en el documento { productos.txt } !!Por favor revise el archivo¡¡ \n\t\t\tGRACIAS POR USAR EL PROGRAMA :) TENGA UNA BUENA TARDE" << endl;
    archivoprueba.close();
}
