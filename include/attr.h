struct attr {
    char *name;
    char *value;
};

/* int getLength(struct node *root); */
char *getAttribute(struct node *root, char *attrName);
int setAttribute(struct node *root, char *attrName, char *attrValue);
/* removeAttribute(struct node *root, char *attrName); */
int hasAttribute(struct node *root, char *attrName);
