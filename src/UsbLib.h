#pragma once
#pragma once

#ifdef USBLIB_EXPORTS
#define USBLIB_API __declspec(dllexport)
#else
#define USBLIB_API __declspec(dllimport)
#endif

#include <string>
#include <vector>

class USBLIB_API UsbDevice {
public:
    std::wstring deviceID;
    std::wstring vid;
    std::wstring pid;
    std::wstring serialNumber;
    std::wstring model;
    std::wstring interfaceType;
    unsigned long long size = 0;

    void Print() const;
    void ParseVIDPIDSerial();
};

class USBLIB_API UsbManager {
private:
    std::vector<UsbDevice> devices;
public:
    bool Scan();
    const std::vector<UsbDevice>& GetDevices() const { return devices; }
};