tarea3-sw
=========

Asumimos Linux como OS :)

Dependencias (Ubuntu 12.04 LTS):

    sudo apt-get install build-essential libpq-dev

Pasos para la compilacion:

    mkdir build dist
    g++ -Wall -g3 -c -MMD -MP -MF build/db.o.d -o build/db.o db.cpp
    g++ -Wall -g3 -c -MMD -MP -MF build/main.o.d -o build/main.o main.cpp
    g++ -Wall -g3 -o dist/app build/db.o build/main.o -lpq

Ejecutar desde dist:
    ./dist/app

Enjoy!
