/*
 * ultra.h
 *
 *  Created on: Mar 2, 2025
 *      Author: user
 */

#ifndef INC_ULTRA_H_
#define INC_ULTRA_H_

#include "main.h"
#include "tim.h"
#include "usart.h"

extern float distance;
extern float distance2;

void microDelay(uint16_t us);
void Distance();

int _write(int file, char *ptr, int len);


#endif /* INC_ULTRA_H_ */
