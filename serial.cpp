#include "serial.hpp"
#include <iostream>
#include <string>

#ifdef _WIN32

std::string GetLastErrorAsString()
{
    //Get the error message, if any.
    DWORD errorMessageID = ::GetLastError();
    if(errorMessageID == 0)
        return std::string(); //No error message has been recorded

    LPSTR messageBuffer = nullptr;
    size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                                 NULL, errorMessageID, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&messageBuffer, 0, NULL);

    std::string message(messageBuffer, size);

    //Free the buffer.
    LocalFree(messageBuffer);

    return message;
}

Serial::Serial(const char *portName) {
    this->connected = false;

    this->hSerial = CreateFile(portName, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

    if (this->hSerial == INVALID_HANDLE_VALUE) {
        if (GetLastError() == ERROR_FILE_NOT_FOUND) {

            printf("ERROR: Handle was not attached. Reason: %s not available.\n", portName);

        } else {
            printf("ERROR!!!");
			std::cout << (GetLastErrorAsString());
        }
    } else {
        DCB dcbSerialParams = {0};

        if (!GetCommState(this->hSerial, &dcbSerialParams)) {
            printf("failed to get current serial parameters!");
        } else {
            dcbSerialParams.BaudRate = CBR_115200;
            dcbSerialParams.ByteSize = 8;
            dcbSerialParams.StopBits = ONESTOPBIT;
            dcbSerialParams.Parity = NOPARITY;
            dcbSerialParams.fDtrControl = DTR_CONTROL_ENABLE;

            if (!SetCommState(hSerial, &dcbSerialParams)) {
                printf("ALERT: Could not set Serial Port parameters");
            } else {
                this->connected = true;
                PurgeComm(this->hSerial, PURGE_RXCLEAR | PURGE_TXCLEAR);
                Sleep(ARDUINO_WAIT_TIME);
            }
        }
    }
}

Serial::~Serial() {
    if (this->connected) {
        this->connected = false;
        CloseHandle(this->hSerial);
    }
}

int Serial::readData(char *buffer, unsigned int size) {
    DWORD bytesRead;
    char c = 'a';
    char response[1024];
    int i = 0;

    ClearCommError(this->hSerial, &this->errors, &this->status);

    if (this->status.cbInQue > 0) {
        // catch message:
		while (c != '\n') {
            if (ReadFile(this->hSerial, &c, 1, &bytesRead, NULL)) {
                if(c != '\r' && c != '\n'){  //remove the characters '\r' and '\n'. see: http://forums.codeguru.com/showthread.php?253826-C-String-What-is-the-difference-between-n-and-r-n
					response[i] = c;
					i++;
				}
            }
        }

		// end string correctly:
		response[i] = '\0';
    }

    strcpy(buffer, response);
    return 1;
}

bool Serial::writeData(const char *buffer, unsigned int size) {
    DWORD bytesSend;

    if (!WriteFile(this->hSerial, (void *)buffer, size, &bytesSend, 0)) {
        ClearCommError(this->hSerial, &this->errors, &this->status);

        return false;
    } else {
        return true;
    }
}

bool Serial::isConnected() {
    return this->connected;
}

void Serial::clearReadBuffer(){
	PurgeComm(this->hSerial, PURGE_RXCLEAR | PURGE_TXCLEAR| PURGE_RXABORT | PURGE_TXABORT);
}

#endif // Windows

#if defined(__unix) || defined(__APPLE__)
Serial::Serial(const char *portName) {
    connected = false;
    struct termios SerialPortSettings;
    file = open(portName, O_RDWR | O_NOCTTY | O_NDELAY);

    if (file == -1) {
        std::cout << "Can't open " << portName << std::endl;
        exit(0);
    } else {
        std::cout << portName << " opened succesfully" << std::endl;
        connected = true;
    }

    tcgetattr(file, &SerialPortSettings);

    cfsetispeed(&SerialPortSettings, B115200);
    cfsetospeed(&SerialPortSettings, B115200);

    SerialPortSettings.c_cflag &= ~PARENB;
    SerialPortSettings.c_cflag &= ~CSTOPB;
    SerialPortSettings.c_cflag &= ~CSIZE;
    SerialPortSettings.c_cflag |= CS8;

    SerialPortSettings.c_cflag &= ~CRTSCTS;
    SerialPortSettings.c_cflag |= CREAD | CLOCAL;

    SerialPortSettings.c_iflag &= ~(IXON | IXOFF | IXANY);
    SerialPortSettings.c_iflag &= ~(ICANON | ECHO | ECHOE | ISIG);

    SerialPortSettings.c_oflag &= ~OPOST;

    if ((tcsetattr(file, TCSANOW, &SerialPortSettings)) != 0) {
        printf("\n  ERROR ! in Setting attributes\n\n");
    } else {
        printf("\n  BaudRate = 115200 \n  StopBits = 1 \n  Parity = none \n\n");
    }
}

Serial::~Serial() {
    if (this->connected) {
        this->connected = false;
    }
}

int Serial::readData(char *buffer, unsigned int size) {
    char c = 'a';
    char response[1024];
    int i = 0;

    while (c != '\n') {
        if (read(file, &c, 1) > 0)
		{
			if(c != '\r' && c != '\n')
			{
				response[i] = c;
				i++;
			}
        }
    }
	response[i] = '\0';
    strcpy(buffer, response);

    return 1;
}

bool Serial::writeData(const char *buffer, unsigned int size) {
    if (write(file, buffer, size)) {
        return true;
    } else {
        return false;
    }
}

bool Serial::isConnected() {
    return this->connected;
}

#endif // Linux
