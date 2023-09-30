//Viral Science www.youtube.com/c/viralscience  www.viralsciencecreativity.com
//OLED 128x64 Graphics Display
//http://marlinfw.org/tools/u8glib/converter.html

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Wire.h"
#include "Adafruit_GFX.h"

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);



#define YT_BMPWIDTH  103
#define YT_BMPHEIGHT 64
const unsigned char bitmap_YT[] PROGMEM = {
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ........................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ........................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ........................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ........................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ........................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ........................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ........................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ........................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ........................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ........................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ........................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ........................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ........................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ........................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ........................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ........................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ........................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ........................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,0xFF,0x00,0x00,0x00, // ..................................................##############################........................
  0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xC0,0x00,0x00, // ................................................##################################......................
  0x00,0x00,0x00,0x00,0x00,0x01,0xFF,0xFF,0xFF,0xFF,0xE0,0x00,0x00, // ...............................................####################################.....................
  0x00,0x00,0x00,0x00,0x00,0x03,0xFF,0xFF,0xFF,0xFF,0xF0,0x00,0x00, // ..............................................######################################....................
  0x00,0x00,0x00,0x00,0x00,0x03,0xFF,0xFF,0xFF,0xFF,0xF8,0x00,0x00, // ..............................................#######################################...................
  0x00,0x00,0x3C,0xF0,0x00,0x03,0x00,0x7F,0x8F,0xFF,0xF8,0x00,0x00, // ..................####..####..................##.........########...#################...................
  0x00,0x00,0x1C,0xE0,0x00,0x07,0x00,0x7F,0x8F,0xFF,0xF8,0x00,0x00, // ...................###..###..................###.........########...#################...................
  0x00,0x00,0x1C,0xE0,0x00,0x07,0x00,0x7F,0x8F,0xFF,0xFC,0x00,0x00, // ...................###..###..................###.........########...##################..................
  0x00,0x00,0x1C,0xE0,0x00,0x07,0xE3,0xFF,0x8F,0xFF,0xFC,0x00,0x00, // ...................###..###..................######...###########...##################..................
  0x00,0x00,0x0C,0xC7,0x8E,0x67,0xE3,0x98,0x88,0xF0,0xFC,0x00,0x00, // ....................##..##...####...###..##..######...###..##...#...#...####....######..................
  0x00,0x00,0x0F,0xCF,0xCE,0xF7,0xE3,0x18,0x80,0x60,0x7C,0x00,0x00, // ....................######..######..###.####.######...##...##...#........##......#####..................
  0x00,0x00,0x0F,0xDF,0xCE,0xE7,0xE3,0x18,0x80,0x40,0x3C,0x00,0x00, // ....................######.#######..###.###..######...##...##...#........#........####..................
  0x00,0x00,0x0F,0x9C,0xEE,0xE7,0xE3,0x18,0x8C,0x46,0x3C,0x00,0x00, // ....................#####..###..###.###.###..######...##...##...#...##...#...##...####..................
  0x00,0x00,0x07,0x9C,0xEE,0xE7,0xE3,0x18,0x8C,0x46,0x3C,0x00,0x00, // .....................####..###..###.###.###..######...##...##...#...##...#...##...####..................
  0x00,0x00,0x07,0x9C,0xEE,0xE7,0xE3,0x18,0x8C,0x40,0x3C,0x00,0x00, // .....................####..###..###.###.###..######...##...##...#...##...#........####..................
  0x00,0x00,0x07,0x9C,0xEE,0xE7,0xE3,0x18,0x8C,0x40,0x3C,0x00,0x00, // .....................####..###..###.###.###..######...##...##...#...##...#........####..................
  0x00,0x00,0x07,0x9C,0xEE,0xE7,0xE3,0x18,0x8C,0x40,0x3C,0x00,0x00, // .....................####..###..###.###.###..######...##...##...#...##...#........####..................
  0x00,0x00,0x07,0x9C,0xEE,0xE7,0xE3,0x18,0x8C,0x47,0xFC,0x00,0x00, // .....................####..###..###.###.###..######...##...##...#...##...#...#########..................
  0x00,0x00,0x07,0x9C,0xEE,0x67,0xE3,0x18,0x8C,0x46,0x3C,0x00,0x00, // .....................####..###..###.###..##..######...##...##...#...##...#...##...####..................
  0x00,0x00,0x07,0x9C,0xEE,0xE7,0xE3,0x18,0x8C,0x46,0x3C,0x00,0x00, // .....................####..###..###.###.###..######...##...##...#...##...#...##...####..................
  0x00,0x00,0x07,0x9F,0xCF,0xE7,0xE3,0x00,0x84,0x40,0x3C,0x00,0x00, // .....................####..#######..#######..######...##........#....#...#........####..................
  0x00,0x00,0x07,0x8F,0xCF,0xF7,0xE3,0x00,0x80,0x60,0x78,0x00,0x00, // .....................####...######..########.######...##........#........##......####...................
  0x00,0x00,0x03,0x0F,0x87,0x63,0xE3,0x88,0x88,0xF0,0xF8,0x00,0x00, // ......................##....#####....###.##...#####...###...#...#...#...####....#####...................
  0x00,0x00,0x00,0x00,0x00,0x03,0xFF,0xFF,0xFF,0xFF,0xF8,0x00,0x00, // ..............................................#######################################...................
  0x00,0x00,0x00,0x00,0x00,0x03,0xFF,0xFF,0xFF,0xFF,0xF0,0x00,0x00, // ..............................................######################################....................
  0x00,0x00,0x00,0x00,0x00,0x01,0xFF,0xFF,0xFF,0xFF,0xF0,0x00,0x00, // ...............................................#####################################....................
  0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xE0,0x00,0x00, // ................................................###################################.....................
  0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0xFF,0xFF,0xFF,0x80,0x00,0x00, // .................................................################################.......................
  0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0xFF,0xFF,0xFE,0x00,0x00,0x00, // ...................................................############################.........................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ........................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ........................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ........................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ........................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ........................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ........................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ........................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ........................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ........................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ........................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ........................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ........................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ........................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ........................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ........................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ........................................................................................................
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00  // ........................................................................................................
};




