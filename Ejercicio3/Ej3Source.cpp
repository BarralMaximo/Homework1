#include <iostream>
#include <memory>

#include "Ej3Header.hpp"

using namespace std;

list_ptr create_list(){
    list_ptr list;
    
    // Se reserva memoria para la nueva lista y se asignan sus parametros, se utiliza un try para manejar el caso en que el new falle
    try {
        list = list_ptr(new list_t); 
        list->size = 0;
        list->head = nullptr;
        list->tail = nullptr;
    } catch (const bad_alloc& e) {
        std::cerr << "ERROR: Failed to allocate memory." << e.what() << std::endl;
    }
    
    return list;
}

node_ptr create_node(int value, node_ptr next){
    node_ptr node;

    // Se reserva memoria para el nuevo nodo y se asignas sus parametros, se utiliza un try para manejar el caso en que el new falle
    try {
        node = node_ptr(new node_t);
        node->value = value;
        node->next = next;
    } catch (const bad_alloc& e) {
        std::cerr << "ERROR: Failed to allocate memory." << e.what() << std::endl;
    }
    return node;
}

void push_front(list_ptr& list, int value){
    node_ptr new_node = create_node(value, list->head); // Crea un nodo con el nuevo valor y lo enlaza al head

    if(list->size == 0) {list->tail = new_node;} // Si la lista está vacía, la cola también debe apuntar al nuevo nodo

    list->head = new_node; // El nuevo nodo se convierte en la cabeza de la lista
    list->size++;
    return;
}

void push_back(list_ptr& list, int value){
    node_ptr new_node = create_node(value, nullptr); // Crea un nodo con el valor y sin siguiente

    if(list->size == 0) {
        list->head = new_node; // Si la lista está vacía, la cabeza apunta al nuevo nodo
        list->tail = new_node; // La cola también apunta al nuevo nodo
    } 
    else {
        list->tail->next = new_node; // Si la lista NO esta vacía, se enlaza el último nodo al nuevo nodo
        list->tail = new_node; // Se actualiza la cola
    }
    list->size++;
}

void insert(list_ptr& list, int value, int pos){
    if (pos < 0) {pos = 0;} // Si la posición es negativa, se inserta al inicio
    if (pos == 0) {push_front(list, value); return;} // Inserta en el frente si la posición es 0
    if (pos >= list->size) {push_back(list, value); return;} // Inserta al final si la posición es mayor o igual al tamaño

    node_ptr iter = list->head;

    for (int i = 0; (i + 1) != pos; i++){
        iter = iter->next; // Se recorre la lista hasta la posición anterior a la deseada
    }

    node_ptr new_node = create_node(value, iter->next);
    iter->next = new_node;
    list->size++;
    return;
}

void erase(list_ptr& list, int pos) {
    if (list->size == 0) {cerr << "ERROR: The list is empty." << endl; return;} // Si la lista está vacía, se muestra un error

    if (pos < 0) {pos = 0;} // Si la posición es negativa, se ajusta a 0
    if (pos >= list->size) {pos = list->size - 1;} // Si la posición es mayor al tamaño, se ajusta al último elemento

    if (pos == 0) {
        list->head = list->head->next; // La cabeza apunta al segundo nodo
        if (list->size == 1) {list->tail = nullptr;} // Si era el único nodo, la cola se vuelve nullptr
    } 
    else {
        // Se recorre la lista hasta el nodo anterior al que se eliminará
        node_ptr iter = list->head;
        for (int i = 0; i < pos - 1; i++) {iter = iter->next;}

        iter->next = iter->next->next; // Se enlaza el nodo anterior con el siguiente del nodo eliminado

        if (pos == list->size - 1) {list->tail = iter;} // Si se eliminó el último nodo, se actualiza la cola
    }

    list->size--;
    return;
}

void print_list(list_ptr& list) {
    node_ptr current = list->head;

    //Usamos el puntero current para recorrer toda la lista e ir imprimiendo valores
    while (current) { 
        cout << current->value << " -> ";
        current = current->next;
    }
    
    cout << "NULL\n"; // Se imprime el final de la lista
}
