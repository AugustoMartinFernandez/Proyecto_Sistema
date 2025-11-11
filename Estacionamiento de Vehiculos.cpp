#include "MenuPrincipal.h"
#include <clocale>

int main() {
    setlocale(LC_ALL, "Spanish");
    MenuPrincipal menu;
    menu.mostrar(); // Inicia todo el sistema
    return 0;
}
