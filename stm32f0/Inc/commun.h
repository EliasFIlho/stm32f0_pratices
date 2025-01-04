/*
 * commun.h
 *
 *  Created on: Jan 4, 2025
 *      Author: elias
 */

#ifndef COMMUN_H_
#define COMMUN_H_

#define CLEAR_BIT(REG,BIT) ((REG) &= ~(1U << (BIT)))
#define SET_BIT(REG, BIT)      ((REG) |= (1U << (BIT)))
#define TOGGLE_BIT(REG, BIT)   ((REG) ^= (1U << (BIT)))

#endif /* COMMUN_H_ */