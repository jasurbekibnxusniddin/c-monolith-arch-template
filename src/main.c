#include "db/postgres.h"
#include "router/router.h"

int main() {
    //PGconn *conn =connect();

    server();
    //printf("Connection: %p\n", conn);

  //  PQfinish(conn);
    return 0;
}