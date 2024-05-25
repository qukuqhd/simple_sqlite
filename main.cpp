#include "include/repl.h"
#include "include/command.h"
int main(int argc, char const *argv[])
{
    InputBuffer *input_buffer = new_input_buffer();//创建输入缓冲
    while (true)//不断地进行输入处理
    {
        print_prompt();   
        read_input(input_buffer);
        
        if (input_buffer->buffer[0]=='.'){
            switch(do_meta_command(input_buffer)){
                case META_COMMAND_SUCCESS:{
                    continue;
                    break;
                }
                case META_COMMAND_UNRECOGNIZED:{
                    printf("预料之外的命令\n"); 
                    continue;     
                    break;
                }
            }
        }
        Statement statement;
        switch(prepare_statement(input_buffer,&statement)){
            case PREPARED_SUCCESS:{
                break;
            }
            case PREPARED_UNRECOGNIZED:{
                printf("预料之外的关键字从'%s'开始.\n",input_buffer->buffer);
                continue;
                break;
            }
        }
        execute_statement(&statement);
        printf("执行成功\n");
    }
    return 0;
}