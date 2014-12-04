#include <stdio.h>

#include "dom.h"
#include "error.h"

#include "util.h"

struct node *insertAfter(struct node *nodeNew, struct node *nodeRef)
{
    if (nodeNew == NULL)
	return NULL;

    if (nodeRef == NULL)
	return NULL;

    struct node *parentNode = nodeRef->parentNode;
    struct node *nodeNext = nodeRef->nextSibling;

    if (nodeNext != NULL)
	insertBefore(nodeNew, nodeRef); else
	appendChild(parentNode, nodeNew);

    return NULL;
}

struct node *getFirstChild(struct node *nodeRoot)
{
    if (nodeRoot == NULL)
	return NULL;

    return nodeRoot->firstChild;
}

struct node *getLastChild(struct node *nodeRoot)
{
    if (nodeRoot == NULL)
	return NULL;

    return nodeRoot->lastChild;
}

struct node *getNextSibling(struct node *nodeSibling)
{
    if (nodeSibling == NULL)
	return NULL;

    return nodeSibling->nextSibling;
}

char *getNodeName(struct node *node)
{
    if (node == NULL)
	return NULL;

    return node->nodeName;
}

struct node *getParentNode(struct node *nodeChild)
{
    if (nodeChild == NULL)
        return NULL;

    return nodeChild->parentNode;
}

struct node *getPreviousSibling(struct node *nodeSibling)
{
    if (nodeSibling == NULL)
        return NULL;

    return nodeSibling->previousSibling;
}

void setNodeValue(struct node *nodeRoot, char *nodeName)
{
    if (nodeRoot == NULL)
        return;

    if (nodeRoot->nodeValue != NULL)
        free(nodeRoot->nodeValue);

    nodeRoot->nodeValue = strdup(nodeName);
}
