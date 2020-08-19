#ifndef ANIMATION_H
#define ANIMATION_H


struct Animation
{
    Animation(int index, int frames, int speed):
        animIndex(index),
        animFrames(frames),
        animSpeed(speed)
    {}
    int animIndex;
    int animFrames;
    int animSpeed;
};

#endif // ANIMATION_H
