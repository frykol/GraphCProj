#include "parser.h"
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#endif
#ifdef linux
#include <dirent.h>
#endif

#ifdef _WIN32
struct Files getAllFiles(){
	WIN32_FIND_DATA files;
	HANDLE handle;

	int count = 10;


	const char* directory = "..\\graph_data";
	char path[100];

	sprintf(path, "%s\\*.*", directory);

	if((handle = FindFirstFile(path, &files)) == INVALID_HANDLE_VALUE){
		printf("Path not found");
	}

	char** graphFiles = (char**)malloc(sizeof(char*) * count);
	for(int a = 0; a<count; a++){
		graphFiles[a] = (char*)malloc(100 * sizeof(char));
	}

	int i = 0;
	
	while(FindNextFile(handle, &files)){
		if(strcmp(files.cFileName, ".") == 0 || strcmp(files.cFileName, "..") == 0){
			continue;
		}
		sprintf(path, "%s\\%s", directory, files.cFileName);

		strcpy(graphFiles[i], path);
		i++;
	}

	struct Files graphF;
	graphF.paths = graphFiles;
	graphF.count = i;
	return graphF;
}
#else
struct Files getAllFiles(){
	DIR *d;
	struct dirent *dir;
	const char* dir_path = "../graph_data";
	d = opendir(dir_path);

	char currentPath[100];

	int count = 10;
	

	char** graphFiles = (char**)malloc(count * sizeof(char));
	
	int i = 0;
	if(d){
		while((dir = readdir(d)) != NULL){
			if(strcmp(dir->d_name, ".") == 0 ||(strcmp(dir->d_name, "..") == 0)){
				continue;
				}
			graphFiles[i] = (char*)malloc(sizeof(char) * 100);
			sprintf(currentPath, "%s/%s",dir_path, dir->d_name);
			strcpy(graphFiles[i], currentPath);
			i++;
		}
		closedir(d);
	}
	struct Files graphF;
	graphF.paths = graphFiles;
	graphF.count = i;
	return graphF;
}
#endif

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
    token = (char*)strtok_r(b->buffer, " \n", &nextToken);

    int count = 0;
    int idx = 0;

	

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
        token = strtok_r(NULL, " \n", &nextToken);
        count++;
    }



    return points;

}

