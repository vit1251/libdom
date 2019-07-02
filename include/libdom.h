
/* dom */

typedef struct dom_doc_t dom_doc_t;

dom_doc_t *dom_doc_new(void);
void dom_doc_release(dom_doc_t *d);

/* dom node */

typedef struct dom_node_t dom_node_t;

dom_node_t *dom_node_new(void);
int dom_node_add_child(dom_node_t *n, dom_node_t *child);
void dom_node_release(dom_node_t *n);
