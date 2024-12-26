#ifndef ROUTER_H
#define ROUTER_H

#include <microhttpd.h>

enum MHD_Result router(const char *method, const char *url, void *cls, struct MHD_Connection *connection);

#endif