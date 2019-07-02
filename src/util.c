
#include "common.h"

dom_node_t *insertAfter(dom_node_t *nodeNew, dom_node_t *nodeRef)
{
    if (nodeNew == NULL)
	return NULL;

    if (nodeRef == NULL)
	return NULL;

    dom_node_t *parentNode = nodeRef->parentNode;
    dom_node_t *nodeNext = nodeRef->nextSibling;

    if (nodeNext != NULL)
	insertBefore(nodeNew, nodeRef); else
	appendChild(parentNode, nodeNew);

    return NULL;
}

dom_node_t *getFirstChild(dom_node_t *nodeRoot)
{
    if (nodeRoot == NULL)
	return NULL;

    return nodeRoot->firstChild;
}

dom_node_t *getLastChild(dom_node_t *nodeRoot)
{
    if (nodeRoot == NULL)
	return NULL;

    return nodeRoot->lastChild;
}

dom_node_t *getNextSibling(dom_node_t *nodeSibling)
{
    if (nodeSibling == NULL)
	return NULL;

    return nodeSibling->nextSibling;
}

char *getNodeName(dom_node_t *node)
{
    if (node == NULL)
	return NULL;

    return node->nodeName;
}

dom_node_t *getParentNode(dom_node_t *nodeChild)
{
    if (nodeChild == NULL)
        return NULL;

    return nodeChild->parentNode;
}

dom_node_t *getPreviousSibling(dom_node_t *nodeSibling)
{
    if (nodeSibling == NULL)
        return NULL;

    return nodeSibling->previousSibling;
}

void setNodeValue(dom_node_t *nodeRoot, char *nodeName)
{
    if (nodeRoot == NULL)
        return;

    if (nodeRoot->nodeValue != NULL)
        free(nodeRoot->nodeValue);

    nodeRoot->nodeValue = strdup(nodeName);
}
