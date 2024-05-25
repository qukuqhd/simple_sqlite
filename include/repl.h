/**
 * @file repl.h
 * @author {gangx} ({gangx6906@gmail.com})
 * @brief 基本的repl相关函数的头文件
 * @version 0.1
 * @date 2024-05-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef _REPL_H
#define _REPL_H
#include <cstdlib>
#include <cstring>
#include <cstdio>
/**
 * @brief 输入缓存
 * 
 */
typedef struct {
    char* buffer;
    size_t bufer_length;
    ssize_t input_length;    
}InputBuffer;
/**
 * @brief 创建一个输入缓存的指针
 * 
 * @return InputBuffer* 
 */
InputBuffer* new_input_buffer(){
    InputBuffer *input_buffer = (InputBuffer*)malloc(sizeof(InputBuffer));
    input_buffer->buffer = NULL;
    input_buffer->bufer_length = 0;
    input_buffer->input_length = 0;
    return input_buffer;
}
/**
 * @brief 打印提示符
 * 
 */
void print_prompt(){
    printf("db > ");
}
/**
 * @brief 读取输入到输入缓存
 * 
 * @param input_buffer 
 */
void read_input(InputBuffer*input_buffer){
    ssize_t bytes_read = getline(&input_buffer->buffer,&input_buffer->bufer_length,stdin);
    if (bytes_read<=0){
        fputs("ERROR READDING INPUT ",stderr);
        exit(EXIT_FAILURE);
    }
    input_buffer->input_length = bytes_read-1;
    input_buffer->buffer[bytes_read-1] = 0;//添加缓存内容的终止符号
}
/**
 * @brief 关闭输入缓存
 * 
 * @param input_buffer 
 */
void close_input_buffer(InputBuffer *input_buffer){
    free(input_buffer->buffer);
    free(input_buffer);
}
#endif