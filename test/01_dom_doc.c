#include <stdio.h>
#include <string.h>

#include "libdom.h"

int main()
{
    dom_doc_t *doc = NULL;
    int rc;

    // Create DOM document
    doc = dom_doc_new();
    if (doc==NULL) {
        rc = 1;
        goto out;
    }

    // Complete
    rc = 0;

  out:

    // Release DOM document
    if (doc!=NULL) {
        dom_doc_release(doc);
        doc=NULL;
    }
    return rc;
}
