#include <iostream>
#include <memory>

#include "Ej3.hpp"

using namespace std;

list_ptr create_list(){
    list_ptr list;
    
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
    node_ptr new_node = create_node(value, list->head);

    if(list->size == 0) {list->tail = new_node;}

    list->head = new_node;
    list->size++;
    return;
}

void push_back(list_ptr& list, int value){
    node_ptr new_node = create_node(value, nullptr);

    if(list->size == 0) {
        list->head = new_node;
        list->tail = new_node;
    } 
    else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
    list->size++;
}

void insert(list_ptr& list, int value, int pos){
    if (pos < 0) {pos = 0;}
    if (pos == 0) {push_front(list, value); return;}
    if (pos >= list->size) {push_back(list, value); return;}

    node_ptr iter = list->head;

    for (int i = 0; (i + 1) != pos; i++){
        iter = iter->next;
    }

    node_ptr new_node = create_node(value, iter->next);
    iter->next = new_node;
    list->size++;
    return;
}

void erase(list_ptr& list, int pos) {
    if (list->size == 0) {cerr << "ERROR: The list is empty." << endl; return;}

    if (pos < 0) {pos = 0;}
    if (pos >= list->size) {pos = list->size - 1;}

    if (pos == 0) {
        list->head = list->head->next;
        if (list->size == 1) {list->tail = nullptr;}
    } 
    else {
        node_ptr iter = list->head;
        for (int i = 0; i < pos - 1; i++) {
            iter = iter->next;
        }

        iter->next = iter->next->next;

        if (pos == list->size - 1) {list->tail = iter;}
    }

    list->size--;
    return;
}

void print_list(list_ptr& list) {
    node_ptr current = list->head;

    while (current) {
        cout << current->value << " -> ";
        current = current->next;
    }
    
    cout << "NULL\n";
}