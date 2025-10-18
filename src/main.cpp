#include <iostream>
#include "UsbLib.h"
#include <fcntl.h>
#include <io.h>

int main() {
    _setmode(_fileno(stdout), _O_U16TEXT);

    UsbManager manager;
    if (manager.Scan()) {
        std::wcout << L"USB ÀåÄ¡ ¼ö: " << manager.GetDevices().size() << L"\n";
        if (!manager.GetDevices().empty()) {
            manager.GetDevices()[0].Print();
            //manager.GetDevices()[1].Print();
        }
    }

    system("pause");
    return 0;
}
