#include <stdio.h>
#include <io.h>
#include <fcntl.h>

// Example of parsing the header
void parseHeader(unsigned char* buffer) {
    // Assuming the header is the first 256 bytes
    // and contains some specific information we are looking for
    printf("Parsing Header Information:\n");
    // Add code here to interpret the header data
}

int main() {
    _setmode(_fileno(stdout), _O_WTEXT);  // Set mode to handle Unicode

    FILE* file;
    errno_t err = fopen_s(&file, "example.SLDPRT", "rb");
    if (err != 0 || file == NULL) {
        wprintf(L"Cannot open the file\n");
        return 1;
    }

    unsigned char buffer[256];
    size_t bytesRead;

    // Read data from the file
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            wprintf(L"%02X ", buffer[i]); // Print data in Hex format
        }
        wprintf(L"\n");
    }

    fclose(file);
    return 0;
}
