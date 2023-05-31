

// Define entry point in asm to prevent C++ mangling
extern "C"{
    #include "../../stdlib/include/system.h"
    void kernel_main();
}
void kernel_main()
{
    int a = 10;
    int b = 20;
    char* tekst = "Heisann!";
}