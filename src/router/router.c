#include <stdio.h>
#include <string.h>
#include "microhttpd.h"
#include "../handlers/handlers.h"

#define PORT 8888

enum MHD_Result router(const char *method, const char *url, void *cls, struct MHD_Connection *connection) {
        
    if (strcmp(url, "/ping") == 0 && strcmp(method, "GET") == 0) {
        return ping(cls, connection);
    } else {
        return not_found(cls, connection);
    }
}   