#include <stdio.h>
#include <string.h>

#include "dom.h"
#include "error.h"

struct node *nodeRoot = NULL;

int main()
{
    nodeRoot = (struct node *)malloc(sizeof(struct node));
    if (nodeRoot == NULL) {
        return ERROR_MALLOC;
    }

    nodeRoot->nodeName = nodeRoot->nodeValue = NULL;
    nodeRoot->nodeType = CDATA_SECTION_NODE;
    nodeRoot->firstChild = nodeRoot->lastChild = NULL;
    nodeRoot->previousSibling = nodeRoot->nextSibling = NULL;
    nodeRoot->parentNode = NULL;
    nodeRoot->attributes = NULL;

    idump(nodeRoot);

    return 0;
}
