#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <assert.h>
#include <string.h>
#include "fruits.h"
#define ARRAY_LEN(xs) (sizeof(xs) / sizeof((xs)[0])) 

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

// DOT is a graph description language. Tools like Graphviz can read DOT 
// anguage files and generate visualizations of graphs. 
void dump_dot(Node *root) {
  size_t index = root - node_pool;
  for (size_t i = 0; i < ARRAY_LEN(root->children); ++i) {
    if (root->children[i] != NULL) {
      size_t child_index = root->children[i] - node_pool;
      printf("  Node_%zu [label=\"%c\"]\n", child_index, (char) i);
      printf("   Node_%zu -> Node_%zu\n [label=\"%c\"]",index,child_index,(char) i);
      dump_dot(root->children[i]);
    }
  }
}

void usage(FILE *sink) {
  fprintf(sink, "Usage: ./trie <SUBCOMMAND>\n");
  fprintf(sink, "SUBCOMMANDS:\n");
  fprintf(sink, "   dot                     Dump the Trie into a Graphviz dot file\n");
  fprintf(sink, "   complete <prefix>       Suggest perfix autocompletion based on Trie.\n");
}
int main(int argc, char **argv) {

  if (argc <2 ) {
    usage(stderr);
    fprintf(stderr, "ERROR: no subcommand is provided\n");
    exit(1);
  }

  const char *subcommand = argv[1];

  if (strcmp(subcommand, "dot") == 0) {
   
  
  Node* root = alloc_node();
  for (size_t i = 0; i < fruits_count; ++i) {
    insert_text(root, fruits[i]);
  }
  printf("digraph Trie {\n");
  printf("   Node_%zu [label=root]\n",root -node_pool);
  dump_dot(root);
  printf("}\n");
  } else if (strcmp(subcommand, "complete") == 0 ) {
    assert(0 && "TODO: complete subcommand is not yet implemented\n");
  } else {
    usage(stderr);
    fprintf(stderr, "ERROR: unknown command `%s`\n",subcommand);
    exit(1);
  }
}
