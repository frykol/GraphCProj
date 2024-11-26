#include "parser.h"
#include <string.h>


int openFile(const char* filepath) {
	FILE* file = fopen(filepath, "rb");
	if (!file) {
		printf("Nie udalo sie otworzyc plikus");
		return -1;
	}
	fclose(file);

	return 1;
}

struct Buffer getBuffer(const char* filepath) {
	FILE* file = fopen(filepath, "rb");
	
	char buffer[BUFFER_SIZE];
	int numberOfPoints = 1;
	size_t bytes = fread(buffer, sizeof(char), (int)BUFFER_SIZE, file);
	for (size_t i = 0; i < bytes; i++) {
		if (buffer[i] == '\n')
			numberOfPoints++;
	}
	buffer[bytes] = '\0';
	struct Buffer b;
	strcpy(b.buffer, buffer);
	b.bytes = bytes;
	b.numberOfPoints = numberOfPoints;

	fclose(file);

	return b;
}

struct Point* readFile(struct Buffer* b) {

    struct Point* points = (struct Point*)malloc(b->numberOfPoints * sizeof(struct Point));
    char* token = NULL;
    char* nextToken = NULL;
    token = strtok_s(b->buffer, " \n", &nextToken);

    int count = 0;
    int idx = 0;

	srand(time(NULL));

	float cr = (float)(rand() % 256) / 255.0f;
	float cg = (float)(rand() % 256) / 255.0f;
	float cb = (float)(rand() % 256) / 255.0f;

    while (token != NULL) {

        if (count % 2 == 0) {
            points[idx].x = atof(token);
        }
        else {
			points[idx].y = atof(token);
			points[idx].r = cr;
			points[idx].g = cg;
			points[idx].b = cb;
            idx++;
        }
        token = strtok_s(NULL, " \n", &nextToken);
        count++;
    }



    return points;

}

