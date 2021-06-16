#include <iostream>

using namespace std;

// Creamos Nuestra Estructura de Dato

struct dato
{
    int Id;
    string Nombre;
    string Cedula;
    double Precio;
    double PrecioTotal;
};

// Creamos Nuestra Estructura Nodo que cumple la dos cosas el dato y un puntero siguiente

struct Nodo
{
    struct dato Dato;
    Nodo *SiguienteNodo;
};

// Los Prototipos de las Funciones que creamos para avisarle a nuestro programa de algo que va a existir despues

void Push (Nodo *&, int , string , string , double , double, int &);
void Pop (Nodo *&, int &, string &, string &,double &);

// La función Principal 

int main(){

    // Paso 1 : Inicializar nuestro puntero pila de tipo a null para indicarle que debajo de el no hay nada
    Nodo *Pila = NULL;
    int Id,C=0; // Creamos dos variables de tipo entero
    string Nombre, Cedula; // Creamos dos variables de tipo string
    double Precio, PrecioconIva=0; // Creamos dos variables de tipo double
    char Bandera; // creamos una variable de tipo char

    /*
    Usamos un ciclo Do-while para llenar nuestros datos y asi decirle al usuario cuando quiere el salir ya 
    y llamando varios veces nuestra funcion push que significa ingresar elementos
    */
    do
    {
         C++;
         cout<<"\nID: ";
         cin>>Id;
         cout<<"\nNombre: ";
         cin>>Nombre;
         cout<<"\nCedula: ";
         cin>>Cedula;
         cout<<"\nPrecio: ";
         cin>>Precio;
         Push(Pila,Id,Nombre,Cedula,Precio,PrecioconIva,C);
         cout<<"\n\n"<<char(168)<<"Quieres Seguir Ingresando Mas Cliente? \nIngresa S/N: ";
         cin>>Bandera;
    } while (Bandera=='S' || Bandera=='s');

    // Estamos aplicado el método de POP sacar datos de la pila
    cout<<"\n\nSacando los Elementos de la Pila...";
    while (Pila!=NULL)
    {
        Pop(Pila,Id,Nombre,Cedula,PrecioconIva);
        if (Pila!=NULL)
        {
            cout<<"\n\n"<<Id<<" Nombre "<<Nombre<<" Cedula "<<Cedula<<" Precio Total a Pagar (Incluido IVA): "<<PrecioconIva;
        }else{
            cout<<"\n\n"<<Id<<" Nombre "<<Nombre<<" Cedula "<<Cedula<<" Precio Total a Pagar (Incluido IVA): "<<PrecioconIva;
        }

    }
    cout<<"\n\n";
    system("pause");
    return 0;
}

void Push (Nodo *&Pila, int Id, string Nombre, string Cedula, double Precio, double PrecioTotal, int & C){

    
    double Aux=0.0;
    Nodo *Nuevo_Nodo = new Nodo();
    Nuevo_Nodo->Dato.Id = Id;
    Nuevo_Nodo->Dato.Nombre = Nombre;
    Nuevo_Nodo->Dato.Cedula = Cedula;
    Nuevo_Nodo->Dato.Precio = Precio;
    Aux = Precio*0.12;
    Nuevo_Nodo->Dato.PrecioTotal = Precio+Aux; 
    Nuevo_Nodo->SiguienteNodo = Pila;
    Pila = Nuevo_Nodo;
    
    cout<<"\n";
    cout<<"\tCliente "<<C<<" Agregado a PILA Correctamente...";
    
}

void Pop (Nodo *&Pila, int &Id, string &Nombre, string &Cedula,double &PrecioTotal){
    Nodo *Aux = Pila;
    Id = Aux->Dato.Id;
    Nombre = Aux->Dato.Nombre;
    Cedula = Aux->Dato.Cedula;
    PrecioTotal = Aux->Dato.PrecioTotal;
    Pila = Aux->SiguienteNodo;
    delete Aux;
}
