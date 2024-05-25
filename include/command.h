#ifndef _COMMAND_H_
#define _COMMAND_H_
#include<stdio.h>
#include<stdlib.h>
#include "repl.h"
/**
 * @brief 元命令地类型
 * 
 */
typedef enum{
    META_COMMAND_SUCCESS,
    META_COMMAND_UNRECOGNIZED    
}MetaCommandResult;
/**
 * @brief 处理结果
 * 
 */
typedef enum{
    PREPARED_SUCCESS,
    PREPARED_UNRECOGNIZED
}PrepareResult;
/**
 * @brief 语句类型枚举
 * 
 */
typedef enum{
    STATEMENT_SELECT,
    STATEMENT_INSERT
}StatementType;
/**
 * @brief 语句结构体
 * 
 */
typedef struct{
    StatementType type;
}Statement;
/**
 * @brief 对元命令进行处理
 * 
 * @param input_buffer 
 * @return MetaCommandResult 
 */
MetaCommandResult do_meta_command(InputBuffer *input_buffer){
    if(strcmp(input_buffer->buffer,".exit")==0){
        close_input_buffer(input_buffer);
        exit(EXIT_SUCCESS);
    }else{
        return META_COMMAND_UNRECOGNIZED;
    }
}
/**
 * @brief 判断语句的类型
 * 
 * @param input_buffer 
 * @param statament 
 * @return PrepareResult 
 */
PrepareResult prepare_statement(InputBuffer*input_buffer,Statement*statament){
    if(strncmp(input_buffer->buffer,"insert",6)==0){
        statament->type = STATEMENT_INSERT;
        return PREPARED_SUCCESS;
    }
    if(strcmp(input_buffer->buffer,"select")==0){
        statament->type = STATEMENT_SELECT;
        return PREPARED_SUCCESS;
    }
    return PREPARED_UNRECOGNIZED;
}
/**
 * @brief 具体根据不同的语句类型进行语句的执行处理
 * 
 * @param statement 
 */
void execute_statement(Statement*statement){
    switch (statement->type)
    {
        case STATEMENT_INSERT:{
            printf("这里会进行一个insert操作\n");
            break;
        }
        case STATEMENT_SELECT:{
            printf("这里会进行一个select操作\n");
            break;
        }
    }
}
#endif