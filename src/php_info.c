#include <stdio.h>
#include <string.h>
#include "../include/php_info.h"

void getPhpVersion(char *phpVersion, size_t size)
{
    char phpInfoCmd[] = "php -v | awk '/^PHP/ {print $2}'";
    FILE *phpVersionPipe = popen(phpInfoCmd, "r");
    if (!phpVersionPipe)
    {
        perror("Error executing command");
        return;
    }
    fgets(phpVersion, size, phpVersionPipe);
    pclose(phpVersionPipe);

    phpVersion[strcspn(phpVersion, "\n")] = '\0';

    char concatenatedInfo[600];
    snprintf(concatenatedInfo, sizeof(concatenatedInfo), "PHP version: %s", phpVersion);
    strncpy(phpVersion, concatenatedInfo, size);
}
