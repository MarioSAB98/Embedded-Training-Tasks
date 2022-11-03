/*
* DIO_utilities.h
*
* Created: 11/3/2022 1:37:42 AM
*  Author: Mario
*/

#ifndef DIO_UTILITES_H_
#define DIO_UTILITES_H_

#define assign_bit(reg,bit_no,value)	(reg = ((~(1<<bit_no) & reg)|(value<<bit_no)))
#define get_bit(reg,bits_no)			(reg & (1<< bits_no))>> bits_no
#define set_bit(reg,bits_no)			(reg|= (1<<bits_no))
#define clr_bit(reg,bits_no)			(reg &= ~(1 << bits_no))
#define toggle_bit(reg,bits_no)		(reg ^= (1 << bits_no))
#define assign_reg(reg,value)			reg|=value
#define set_reg(reg)					reg =0xff
#define clr_reg(reg)					reg=0x00
#define toggle_reg(reg)					reg ^=0xff
#define get_low_nible(reg)				reg & 0x0f
#define clr_low_nible(reg)				reg &= 0xf0
#define set_low_nible(reg)				reg |= 0x0f
#define toggle_low_nible(reg)			reg ^= 0x0f
#define assign_low_nible(reg,value)		reg |= (reg & 0xf0) | (value & 0x0f)
#define get_high_nible(reg)				(reg & 0xf0) >>4
#define clr_high_nible(reg)				reg &= 0x0f
#define set_high_nible(reg)				reg |= 0xf0
#define toggle_high_nible(reg)			reg ^= 0xf0
#define assing_high_nible(reg,value)	reg = (reg & x0f) | (value <<4)
#define assigning_reg(reg,value)		reg=value

#endif /* DIO_UTILITES_H_ */
