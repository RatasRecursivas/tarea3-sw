#include <postgresql/libpq-fe.h>
#include <cstring>
#include <cstdio>
#include <iostream>

PGconn* conectarDB(char* server, int puerto, char* db, char* user, char* password); // Conexion a la db
PGresult* query(PGconn* conex, char* sql); // Realiza un query sql desde un string c
long cantResultados(PGresult* res); // Retorna la cantidad de rows devueltos por el query realizado en res
char* filaToString(PGresult* res, long fila, int columna); // Transforma el 'columna' esimo atributo  de la 'fila' esima fila del query realizado en res
void cerrarConexion(PGconn* con); // Cierra la conexion a la db, es una buena constumbre aunque el motor lo haga solito con un timeout
void limpiarRes(PGresult* res); // Limpia la memoria usada por un PGresult, no creo que se use mucho pero asi evitamos algun memory leak
