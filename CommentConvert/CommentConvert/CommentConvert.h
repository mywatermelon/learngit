#ifndef __COMMENT_CONVERT_H__
#define __COMMENT_CONVERT_H__

#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
typedef enum CONVERT_STATE
{
	NULL_STATE,
	C_STATE,
	CPP_STATE,
	END_STATE
}StateType;

#define INPUTFILENAME "input.c"
#define OUTPUTFILENAME "output.c"

void CommentConvert();
void ConvertWork(FILE *read, FILE *write);

void DoCState(FILE *read, FILE *write);
void DoCppState(FILE *read, FILE *write);
void DoNullState(FILE *read, FILE *write);


#endif