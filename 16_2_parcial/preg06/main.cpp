#include <iostream>
#include "Funciones-tweets.h"

int main() {
    void *tweets, *users;
    leerTweets(tweets,users);
    reporteUsuarios(users);
    buscarUsuarioMasMencionado(tweets,users);
    return 0;
}