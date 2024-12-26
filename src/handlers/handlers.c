#include <string.h>
#include "microhttpd.h"

enum MHD_Result ping(void *cls, struct MHD_Connection *connection) {

    const char *response_text = "<html><body><h1>pong</h1></body></html>";
    
    struct MHD_Response *response;
    {
        response = MHD_create_response_from_buffer(
            strlen(response_text), 
            (void *)response_text, 
            MHD_RESPMEM_PERSISTENT
        );
    }
    
    enum MHD_Result ret;
    {
        ret = MHD_queue_response(
            connection, 
            MHD_HTTP_OK, 
            response
        );
    }
   
    MHD_destroy_response(response);
    
    return ret;
}

enum MHD_Result not_found(void *cls, struct MHD_Connection *connection) {
    
    const char *response_text = "<html><body><h1>404 Not Found</h1></body></html>";
    
    struct MHD_Response *response;
    {
        response = MHD_create_response_from_buffer(
            strlen(response_text), 
            (void *)response_text, 
            MHD_RESPMEM_PERSISTENT
        );
    }
    
    enum MHD_Result ret;
    {
        ret = MHD_queue_response(
            connection, 
            MHD_HTTP_NOT_FOUND, 
            response
        );
    }
    
    MHD_destroy_response(response);
    
    return ret;
}