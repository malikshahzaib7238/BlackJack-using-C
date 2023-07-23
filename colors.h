#pragma once
#include<stdio.h>
void yellowBlink(){
    printf("\033[5;33m");

}
void redBlink()
{
    printf("\033[5;31m");
}
void red()
{
    printf("\033[1;31m");
}

void green()
{
    printf("\033[0;32m");
}
void yellow()
{
    printf("\033[0;33m");
}
void blue()
{
    printf("\033[0;34m");
}
void cyan()
{
    printf("\033[0;36m");
}
void magenta()
{
    printf("\033[1;35m");
}
void reset()
{
    printf("\033[0m");
}