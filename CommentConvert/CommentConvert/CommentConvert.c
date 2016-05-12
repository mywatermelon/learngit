#include "CommentConvert.h"
#define _CRT_SECURE_NO_WARNINGS 1
StateType state;

void DoNullState(FILE *read, FILE *write)
{
	int first = fgetc(read);
	int second = 0;
	switch (first)
	{
	case '/':
		second = getc(read);
		if (second == '*')
		{
			fputc(first, write);
			fputc('/', write);
			state = C_STATE;
		}
		else if (second == '/')
		{
			fputc(first, write);
			fputc(second, write);
			state = CPP_STATE;
		}
		else
		{
			fputc(first, write);
			fputc(second, write);
		}
		break;
	case EOF:
		fputc(first, write);
		state = END_STATE;
		break;
	default:
		fputc(first, write);
		break;
	}
}

void DoCState(FILE *read, FILE *write)
{

	int first = fgetc(read);
	int second = 0;
	switch (first)
	{
	case '*':
		second = fgetc(read);
		if (second == '/')
		{
			fputc('\n', write);
			state = NULL_STATE;
		}
		else
		{
			fputc(first, write);
			fseek(read, -1, SEEK_CUR);
		}
		break;
	case '\n':
		fputc(first, write);
		fputc('/', write);
		fputc('/', write);
		break;
	case EOF:
		fputc(first, write);
		state = END_STATE;
		break;
	default:
		fputc(first, write);
		break;
	}
}

void DoCppState(FILE *read, FILE *write)
{
	int first = fgetc(read);
	int second = 0;
	switch (first)
	{
	case '\n':
		fputc(first, write);
		state = NULL_STATE;
		break;
	case EOF:
		fputc(first, write);
		state = END_STATE;
		break;
	default:
		fputc(first, write);
		break;
	}
}

void ConvertWork(FILE *read, FILE *write)
{
	state = NULL_STATE;
	while (state!=END_STATE)
	{
		switch (state)
		{
		case NULL_STATE:
			DoNullState(read, write);
			break;
		case C_STATE:
			DoCState(read, write);
			break;
		case CPP_STATE:
			DoCppState(read, write);
			break;
		}
	}
}

void CommentConvert()
{
	FILE *pRead = fopen(INPUTFILENAME,"r");
	if (pRead == NULL)
	{
		perror("open file for read");
		exit(EXIT_FAILURE);
	}
	FILE *pWrite = fopen(OUTPUTFILENAME, "w");
	if (pWrite == NULL)
	{
		fclose(pRead);
		perror("open file for read");
		exit(EXIT_FAILURE);
	}
	ConvertWork(pRead, pWrite);
	fclose(pRead);
	fclose(pWrite);
}