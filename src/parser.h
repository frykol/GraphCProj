#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BUFFER_SIZE 1000

struct Point{
	float x;
	float y;
	float r;
	float g;
	float b;
};

struct Files{
	char** paths;
	int count;
};

struct Buffer {
	char buffer[BUFFER_SIZE];
	size_t bytes;
	int numberOfPoints;
};

int openFile(const char* filepath);

struct Buffer getBuffer(const char* filepath);

struct Point* readFile(struct Buffer* b);

struct Files getAllFiles();

