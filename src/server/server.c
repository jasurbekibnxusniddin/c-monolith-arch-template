#include "server.h"
#include <microhttpd.h>
#include "../router/router.h"

#define PORT 8080

static enum MHD_Result apc_cls(
    void *cls, 
    struct MHD_Connection *connection,                         
    const char *url, 
    const char *method,
    const char *version, 
    const char *upload_data,
    size_t *upload_data_size, 
    void **con_cls ) {
    
    return router(method, url, cls, connection);   
}

int server() {
    
    struct MHD_Daemon *daemon;
    {
        daemon = MHD_start_daemon(
            MHD_USE_THREAD_PER_CONNECTION, 
            PORT, NULL, NULL,
            &apc_cls, NULL, 
            MHD_OPTION_END
        );

        if (NULL == daemon)
        return 1;
    }

    getchar();
    
    MHD_stop_daemon(daemon);
    
    return 0;
}
