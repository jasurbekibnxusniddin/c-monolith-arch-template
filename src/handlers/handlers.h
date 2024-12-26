#ifndef HANDLERS_H
#define HANDLERS_H

#include <microhttpd.h>

enum MHD_Result ping(void *cls, struct MHD_Connection *connection);
enum MHD_Result not_found(void *cls, struct MHD_Connection *connection);

#endif