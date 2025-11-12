#include <stdio.h>
#include <stdlib.h>

// Estructura del nodo
struct Node {
    int key;
    struct Node *left;
    struct Node *right;
};

// Crear un nuevo nodo
struct Node* create_node(int key) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    if (node == NULL) {
        fprintf(stderr, "Error: memoria insuficiente\n");
        exit(EXIT_FAILURE);
    }
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Insertar al arbol
struct Node* insert(struct Node* root, int key) {
    if (root == NULL) {
        return create_node(key);
    }

    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

// Hacer search
struct Node* search(struct Node* root, int key) {
    if (root == NULL) return NULL;
    if (key == root->key) return root;
    if (key < root->key) return search(root->left, key);
    return search(root->right, key);
}

// los order
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}

void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->key);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->key);
}

// liberar memoria
void free_tree(struct Node* root) {
    if (root == NULL) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

// Programa
int main(void) {
    struct Node* root = NULL;
    int n, value;

    printf("¿Cuántos valores desea ingresar? ");
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        printf("Ingrese el valor #%d: ", i + 1);
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\nRecorridos\n");
    printf("Inorder (orden ascendente): ");
    inorder(root);
    printf("\n");

    printf("Preorder: ");
    preorder(root);
    printf("\n");

    printf("Postorder: ");
    postorder(root);
    printf("\n");

    // Búsqueda de claves
    int to_find1, to_find2;
    printf("\nIngrese 2 valores a buscar en el árbol: ");
    scanf("%d %d", &to_find1, &to_find2);

    struct Node* found1 = search(root, to_find1);
    if (found1)
        printf("Clave %d encontrada en el árbol.\n", to_find1);
    else
        printf("Clave %d NO encontrada en el árbol.\n", to_find1);

    struct Node* found2 = search(root, to_find2);
    if (found2)
        printf("Clave %d encontrada en el árbol.\n", to_find2);
    else
        printf("Clave %d NO encontrada en el árbol.\n", to_find2);

    // Liberar memoria
    free_tree(root);

    return 0;
}
