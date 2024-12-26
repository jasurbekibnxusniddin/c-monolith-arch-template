#include "db/postgres.h"
#include "server/server.h"

int main() {
    PGconn *conn = pg_connect(); 

    server();
    printf("Connection: %p\n", conn);

    PQfinish(conn);
    return 0;
}