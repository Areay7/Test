#ifndef AiOS_INTERRUPT_H
#define AiOS_INTERRUPT_H

#include <AiOS/types.h>

#define IDT_SIZE 256

typedef struct gate_t
{
    u16 offset0;    // 段内偏移 0 ~ 15 位
    u16 selector;   // 代码段选择子
    u8 reserved;    // 保留不用
    u8 type : 4;    // 任务门/中断门/陷阱门
    u8 segment : 1; // segment = 0 表示系统段
    u8 DPL : 2;     // 使用 int 指令访问的最低权限
    u8 present : 1; // 是否有效
    u16 offset1;    // 段内偏移 16 ~ 31 位
} _packed gate_t;


void interrupt_init();

typedef void *handler_t; // 中断处理函数

void send_eoi(int vector);

void set_exception_handler(u32 intr, handler_t handler);

// 设置中断处理函数
void set_interrupt_handler(u32 irq, handler_t handler);
void set_interrupt_mask(u32 irq, bool enable);

bool interrupt_disable();             // 清除 IF 位，返回设置之前的值
bool get_interrupt_state();           // 获得 IF 位
void set_interrupt_state(bool state); // 设置 IF 位

#endif
