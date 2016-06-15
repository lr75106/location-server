#include<stdio.h>
#include<fcntl.h>
#include<linux/videodev2.h>

void main()
{
	int fd=open("/dev/video0",O_RDWR);
	//system("sleep 3");
	struct v4l2_capability cap;
	ioctl(fd,VIDIOC_QUERYCAP,&cap);
	printf("\nDriverName:%s\nCard Name:%s\nBus info:%s\nDriverVersion:%u.%u.%u\n",
	cap.driver,cap.card,cap.bus_info,
	(cap.version>>16)&0xFF,(cap.version>>8)&0xFF,cap.version&0xFF);
	
	struct v4l2_fmtdesc fmtdesc;
	fmtdesc.index=0;
	fmtdesc.type=V4L2_BUF_TYPE_VIDEO_CAPTURE;
	printf("\nSupportformat:\n");
	while(ioctl(fd,VIDIOC_ENUM_FMT,&fmtdesc)!=-1)  
	{  
		printf("\t%d.%s\n",fmtdesc.index+1,fmtdesc.description);  
		fmtdesc.index++;  
	} 

	struct v4l2_format fmt;
	fmt.type=V4L2_BUF_TYPE_VIDEO_CAPTURE;
	ioctl(fd,VIDIOC_G_FMT,&fmt);
	printf("currentdata format information:\n\twidth:%d\n\theight:%d",fmt.fmt.pix.width,fmt.fmt.pix.height);
	fmtdesc.index=0;
	while(ioctl(fd,VIDIOC_ENUM_FMT,&fmtdesc)!=-1)
	{
		if(fmtdesc.pixelformat/*& fmt.fmt.pixelformat*/)
		{
			printf("\n\tformat:%s\n",fmtdesc.description);
			break;
		}
		fmtdesc.index++;
	}
	close(fd);
}


