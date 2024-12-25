#include <stdio.h>
#include <string.h>
#include "microhttpd.h"
#include "handlers/handlers.h"

#define PORT 8888

static enum MHD_Result answer_to_request(
    void *cls, 
    struct MHD_Connection *connection,                         
    const char *url, 
    const char *method,
    const char *version, 
    const char *upload_data,
    size_t *upload_data_size, 
    void **con_cls ) {
    
    if ((strcmp(url, "/ping") == 0) && (strcmp(method, "GET") == 0)) {
        return handle_ping(cls, connection);
    }
    
    const char *response_text = "<html><body>404 Not Found</body></html>";

    struct MHD_Response *response;
    response = MHD_create_response_from_buffer(strlen(response_text), (void *)response_text, MHD_RESPMEM_PERSISTENT);
    int ret = MHD_queue_response(connection, MHD_HTTP_NOT_FOUND, response);
    
    MHD_destroy_response(response);
    
    return ret;
}

int server() {
    
    struct MHD_Daemon *daemon;

    daemon = MHD_start_daemon(
                MHD_USE_THREAD_PER_CONNECTION, 
                PORT, NULL, NULL,
                &answer_to_request, NULL, 
                MHD_OPTION_END
            );

    if (NULL == daemon)
        return 1;

    getchar();
    
    MHD_stop_daemon(daemon);
    
    return 0;
}
