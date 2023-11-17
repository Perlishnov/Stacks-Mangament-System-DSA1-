#include <iostream>
using namespace std;

struct Pila
{
    int dato;
    Pila *next;
};

void MostrarMensaje();
void Push(Pila *&stack, int data);
void Pop(Pila *&stack);

int main()
{

    Pila *stack;
    stack = NULL;
    bool isRunning = true;
    int userOption;
    int numberToBePushed = 0;

    MostrarMensaje();
    cin >> userOption;

    while (isRunning)
    {
        switch (userOption)
        {
        case 1:
            cout << "Ha salido del sistema";
            break;
        case 2:
            cout << "Ingrese el dato(numerico)";
            cin >> numberToBePushed;
            Push(stack, numberToBePushed);
            break;
        case 3:
            Pop(stack);
            
            break;
        default:
            cout << "Opcion no valida" << endl;
            MostrarMensaje();
            continue;
        }
        isRunning = false;
    }

    return 0;
}

void MostrarMensaje()
{
    cout << "Programa para manejar pilas con operaciones push y pop" << endl;
    cout << "Operaciones: \n 1-Salir del programa \n 2-Insertar un dato \n 3-Eliminar un dato" << endl;
}
void Push(Pila *&stack, int data)
{
    Pila *nuevoNodo = new Pila;
    nuevoNodo->dato = data;
    nuevoNodo->next = stack;
    stack = nuevoNodo;

    cout << "Ha sido agregado el valor" << nuevoNodo->dato << "al stack"<<endl;
}
void Pop(Pila *&stack)
{
    Pila *aux = stack;
    if (aux != NULL)
    {
        cout << "Nodo" << aux->dato << "Eliminado";
        stack = aux->next;
        delete aux;
    }
    else
    {
        cout << "Empty Stack" << endl;
    }
}