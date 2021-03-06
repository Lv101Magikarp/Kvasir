#ifndef MOVEMENT_HPP
#define MOVEMENT_HPP

class Movement
{
private:

public:
    bool stay_still;
    double linear_vel_angle;
    double linear_vel_scaling;
    double angular_vel_scaling; //positive for one direction, negative for the other

    inline Movement() : stay_still(true), linear_vel_angle(0),
    linear_vel_scaling(0), angular_vel_scaling(0) {};

    inline Movement& operator=(const Movement &copied)
    {
        if(this != &copied)
        {
            stay_still = copied.stay_still;
            linear_vel_angle = copied.linear_vel_angle;
            linear_vel_scaling = copied.linear_vel_scaling;
            angular_vel_scaling = copied.angular_vel_scaling;
        }
        return *this;
    }
};

#endif // MOVEMENT_HPP
