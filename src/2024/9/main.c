#include <stdio.h>
#include <string.h>

//https://adventofcode.com/2024/day/9
extern int pack_and_validate_volume(const char *map);

int main(int argc, char *argv[])
{
    FILE *fptr;

    fptr = fopen("./src/2024/9/input.txt", "r");
    char *text = malloc(1048576);
    fgets(text, 1048576, fptr);
    // printf("%s\n", text);
    int checksum = pack_and_validate_volume(text);
    printf("%d", checksum);
    return 0;
}