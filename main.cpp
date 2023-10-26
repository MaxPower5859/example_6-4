//=====[Libraries]=============================================================

#include "smart_home_system.h"

//=====[Main function, the program entry point after power on or reset]========

int main()
{
    smartHomeSystemInit();
    while (true) {
        smartHomeSystemUpdate();
    }
}
/*
Los pines utilizados por el SPI son:

#define SPI1_MOSI PA_7
#define SPI1_MISO PA_6
#define SPI1_SCK  PA_5
#define SPI1_CS   PD_14

clases
DigitalOut spiSt7920ChipSelect(SPI1_CS);
SPI spiSt7920(SPI1_MOSI, SPI1_MISO, SPI1_SCK);

en display init se inicializa como:
    if( display.connection == DISPLAY_CONNECTION_SPI) {
        spiSt7920.format( 8, 3 );
        spiSt7920.frequency( 1000000 );
    }   
 y despues


En la funcion static void displayCodeWrite( bool type, uint8_t dataBus )
Se utiliza el lock y unlock, es para que el sistema no tome propiedad de esas 
variables mientras estan bloqueadas esto lo hace para el objeto spist7920, 
ya que tiene que cargar los datos a mandar

Las funciones displayPinWrite( uint8_t pinName, int value ) y  displayDataBusWrite( uint8_t dataBus )
no hace nada en el caso de spi ya que la trama se manda directamente
*/
