#include "BSP/bsp.h"
#include "BSP/HAL/gpu.h"
#include "BSP/characters.h"


#define SCREEN_WIDTH    1024
#define SCREEN_HEIGHT   768
#define SCREEN_BPP      24    //<<<<< sera esto?

int y;
int x;

/*Prototype*/

 //

int notmain ( void )
{
    
    bsp_init();
    struct img_t metroid;
    metroid.width = 25;
    metroid.height = 48;
    int k;
    //Apuntar
    for(k = 0; k<metroid.height; k++)
		metroid.data[k] = metroidMatrix[k];	
	/**/

    // Checkerboard pattern
    uint32_t* screen = gpu_init(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP);
    int i=0;
    int j=0;
    while(1){
        for (y=0 ; y<SCREEN_HEIGHT ; y++) {
            for (x=0 ; x<SCREEN_WIDTH ; x++) {
                
                if(j<metroid.width){
                	screen[y*SCREEN_WIDTH+x] = metroid.data[i][j];
                	j++;
                }
                else
                    screen[y*SCREEN_WIDTH+x] = 0x000000;
                	
            }
            	if(j>=metroid.width && i< metroid.height){
            		i++;
            		j=0;
            	}
            	else
                    screen[y*SCREEN_WIDTH+x] = 0x000000;


        }
        i=0;
        j=0;
    }
    return(0);
}


