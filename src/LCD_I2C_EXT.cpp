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

#include "LCD_I2C_EXT.h"
#include "Wire.h"

void LCD_I2C_EXT::begin(bool beginWire)
{
    if (beginWire)
        _i2c->begin();

    LCD_I2C::begin(false);
}

void LCD_I2C_EXT::I2C_Write(uint8_t output)
{
    _i2c->beginTransmission(_address);
    _i2c->write(output);
    _i2c->endTransmission();
}
