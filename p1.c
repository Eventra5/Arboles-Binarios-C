#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct Nodo {
    int dato;
    struct Nodo *izquierda;
    struct Nodo *derecha;
};


struct Nodo *nuevoNodo(int dato) {
	
    size_t tamanioNodo = sizeof(struct Nodo);
    struct Nodo *nodo = (struct Nodo *) malloc(tamanioNodo);
    
    nodo->dato = dato;
    nodo->izquierda = nodo->derecha = NULL;
    return nodo;
}

void insertar(struct Nodo *nodo, int dato) {
    
    if (dato > nodo->dato) {
        
        if (nodo->derecha == NULL) { nodo->derecha = nuevoNodo(dato); }
		
		else { insertar(nodo->derecha, dato); }
        
    } 
	
	else {
    	
        if (nodo->izquierda == NULL) { nodo->izquierda = nuevoNodo(dato); } 
        
		else { insertar(nodo->izquierda, dato); }
    }
}

void preorden(struct Nodo *nodo) {
    if (nodo != NULL) {
        printf("%d,", nodo->dato);
        preorden(nodo->izquierda);
        preorden(nodo->derecha);
    }
}

void inorden(struct Nodo *nodo) {
    if (nodo != NULL) {
        inorden(nodo->izquierda);
        printf("%d,", nodo->dato);
        inorden(nodo->derecha);
    }
}

void postorden(struct Nodo *nodo) {
    if (nodo != NULL) {
        postorden(nodo->izquierda);
        postorden(nodo->derecha);
        printf("%d,", nodo->dato);
    }
}

struct Nodo* find(struct Nodo* raiz, int valor) {
    if (raiz == NULL) {
        return NULL;
    }

    if (raiz->dato == valor) {
    	
        printf("\n\nnodo: %d", raiz->dato);
        
        if (raiz->izquierda != NULL) {
        	
            printf(", izquierda: %d", raiz->izquierda->dato);
            
        } else {
            printf(", izquierda: NULL");
        }

        if (raiz->derecha != NULL) {
        	
            printf(", derecha: %d", raiz->derecha->dato);
            
        } else {
            printf(", derecha: NULL");
        }
        
        printf("\n");
        return raiz;
    }
    

    struct Nodo* nodoEncontrado = NULL;
    if (valor < raiz->dato) {
        nodoEncontrado = find(raiz->izquierda, valor);
    } else {
        nodoEncontrado = find(raiz->derecha, valor);
    }

    return nodoEncontrado;
}


bool Validacion(struct Nodo *nodo, int min, int max) {
	
    if (nodo == NULL) { return true; }

    if (nodo->dato < min || nodo->dato > max) { return false; }

    return Validacion(nodo->izquierda, min, nodo->dato - 1) && Validacion(nodo->derecha, nodo->dato + 1, max);
    
}

bool validar(struct Nodo *raiz) {
    return Validacion(raiz, INT_MIN, INT_MAX);
}

main(void) {

	struct Nodo *raiz = nuevoNodo(10);
    insertar(raiz, 5);
    insertar(raiz, 15);
    insertar(raiz->izquierda, 20);
    
    printf("\nPreorden\n");
    preorden(raiz);
    
    printf("\n\nInorden\n");
    inorden(raiz);		
    
    printf("\n\nPostorden\n");
    postorden(raiz);
    
	int valorBuscado = 10;
      
    struct Nodo* nodoEncontrado = find(raiz, valorBuscado);

        if (validar(raiz)) {
        printf("\n\nValido.\n");
        
    } else {
        printf("\n\nDont Valido.\n");
    }


    return 0;
}
