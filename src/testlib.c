#include <stdio.h>
#include <string.h>

int passed = 0;
int tests = 0;

int summerize_tests()
{
    printf("---------------------------------------\n");
    printf("\n%d/%d tests passed!\n", passed, tests);

     if(passed == tests)
        return 0;
    
    return 1;
}

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

void log_array_result(int *exp, int *res, int equals, int len, char *test_name)
{
    printf("%d, %s ", tests, test_name);
    printf("expected-length: %d ", len);
    printf("expected: ");
    print_unpacked(exp, len);
    printf(" result: ");
    print_unpacked(res, len);

    char* fail = apply_result(equals);
    printf("%s\n", fail);
}

void add_x_int(int* arr, int s_index, int times, int number)
{
    int max = s_index + times + 1;
    for (int i = s_index; i < max; i++)
    {
        arr[i] = number;
    }
}