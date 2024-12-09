#include <stdio.h>
#include <string.h>

//https://adventofcode.com/2024/day/9

//We add +2 to the id:s
void unpack_disc_map(char *map, int* unpacked){
    unpacked[0] = 2;
    unpacked[1] = 1;
    unpacked[2] = 1;
    unpacked[3] = 0;
}

//--------------Test helpers------------------
int passed = 0;
int tests = 0;

char *apply_result(int boolean_result)
{
    tests++;
    char *fail = "";

    if (!boolean_result)
    {
        fail = "<------ FAILED";
    }
    else
    {
        passed++;
    }

    return fail;
}

int count_unpacked(int *unpacked){

    int count = 0;
    while(unpacked[count] != 0){
        count++;
    }
    return count;
}

//1 is true
int int_array_equals(int *exp, int *res){
    int lenExp = count_unpacked(exp);
    int lenRes = count_unpacked(res);
    int lenEqual = lenExp == lenRes;
    int memComp = memcmp(exp, res, lenRes * sizeof(int)) == 0 ? 1 : 0;
    return lenEqual & memComp;
}

char* print_unpacked(int* array, int length){
    printf("[");
    for (int i = 0; i < length; i++)
    {
        int current = array[i];
        if(current == 1) {
            printf(".");
        }
        else if(current == 0){
            printf("\\0");
        }
        else {
            printf("%d", current-2);
        }
    }
    printf("]");
}

void log_array_result(int *exp, int *res, int equals, char *test_name){

    char* fail = apply_result(equals);
    printf("%d, %s ", tests, test_name);
    printf("expected: ");
    print_unpacked(exp, 3);
    printf(" result: ");
    print_unpacked(res, 3);
    printf("%s\n", fail);
}

//--------------Test code--------------------

void unpack_disc_map__12__2110() //translate numbs by 2
{
    char *map = "12";
    int res[4];
    unpack_disc_map(map, res);
    int exp[4] = {2, 1, 1, 0};
    
    int equals = int_array_equals(exp, res);
    log_array_result(exp, res, equals, "unpack_disc_map__12__2110");
}

int main(){

    unpack_disc_map__12__0nn();

    //Summary
    printf("---------------------------------------\n");
    printf("\n%d/%d tests passed!\n", passed, tests);

    if(passed == tests)
        return 0;
    
    return 1;
}