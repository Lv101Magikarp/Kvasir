#include "VelocitiesLoader.hpp"

using namespace boost::interprocess;

VelocitiesLoader* VelocitiesLoader::instance = NULL;

VelocitiesLoader* VelocitiesLoader::getInstance(void)
{
    if(instance==NULL)
        instance = new VelocitiesLoader;
    return instance;
}

VelocitiesLoader::VelocitiesLoader()
{
    shared_memory = NULL;
    openSharedMemory();
}

VelocitiesLoader::~VelocitiesLoader()
{
    delete instance;
}

void VelocitiesLoader::openSharedMemory(void)
{
    if(shared_memory!=NULL) //deletes the last opened vision shared memory if it exists
        delete shared_memory;

    bool opened = false;
    while(!opened)
    {
        try //tries to open the vision shared memory until it succeeds
        {
            shared_memory = new managed_shared_memory(open_only,AI_SHARED_MEMORY_NAME);
            opened = true;
        }
        catch(...)
        {
            std::cout<<"erro ao abrir memoria"<<std::endl;
        }
    }
}

void VelocitiesLoader::updateVelocities(void)
{
    bool opened = false;

    while(!opened)
    {
        try
        {
            robot_velocity = shared_memory->find<velocity>(VELOCITIES_MEMORY_NAME);
            opened = true;
        }
        catch(...)
        {
            std::cout << std::endl << "trying to reload the shared memory" << std::endl;
            openSharedMemory();
        }
    }
}

double VelocitiesLoader::getVelX(int robot)
{
    if(robot >= N_PLAYERS || robot < 0)
        return 0.0;
    return robot_velocity.first[robot].x;
}

double VelocitiesLoader::getVelY(int robot)
{
    if(robot >= N_PLAYERS || robot < 0)
        return 0.0;
    return robot_velocity.first[robot].y;
}

double VelocitiesLoader::getVelAng(int robot)
{
    if(robot >= N_PLAYERS || robot < 0)
        return 0.0;
    return robot_velocity.first[robot].ang;
}
