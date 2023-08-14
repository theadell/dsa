#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <assert.h>

typedef struct Node Node;

struct Node{
  Node* children[256];
};

#define NODE_POOL_CAP 1024
Node node_pool[NODE_POOL_CAP] = {0};
size_t node_pool_count = 0;


Node* alloc_node() {
  assert(node_pool_count < NODE_POOL_CAP);
  return &node_pool[node_pool_count++];
}

void insert_text(Node* root, const char* text) {
  if (*text == '\0' || text == NULL) {
    return; 
  }
  assert(root != NULL);

  size_t idx = (size_t)*text;
  if(root->children[idx] == NULL) {
    root->children[idx] = alloc_node();
  }
  insert_text(root->children[idx], text +1);
}

int main() {
  Node* root = alloc_node();
  insert_text(root, "Hello");
  return 0;
}
