#include <cstring>
#include <iostream>
#include "db.hpp"

using namespace std;
int main()
{
    char *sql = new char[1024]; // Aqui va el query sql
    memset(sql, 0, sizeof(sql));
    
    //char *asignatura = new char[256];
    //memset(asignatura, 0, sizeof(asignatura));
    string asignatura;
    cout << "\tPrograma realizado por:" << endl  << "\t\tPatricio Perez Valverde" <<endl <<  "\t\tSebastian Rocha Reyes" << endl << "\t\tNatalia  Tarifeño Ortiz" << endl << endl;
    
    cout << "Ingrese nombre de asignatura" << endl;
    getline(cin,asignatura);
    //cin >> asignatura; // Ojala que funcione esto ...
    
    // Ahora reemplazamos el nombre de asignatura en el query y a jugar
    // Validacion? what is that?
    sprintf(sql, "SELECT AVG(nota) FROM asignaturas_cursadas WHERE curso_id IN (SELECT curso_id FROM cursos WHERE asignatura = '%s')", asignatura.c_str());
    
    PGconn* con = conectarDB("146.83.181.4", 6432, "iswdb", "isw","isw"); //conexion
    PGresult* res = query(con, sql); // Hacer query
    long hits = cantResultados(res); // Cuantas rows devolvio
    if(hits > 1)
        cout << "El ranking para " << asignatura << " es " << filaToString(res, 0, 0) << endl;
    else
        cout << "No se encontraron resultados para " << asignatura << endl;
    cerrarConexion(con); // Cerramos la conexion, hay que tener respeto
    return 0;
}
