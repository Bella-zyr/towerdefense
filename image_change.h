#ifndef IMAGE_CHANGE_H
#define IMAGE_CHANGE_H


class Image_Change
{
public:
    Image_Change();
    char *NextImage();
    //ͼƬ·��
    char * images[2]={
        ":/image/beijing.png",":/image/map2.png"
    };
    int index;
};

#endif // IMAGE_CHANGE_H
