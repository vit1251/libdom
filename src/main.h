
#define BUFF 64
#define ARG 8

typedef void (*op_cb_t)(void);

struct operation_t {
    char *name;
    op_cb_t cb;
    char *help;
};
