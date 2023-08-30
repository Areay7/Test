#include <AiOS/AiOS.h>
#include <AiOS/types.h>
#include <AiOS/io.h>
#include <AiOS/string.h>
#include <AiOS/console.h>
#include <AiOS/printk.h>
#include <AiOS/assert.h>
#include <AiOS/debug.h>
#include <AiOS/global.h>
#include <AiOS/task.h>
#include <AiOS/interrupt.h>
#include <AiOS/stdlib.h>

void kernel_init()
{

  console_init();

  gdt_init();
  
  interrupt_init();

  // task_init();

  asm volatile(
      "sti\n"
      "movl %eax, %eax\n");
  
  u32 counter = 0;
  while (true)
  {
    DEBUGK("looping in kernel init %d ...\n", counter++);
    delay(100000000);
  }

   return;   
}

