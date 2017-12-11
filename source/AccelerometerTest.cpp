#include "MicroBit.h"

extern MicroBit uBit;

void 
fxos_test()
{
    int result;

    while(1)
    {
        result = uBit.fxos.whoAmI();
        DMESG("WHOAMI: %d\n", result);
        uBit.sleep(1000);
    }
}

void
accelerometer_test1()
{
    while(1)
    {
        DMESG("Acc [X:%d][Y:%d][Z:%d]", uBit.accelerometer.getX(), uBit.accelerometer.getY(), uBit.accelerometer.getZ());
        uBit.sleep(1000);
    }
}

int g_to_pix(int g)
{
    int v = 2;
    if ( g < -200) v--;
    if ( g < -500) v--;
    if ( g > 200) v++;
    if ( g > 500) v++;

    return v;
}    

void
spirit_level2()
{
    DMESG("SPIRIT_LEVEL_2");

    int ox=0;
    int oy=0;
    int moves = 0;

    while(moves < 15)
    {
        int x = uBit.accelerometer.getX();
        int y = uBit.accelerometer.getY();
        int z = uBit.accelerometer.getZ();

        uBit.serial.printf("Acc [X:%d][Y:%d][Z:%d]\r\n", x, y, z);

        int px = g_to_pix(x);
        int py = g_to_pix(y);

        if (ox != px || oy != py)
            moves++;

        ox = px;
        oy = py;

        uBit.display.image.clear();
        uBit.display.image.setPixelValue(px,py,255);

        uBit.sleep(100);
    }

    uBit.display.clear();
}

void
spirit_level()
{
    while(1)
    {
        int x = uBit.accelerometer.getX();
        int y = uBit.accelerometer.getY();
        int z = uBit.accelerometer.getZ();

        DMESG("Acc [X:%d][Y:%d][Z:%d]", x, y, z);

        int px = g_to_pix(x);
        int py = g_to_pix(y);

        uBit.display.image.clear();
        uBit.display.image.setPixelValue(px,py,255);

        uBit.sleep(100);
    }
}

void
compass_test1()
{
    while(1)
    {
        DMESG("Mag [X:%d][Y:%d][Z:%d]", uBit.compass.getX(), uBit.compass.getY(), uBit.compass.getZ());
        uBit.sleep(1000);
    }
}

void
compass_test2()
{
    while(1)
    {
        DMESG("Heading [%d]", uBit.compass.heading());
        uBit.sleep(1000);
    }
}
