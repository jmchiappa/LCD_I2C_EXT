/*
    LCD_I2C - Arduino library to control a 16x2 LCD via an I2C adapter based on PCF8574
    * 2021-11-18 Brewmanz: make changes to also work for 20x4 LCD2004

    Copyright(C) 2020 Blackhack <davidaristi.0504@gmail.com>

    This program is free software : you can redistribute it and /or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.If not, see < https://www.gnu.org/licenses/>.
*/

#ifndef _LCD_I2C_EXT_h
#define _LCD_I2C_EXT_h

#include "LCD_I2C.h"
#include "Wire.h"

class LCD_I2C_EXT : public LCD_I2C
{
public:
    LCD_I2C_EXT(uint8_t address, uint8_t columns = 16, uint8_t rows = 2)
    : LCD_I2C_EXT(&Wire,address,columns,rows) {}
    
    LCD_I2C_EXT(TwoWire *i2c, uint8_t address, uint8_t columns = 16, uint8_t rows = 2)
    : _i2c(i2c), _address(address), LCD_I2C(address,columns,rows) {}

    void begin(bool beginWire = false);

private:
    void I2C_Write(uint8_t output);

private:
    uint8_t _address;
    TwoWire *_i2c;
};

#endif
