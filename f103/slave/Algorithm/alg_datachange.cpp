#include "alg_datachange.h"
#include "config.h"
#include "string.h"
int8_t static_error[2][2]={{10,-10},{-30,-50}};//先是下舵的右左，再是上舵
float last_error[2];//用来检测是否没有识别到
int count;
void char_to_uint32(uint8_t* buffer)
{
		memcpy(&error[0],buffer+1,sizeof(float));
		memcpy(&error[1],buffer+5,sizeof(float));//视觉数据解包
		memcpy(&photo_data[2],buffer+9,sizeof(uint8_t));
		memcpy(&photo_data[3],buffer+10,sizeof(uint8_t));
	
	if((last_error[0]==error[0])&&(last_error[1]==last_error[1]))
	{
		count++;
		if(count>=200)

			unwatch_flag=1;
	}
	else if(last_error[0]!=error[0])
		count=0;
	
		if(count>=500)
			count=0;
	if((error[0]<=static_error[0][0])&&(error[0]>=static_error[0][1])) error[0]=0;
	if(error[1]<=static_error[1][0]&&error[1]>=static_error[1][1]) error[1]=0;	
		last_error[0]=error[0];
	last_error[1]=error[1];
}

void char_to_float(uint8_t* buffer)
{
		memcpy(&radar_data[0],buffer,sizeof(float));
		memcpy(&radar_data[1],buffer+4,sizeof(float));
		memcpy(&radar_data[2],buffer+8,sizeof(float));	
}

