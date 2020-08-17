#include <stdio.h>
#include <stdlib.h>

struct file_data {
	void *data;
	size_t size;
};

struct file_data *get_file(char *path)
{
	FILE *f = fopen(path, "r");

	fseek(f, 0, SEEK_END);
	size_t bufsize = ftell(f);
	fseek(f, 0, SEEK_SET);

	char *buf;
	buf = malloc(bufsize);

	fread(buf, 1, bufsize, f);

	fclose(f);

	struct file_data *fdata = malloc(sizeof(*f));
	fdata->data = buf;
	fdata->size = bufsize;

	return fdata;
}
