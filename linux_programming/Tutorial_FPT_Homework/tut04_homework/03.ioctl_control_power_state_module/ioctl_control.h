/* Ioctl header file to define the magic number */
#ifndef _IOCTL_H_
#define _IOCTL_H_

#include <linux/ioctl.h>  /* Needed for the _IOW etc stuff used later */

/* 
 * Ioctl definition	
 */

/* Define magic number */
#define POWER_IOC_MAGIC   	'P'


#define POWER_SHUTDOWN   	_IOW(POWER_IOC_MAGIC, 0, int)
#define POWER_RESTART  		_IOW(POWER_IOC_MAGIC, 1, int)

/* Define maximum number of IOCTL command */
#define POWER_IOC_MAX_NUM 	1

#endif