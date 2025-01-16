#include <iostream>
#include <unistd.h> // Para fork()  
#include <cstdlib> // Para exit()

int main() {
    pid_t pid = fork(); // Crear un proceso hijo

    if (pid < 0) {
        // Error al crear el proceso hijo
        std::cerr << "Error: No se pudo crear el proceso hijo." << std::endl;
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Código ejecutado por el proceso hijo
        std::cout << "Child process. PID: " << getpid() << std::endl;
    } else {
        // Código ejecutado por el proceso padre
        std::cout << "Parent process. PID: " << getpid() << ", Child PID: " << pid << std::endl;
    }

    return 0;
}
