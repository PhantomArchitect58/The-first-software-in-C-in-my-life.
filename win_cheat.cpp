#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <memory>
#include <stdexcept>
#include <algorithm>
#include <thread>
#include <mutex>
#include <future>
//#include <sys/socket.h>
//#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
//#include <arpa/inet.h>
#include <sstream>
#include <queue>
#include <condition_variable>
#include <windows.h>

int main(void)
{
    SetConsoleOutputCP(65001);
    DWORD pid;
    std::cout << "Введите пид процесса gta: ";
    std::cin >> pid;

    HANDLE hProcess = OpenProcess(PROCESS_VM_WRITE | PROCESS_VM_OPERATION, false, pid);
    if(!hProcess)
    {
        std::cout << "Ошибка. Неверный pid." << std::endl;
        return 1;
    }
    else{
        std::cout << "Успех. Доступ получен." <<std::endl;
    }

    LPVOID adress = reinterpret_cast<LPVOID>(0x00B7F4D0);
    int money = 22222;
    SIZE_T bytes;

    bool result = WriteProcessMemory(hProcess, adress, &money, sizeof(money), &bytes);
    if(result && bytes == sizeof(money))
    {
        std::cout << "Изменено байт: " << bytes << std::endl;
        std::cout << "Деньги изменены." << std::endl;
    }
    else{
        std::cout << "Ошибка записи Windows." << GetLastError << std::endl;
    }
     CloseHandle(hProcess);

     return 0;
}

// comp //// x86_64-w64-mingw32-g++ win_cheat.cpp -o win_cheat.exe -static-libgcc -static-libstdc++
// poisk //// cd %userprofile%\Desktop