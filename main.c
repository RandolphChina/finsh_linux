#include <rtthread.h>
#include <curses.h>

#ifdef RT_USING_FINSH
#include "finsh.h"

void func_one_param(int num)
{
    rt_kprintf("func_one_param(int):%d\n",num);
}

void func_two_param(int num,char * str)
{
    rt_kprintf("func_two_param(int):%d,%s\n",num,str);
}

void cls(int num)
{
    rt_kprintf("\033[2J");
}


void test()
{
    rt_kprintf("\033[1;32;40m hello world \033[0m\n");
}

FINSH_FUNCTION_EXPORT(func_one_param, func with one param);
FINSH_FUNCTION_EXPORT(func_two_param, func with two param);
FINSH_FUNCTION_EXPORT(cls, clear the screen: cls());
#endif
#include <termios.h>
int set_conse()
{
    int STDIN_FILENO = 0;
    struct termios org_opts, new_opts;
    tcgetattr(STDIN_FILENO,&org_opts);
    memcpy(&new_opts, &org_opts, sizeof(new_opts));
    new_opts.c_lflag &= ~(ICANON | ECHO | ECHOE | ECHOK | ECHONL | ECHOPRT | ECHOKE | ICRNL);
    //new_opts.c_lflag &= ~(ICANON| ECHO);// | ECHONL | ECHOPRT | ECHOKE | ICRNL);
    new_opts.c_cc[VMIN] = 1;
    new_opts.c_cc[VTIME] = 0;
    tcsetattr(STDIN_FILENO, TCSANOW, &new_opts);
    
}
#include <fcntl.h>
int main(int argc,char *argv[])
{
    test();

    //initscr();
    //cbreak();
    rt_kprintf("---------------------------------------\n");
    rt_kprintf("abcdef");
    rt_kprintf("\033[2K\r");
    rt_kprintf("---------------------------------------\n");
    //refresh();
    set_conse();
    finsh_system_init();
    while(1){
        sleep(2);
        //rt_kprintf("sleep..............\n");
    }
    //endwin();
}















