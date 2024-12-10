#include <stdio.h>
#include <string.h>

//https://adventofcode.com/2024/day/9

//We add +2 to the id:s
int unpack_disc_map(char *map, int* unpacked){
    
    int next = 0;
    int STATE_disc = 1;
    // int id = 0;
    int unpacked_i = 0;
    int i = 0;
    while (map[i] != 0)
    {
        next = map[i] - 0x30;
        if(STATE_disc){
            
            for (int i_state = 0; i_state < next; i_state++)
            {
                unpacked[unpacked_i] = 0;
                unpacked_i++;
            }

            STATE_disc = 0;
        }
        //STATE disc space
        else {
            for (int i_state = 0; i_state < next; i_state++)
            {
                unpacked[unpacked_i] = -1;
                unpacked_i++;
            }
            
            STATE_disc = 1;   
        }

        i++;
    }
    return i;
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

int int_array_equals(int *exp, int *res, int len){
    return memcmp(exp, res, len * sizeof(int)) == 0 ? 1 : 0;
}

char* print_unpacked(int* array, int length){
    printf("[");
    for (int i = 0; i < length; i++)
    {
        printf("%d", array[i]);
    }
    printf("]");
}

void log_array_result(int *exp, int *res, int equals, int len, char *test_name){

    printf("%d, %s ", tests, test_name);
    printf("expected: ");
    print_unpacked(exp, len);
    printf(" result: ");
    print_unpacked(res, len);

    char* fail = apply_result(equals);
    printf("%s\n", fail);
}

//--------------Test code--------------------

void unpack_disc_map__12__0m1m1()
{
    char *map = "12";
    int res[10];
    int len = unpack_disc_map(map, res);
    int exp[3] = {0, -1, -1};
    
    int equals = int_array_equals(exp, res, len);
    log_array_result(exp, res, equals, 3,  "unpack_disc_map__12__0m1m1");
}

void unpack_disc_map__11__0m1()
{
    char *map = "11";
    int res[10];
    int len = unpack_disc_map(map, res);
    int exp[3] = {0, -1};
    
    int equals = int_array_equals(exp, res, len);
    log_array_result(exp, res, equals, len,  "unpack_disc_map__11__0m1");
}

void unpack_disc_map__21__00m1()
{
    char *map = "21";
    int res[10];
    int len = unpack_disc_map(map, res);
    int exp[3] = {0, 0, -1};
    
    int equals = int_array_equals(exp, res, len);
    log_array_result(exp, res, equals, len,  "unpack_disc_map__21__00m1");
}

int main(){

    unpack_disc_map__12__0m1m1();
    unpack_disc_map__11__0m1();
    unpack_disc_map__21__00m1();

    //Summary
    printf("---------------------------------------\n");
    printf("\n%d/%d tests passed!\n", passed, tests);

    if(passed == tests)
        return 0;
    
    return 1;
}