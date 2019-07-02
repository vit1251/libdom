
enum dom_node_type_t {
    ELEMENT_NODE         = 1,
    ATTRIBUTE_NODE       = 2,
    TEXT_NODE            = 3,
    CDATA_SECTION_NODE   = 4,
    COMMENT_NODE         = 8,
    DOCUMENT_NODE        = 9,
    DOCUMENT_TYPE_NODE   = 10,
};

struct dom_node_t {

    int ref_count;

    enum dom_node_type_t nodeType;

    char *nodeName;
    char *nodeValue;

    dom_node_t *parentNode;
    dom_node_t *firstChild;
    dom_node_t *lastChild;
    dom_node_t *previousSibling;
    dom_node_t *nextSibling;

    void *attributes;
};

