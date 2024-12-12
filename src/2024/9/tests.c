#include <stdio.h>
#include <string.h>

extern char *apply_result(int boolean_result);
extern int int_array_equals(int *exp, int *res, int len);
extern char* print_unpacked(int* array, int length);
extern void log_array_result(int *exp, int *res, int equals, int len, char *test_name);
extern void add_x_int(int* arr, int s_index, int times, int number);
extern int summerize_tests();

extern int unpack_disc_map(const char *map, int* unpacked);
extern int get_empty_slots(int* unpacked, int len, int* empty_slots);
extern int fill_empty_slots(int* unpacked, int* empty_slots, int len_unpacked, int len_empty_slots);
extern int move_files_left(int* unpacked, int len_unpacked, int *empty_slots_buffer);
extern unsigned long calcultate_checksum(int *packed_volume, int len);
int pack_and_validate_volume(const char *map, int *buffer_unpacked, int *buffer_empty_slots);

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
    int buffer_empty_slots[3];
    int len = move_files_left(unpacked, 1, buffer_empty_slots);
    int *res = unpacked;
    int exp[] = {0};

    int equals = int_array_equals(exp, res, len);
    log_array_result(exp, res, equals, len,  "move_files_left__0_0");
}

void move_files_left__m1_0__0(){
    int unpacked[3] = {-1,0};
    int buffer_empty_slots[3];
    int len = move_files_left(unpacked, 2, buffer_empty_slots);
    int *res = unpacked;
    int exp[] = {0};
    int equals = int_array_equals(exp, res, len);
    log_array_result(exp, res, equals, len,  "move_files_left__m1_0__0");
}

void move_files_left__0_m1_1__0_1(){
    int unpacked[3] = {0,-1,1};
    int buffer_empty_slots[3];
    int len = move_files_left(unpacked, 3, buffer_empty_slots);
    int *res = unpacked;
    int exp[] = {0,1};

    int equals = int_array_equals(exp, res, len);

    log_array_result(exp, res, equals, 2,  "move_files_left__0_m1_1__0_1");
}

void move_files_left__0_m1_1__len2(){
    int unpacked[10] = {0,-1,1};
    int buffer_empty_slots[3];
    int len = move_files_left(unpacked, 3, buffer_empty_slots);
    int res[] = { len };
    int exp[] = { 2 };

    int equals = int_array_equals(exp, res, 1);

    log_array_result(exp, res, equals, 1,  "move_files_left__0_m1_1__len2");
}

void move_files_left__0_m1_m1_1__len2(){
    int unpacked[10] = {0,-1,-1, 1};
    int buffer_empty_slots[10];
    int len = move_files_left(unpacked, 4, buffer_empty_slots);
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

void pack_and_validate_volume__11__0(){
    char *map = "11";
    int unpacked_buffer[20];
    int buffer_empty_slots[20];
    int checksum = pack_and_validate_volume(map, unpacked_buffer, buffer_empty_slots);
    int exp[3] = {0};
    int res[3] = { checksum };
    
    int equals = int_array_equals(exp, res, 1);
    log_array_result(exp, res, equals, 1,  "pack_and_validate_volume__11__0");
}

void pack_and_validate_volume__1m11__1(){
    char *map = "111";
    int unpacked_buffer[20];
    int buffer_empty_slots[20];
    int checksum = pack_and_validate_volume(map, unpacked_buffer, buffer_empty_slots);
    int exp[3] = {1};
    int res[3] = { checksum };
    
    int equals = int_array_equals(exp, res, 1);
    log_array_result(exp, res, equals, 1,  "pack_and_validate_volume__11__0");
}

void pack_and_validate_volume__2333133121414131402__1928(){
    char *map = "2333133121414131402";
    int unpacked_buffer[64];
    int buffer_empty_slots[64];
    int checksum = pack_and_validate_volume(map, unpacked_buffer, buffer_empty_slots);
    int exp[1] = {1928};
    int res[1] = { checksum };
    
    int equals = int_array_equals(exp, res, 1);
    log_array_result(exp, res, equals, 1,  "pack_and_validate_volume__11__0");
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

    pack_and_validate_volume__11__0();
    pack_and_validate_volume__1m11__1();
    pack_and_validate_volume__2333133121414131402__1928();
    //Summary
    return summerize_tests();
}