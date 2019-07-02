
#include "common.h"

#include "main.h"


static char *prompt = "DOM> ";

/**
 * Read input and return memory chunk
 *
 */
static char *readInput(void)
{
    char buff[BUFF];

    fprintf(stdout, prompt);
    fflush(stdout);

    fgets(buff, sizeof(buff), stdin);

    if (feof(stdin)) {
        exit(1);
    }

    return strdup(buff);
}

/**
 * Parse arguments
 */
static void parseInput(const char *input)
{
    int len;

    len = strlen(input);

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
}

struct args_t {
    int count;
    char *args[];
}

static void dumpArgs(struct args_t *args)
{
    int i;

    for(i=0; i < ARG; i++) {
        fprintf(stdout, "dump: arg %d is %s\n", i, arg[i]);
    }
}




static void _debug_prev(struct args_t *args, dom_node_t *root, dom_node_t *node)
{
    if (node->previousSibling) {
        node = node->previousSibling;
    } else {
        fprintf(stderr, "warning: no previousSibling!\n");
    }
}

static void _debug_next(struct args_t *args, dom_node_t *root, dom_node_t *node)
{
    if (node->nextSibling) {
        node = node->nextSibling;
    } else {
        fprintf(stderr, "warning: no nextSibling!\n");
    }
}

//	if (strcmp(cmd, "first") == 0) {
//            if (node->firstChild)
//                node = node->firstChild; else
//                fprintf(stderr, "warning: no firstChild!\n");
//	} else
//        if (strcmp(cmd, "last") == 0) {
//            if (node->lastChild)
//                node = node->lastChild; else
//                fprintf(stderr, "warning: no lastChild!\n");
//                
//	} else
//
//        if (strcmp(cmd, "parent") == 0) {
//            if (node->parentNode != NULL)
//                node=node->parentNode; else
//                fprintf(stderr, "warning: no parentNode!\n");
//        } else

static void _debug_help(struct args_t *args, dom_node_t *root, dom_node_t *node)
{

    fprintf(stdout, "Command:\n");
    fprintf(stdout, "\tinsertBefore\tinsert before current new text node\n");
    fprintf(stdout, "\tinsertAfter\tinsert after current new text node\n");

    fprintf(stdout, "\tappendChild\tappend child to current node\n");

    fprintf(stdout, "Navigation:\n");

    fprintf(stdout, "\tprevious\n");
    fprintf(stdout, "\tnext\n");
    fprintf(stdout, "\tfirstChild\tmove to first child\n");
    fprintf(stdout, "\tlastChild\tmode to last child\n");

    fprintf(stdout, "\tparent\tmove to parent node\n");

    fprintf(stdout, "Dump:\n");
    fprintf(stdout, "\tattr\tshow attributes (current node)\n");
    fprintf(stdout, "\ttree\tshow tree (from current node)\n");
    fprintf(stdout, "\tshow\tshow info (current node)\n");
    fprintf(stdout, "\tquit\t\n");

}

static void _debug_set_attr()
{
    struct dom_attr_t *attr = NULL;

    // Guard input value
    if (arg[1] && arg[2]) {
    }

    // Set node attribute
    setAttribute(node, arg[1], arg[2]);

}

static void _debug_show_attrs()
{
    struct dom_attr_t *attr = NULL;
    int i;

    for (i=0; i < 10; i++) {
        attr = node->attributes[i];

        fprintf(stdout, "  %s = %s\n", attr->name, attr->value);
    }

}

static void _debug_append_child(struct args_t *args, dom_node_t *root, dom_node_t *node)
{
    dom_node_t *temp = NULL;

    temp = (dom_node_t *)malloc(sizeof(dom_node_t));
    if (temp == NULL) {
        fprintf(stderr, "error: no memory.\n");
        exit(1);
    }
    temp->nodeName = temp->nodeValue = NULL;
    temp->nodeType = 0;
    temp->firstChild = temp->lastChild = NULL;
    temp->previousSibling = temp->nextSibling = NULL;
    temp->attributes = NULL;

    node = appendChild(node, temp);
}

struct operation_t ops {

    // Construction

    {"insertBefore", _debug_insert_before, ""},
    {"insertAfter", NULL, ""},

    {"appendChild", _debug_append_child, ""},

    // Navigation

    {"prev", _debug_prev, ""},
    {"next", _debug_next, ""},

    {NULL, NULL, NULL}
};

static void processCommand(struct args_t *args, dom_node_t *root, dom_node_t *node)
{
    int i;
    for (i=0; i < 10; i++) {
    }
}

int main()
{
    dom_node_t *root = NULL;
    char *input = NULL;
    struct args_t args;

    for (;;) {

        // Process input
        input = readInput();

        // Parse parameters
        parseInput(input, &args);

        // Dump arguments
        dumpArgs(&args);

        // Process command
        processCommand(&args, root);

        // Release memory
        releaseInput(input);
        releaseArguments(&args)

    }

    return 0;
}
