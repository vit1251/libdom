
#include "common.h"

int getLength(void *attributes)
{
    struct attr *attr = NULL;
    int cnt = 0;

    if (attributes == NULL) {
        return cnt;
    }

    attr = (struct attr *)attributes;
    while (attr->name || attr->value) {
        cnt++; attr++;
    }

    return cnt;
}

int setAttribute(dom_node_t *node, char *attrName, char *attrValue)
{
    struct attr *attr = NULL;
    void *temp=NULL;
    int cnt=0;

    cnt = getLength(node->attributes);
    fprintf(stderr, "debug: attr.length is %d (%d)\n", cnt);

    if (cnt == 0) {
        node->attributes = (void *)malloc(2*sizeof(struct attr));
        attr = node->attributes;

    } else {
        node->attributes = (void *)realloc(node->attributes, (cnt + 2)*sizeof(struct attr));
        attr = node->attributes;

        while (attr->name || attr->value)
            attr++;
    }

    attr->name = attrName;
    attr->value = attrValue;
    attr++;
    attr->name = NULL;
    attr->value = NULL;
}

char *getAttribute(dom_node_t *node, char *attrName)
{
    struct attr *attr = NULL;

    attr = node->attributes;
    while ( attr && (attr->name || attr->value) ) {

        if ( strcmp(attrName, attr->name) == 0 ) {
            return attr->name;
        }

        attr++;
    }

    return NULL;
}
