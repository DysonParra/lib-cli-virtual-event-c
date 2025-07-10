/*
 * @overview        {FileName}
 *
 * @version         2.0
 *
 * @author          Dyson Arley Parra Tilano <dysontilano@gmail.com>
 *
 * @copyright       Dyson Parra
 * @see             github.com/DysonParra
 *
 * History
 * @version 1.0     Implementation done.
 * @version 2.0     Documentation added.
 */
#include "virtual_event.h"
#include "tester.h"
#include <stdio.h>
#include <stdlib.h>

#define VK_MOUSE_CLIC_EVENT_LEFT 1
#define VK_MOUSE_CLIC_EVENT_RIGHT 2
#define VK_MOUSE_CLIC_EVENT_MIDDLE 4
#define VK_MOUSE_CLIC_EVENT_LEFT_DOUBLE 7

#define VK_MOUSE_MOVE_EVENT_LEFT 10
#define VK_MOUSE_MOVE_EVENT_RIGHT 20
#define VK_MOUSE_MOVE_EVENT_UP 30
#define VK_MOUSE_MOVE_EVENT_DOWN 40

/**
 * Entrada principal del sistema.
 *
 * @param argc cantidad de argumentos pasados en la linea de comandos.
 * @param argv argumentos de la linea de comandos.
 * @return {0} si el programa se ejecutó correctamente.
 */
int main(int argc, char** argv) {

    runVirtualKeyEvent(91);

    // runVirtualMouseClicEvent(VK_MOUSE_CLIC_EVENT_LEFT);
    // runVirtualMouseClicEvent(VK_MOUSE_CLIC_EVENT_RIGHT);
    // runVirtualMouseClicEvent(VK_MOUSE_CLIC_EVENT_MIDDLE);
    // runVirtualMouseClicEvent(VK_MOUSE_CLIC_EVENT_LEFT_DOUBLE);

    // runVirtualMouseMoveEvent(VK_MOUSE_MOVE_EVENT_LEFT,  20);
    // runVirtualMouseMoveEvent(VK_MOUSE_MOVE_EVENT_RIGHT, 20);
    // runVirtualMouseMoveEvent(VK_MOUSE_MOVE_EVENT_UP,  20);
    // runVirtualMouseMoveEvent(VK_MOUSE_MOVE_EVENT_DOWN,  20);

    return 0;
}
