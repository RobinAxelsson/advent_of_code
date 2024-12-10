#include <stdio.h>
#include <string.h>

//https://adventofcode.com/2024/day/9

//We add +2 to the id:s
int unpack_disc_map(const char *map, int* unpacked){
    
    int next = 0;
    int STATE_disc = 1;
    int id = 0;
    int unpacked_i = 0;
    int i = 0;
    while (map[i] != 0)
    {
        next = map[i] - 0x30;
        if(STATE_disc){
            
            for (int i_state = 0; i_state < next; i_state++)
            {
                unpacked[unpacked_i] = id;
                unpacked_i++;
            }
            id++;
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
    return unpacked_i;
}

int get_empty_slots(int* unpacked, int len, int* empty_slots){
    int i_empty = 0;

    for (int i = 0; i < len; i++)
    {
        int unpack  = unpacked[i];
        if(unpack == -1){
            empty_slots[i_empty] = i;
            i_empty++;
        }
    }

    return i_empty;
}

int fill_empty_slots(int* unpacked, int* empty_slots, int len_unpacked, int len_empty_slots){
    // int new_size = len_unpacked; //tracks the shrinking unpacked
    int i_empty_slots = 0;
    int i_unpacked = len_unpacked-1; //iterate backwards

    while (i_empty_slots < len_empty_slots) //check if the empty spots are filled
    {
        int rightmost_unpacked = unpacked[i_unpacked];
        //if it is a number - not a empty slot swap the values
        if(rightmost_unpacked != -1){
            //Get the empty slot
            int next_empty_slot = empty_slots[i_empty_slots];
            
            //set the value at the empty slot
            unpacked[next_empty_slot] = rightmost_unpacked;

            //set the -1 at the end
            unpacked[i_unpacked] = -1;
            i_empty_slots++;
        }
        else {
            len_empty_slots--;
        }
        //decrement to get next value from end
        i_unpacked--;
    }

    
    
    return i_unpacked + 1;
}

int move_files_left(int* unpacked, int len_unpacked){
    int empty_slots[10];

    //Get index of all the empty spots
    int len_empty_slots = get_empty_slots(unpacked, len_unpacked, empty_slots);
    int new_size = fill_empty_slots(unpacked, empty_slots, len_unpacked, len_empty_slots);
    
    return new_size;
}

int calcultate_checksum(int *packed_volume, int len)
{
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum += packed_volume[i] * i;
    }
    
    return sum;
}

// int pack_disk_map(char* disc_map){
//     int * unpacked[1000] = unpack_disc_map(disc_map);
// }

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

void unpack_disc_map__1111__0_m1_1_m1()
{
    char *map = "1111";
    int res[10];
    int len = unpack_disc_map(map, res);
    int exp[10] = {0, -1, 1, -1};
    
    int equals = int_array_equals(exp, res, len);
    log_array_result(exp, res, equals, len,  "unpack_disc_map__1111__0_m1_1_m1");
}

void unpack_disc_map__1010__01()
{
    char *map = "1010";
    int res[10];
    int len = unpack_disc_map(map, res);
    int exp[10] = {0, 1};
    
    int equals = int_array_equals(exp, res, len);
    log_array_result(exp, res, equals, len,  "unpack_disc_map__1010__01");
}

void unpack_disc_map__101010__012()
{
    char *map = "101010";
    int res[10];
    int len = unpack_disc_map(map, res);
    int exp[10] = {0, 1, 2};
    
    int equals = int_array_equals(exp, res, len);
    log_array_result(exp, res, equals, len,  "unpack_disc_map__101010__012");
}


void unpack_disc_map__202020__001122()
{
    char *map = "202020";
    int res[10];
    int len = unpack_disc_map(map, res);
    int exp[10];
    add_x_int(exp, 0, 2, 0);
    add_x_int(exp, 2, 2, 1);
    add_x_int(exp, 4, 2, 2);

    int equals = int_array_equals(exp, res, len);
    log_array_result(exp, res, equals, len,  "unpack_disc_map__202020__001122");
}

void unpack_disc_map__99()
{
    char *map = "99";
    int res[100];
    int len = unpack_disc_map(map, res);
    int exp[100];
    add_x_int(exp, 0, 9, 0);
    add_x_int(exp, 9, 9, -1);
    
    int equals = int_array_equals(exp, res, len);
    log_array_result(exp, res, equals, len,  "unpack_disc_map__99");
}


void unpack_disc_map__9999()
{
    char *map = "9999";
    int res[100];
    int len = unpack_disc_map(map, res);
    int exp[100];
    add_x_int(exp, 0, 9, 0);
    add_x_int(exp, 9, 9, -1);
    add_x_int(exp, 18, 9, 1);
    add_x_int(exp, 27, 9, -1);
    
    int equals = int_array_equals(exp, res, len);
    log_array_result(exp, res, equals, len,  "unpack_disc_map__9999");
}

void move_files_left__0_0(){
    int unpacked[3] = {0};
    int len = move_files_left(unpacked, 1);
    int *res = unpacked;
    int exp[] = {0};

    int equals = int_array_equals(exp, res, len);
    log_array_result(exp, res, equals, len,  "move_files_left__0_0");
}

void move_files_left__m1_0__0(){
    int unpacked[3] = {-1,0};
    int len = move_files_left(unpacked, 2);
    int *res = unpacked;
    int exp[] = {0};
    int equals = int_array_equals(exp, res, len);
    log_array_result(exp, res, equals, len,  "move_files_left__m1_0__0");
}

void move_files_left__0_m1_1__0_1(){
    int unpacked[3] = {0,-1,1};
    int len = move_files_left(unpacked, 3);
    int *res = unpacked;
    int exp[] = {0,1};

    int equals = int_array_equals(exp, res, len);

    log_array_result(exp, res, equals, 2,  "move_files_left__0_m1_1__0_1");
}

void move_files_left__0_m1_1__len2(){
    int unpacked[10] = {0,-1,1};
    int len = move_files_left(unpacked, 3);
    int res[] = { len };
    int exp[] = { 2 };

    int equals = int_array_equals(exp, res, 1);

    log_array_result(exp, res, equals, 1,  "move_files_left__0_m1_1__len2");
}

void move_files_left__0_m1_m1_1__len2(){
    int unpacked[10] = {0,-1,-1, 1};
    int len = move_files_left(unpacked, 4);
    int res[] = { len };
    int exp[] = { 2 };

    int equals = int_array_equals(exp, res, 1);

    log_array_result(exp, res, equals, 1,  "move_files_left__0_m1_m1_1__len2");
}

void get_empty_slots__0_m1_m1_1__len2(){
    int unpacked[10] = {0,-1,-1, 1};
    int empty_slots[5];
    int len = get_empty_slots(unpacked, 4, empty_slots);
    int res[] = { len };
    int exp[] = { 2 };

    int equals = int_array_equals(exp, res, 1);

    log_array_result(exp, res, equals, 1,  "get_empty_slots__0_m1_m1_1__len2");
}

void get_empty_slots__0_m1_m1_1__1_2(){
    int unpacked[10] = {0,-1,-1, 1};
    int res[5];
    int len = get_empty_slots(unpacked, 2, res);
    int exp[] = { 1, 2 };

    int equals = int_array_equals(exp, res, 2);

    log_array_result(exp, res, equals, 1,  "get_empty_slots__0_m1_m1_1__1_2");
}

void get_empty_slots__0_m1_m1_1_m1__1_2_4(){
    int unpacked[10] = {0,-1,-1,-1};
    int res[5];
    int len = get_empty_slots(unpacked, 4, res);
    int exp[] = { 1, 2, 3 };

    int equals = int_array_equals(exp, res, 3);

    log_array_result(exp, res, equals, 3,  "get_empty_slots__0_m1_m1_1_m1__1_2_4");
}

void fill_empty_slots__m10__0(){
    int res[10] = {-1, 0};
    int empty_slots[10] = { 0 };
    int len = fill_empty_slots(res, empty_slots, 2, 1);
    int exp[] = { 0 };

    int equals = int_array_equals(exp, res, 1);
    log_array_result(exp, res, equals, 1,  "fill_empty_slots__m10__0");
}

void fill_empty_slots__0m11__01(){
    int res[10] = {0, -1, 1};
    int empty_slots[10] = { 1 };
    int len = fill_empty_slots(res, empty_slots, 3, 1);
    int exp[] = { 0, 1 };

    int equals = int_array_equals(exp, res, 1) && len == 2;
    log_array_result(exp, res, equals, 1,  "fill_empty_slots__0m11__01");
}

void fill_empty_slots__0_m1_m1_1__len2(){
    int unpacked[10] = {0, -1, -1, 1};
    int empty_slots[10] = { 1, 2 };
    int len = fill_empty_slots(unpacked, empty_slots, 4, 2);
    int exp[] = { 2 };
    int res[] = { len };

    int equals = int_array_equals(exp, res, 1);
    log_array_result(exp, res, equals, 1,  "fill_empty_slots__0m11__01");
}

void calculate_checksum__0__0(){
    int packed_volume[10] = {0};
    int sum = calcultate_checksum(packed_volume, 1);
    int exp[] = { 0 };
    int res[] = { sum };

    int equals = int_array_equals(exp, res, 1);
    log_array_result(exp, res, equals, 1,  "calculate_checksum__0__0");
}

void calculate_checksum__00__0(){
    int packed_volume[10] = {0, 0};
    int sum = calcultate_checksum(packed_volume, 2);
    int exp[] = { 0 };
    int res[] = { sum };

    int equals = int_array_equals(exp, res, 1);
    log_array_result(exp, res, equals, 1,  "calculate_checksum__00__0");
}

void calculate_checksum__01__1(){
    int packed_volume[10] = {0, 1};
    int sum = calcultate_checksum(packed_volume, 2);
    int exp[] = { 1 };
    int res[] = { sum };

    int equals = int_array_equals(exp, res, 1);
    log_array_result(exp, res, equals, 1,  "calculate_checksum__00__0");
}

int main(){

    unpack_disc_map__12__0m1m1();
    unpack_disc_map__11__0m1();
    unpack_disc_map__21__00m1();
    unpack_disc_map__1111__0_m1_1_m1();
    unpack_disc_map__1010__01();
    unpack_disc_map__101010__012();
    unpack_disc_map__202020__001122();
    unpack_disc_map__99();
    unpack_disc_map__9999();

    move_files_left__0_0();
    move_files_left__m1_0__0();
    move_files_left__0_m1_1__0_1();
    move_files_left__0_m1_1__len2();
    move_files_left__0_m1_m1_1__len2();
    move_files_left__0_m1_1__len2();
    get_empty_slots__0_m1_m1_1__len2();
    get_empty_slots__0_m1_m1_1__1_2();
    get_empty_slots__0_m1_m1_1_m1__1_2_4();

    fill_empty_slots__m10__0();
    fill_empty_slots__0m11__01();
    fill_empty_slots__0_m1_m1_1__len2();

    calculate_checksum__0__0();
    calculate_checksum__00__0();
    calculate_checksum__01__1();

    //Summary
    printf("---------------------------------------\n");
    printf("\n%d/%d tests passed!\n", passed, tests);

    if(passed == tests)
        return 0;
    
    return 1;
}