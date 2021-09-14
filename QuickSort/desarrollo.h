
//desarrollo de las funciones


int mitad (int a[],int pinicial, int pfinal){
    return a[(pinicial+pfinal)/2];
}


void ordenar (int a[],int pinicial, int pfinal){

    int i=pinicial;
    int j=pfinal;
    int temp;
    int piv=mitad(a,pinicial,pfinal);

    do {
        while(a[i]<piv){
            i++;
        }
        while(a[j]>piv)
        {
            j--;
        }
        if(i<=j)
        {
            temp =a[i];
            a[i]=a[j];
            a[j]=temp;
            i++;
            j--;
        }
    }
    while(i<=j);
    if(pinicial<j)
    {
        ordenar(a,pinicial,j);
    }
    if(i<pfinal)
    {
      ordenar(a,i,pfinal);
    }
}
