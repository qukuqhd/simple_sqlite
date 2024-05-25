#include "include/repl.h"
int main(int argc, char const *argv[])
{
    InputBuffer *input_buffer = new_input_buffer();//创建输入缓冲
    while (true)//不断地进行输入处理
    {
        print_prompt();   
        read_input(input_buffer);
        if (strcmp(input_buffer->buffer, ".exit")==0){
            close_input_buffer(input_buffer);
            exit(EXIT_SUCCESS);           
        }else{
            printf("预料之外地命令\n");
        }
    }
    return 0;
}