
#include "common.h"

dom_node_t *dom_node_new()
{
    dom_node_t *n = NULL;
    n = malloc(sizeof(*n));
    if (n==NULL) {
        goto out;
    }
    n->ref_count = 1;
    n->nodeName = NULL;
    n->nodeValue = NULL;
    n->nodeType = 0;
    n->parentNode = NULL;
    n->firstChild = NULL;
    n->lastChild = NULL;
    n->previousSibling = NULL;
    n->nextSibling = NULL;
    n->attributes = NULL;
  out:
    return n;
}


//dom_node_t *insertBefore(dom_node_t *nodeNew, dom_node_t *nodeRef)
//{
//}

//dom_node_t *replaceChild(dom_node_t *nodeNew, dom_node_t *nodeOld)
//{
//}

//dom_node_t *removeChild(dom_node_t *nodeChild)
//{
//	dom_node_t *nodeIterator=NULL;
//
//	if (nodeChild == NULL)
//		return NULL;
//
//	if (nodeChild->parentNode == NULL)
//		return NULL;
//
//	nodeIterator = nodeChild->parentNode->firstChild;
//	while (nodeIterator != NULL) {
//		if (nodeIterator == nodeChild) {
//			dom_node_t *nodePrevious = NULL;
//			dom_node_t *nodeNext = NULL;
//
//			nodePrevious = nodeIterator->previousSibling;
//			nodeNext = nodeIterator->nextSibling;
//
//			nodePrevious->nextSibling = nodeNext;
//			nodeNext->previousSibling = nodePrevious;
//
//			nodeChild->nextSibling = NULL;
//			nodeChild->previousSibling = NULL;
//			nodeChild->parentNode = NULL;
//
//			break;
//		}
//
//		nodeIterator = nodeIterator->nextSibling;
//	}
//
//	return nodeIterator;
//}

int dom_node_add_child(dom_node_t *n, dom_node_t *child)
{
    int rc;

    if (n==NULL) {
        rc = 1;
        goto out;
    }
    if (child==NULL) {
        rc = 1;
        goto out;
    }

    child->ref_count += 1;

    if (n->firstChild==NULL) {
        n->firstChild = child;
        n->lastChild = child;
    } else {
        child->previousSibling = n->lastChild;
        n->lastChild->nextSibling = child;
        n->lastChild = child;
    }
    child->parentNode = n;

    rc = 0;
  out:
    return rc;
}

int dom_node_set_name(dom_node_t *n, char *name)
{
    int rc;
    if (n==NULL) {
        rc=1;
        goto out;
    }
//    if (n->nodeType) {
//    }
//    n->nodeType = 0;

    // Release node name
    if (n->nodeName!=NULL) {
        free(n->nodeName);
        n->nodeName = NULL;
    }

    // Set new node name
    if (name!=NULL) {
        n->nodeName = strdup(name);
    }

    // Complete
    rc = 0;
  out:
    return rc;
}

static void dom_node_free(dom_node_t *n)
{
    if (n->nodeName != NULL) {
        free(n->nodeName);
        n->nodeName = NULL;
    }
    free(n);
}

void dom_node_release(dom_node_t *n)
{
    if (n->ref_count > 1) {
        n->ref_count --;
    } else {
        dom_node_free(n);
    }
}
