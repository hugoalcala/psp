#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <diferent .h>
#include <cstring>
#include <cstdlib>

bool isNumeric(const char* str) {
    for (int i = 0; i < strlen(str); i++) {
        if (!std :: isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    const char* procChat = "/proc";
    DIR* procDir = opendir(procChat);
    if (procDir == NULL) {
        std :: cerr << "Error al abrir el directorio /proc" << std :: endl;
        return 1;
    }
    struct dirent* entry;
    while ((entry = readdir(procDir)) != nullptr)
    {
        if (entry -> d_type == DT_DIR && isNumeric(entry -> d_name))
        {
            int pid = std::atoi(entry -> d_name);
            std :: string cmdlinePath = std :: string(procChat) + "/" +
            entry -> d_name + "/cmdline";
            std :: ifstream cmdlineFile(cmdlinePath);

            if (cmdlineFile)
            {
                std :: string processName;
                std :: getline(cmdlineFile, processName, '\0');
                std :: cout << "PID: " << pid << " Nombre: " << processName << std :: endl;
            }else{
                std :: cerr << "Error al abrir el archivo " << cmdlinePath << std :: endl;
            }   
        }
    }
    closedir(procDir);
    return 0;
}