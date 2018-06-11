#include "BSP/bsp.h"
#include "BSP/HAL/gpu.h"
#include "BSP/characters.h"
#define SCREEN_WIDTH    480	
#define SCREEN_HEIGHT   320
#define SCREEN_BPP      16  
#define BOTON_IZQ 4
#define BOTON_DER 5

int y;
int x;
int row=0;
int col=0;
int nImagen=0;
int presionado = 0;
uint32_t screenMatrix[SCREEN_HEIGHT][SCREEN_WIDTH];
/*Prototype*/
void cargarMetroid(int posX, int posY, int width);
void drawImgR(int posX, int posY);
//

    struct img_t metroid;
    struct img_t metroid1;
    struct img_t metroid2;
    struct img_t metroid3;
    struct img_t metroid4;
    struct img_t metroid5;


int notmain ( void )
{
    
    bsp_init();
    int posX=0;
    int posY;
    //

    metroid.width = 25;
    metroid.height = 48;
    metroid1.width = 25;
    metroid1.height = 48;

    metroid2.width = 25;
    metroid2.height = 48;

    metroid3.width = 25;
    metroid3.height = 48;

    metroid4.width = 25;
    metroid4.height = 48;

    metroid5.width = 35;
    metroid5.height = 48;

    
    // Checkerboard pattern
    uint16_t* screen = gpu_init(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP);
   

    
        int i;
        int j;

    while(1){
    	//inicializar screen
          if(posX<SCREEN_WIDTH-metroid.width){
          		for(i=0; i<SCREEN_HEIGHT ; i++){
        			for(j=0 ; j<SCREEN_WIDTH; j++){
            			screenMatrix[i][j]= 0xffffff;
        			}
    			}
			}


        posY= SCREEN_HEIGHT-metroid.height;
        cargarMetroid(posX, posY, metroid.width);

            if(posX < SCREEN_WIDTH-metroid.width){
            		if(boton_read(BOTON_DER)!=0){
            			drawImgR(posX, posY);
            			posX = posX +4;
            			nImagen++;
            			presionado= 1;
            		}
            		else if(presionado == 0){ 
            			nImagen=0;
            			presionado = 0;
            			
            		}

        	}
        	if(posX > 0){
        			if(boton_read(BOTON_IZQ)!=0)
            		posX = posX -4;
        		}


        for (y=0 ; y<SCREEN_HEIGHT ; y++) {
            for (x=0 ; x<SCREEN_WIDTH ; x++) {
                
                screen[y*SCREEN_WIDTH+x] = screenMatrix[y][x];


        }

        
      
    }



    
}


return(0);

}



void cargarMetroid(int posX, int posY, int width){
    int i;
    int j; 
    int k= 0;
    int l= 0;
    for(i=posY ; i<SCREEN_HEIGHT; i++){
        for(j=posX ; j< posX+width && posX+width < SCREEN_WIDTH; j++){
            screenMatrix[i][j]= metroidMatrix[k][l];
            l++;
        }
        k++;
        l=0;
    } 

}
void drawImgR(int posX, int posY){

	if(nImagen>5){
		nImagen=2;
	}
		int i;
    	int j; 
    	int k= 0;
    	int l= 0;
	switch(nImagen){

		case 1:
				   
    				for(i=posY ; i<SCREEN_HEIGHT; i++){
        				for(j=posX ; j< posX+metroid1.width && posX+metroid1.width < SCREEN_WIDTH; j++){
            				screenMatrix[i][j]= metroidMatrix1[k][l];
            				l++;
        			}
        			k++;
        			l=0;
        		}
    				 
		break;
		case 2:
		
    				for(i=posY ; i<SCREEN_HEIGHT; i++){
        				for(j=posX ; j< posX+metroid2.width && posX+metroid2.width < SCREEN_WIDTH; j++){
            				screenMatrix[i][j]= metroidMatrix2[k][l];
            				l++;
        			}
        			k++;
        			l=0;
    				} 
		break;
		case 3:
	
    				for(i=posY ; i<SCREEN_HEIGHT; i++){
        				for(j=posX ; j< posX+metroid3.width && posX+metroid3.width < SCREEN_WIDTH; j++){
            				screenMatrix[i][j]= metroidMatrix3[k][l];
            				l++;
        			}
        			k++;
        			l=0;
    				} 
		break;
		case 4:

    				for(i=posY ; i<SCREEN_HEIGHT; i++){
        				for(j=posX ; j< posX+metroid4.width && posX+metroid4.width < SCREEN_WIDTH; j++){
            				screenMatrix[i][j]= metroidMatrix4[k][l];
            				l++;
        			}
        			k++;
        			l=0;
    				} 
		break;
		case 5:

    				for(i=posY ; i<SCREEN_HEIGHT; i++){
        				for(j=posX ; j< posX+metroid5.width && posX+metroid5.width < SCREEN_WIDTH; j++){
            				screenMatrix[i][j]= metroidMatrix5[k][l];
            				l++;
        			}
        			k++;
        			l=0;
    				} 
		break;
	}

}


