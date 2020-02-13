/* Ioctl header file to define the magic number */
#ifndef _IOCTL_H_
#define _IOCTL_H_

#include <linux/ioctl.h>  /* Needed for the _IOW etc stuff used later */

/* 
 * Ioctl definition	
 */

/* Define magic number */
#define LED_IOC_MAGIC   	'L'

#define LED_BLINK			_IOW(LED_IOC_MAGIC, 0, int)
#define LED_ON_OFF			_IOW(LED_IOC_MAGIC, 1, int)

/* Define maximum number of IOCTL command */
#define LED_IOC_MAX_NUM 	1

#endif