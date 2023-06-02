#include "system.h"
#include "screenstuff.h"
#include "idt/isr.h"


// Define entry point in asm to prevent C++ mangling
extern "C"{
    void kernel_main();
}


const char* group[] = {
    "***************     *****      ******     ******  *****  ****     **************",
    "**************  ***  ****  **   ****  ***  *****  *****  ****  ***  ************",
    "*************  **********  ***  ***  *****  ****  *****  ****  ****  ***********",
    "************  ***     ***      ****  *****  ****  *****  ****  ***  ************",
    "*************  ****  ****  **  *****  ***  ******  ***  *****  *****************",
    "**************      *****  ***  *****     ********     ******  *****************",
    
};

const char* tretitre[] = {
    "**********************      ******         ******      *************************",
    "**********************    **     ***     **     ***    *************************",
    "**********************   **       ***   **       ***   *************************",
    "**********************          ****           ****    *************************",
    "**********************    **      ***   **       ***   *************************",
    "**********************     **    ***     **     ***    *************************",
    "**********************       *****         *****       *************************",
    
};

void kernel_main()
{
    clear_screen();

    
    const char* hei = "Hello World!";
    write_string(2,32,15, hei);
    write_string(5,30,9,"printed for you by");
    print_pattern(group,6,10);
    print_pattern(tretitre,7,16);


     //Register interrupt handler for interrupt 1
    
    UiAOS::CPU::ISR::register_interrupt_handler(ISR1, UiAOS::CPU::ISR::print_interrupt_message, nullptr);
    UiAOS::CPU::ISR::register_interrupt_handler(ISR2, UiAOS::CPU::ISR::print_interrupt_message, nullptr);
    



    ///Trigger interrupt 1 manually
    asm volatile("int $1");
    
    while(1){};
}
