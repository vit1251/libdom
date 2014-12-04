#include <stdlib.h>
#include <string.h>

#include "dom.h"


struct node *insertBefore(struct node *nodeNew, struct node *nodeRef)
{
}

struct node *replaceChild(struct node *nodeNew, struct node *nodeOld)
{
	/* modyfy nodeNew->last next */
	/* free nodeOld */
	/* set nodeNew */

	return nodeNew;
}

struct node *removeChild(struct node *nodeChild)
{
	struct node *nodeIterator=NULL;

	if (nodeChild == NULL)
		return NULL;

	if (nodeChild->parentNode == NULL)
		return NULL;

	nodeIterator = nodeChild->parentNode->firstChild;
	while (nodeIterator != NULL) {
		if (nodeIterator == nodeChild) {
			struct node *nodePrevious = NULL;
			struct node *nodeNext = NULL;

			nodePrevious = nodeIterator->previousSibling;
			nodeNext = nodeIterator->nextSibling;

			nodePrevious->nextSibling = nodeNext;
			nodeNext->previousSibling = nodePrevious;

			nodeChild->nextSibling = NULL;
			nodeChild->previousSibling = NULL;
			nodeChild->parentNode = NULL;

			break;
		}

		nodeIterator = nodeIterator->nextSibling;
	}

	return nodeIterator;
}

struct node *appendChild(struct node *nodeRoot, struct node *nodeAppend)
{
	struct node *nodeNew = NULL;

	/* If nodeRoot == NULL then fail */
	if (nodeRoot == NULL)
		return NULL;

	/* If nodeAppend == NULL then fail */
	if (nodeAppend == NULL)
		return NULL;

	/* Create new node entry */
	nodeNew = (struct node *)malloc(sizeof(struct node));
	if (nodeNew == NULL)
		return NULL;

	/* Set node field */
	nodeNew->nodeName = nodeAppend->nodeName?strdup(nodeAppend->nodeName):NULL;
	nodeNew->nodeValue = NULL;
	nodeNew->nodeType = 0;
	nodeNew->parentNode = nodeRoot;
	nodeNew->firstChild = NULL;
	nodeNew->lastChild = NULL;
	nodeNew->previousSibling = NULL;
	nodeNew->nextSibling = NULL;
	nodeNew->attributes = NULL;

	/* If first child */
	if (nodeRoot->firstChild == NULL) {
		nodeRoot->firstChild = nodeNew;
		nodeRoot->lastChild = nodeNew;
	} else {
		nodeNew->previousSibling = nodeRoot->lastChild;
		nodeRoot->lastChild->nextSibling = nodeNew;
		nodeRoot->lastChild = nodeNew;
	}

	return nodeNew;
}

int hasChildNodes(struct node *node)
{
	if (node == NULL)
		return 0;

	return node->firstChild?1:0;
}

struct node *cloneNode(struct node *node)
{
	struct node *nodeNew = NULL;

	if (node == NULL)
		return NULL;

	/* Create new node entry */
	nodeNew = (struct node *)malloc(sizeof(struct node));
	if (nodeNew == NULL)
		return NULL;

	nodeNew->nodeName=strdup(node->nodeName);
	/* ... */

	return nodeNew;
}
