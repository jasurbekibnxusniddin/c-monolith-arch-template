#include "db/postgres.h"

int main() {
    PGconn *conn =connect();

    printf("Connection: %p\n", conn);

    PQfinish(conn);
    return 0;
}