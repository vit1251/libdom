#include <stdio.h>
#include <stdlib.h>

#include "dom.h"
#include "attr.h"
#include "util.h"

#include "dump.h"

char *nodeType[] = {
        "UNKNOWN",
        "ELEMENT_NODE",
        "ATTRIBUTE_NODE",
        "TEXT_NODE",
        "CDATA_SECTION_NODE"
    };


void show(struct node *nodeProc)
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


void dump(struct node *nodeProc, int nLevel)
{
    struct node *iterator = NULL;

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

#define BUFF 64
#define ARG 8

int idump(struct node *root)
{
    struct node *node = NULL;

    char buff[BUFF];
    char *arg[ARG];
    char *cmd;
    char *p;
    int i=0;
    int len;
    int msg = 0;

    node=root;
    do {
        fprintf(stderr, "DOM> ");

        fgets(buff, sizeof(buff), stdin);
        len=strlen(buff);

        if ((buff[len-1] == '\n') || (buff[len-1] == '\r'))
            buff[--len]='\0';

        for(i=0; i < ARG; i++)
            arg[i]=NULL;

        arg[0] = cmd = p = buff;
        i=0;
        while (p = strchr(p, ' ')) {
            *p='\0'; i++; p=p+1;
            if (i < ARG)
                arg[i]=p; else
                fprintf(stderr, "warning: line too long\n");
        }

//        for(i=0; i < ARG; i++)
//            fprintf(stderr, "dump: arg %d is %s\n", i, arg[i]);

        // DOM Command

        if (strncmp(cmd, "insertBefore", 10) == 0) {
        } else
	if (strncmp(cmd, "insertAfter", 10) == 0) {
        } else
        if (strcmp(cmd, "appendChild") == 0) {
	    struct node *temp = NULL;

            temp = (struct node *)malloc(sizeof(struct node));
            if (temp == NULL) {
                fprintf(stderr, "error: no memory.\n");
                continue;
            }
            temp->nodeName = temp->nodeValue = NULL;
            temp->nodeType = 0;
            temp->firstChild = temp->lastChild = NULL;
            temp->previousSibling = temp->nextSibling = NULL;
            temp->attributes = NULL;

            node = appendChild(node, temp);
        } else

        // Internal command

        if (strcmp(cmd, "prev") == 0) {
            if (node->previousSibling)
                node = node->previousSibling; else
                fprintf(stderr, "warning: no previousSibling!\n");
	} else
	if (strcmp(cmd, "next") == 0) {
            if (node->nextSibling)
                node = node->nextSibling; else
                fprintf(stderr, "warning: no nextSibling!\n");
        } else

	if (strcmp(cmd, "first") == 0) {
            if (node->firstChild)
                node = node->firstChild; else
                fprintf(stderr, "warning: no firstChild!\n");
	} else
        if (strcmp(cmd, "last") == 0) {
            if (node->lastChild)
                node = node->lastChild; else
                fprintf(stderr, "warning: no lastChild!\n");
                
	} else

        if (strcmp(cmd, "parent") == 0) {
            if (node->parentNode != NULL)
                node=node->parentNode; else
                fprintf(stderr, "warning: no parentNode!\n");
        } else

	// DUMP Commnd

	if (strcmp(cmd, "attr") == 0) {
            struct attr *attr = NULL;

            // Do some
            
            if (arg[1] && arg[2]) {
                setAttribute(node, strdup(arg[1]), strdup(arg[2]));
            } else
            if (arg[1]) {
                getAttribute(node, arg[1]);
            } else {

                attr = (struct attr *)node->attributes;
                while (attr && (attr->name || attr->value)) {
                    fprintf(stdout, "\t'%s'='%s'\n", attr->name, attr->value);
                
                    attr++;
                }
                
            }

        } else
        if (strcmp(cmd, "tree") == 0) {
            dump(node, 0);
        } else
        if (strcmp(cmd, "show") == 0) {
            show(node);
        } else
        if (strcmp(cmd, "quit") == 0) {
            msg=1;
        } else
        if (strcmp(cmd, "help") == 0) {
            fprintf(stdout, "Command:\n");
            fprintf(stdout, "\tinsertBefore\tinsert before current new text node\n");
            fprintf(stdout, "\tinsertAfter\tinsert after current new text node\n");

			fprintf(stdout, "\tappendChild\tappend child to current node\n");

			fprintf(stdout, "Navigation:\n");

//			fprintf(stdout, "\tprevious\n");
//			fprintf(stdout, "\tnext\n");
			fprintf(stdout, "\tfirstChild\tmove to first child\n");
			fprintf(stdout, "\tlastChild\tmode to last child\n");

			fprintf(stdout, "\tparent\tmove to parent node\n");

			fprintf(stdout, "Dump:\n");
			fprintf(stdout, "\tattr\tshow attributes (current node)\n");
			fprintf(stdout, "\ttree\tshow tree (from current node)\n");
			fprintf(stdout, "\tshow\tshow info (current node)\n");
			fprintf(stdout, "\tquit\t\n");
        } else

        // Other

        {
            fprintf(stdout, "Unknown command.\n");
        }


    } while ( msg == 0 && !feof(stdin) );

    return 0;
}
