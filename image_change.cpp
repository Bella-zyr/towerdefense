#include "image_change.h"

Image_Change::Image_Change()
{
   index =-1;
}
//�л�ͼƬ�ķ���
char * Image_Change::NextImage()
{
    if(index>=1)//����ͼƬ��ʾ��󣬾Ͱ�index��0��������ʾ��һ��ͼƬ
        index=0;
    else index++;
    return images[index];//����ͼƬ·��
}
