struct attr {
    char *name;
    char *value;
};

/* int getLength(dom_node_t *root); */
char *getAttribute(dom_node_t *root, char *attrName);
int setAttribute(dom_node_t *root, char *attrName, char *attrValue);
/* removeAttribute(dom_node_t *root, char *attrName); */
int hasAttribute(dom_node_t *root, char *attrName);
