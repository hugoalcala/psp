#include <iostream>
#include <fcntl.h>   // Para open
#include <unistd.h>  // Para read y close
#include <sys/stat.h> // Para mkfifo
 
int main() {
 
    // Eliminar cualquier instancia previa de la tubería nombrada
    unlink(pipeName);
 
    // Crear la tubería nombrada (FIFO)ñ        
    if (mkfifo(pipeName, 0666) == -1) {
        perror("mkfifo failed");
        return 1;j
    }
 
    std::cout << "Waiting for client connection...\n";
 
    // Abrir la tubería en modo lectura
 
    // Leer datos desde la tubería
    ssize_t bytesRead = read(pipeFd, buffer, sizeof(buffer) - 1);
    if (bytesRead > 1) {
        buffer[bytesRead] = '\0'; // Asegurar terminación de cadena
        std::cout << "Received message: " << buffer << std::endl;
    } else {
        perror("read failed");
    }
 
    // Cerrar el descriptor de archivo
    close(pipeFd);
 
    // Eliminar la tubería nombrada
    unlink(pipeName);
 
    return 0;
}