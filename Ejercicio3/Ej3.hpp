#ifndef Ej3_hpp
#define Ej3_hpp

#include <memory>

/**
 * @brief Estructura que representa un nodo en la lista enlazada
 */
struct node_t {
    int value;                  ///< Valor almacenado en el nodo
    std::shared_ptr<node_t> next; ///< Puntero al siguiente nodo en la lista
};

/**
 * @brief Estructura que representa una lista enlazada
 */
struct list_t {
    size_t size;                  ///< Número de elementos en la lista
    std::shared_ptr<node_t> head; ///< Puntero al primer nodo de la lista
    std::shared_ptr<node_t> tail; ///< Puntero al último nodo de la lista
};

// Alias de tipos para mejorar la legibilidad
using node_ptr = std::shared_ptr<node_t>;
using list_ptr = std::shared_ptr<list_t>;

/**
 * @brief Crea una nueva lista enlazada vacía
 * 
 * @return list_ptr Un puntero inteligente a la nueva lista
 * @throws Captura y reporta excepciones de tipo bad_alloc si falla la asignación de memoria
 */
list_ptr create_list();

/**
 * @brief Crea un nuevo nodo para la lista enlazada
 * 
 * @param value El valor entero a almacenar en el nodo
 * @param next Un puntero al siguiente nodo de la lista, o nullptr si es el último
 * @return node_ptr Un puntero inteligente al nuevo nodo
 * @throws Captura y reporta excepciones de tipo bad_alloc si falla la asignación de memoria
 */
node_ptr create_node(int value, node_ptr next);

/**
 * @brief Inserta un nuevo elemento al principio de la lista
 * 
 * @param list Referencia al puntero de la lista
 * @param value El valor entero a insertar
 * @post La lista tiene un nuevo elemento al principio y su tamaño aumenta en 1
 */
void push_front(list_ptr& list, int value);

/**
 * @brief Inserta un nuevo elemento al final de la lista
 * 
 * @param list Referencia al puntero de la lista
 * @param value El valor entero a insertar
 * @post La lista tiene un nuevo elemento al final y su tamaño aumenta en 1
 */
void push_back(list_ptr& list, int value);

/**
 * @brief Inserta un nuevo elemento en una posición específica de la lista
 * 
 * @param list Referencia al puntero de la lista
 * @param value El valor entero a insertar
 * @param pos La posición en la que insertar (0 = principio). Si es negativa, se inserta al principio.
 *            Si es mayor o igual que el tamaño de la lista, se inserta al final.
 * @post La lista tiene un nuevo elemento en la posición especificada y su tamaño aumenta en 1
 */
void insert(list_ptr& list, int value, int pos);

/**
 * @brief Elimina un elemento de una posición específica de la lista
 * 
 * @param list Referencia al puntero de la lista
 * @param pos La posición del elemento a eliminar (0 = principio). Si es negativa, se elimina el primero.
 *            Si es mayor o igual que el tamaño de la lista, se elimina el último.
 * @post Si la lista no está vacía, se elimina el elemento y el tamaño disminuye en 1
 */
void erase(list_ptr& list, int pos);

/**
 * @brief Imprime el contenido de la lista por consola
 * 
 * @param list Referencia al puntero de la lista a imprimir
 * @post Muestra cada elemento de la lista seguido de " -> " y finaliza con "NULL"
 */
void print_list(list_ptr& list);

#endif
