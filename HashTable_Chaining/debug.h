#ifndef __DEBUG_H__
#define __DEBUG_H__

#include "errno.h"

#define TR_FUNC(_value_)  \
    if(_value_)            \
    printf("FILENAME:%s, FUNCNAME: %s, LINENUM: %d \r\n" \
	    , __FILE__, __FUNCTION__, __LINE__)

#define ERR_OUT(err) printf((char *)(__FILE__ ":%d = %s(%d)\n"), __LINE__, strerror((err)), (err))
#define ERR_SET_OUT(err, val) \
    do { \
        (err) = (val); \
        ERR_OUT(err);  \
    } while(0);

#endif 
