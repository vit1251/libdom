
#include "common.h"

int main()
{
    dom_node_t *root = NULL;
    dom_node_t *node = NULL;
    char buff[BUFF];
    char *arg[ARG];
    char *cmd;
    char *p;
    int i=0;
    int len;
    int msg = 0;

    node = root;
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
	    dom_node_t *temp = NULL;

            temp = (dom_node_t *)malloc(sizeof(dom_node_t));
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
