struct node {
	char *nodeName;
	char *nodeValue;
	int nodeType;
	struct node *parentNode;
	struct node *firstChild;
	struct node *lastChild;
	struct node *previousSibling;
	struct node *nextSibling;
	void *attributes;
};

#define ELEMENT_NODE         1
#define ATTRIBUTE_NODE       2
#define TEXT_NODE            3
#define CDATA_SECTION_NODE   4
#define COMMENT_NODE         8
#define DOCUMENT_NODE        9
#define DOCUMENT_TYPE_NODE  10

struct node *inserBefore(struct node *nodeNew, struct node *nodeOld);
/* struct node *replaceChild(struct node *nodeNew, struct node *nodeOld); */
/* struct node *removeChild(struct node *node); */
struct node *appendChild(struct node *nodeRoot, struct node *nodeAppend);
int hasChildNodes(struct node *node);
/* struct node *cloneNode(struct node *node); */

/* void setAttribute(struct node *node, char *attrName, char *attrValue); */