#define YT1_BMPWIDTH  91
#define YT1_BMPHEIGHT 64
const unsigned char bitmap_YT1[] PROGMEM = {
  0x00,0x00,0x1F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x80,0x00,0x00, // ...................######################################################.......................
  0x00,0x3F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x80,0x00, // ..........#######################################################################...............
  0x01,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,0x00, // .......#############################################################################............
  0x03,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF8,0x00, // ......###############################################################################...........
  0x07,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFC,0x00, // .....#################################################################################..........
  0x0F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0x00, // ....###################################################################################.........
  0x1F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00, // ...#####################################################################################........
  0x1F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00, // ...#####################################################################################........
  0x3F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x80, // ..#######################################################################################.......
  0x3F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x80, // ..#######################################################################################.......
  0x3F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xC0, // ..########################################################################################......
  0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xC0, // .#########################################################################################......
  0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xC0, // .#########################################################################################......
  0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xC0, // .#########################################################################################......
  0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xC0, // .#########################################################################################......
  0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xE0, // .##########################################################################################.....
  0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xE0, // .##########################################################################################.....
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xE0, // ###########################################################################################.....
  0xFF,0xFF,0xFF,0xFF,0xF7,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xE0, // ####################################.######################################################.....
  0xFF,0xFF,0xFF,0xFF,0xF1,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xE0, // ####################################...####################################################.....
  0xFF,0xFF,0xFF,0xFF,0xF0,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xE0, // ####################################.....##################################################.....
  0xFF,0xFF,0xFF,0xFF,0xF0,0x1F,0xFF,0xFF,0xFF,0xFF,0xFF,0xE0, // ####################################.......################################################.....
  0xFF,0xFF,0xFF,0xFF,0xF0,0x07,0xFF,0xFF,0xFF,0xFF,0xFF,0xE0, // ####################################.........##############################################.....
  0xFF,0xFF,0xFF,0xFF,0xF0,0x03,0xFF,0xFF,0xFF,0xFF,0xFF,0xE0, // ####################################..........#############################################.....
  0xFF,0xFF,0xFF,0xFF,0xF0,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xE0, // ####################################............###########################################.....
  0xFF,0xFF,0xFF,0xFF,0xF0,0x00,0x3F,0xFF,0xFF,0xFF,0xFF,0xE0, // ####################################..............#########################################.....
  0xFF,0xFF,0xFF,0xFF,0xF0,0x00,0x0F,0xFF,0xFF,0xFF,0xFF,0xE0, // ####################################................#######################################.....
  0xFF,0xFF,0xFF,0xFF,0xF0,0x00,0x03,0xFF,0xFF,0xFF,0xFF,0xE0, // ####################################..................#####################################.....
  0xFF,0xFF,0xFF,0xFF,0xF0,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xE0, // ####################################....................###################################.....
  0xFF,0xFF,0xFF,0xFF,0xF0,0x00,0x00,0x3F,0xFF,0xFF,0xFF,0xE0, // ####################################......................#################################.....
  0xFF,0xFF,0xFF,0xFF,0xF0,0x00,0x00,0x0F,0xFF,0xFF,0xFF,0xE0, // ####################################........................###############################.....
  0xFF,0xFF,0xFF,0xFF,0xF0,0x00,0x00,0x0F,0xFF,0xFF,0xFF,0xE0, // ####################################........................###############################.....
  0xFF,0xFF,0xFF,0xFF,0xF0,0x00,0x00,0x3F,0xFF,0xFF,0xFF,0xE0, // ####################################......................#################################.....
  0xFF,0xFF,0xFF,0xFF,0xF0,0x00,0x00,0x7F,0xFF,0xFF,0xFF,0xE0, // ####################################.....................##################################.....
  0xFF,0xFF,0xFF,0xFF,0xF0,0x00,0x01,0xFF,0xFF,0xFF,0xFF,0xE0, // ####################################...................####################################.....
  0xFF,0xFF,0xFF,0xFF,0xF0,0x00,0x07,0xFF,0xFF,0xFF,0xFF,0xE0, // ####################################.................######################################.....
  0xFF,0xFF,0xFF,0xFF,0xF0,0x00,0x1F,0xFF,0xFF,0xFF,0xFF,0xE0, // ####################################...............########################################.....
  0xFF,0xFF,0xFF,0xFF,0xF0,0x00,0x7F,0xFF,0xFF,0xFF,0xFF,0xE0, // ####################################.............##########################################.....
  0xFF,0xFF,0xFF,0xFF,0xF0,0x01,0xFF,0xFF,0xFF,0xFF,0xFF,0xE0, // ####################################...........############################################.....
  0xFF,0xFF,0xFF,0xFF,0xF0,0x07,0xFF,0xFF,0xFF,0xFF,0xFF,0xE0, // ####################################.........##############################################.....
  0xFF,0xFF,0xFF,0xFF,0xF0,0x1F,0xFF,0xFF,0xFF,0xFF,0xFF,0xE0, // ####################################.......################################################.....
  0xFF,0xFF,0xFF,0xFF,0xF0,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xE0, // ####################################.....##################################################.....
  0xFF,0xFF,0xFF,0xFF,0xF1,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xE0, // ####################################...####################################################.....
  0xFF,0xFF,0xFF,0xFF,0xF7,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xE0, // ####################################.######################################################.....
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xE0, // ###########################################################################################.....
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xE0, // ###########################################################################################.....
  0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xE0, // ###########################################################################################.....
  0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xE0, // .##########################################################################################.....
  0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xE0, // .##########################################################################################.....
  0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xC0, // .#########################################################################################......
  0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xC0, // .#########################################################################################......
  0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xC0, // .#########################################################################################......
  0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xC0, // .#########################################################################################......
  0x3F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xC0, // ..########################################################################################......
  0x3F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x80, // ..#######################################################################################.......
  0x3F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x80, // ..#######################################################################################.......
  0x1F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00, // ...#####################################################################################........
  0x1F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00, // ...#####################################################################################........
  0x0F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0x00, // ....###################################################################################.........
  0x07,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFC,0x00, // .....#################################################################################..........
  0x03,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF8,0x00, // ......###############################################################################...........
  0x01,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,0x00, // .......#############################################################################............
  0x00,0x3F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xC0,0x00, // ..........########################################################################..............
  0x00,0x00,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xC0,0x00,0x00  // .................#########################################################......................
};


