#include "db.hpp"

using namespace std;

PGconn* conectarDB(char* server,  int puerto, char* db, char* user, char* password )
{
    PGconn* conn = NULL;
    char* parametrosDB = new char[256]; // eso es c++ xd // estamos en c/c++ es un nuevo mundo
    memset(parametrosDB, 0,sizeof(parametrosDB)); // Inicializar los valores del array
    sprintf(parametrosDB, "host = '%s' port = '%d' dbname = '%s' user = '%s' password = '%s'", server, puerto, db, user, password);
    conn = PQconnectdb(parametrosDB); // Conectar a pgsql
    
    if( PQstatus(conn) != CONNECTION_OK)
    {
        cout << "Fail! no logramos conectarnos a Postgres! :(" << endl;
        cerrarConexion(conn);
        conn = NULL;
    }

    //habemus patria! habemus conexion :D
    // But they'll never take OUR FREEDOM!
    return conn;
}

PGresult* query(PGconn* conex, char* sql)
{
    return PQexec(conex, sql); // Que sea lo que dios quiera
}

long cantResultados(PGresult* res)
{
    long count = 0;
    char *rowCount = PQcmdTuples(res); // PQcmdTuples da la cantidad de filas, pero en char*
    sscanf(rowCount,"%li", &count); // Encuentra lo que primero se asemeje a un long integer
    return count;
}

void cerrarConexion(PGconn* conn)
{
    PQfinish(conn);
}

char* filaToString(PGresult* res, long fila, int columna)
{
    char * str = NULL; // dolor de cabeza
    if(res != NULL)
        str = PQgetvalue(res, fila, columna);
    return str;
}

void limpiarRes(PGresult* res)
{
    PQclear(res);
}
