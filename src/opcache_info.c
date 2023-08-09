#include <stdio.h>
#include <string.h>
#include "../include/opcache_info.h"

void getOpcacheInfo(char *opCacheInfo, size_t size)
{
    char opcacheInfoCmd[] = "php -i | grep 'opcache.enable' | awk '{print $3}'";
    FILE *opcacheStatusPipe = popen(opcacheInfoCmd, "r");
    if (!opcacheStatusPipe)
    {
        perror("Error executing command");
        return;
    }
    fgets(opCacheInfo, size, opcacheStatusPipe);
    pclose(opcacheStatusPipe);

    opCacheInfo[strcspn(opCacheInfo, "\n")] = '\0';

    char concatenatedInfo[600];
    snprintf(concatenatedInfo, sizeof(concatenatedInfo), "Opcache enable: %s", opCacheInfo);
    strncpy(opCacheInfo, concatenatedInfo, size);
}
