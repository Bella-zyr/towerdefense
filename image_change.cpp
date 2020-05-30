#include "image_change.h"

Image_Change::Image_Change()
{
   index =-1;
}
//切换图片的方法
char * Image_Change::NextImage()
{
    if(index>=1)//两张图片显示完后，就把index归0，重新显示第一张图片
        index=0;
    else index++;
    return images[index];//返回图片路径
}
