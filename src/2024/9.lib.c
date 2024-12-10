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