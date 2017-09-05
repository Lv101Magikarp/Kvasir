#include "vision.hpp"

void visionStart(bool setupMasks, bool printMasks, bool trackObjects,
                 bool printObjects, bool showImage, bool printTime, bool fixedSamplingPeriod)
{
    FramesHolder frames;
    ColorMasks masks;
    SightedObjects *objects = SightedObjects::getInstance();

    frames.setCameraToDefault();

    if(setupMasks)
    {
        masks.setupMasks(&frames);
        masks.saveMaskFile(COLOR_MASKS_FILENAME);
    }

    masks.openMaskFile(COLOR_MASKS_FILENAME);

    if(printMasks)
        masks.printMasks();

    std::clock_t clock_start;

    while(trackObjects)
    {
        clock_start = clock();

        objects->sharedMemoryTest();

        objects->destroyList();
        objects->saveListHead();

        frames.findObjectsFromMasks(&masks,objects);

        if(printObjects)
            objects->printObjects();

        if(showImage)
        {
            objects->paintObjects(&frames);
            frames.showRawImage();
        }

        if(cv::waitKey(WAIT_KEY_PRESS_TIME) == DONE_KEY)
        {
            objects->destroyList();
            break;
        }

        if(printTime)
            std::cout << std::endl << "Object finding time: "
                      << (clock()-clock_start)/(CLOCKS_PER_SEC*0.000001) << std::endl;

        if(fixedSamplingPeriod)
            while((clock()-clock_start)/(CLOCKS_PER_SEC*0.000001) < SAMPLING_PERIOD)
                ;

        objects->incrementTime((useconds_t)((clock()-clock_start)/(CLOCKS_PER_SEC*0.000001)));
    }
    objects->~SightedObjects();
}
