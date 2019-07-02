#include "common.h"

char *nodeType[] = {
        "UNKNOWN",
        "ELEMENT_NODE",
        "ATTRIBUTE_NODE",
        "TEXT_NODE",
        "CDATA_SECTION_NODE"
};

void show(dom_node_t *nodeProc)
{
    if (nodeProc == NULL)
        return;

    fprintf(stdout, "Memory locattion: 0x%X\n", nodeProc);

    fprintf(stdout, "nodeName: %s\n", nodeProc->nodeName);
    fprintf(stdout, "nodeValue: %s\n", nodeProc->nodeValue);
    fprintf(stdout, "nodeType: %s\n", nodeType[nodeProc->nodeType]);
    fprintf(stdout, "parentNode: 0x%X\n", nodeProc->parentNode);
    fprintf(stdout, "firstChild: 0x%X\n", nodeProc->firstChild);
    fprintf(stdout, "lastChild: 0x%X\n", nodeProc->lastChild);
    fprintf(stdout, "previousSibling: 0x%X\n", nodeProc->previousSibling);
    fprintf(stdout, "nextSibling: 0x%X\n", nodeProc->nextSibling);
    fprintf(stdout, "attributes: 0x%X\n", nodeProc->attributes);
}


void dump(dom_node_t *nodeProc, int nLevel)
{
    dom_node_t *iterator = NULL;

    if (nodeProc == NULL)
        return;

    iterator = nodeProc;
    while (iterator != NULL) {
        int i;

        for(i=0; i < nLevel; i++)
            fprintf(stdout, "|\t");

        fprintf(stdout, "+ 0x%X\t%s\t%s\n", iterator, nodeType[iterator->nodeType], iterator->nodeName);
        if (hasChildNodes(iterator)) {
            dump(iterator->firstChild, nLevel+1);
        }

        iterator = iterator->nextSibling;
    }
}
