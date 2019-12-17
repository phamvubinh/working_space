/*
struct input_event {
    struct timeval time;
    unsigned short type;
    unsigned short code;
    unsigned int value;
};

EV_REL: 2
EV_SYN: 0
EV_KEY: 1
EV_ABS: 3
EV_MSC: 4
EV_SW:  5

*/
#include <linux/input.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int fd, i;
    int x=0,y=0,z=0;
    struct input_event ev[64];
    
    if(argc < 2) 
    {
        printf("Usage: sudo %s /dev/input/eventX \n", argv[0]);
        return 1;
    }
    
    /* Open eventX to get mouse event */
    fd = open(argv[1], O_RDONLY, 777);
    if(fd < 0)
    {
        printf("File open error\n");
    }
    else
    {
        printf("File open success: %d\n", fd);
    }

    while (1)
    {
        /* Read event data from eventX file */
        int bytes = read(fd, &ev, sizeof(struct input_event)*64);
        if(bytes > 0)
        {
#if 0
            printf("EV_REL: %d\n", EV_REL);
            printf("EV_SYN: %d\n", EV_SYN);
            printf("EV_KEY: %d\n", EV_KEY);
            printf("EV_ABS: %d\n", EV_ABS);
            printf("EV_MSC: %d\n", EV_MSC);
            printf("EV_SW: %d\n", EV_SW);
#endif
            for (i = 0;  i < (int)(bytes / sizeof(struct input_event)); i++) 
            {
                /* Check if event is from keyboard /dev/input/event3 */
                if(ev[i].type == EV_KEY)
                {
                    //printf("key %i state %i\n", ev.code, ev.value);
                    if(ev[i].value == 0)
                    {
                        printf("[key %i]\n ", ev[i].code);
                    }
                }
                /* Check if event is absolutely position of mouse /dev/input/event5 */
                if(ev[i].type == EV_ABS) 
                {
                    //printf("Ev.type %d, Ev.code %d, Ev.value %d\n", ev[i].type, ev[i].code, ev[i].value);
                    /* Check code value to know the event mouse move by vertical or horizontal value */
                    if(ev[i].code == 0)
                    {
                        /* Value is the absolutely position of mouse */
                        /* (0,0) is at the top left corner */ 
                        x = ev[i].value;
                    }
                    else
                    {
                        /* Value is the absolutely position of mouse */
                        /* (0,0) is at the top left corner */ 
                        y = ev[i].value;
                    }
                    printf("X = %d, Y = %d\n", x,y);
                }
                /* Check if event is mouse button press /dev/input/event6 */
                if(ev[i].type == EV_REL) 
                {
                    //printf("Ev.type %d, Ev.code %d, Ev.value %d\n", ev[i].type, ev[i].code, ev[i].value);
                    if(ev[i].code == REL_X)
                    {
                        x+=ev[i].value;
                    }
                    if(ev[i].code == REL_Y)
                    {
                        y+=ev[i].value;
                    }
                    /* Get z value by scroll wheel */
                    if(ev[i].code == REL_WHEEL)
                    {
                        z+=ev[i].value;
                    }
                    printf("X = %d, Y = %d, Z = %d\n", x,y,z);
                }
            }
        }
        else
        {
            printf("Read failed, byte number: %d\n", bytes);
        }
    }
}