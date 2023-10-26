/*
 * @fileoverview    {FileName}
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
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#if (!defined STATIC_LIB_) && (!defined NO_DLL_MAIN_)
/**
 * Entrada principal de la dll (creado si no se indica que es biblioteca estática)
 *
 * @param instance identificador del módulo.
 * @param reason   razón de la llamada.
 * @param reserved argumento reservado.
 * @return {@code TRUE} si se completó exitosamente la llamada, caso contrario {@code FALSE}.
 */
BOOL APIENTRY DllMain(HINSTANCE instance, DWORD reason, LPVOID reserved) {
    /*
     * Evalúa la razón de la llamada a la dll.
     */
    switch (reason) {
        /*
         * Se cargó la dll en el proceso actual.
         */
        case DLL_PROCESS_ATTACH:
            // printf("%s\n", "DLL_PROCESS_ATTACH");
            break;

        /*
         * Se liberó la dll en el proceso actual.
         */
        case DLL_PROCESS_DETACH:
            // printf("%s\n", "DLL_PROCESS_DETACH");
            break;

        /*
         * Se cargó la dll en un nuevo hilo.
         */
        case DLL_THREAD_ATTACH:
            // printf("%s\n", "DLL_THREAD_ATTACH");
            break;

        /*
         * Se liberó la dll en el nuevo hilo.
         */
        case DLL_THREAD_DETACH:
            // printf("%s\n", "DLL_THREAD_DETACH");
            break;
    }

    return TRUE;
}
#endif

// 16   VK_SHIFT.
// 17   VK_CONTROL.
// 18   VK_MENU.
// 91   VK_LWIN.
// 92   VK_RWIN.
// 160  VK_LSHIFT.
// 161  VK_RSHIFT.
// 162  VK_LCONTROL.
// 163  VK_RCONTROL.
// 164  VK_LMENU.
// 165  VK_RMENU.

/**
 * FIXME: Definición de {@code runVirtualKeyEvent}.
 * Simula la pulsación de una tecla.
 */
LANGUAGE DLLIMPORT CALLING void runVirtualKeyEvent(int eventCode) {
    int eventCodeAux = 0;

    // Evalúa la tecla obtenida.
    switch (eventCode) {
        case VK_SHIFT:
            eventCodeAux = VK_LSHIFT;
            break;

        case VK_CONTROL:
            eventCodeAux = VK_LCONTROL;
            break;

        case VK_MENU:
            eventCodeAux = VK_LMENU;
            break;

        default:
            eventCodeAux = eventCode;
    }

    // printf("The event Code is %d\n", eventCodeAux);
    // Sleep(2000);
    keybd_event(eventCodeAux, 0, KEYEVENTF_EXTENDEDKEY, 0);
    keybd_event(eventCodeAux, 0, KEYEVENTF_KEYUP, 0);
}

#define VK_LBUTTON_DOUBLE 0x07

/**
 * FIXME: Definición de {@code runVirtualMouseClicEvent}.
 * Simula un evento de clic.
 */
LANGUAGE DLLIMPORT CALLING void runVirtualMouseClicEvent(int eventCode) {
    // Crea variable para almacenar las coordenadas actuales del mouse.
    POINT position;

    // Almacena las coordenadas actuales.
    GetCursorPos(&position);
    int positionX = position.x;
    int positionY = position.y;

    // Asignamos posición al mouse.
    // SetCursorPos(0,0);

    // printf("The event Code is %d\n", eventCode);

    // Evalúa el tipo de clic obtenido.
    switch (eventCode) {
        case VK_LBUTTON: // Clic.
            mouse_event(MOUSEEVENTF_LEFTDOWN, positionX, positionY, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, positionX, positionY, 0, 0);
            break;

        case VK_RBUTTON: // Clic derecho.
            mouse_event(MOUSEEVENTF_RIGHTDOWN, positionX, positionY, 0, 0);
            mouse_event(MOUSEEVENTF_RIGHTUP, positionX, positionY, 0, 0);
            break;

        case VK_MBUTTON: // Clic medio.
            mouse_event(MOUSEEVENTF_MIDDLEDOWN, positionX, positionY, 0, 0);
            mouse_event(MOUSEEVENTF_MIDDLEUP, positionX, positionY, 0, 0);
            break;

        case VK_LBUTTON_DOUBLE: // Doble clic.
            mouse_event(MOUSEEVENTF_LEFTDOWN, positionX, positionY, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, positionX, positionY, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTDOWN, positionX, positionY, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, positionX, positionY, 0, 0);
            break;

        default:
            break;
    }
}

#undef VK_LBUTTON_DOUBLE

#define VK_MOUSE_MOVE_EVENT_LEFT 10
#define VK_MOUSE_MOVE_EVENT_RIGHT 20
#define VK_MOUSE_MOVE_EVENT_UP 30
#define VK_MOUSE_MOVE_EVENT_DOWN 40

/**
 * FIXME: Definición de {@code runVirtualMouseMoveEvent}.
 * Simula un evento de movimiento de mouse.
 */
LANGUAGE DLLIMPORT CALLING void runVirtualMouseMoveEvent(int eventCode, int pixelQuantity) {
    // Crea variable para almacenar las coordenadas actuales del mouse.
    POINT position;

    // Almacena las coordenadas actuales.
    GetCursorPos(&position);
    int positionX = position.x;
    int positionY = position.y;

    // Evalúa el tipo de mover obtenido.
    switch (eventCode) {
        case VK_MOUSE_MOVE_EVENT_LEFT:                          // Izquierda.
            SetCursorPos(positionX - pixelQuantity, positionY); // Asignamos posición al mouse.
            break;

        case VK_MOUSE_MOVE_EVENT_RIGHT:                         // Derecha.
            SetCursorPos(positionX + pixelQuantity, positionY); // Asignamos posición al mouse.
            break;

        case VK_MOUSE_MOVE_EVENT_UP:                            // Arriba.
            SetCursorPos(positionX, positionY - pixelQuantity); // Asignamos posición al mouse.
            break;

        case VK_MOUSE_MOVE_EVENT_DOWN:                          // Abajo.
            SetCursorPos(positionX, positionY + pixelQuantity); // Asignamos posición al mouse.
            break;

        default:
            break;
    }
}

#undef VK_MOUSE_MOVE_EVENT_LEFT
#undef VK_MOUSE_MOVE_EVENT_RIGHT
#undef VK_MOUSE_MOVE_EVENT_UP
#undef VK_MOUSE_MOVE_EVENT_DOWN