const unsigned char audi_logo [] PROGMEM = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x7c, 0x00, 0x00, 0xfc, 0x00, 0x00, 0xf8, 0x00, 0x01, 0xf0, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x07, 0xff, 0xe0, 0x07, 0xff, 0xc0, 0x0f, 0xff, 0xc0, 0x1f, 0xff, 0x80, 0x00, 0x00, 
  0x00, 0x00, 0x3f, 0xff, 0xfc, 0x7f, 0xff, 0xf8, 0x7f, 0xff, 0xf0, 0xff, 0xff, 0xe0, 0x00, 0x00, 
  0x00, 0x00, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xfd, 0xff, 0xff, 0xfd, 0xff, 0xff, 0xf8, 0x00, 0x00, 
  0x00, 0x01, 0xfe, 0x00, 0x7f, 0xfc, 0x00, 0xff, 0xfc, 0x01, 0xff, 0xf8, 0x01, 0xfe, 0x00, 0x00, 
  0x00, 0x03, 0xf0, 0x00, 0x1f, 0xf0, 0x00, 0x1f, 0xe0, 0x00, 0x3f, 0xe0, 0x00, 0x7f, 0x00, 0x00, 
  0x00, 0x07, 0xe0, 0x00, 0x0f, 0xe0, 0x00, 0x1f, 0xc0, 0x00, 0x1f, 0xc0, 0x00, 0x1f, 0x80, 0x00, 
  0x00, 0x0f, 0xc0, 0x00, 0x1f, 0xf0, 0x00, 0x1f, 0xe0, 0x00, 0x3f, 0xe0, 0x00, 0x0f, 0xc0, 0x00, 
  0x00, 0x1f, 0x00, 0x00, 0x3f, 0xf8, 0x00, 0x3f, 0xf0, 0x00, 0x7f, 0xe0, 0x00, 0x03, 0xe0, 0x00, 
  0x00, 0x3e, 0x00, 0x00, 0x3e, 0x78, 0x00, 0x7c, 0xf8, 0x00, 0xf9, 0xf0, 0x00, 0x03, 0xe0, 0x00, 
  0x00, 0x3e, 0x00, 0x00, 0x7c, 0x7c, 0x00, 0x78, 0xf8, 0x00, 0xf8, 0xf0, 0x00, 0x01, 0xf0, 0x00, 
  0x00, 0x3c, 0x00, 0x00, 0x78, 0x3c, 0x00, 0xf8, 0x78, 0x00, 0xf0, 0xf8, 0x00, 0x00, 0xf0, 0x00, 
  0x00, 0x7c, 0x00, 0x00, 0x78, 0x3c, 0x00, 0xf0, 0x7c, 0x01, 0xf0, 0x78, 0x00, 0x00, 0xf0, 0x00, 
  0x00, 0x7c, 0x00, 0x00, 0x78, 0x3e, 0x00, 0xf0, 0x7c, 0x01, 0xe0, 0x78, 0x00, 0x00, 0xf0, 0x00, 
  0x00, 0x78, 0x00, 0x00, 0xf8, 0x3e, 0x00, 0xf0, 0x3c, 0x01, 0xe0, 0x78, 0x00, 0x00, 0xf8, 0x00, 
  0x00, 0x78, 0x00, 0x00, 0xf8, 0x3e, 0x00, 0xf0, 0x3c, 0x01, 0xe0, 0x78, 0x00, 0x00, 0xf8, 0x00, 
  0x00, 0x7c, 0x00, 0x00, 0xf8, 0x3e, 0x00, 0xf0, 0x3c, 0x01, 0xe0, 0x78, 0x00, 0x00, 0xf0, 0x00, 
  0x00, 0x7c, 0x00, 0x00, 0x78, 0x3c, 0x00, 0xf0, 0x7c, 0x01, 0xf0, 0x78, 0x00, 0x00, 0xf0, 0x00, 
  0x00, 0x3c, 0x00, 0x00, 0x78, 0x3c, 0x00, 0xf8, 0x7c, 0x01, 0xf0, 0xf8, 0x00, 0x00, 0xf0, 0x00, 
  0x00, 0x3c, 0x00, 0x00, 0x7c, 0x7c, 0x00, 0xf8, 0x78, 0x00, 0xf0, 0xf8, 0x00, 0x01, 0xf0, 0x00, 
  0x00, 0x3e, 0x00, 0x00, 0x3c, 0x78, 0x00, 0x7c, 0xf8, 0x00, 0xf9, 0xf0, 0x00, 0x01, 0xe0, 0x00, 
  0x00, 0x1f, 0x00, 0x00, 0x3e, 0xf8, 0x00, 0x7d, 0xf0, 0x00, 0x7d, 0xf0, 0x00, 0x03, 0xe0, 0x00, 
  0x00, 0x1f, 0x80, 0x00, 0x1f, 0xf0, 0x00, 0x3f, 0xf0, 0x00, 0x3f, 0xe0, 0x00, 0x07, 0xc0, 0x00, 
  0x00, 0x0f, 0xc0, 0x00, 0x0f, 0xe0, 0x00, 0x1f, 0xe0, 0x00, 0x3f, 0xc0, 0x00, 0x0f, 0xc0, 0x00, 
  0x00, 0x07, 0xf0, 0x00, 0x0f, 0xe0, 0x00, 0x1f, 0xc0, 0x00, 0x1f, 0xc0, 0x00, 0x3f, 0x00, 0x00, 
  0x00, 0x01, 0xfc, 0x00, 0x7f, 0xfc, 0x00, 0x7f, 0xf8, 0x00, 0xff, 0xf0, 0x01, 0xfe, 0x00, 0x00, 
  0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 
  0x00, 0x00, 0x3f, 0xff, 0xfc, 0x7f, 0xff, 0xf8, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xf0, 0x00, 0x00, 
  0x00, 0x00, 0x0f, 0xff, 0xf0, 0x1f, 0xff, 0xe0, 0x3f, 0xff, 0xe0, 0x3f, 0xff, 0xc0, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x01, 0xfe, 0x00, 0x01, 0xfc, 0x00, 0x03, 0xfc, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x01, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x03, 0xff, 0xc0, 0x3f, 0x01, 0xf8, 0x3f, 0xff, 0x83, 0xf0, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x03, 0xf7, 0xe0, 0x3f, 0x01, 0xf8, 0x7f, 0xff, 0xe3, 0xf0, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x07, 0xe3, 0xf0, 0x3f, 0x01, 0xf9, 0xfe, 0x1f, 0xe3, 0xf0, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x0f, 0xc3, 0xf8, 0x3f, 0x01, 0xfb, 0xf8, 0x07, 0xf3, 0xf0, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x1f, 0x81, 0xfc, 0x3f, 0x01, 0xfb, 0xf0, 0x03, 0xf3, 0xf0, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x1f, 0x80, 0xfe, 0x3f, 0x01, 0xfb, 0xf0, 0x01, 0xf3, 0xf0, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x7f, 0xff, 0xfe, 0x3f, 0x01, 0xfb, 0xf0, 0x03, 0xf3, 0xf0, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x3f, 0x83, 0xf1, 0xf8, 0x07, 0xf3, 0xf0, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x9f, 0xcf, 0xf1, 0xff, 0x3f, 0xe3, 0xf0, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x01, 0xf8, 0x00, 0x1f, 0xcf, 0xff, 0xe0, 0x7f, 0xff, 0xc3, 0xf0, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x03, 0xf8, 0x00, 0x0f, 0xe7, 0xff, 0xc0, 0x3f, 0xff, 0x03, 0xf0, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
};


