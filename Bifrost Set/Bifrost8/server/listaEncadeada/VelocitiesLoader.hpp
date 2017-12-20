#ifndef VELOCITIESLOADER_HPP
#define VELOCITIESLOADER_HPP

#include <iostream>

#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/offset_ptr.hpp>

//should be the same as in aiconstants.h
//to be linked in the future
#define AI_SHARED_MEMORY_NAME "AI"
#define VELOCITIES_MEMORY_NAME "velocities"
#define N_PLAYERS 3

//should be the same as in velocity.h
//to be linked in the future
typedef struct
{
    double x;
    double y;
    double ang;
}velocity;

class VelocitiesLoader
{
private:
    boost::interprocess::managed_shared_memory *shared_memory;
    std::pair<velocity*, boost::interprocess::managed_shared_memory::size_type> robot_velocity;
    static VelocitiesLoader* instance;
    void openSharedMemory(void);
    VelocitiesLoader();
public:
    ~VelocitiesLoader();
    static VelocitiesLoader* getInstance(void);
    void updateVelocities(void);
    double getVelX(int robot);
    double getVelY(int robot);
    double getVelAng(int robot);
};

#endif // VELOCITIESLOADER_HPP
