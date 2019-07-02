
#include "common.h"


dom_doc_t *dom_doc_new(void)
{
    dom_doc_t *d = NULL;
    d = malloc(sizeof(*d));
    if (d==NULL) {
        goto out;
    }
    d->ref_count = 1;
  out:
    return d;
}

static void dom_doc_free(dom_doc_t *d)
{
    free(d);
}

void dom_doc_release(dom_doc_t *d)
{
    if (d->ref_count > 1) {
        d->ref_count --;
    } else {
        dom_doc_free(d);
    }
}
