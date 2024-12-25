#include <stdio.h>
#include <libpq-fe.h>

PGconn* connect() {
    
    PGconn *conn = PQconnectdb("user=postgres dbname=postgres password=postgres");

    if (PQstatus(conn) == CONNECTION_BAD) {
        fprintf(stderr, "Connection to database failed: %s", PQerrorMessage(conn));
        PQfinish(conn);
        return NULL;
    }

    printf("Connected to the database successfully!\n");
    //PQfinish(conn);
    return conn;
}
