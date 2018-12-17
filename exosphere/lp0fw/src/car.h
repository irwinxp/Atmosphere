/*
 * Copyright (c) 2018 Atmosphère-NX
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 
#ifndef EXOSPHERE_WARMBOOT_BIN_CLOCK_AND_RESET_H
#define EXOSPHERE_WARMBOOT_BIN_CLOCK_AND_RESET_H

#include <stdint.h>

#define CAR_BASE 0x60006000

#define MAKE_CAR_REG(n) MAKE_REG32(CAR_BASE + n)

#define CLK_RST_CONTROLLER_MISC_CLK_ENB_0 MAKE_CAR_REG(0x048)
#define CLK_RST_CONTROLLER_OSC_CTRL_0 MAKE_CAR_REG(0x050)
#define CLK_RST_CONTROLLER_RST_DEVICES_H_0 MAKE_CAR_REG(0x008)
#define CLK_RST_CONTROLLER_LVL2_CLK_GATE_OVRD_0 MAKE_CAR_REG(0x3A4)
#define CLK_RST_CONTROLLER_RST_CPUG_CMPLX_SET_0 MAKE_CAR_REG(0x450)
#define CLK_RST_CONTROLLER_RST_CPUG_CMPLX_CLR_0 MAKE_CAR_REG(0x454)

#define CLK_RST_CONTROLLER_LVL2_CLK_GATE_OVRA_0 MAKE_CAR_REG(0x0F8)
#define CLK_RST_CONTROLLER_LVL2_CLK_GATE_OVRB_0 MAKE_CAR_REG(0x0FC)
#define CLK_RST_CONTROLLER_LVL2_CLK_GATE_OVRC_0 MAKE_CAR_REG(0x3A0)
#define CLK_RST_CONTROLLER_LVL2_CLK_GATE_OVRD_0 MAKE_CAR_REG(0x3A4)
#define CLK_RST_CONTROLLER_LVL2_CLK_GATE_OVRE_0 MAKE_CAR_REG(0x554)

#define CLK_RST_CONTROLLER_SPARE_REG0_0 MAKE_CAR_REG(0x55C)

#define CLK_RST_CONTROLLER_CLK_ENB_W_SET_0 MAKE_CAR_REG(0x448)

#define NUM_CAR_BANKS 7

typedef enum {
    CARDEVICE_UARTA = 6,
    CARDEVICE_UARTB = 7,
    CARDEVICE_I2C1 = 12,
    CARDEVICE_I2C5 = 47,
    CARDEVICE_ACTMON = 119,
    CARDEVICE_BPMP = 1
} CarDevice;

void car_configure_oscillators(void);
void car_mbist_workaround(void);

void clk_enable(CarDevice dev);
void clk_disable(CarDevice dev);
void rst_enable(CarDevice dev);
void rst_disable(CarDevice dev);

void clkrst_enable(CarDevice dev);
void clkrst_disable(CarDevice dev);

void clkrst_reboot(CarDevice dev);

#endif