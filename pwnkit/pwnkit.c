#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

void gconv_init(int target_pid);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <PID>\n", argv[0]);
        return 1;
    }

    int target_pid = atoi(argv[1]);

    // Load the shared object file
    void *handle;
    void (*gconv_init_ptr)(int);
    handle = dlopen("./gconv.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        return 1;
    }

    // Get the function pointer
    *(void **)(&gconv_init_ptr) = dlsym(handle, "gconv_init");
    if (!gconv_init_ptr) {
        fprintf(stderr, "%s\n", dlerror());
        dlclose(handle);
        return 1;
    }

    // Call the function
    gconv_init_ptr(target_pid);

    dlclose(handle);
    return 0;
}
