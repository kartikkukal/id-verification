#include <stdio.h>
#include <stdlib.h>

#define ID_LENGTH 16
#define GROUP_LENGTH 4

#include "console.c"
#include "damm.c"


int main() {
    console_initialize();

    while(1) {

        // Clear previous menu
        console_clear();

        // Print menu
        console_print("\tSelect option:\n");
        console_print("1. Verify ID\n");
        console_print("2. Generate ID\n");

        // Input prompt
        console_print("> ");

        // Input option selection
        char option = console_input_option();

        if (option == '1') {
            char id[ID_LENGTH];

            // Input ID with group delimiter
            console_input_id(id, ID_LENGTH, GROUP_LENGTH);
            console_print("\n");
            
            // Verify ID
            int result = verify_damm_id(id, ID_LENGTH);

            if (result == 0) {
                console_print("ID is valid!");
            } else {
                console_print("ID is invalid!");
            }

            console_print("\n");

            // Wait for any key
            console_wait();

            continue;
        }

        if (option == '2') {
            char id[ID_LENGTH];
            
            // Generate new random ID
            int result = generate_damm_id(id, ID_LENGTH);

            // Check for errors
            if (result != 0) {
                console_print("error while generating id\n");
                break;
            }

            // Print ID with group delimiter
            console_print_id(id, ID_LENGTH, GROUP_LENGTH);
            console_print("\n");

            // Wait for any key
            console_wait();
            
            continue;
        }

        break;
    }
    
    // Clean up
    console_finish();
}