#include "alg_datachange.h"
#include "string.h"
#include "config.h"
float photo_data[2]={140,157};
void char_to_float(uint8_t* buffer)
{
		memcpy(&radar_data[0],buffer+1,sizeof(float));
		memcpy(&radar_data[1],buffer+5,sizeof(float));
		memcpy(&radar_data[2],buffer+9,sizeof(float));	
//			memcpy(&photo_data[0],buffer+1,sizeof(float));
//		memcpy(&photo_data[1],buffer+5,sizeof(float));//视觉数据解包
}


