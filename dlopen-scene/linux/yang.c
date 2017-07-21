#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

#define LIBDVB "./lib/libdvbtest.so"

typedef int (*pdvbtest)();

int main()
{
	void *handle;
	pdvbtest pdvbtest_func = NULL;
	const char *error;

	handle = dlopen(LIBDVB, RTLD_LAZY);
	if (!handle) {
		fprintf(stderr, "%s\n", dlerror());
		exit(EXIT_FAILURE);
	}

	dlerror();

	pdvbtest_func = (pdvbtest)dlsym(handle, "dvbtest");
	if ((error = dlerror()) != NULL)  {
		fprintf(stderr, "%s\n", error);
		exit(EXIT_FAILURE);
	}

	pdvbtest_func();

	return 0;
}
