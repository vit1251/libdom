#include <stdio.h>
#include <string.h>

#include "libdom.h"

int main()
{
    dom_node_t *root = NULL;
    dom_node_t *child1 = NULL;
    dom_node_t *child2 = NULL;
    char *content = NULL;
    int rc;

    // Create root node
    root = dom_node_new();
    dom_node_set_name(root, "root");

    child1 = dom_node_new();
    dom_node_set_name(child1, "name");
    dom_node_add_child(root, child1);
    dom_node_release(child1);

    child2 = dom_node_new();
    dom_node_set_name(child2, "value");
    dom_node_add_child(root, child2);
    dom_node_release(child2);

    // Prepare XML document
    content = dom_node_to_string(root);
    fprintf(stdout, "XML = %s", content);
    free(content);

    //dom_node_add_child(root, value1);
    dom_node_release(root);

    // Complete
    rc = 0;

  out:

    return rc;
}