int sensorValue = 0;
int voltage = 0;
const int analogInPin = A0;

//display.invertDisplay(true); // invert the colours of led display
//display.invertDisplay(false);
//display.drawPixel(10, 10, WHITE);//to highlight a particular pixel
void setup()   
{ 
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize I2C addr to 0x3C ( for 128x64 Display )
  
  display.clearDisplay(); // clear the display before starting the program to avoid adafruit splashscreen ( *we can also skip it by modifing header file )
  // drawBitmap(x-axis position, y-axis position, bitmap data, bitmap width, bitmap height, color)
  
}
/////////////////////////////////////////////////////////////////////////////////////////////



void loop() 
{ 
  display.clearDisplay();
  display.drawBitmap(0, 0, bitmap_YT, 103, 64, WHITE);
  display.display();
  delay(1000);
  display.clearDisplay();
  display.drawBitmap(0, 0, bitmap_YT1, 91, 64, WHITE);
  display.display();
  delay(1000);
  display.clearDisplay();
  display.drawBitmap(0, 0, audi_logo, 128, 64, WHITE);
  display.display();
  delay(1000);
  
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("VIRAL");
  display.setCursor(1,20);
  display.println("SCIENCE");
  display.display();
  delay(1000);
  
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(1,0);
  display.println("SUBSCRIBE");
  display.display();
  delay(1000);
  
}