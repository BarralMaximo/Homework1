#include "Ej3.hpp"

int main() {
    std::cout << "PRUEBA DE FUNCIONAMIENTO - EJERCICIO 3 - BARRAL MÁXIMO\n";

    // Prueba 1: Crear una lista vacía
    list_ptr my_list = create_list();
    std::cout << "\nPrueba 1: Lista creada.\n";
    print_list(my_list); // Debe imprimir: NULL

    // Prueba 2: Insertar al frente en una lista vacía
    std::cout << "\nPrueba 2: Insertar 10 al frente de la lista...\n";
    push_front(my_list, 10);
    print_list(my_list); // Debe imprimir: 10 -> NULL

    // Prueba 3: Insertar al frente en una lista no vacía
    std::cout << "\nPrueba 3: Insertar 20 al frente de la lista...\n";
    push_front(my_list, 20);
    print_list(my_list); // Debe imprimir: 20 -> 10 -> NULL

    // Prueba 4: Insertar al final en una lista no vacía
    std::cout << "\nPrueba 4: Insertar 30 al final de la lista...\n";
    push_back(my_list, 30);
    print_list(my_list); // Debe imprimir: 20 -> 10 -> 30 -> NULL

    // Prueba 5: Insertar en una posición válida
    std::cout << "\nPrueba 5: Insertar 15 en la posición 1...\n";
    insert(my_list, 15, 1);
    print_list(my_list); // Debe imprimir: 20 -> 15 -> 10 -> 30 -> NULL

    // Prueba 6: Insertar en una posición inválida (más allá del tamaño)
    std::cout << "\nPrueba 6: Insertar 40 en la posición 10...\n";
    insert(my_list, 40, 10);
    print_list(my_list); // Debe imprimir: 20 -> 15 -> 10 -> 30 -> 40 -> NULL

    // Prueba 7: Insertar en la posición 0 (frente)
    std::cout << "\nPrueba 7: Insertar 5 en la posición 0...\n";
    insert(my_list, 5, 0);
    print_list(my_list); // Debe imprimir: 5 -> 20 -> 15 -> 10 -> 30 -> 40 -> NULL

    // Prueba 8: Eliminar el primer elemento
    std::cout << "\nPrueba 8: Eliminar el elemento en la posición 0...\n";
    erase(my_list, 0);
    print_list(my_list); // Debe imprimir: 20 -> 15 -> 10 -> 30 -> 40 -> NULL

    // Prueba 9: Eliminar un elemento en una posición válida
    std::cout << "\nPrueba 9: Eliminar el elemento en la posición 2...\n";
    erase(my_list, 2);
    print_list(my_list); // Debe imprimir: 20 -> 15 -> 30 -> 40 -> NULL

    // Prueba 10: Eliminar el último elemento
    std::cout << "\nPrueba 10: Eliminar el último elemento...\n";
    erase(my_list, my_list->size - 1);
    print_list(my_list); // Debe imprimir: 20 -> 15 -> 30 -> NULL

    // Prueba 11: Eliminar un elemento en una posición inválida (más allá del tamaño)
    std::cout << "\nPrueba 11: Eliminar el elemento en la posición 10...\n";
    erase(my_list, 10);
    print_list(my_list); // Debe imprimir: 20 -> 15 -> NULL

    // Prueba 12: Eliminar todos los elementos uno por uno
    std::cout << "\nPrueba 12: Eliminar todos los elementos...\n";
    while (my_list->size > 0) {erase(my_list, 0);}
    print_list(my_list); // Debe imprimir: NULL

    // Prueba 13: Intentar eliminar de una lista vacía
    std::cout << "\nPrueba 13: Intentar eliminar de una lista vacía...\n";
    erase(my_list, 0); // Debe imprimir: ERROR: The list is empty.
    print_list(my_list); // Debe imprimir: NULL

    // Prueba 14: Insertar en una lista vacía después de haberla vaciado
    std::cout << "\nPrueba 14: Insertar 100 al frente de la lista vacía...\n";
    push_front(my_list, 100);
    print_list(my_list); // Debe imprimir: 100 -> NULL

    // Prueba 15: Insertar al final en una lista con un solo elemento
    std::cout << "\nPrueba 15: Insertar 200 al final de la lista...\n";
    push_back(my_list, 200);
    print_list(my_list); // Debe imprimir: 100 -> 200 -> NULL

    // Prueba 16: Eliminar el único elemento de la lista
    std::cout << "\nPrueba 16: Eliminar el único elemento de la lista...\n";
    erase(my_list, 0);
    print_list(my_list); // Debe imprimir: 200 -> NULL

    // Prueba 17: Eliminar el último elemento restante
    std::cout << "\nPrueba 17: Eliminar el último elemento restante...\n";
    erase(my_list, 0);
    print_list(my_list); // Debe imprimir: NULL

    // Prueba 18: Insertar en una posición negativa
    std::cout << "\nPrueba 18: Insertar 300 en la posición -1...\n";
    insert(my_list, 300, -1);
    print_list(my_list); // Debe imprimir: 300 -> NULL

    // Prueba 19: Insertar en una lista con un solo elemento
    std::cout << "\nPrueba 19: Insertar 400 en la posición 1...\n";
    insert(my_list, 400, 1);
    print_list(my_list); // Debe imprimir: 300 -> 400 -> NULL

    // Prueba 20: Eliminar el último elemento nuevamente
    std::cout << "\nPrueba 20: Eliminar el último elemento...\n";
    erase(my_list, my_list->size - 1);
    print_list(my_list); // Debe imprimir: 300 -> NULL

    return 0;
}