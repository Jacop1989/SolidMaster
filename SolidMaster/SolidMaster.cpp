#include <stdio.h>
#include <io.h>
#include <fcntl.h>

// Example of parsing the header
void parseHeader(unsigned char* buffer) {
    printf("Parsing Header Information:\n");
    // Add code here to interpret the header data
    for (int i = 0; i < 8; i++) {
        printf("%02X ", buffer[i]);
    }
    printf("\n");
}

int main() {
    // Comment out the Unicode setting for now
    // _setmode(_fileno(stdout), _O_WTEXT);  // Set mode to handle Unicode

    FILE* file;
    errno_t err = fopen_s(&file, "example.SLDPRT", "rb");
    if (err != 0 || file == NULL) {
        printf("Cannot open the file\n");
        return 1;
    }

    unsigned char buffer[256];
    size_t bytesRead;

    // Read data from the file
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            printf("%02X ", buffer[i]); // Print data in Hex format
        }
        printf("\n");
    }

    // Call the header parsing function after reading the first 256 bytes
    parseHeader(buffer);

    fclose(file);
    return 0;
}
