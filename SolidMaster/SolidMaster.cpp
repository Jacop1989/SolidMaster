#include <stdio.h>
#include <io.h>
#include <fcntl.h>

// Example of parsing the header
void parseHeader(unsigned char* buffer) {
    printf("Parsing Header Information:\n");

    // Example: Extracting file version from the header
    printf("File Version: %02X %02X\n", buffer[0], buffer[1]);

    // Extract other important information as needed
    // ...
}

// Example of parsing metadata (if needed)
void parseMetadata(unsigned char* buffer) {
    printf("Parsing Metadata Information:\n");

    // Example: Extracting file name from metadata
    printf("File Name: %s\n", buffer + 10);  // Assuming the file name starts at byte 10

    // Extract creation or modification date, etc.
    // ...
}

int main() {
    // Comment out the Unicode setting if not needed
    // _setmode(_fileno(stdout), _O_WTEXT);  // Set mode to handle Unicode

    FILE* file;
    errno_t err = fopen_s(&file, "example.SLDPRT", "rb");
    if (err != 0 || file == NULL) {
        printf("Cannot open the file\n");
        return 1;
    }

    unsigned char buffer[256];
    size_t bytesRead;

    // Read data from the file and display in Hex format
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            printf("%02X ", buffer[i]); // Print data in Hex format
        }
        printf("\n");
    }

    // Call the header parsing function after reading the first 256 bytes
    parseHeader(buffer);

    // Call the metadata parsing function (if needed)
    parseMetadata(buffer);

    fclose(file);
    return 0;
}
