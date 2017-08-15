#include "framesholder.hpp"

using namespace cv;

FramesHolder::FramesHolder(){}

/**
    void FramesHolder::setCameraToDefault(void)

    Sets the camera to the system's default and sets the
    capture size to the size specified in visionconstants.h.

    @author Lucca Rawlyk
    @version 2017.08.14-1
*/

void FramesHolder::setCameraToDefault(void)
{
    camera.open(0);
    camera.set(CV_CAP_PROP_FRAME_WIDTH,FRAME_WIDTH);
    camera.set(CV_CAP_PROP_FRAME_HEIGHT,FRAME_HEIGHT);
}

/**
    void FramesHolder::updateRawAndHSVImages(void)

    Updates the raw image from the set camera and calculates the hsv image from it.

    @author Lucca Rawlyk
    @version 2017.08.14-1
*/

void FramesHolder::updateRawAndHSVImages(void)
{
    camera.read(raw_image);
    cvtColor(raw_image,hsv_image,COLOR_RGB2HSV);
}

/**
    void FramesHolder::updateThresholdedImage(HSVMask* mask)

    Updates the thresholded image using the mask parameter, and uses morphing operations if set to.

    @author Lucca Rawlyk
    @version 2017.08.14-1
*/

void FramesHolder::updateThresholdedImage(HSVMask* mask)
{
    inRange(hsv_image,Scalar(mask->h_min, mask->s_min, mask->v_min),
            Scalar(mask->h_max, mask->s_max, mask->v_max),thresholded_image);
    if(USE_MORPHING_OPERATIONS)
        useMorphingOperations();
}

/**
    void FramesHolder::useMorphingOperations(void)

    Uses morphing operations to try to correct object outlines.

    @author Lucca Rawlyk
    @version 2017.08.14-1
*/

void FramesHolder::useMorphingOperations(void)
{
    Mat erode_element = getStructuringElement(MORPH_RECT,
                                              Size(MORPH_OPS_ERODE_RECT_SIZE,MORPH_OPS_ERODE_RECT_SIZE));
    Mat dilate_element = getStructuringElement(MORPH_RECT,
                                               Size(MORPH_OPS_DILATE_RECT_SIZE,MORPH_OPS_DILATE_RECT_SIZE));

    erode(thresholded_image,thresholded_image,erode_element);
    erode(thresholded_image,thresholded_image,erode_element);

    dilate(thresholded_image,thresholded_image,dilate_element);
    dilate(thresholded_image,thresholded_image,dilate_element);
}

void FramesHolder::showAllImages(void)
{
    imshow(RAW_IMAGE_WINDOW_NAME,raw_image);
    imshow(HSV_IMAGE_WINDOW_NAME,hsv_image);
    imshow(THRESHOLDED_IMAGE_WINDOW_NAME,thresholded_image);
}

void FramesHolder::showRawImage(void)
{
    imshow(RAW_IMAGE_WINDOW_NAME,raw_image);
}

void FramesHolder::showHSVImage(void)
{
    imshow(HSV_IMAGE_WINDOW_NAME,hsv_image);
}

void FramesHolder::showThresholdedImage(void)
{
    imshow(THRESHOLDED_IMAGE_WINDOW_NAME,thresholded_image);
}

/**
    void FramesHolder::setupHSVMaskFromWindow(HSVMask* mask, objectColor color, int* active)

    Sets up a window able to display the raw, hsv and thresholded images,
    and ajust the mask using sliders.

    @author Lucca Rawlyk
    @version 2017.08.14-1
*/

void FramesHolder::setupHSVMaskFromWindow(HSVMask* mask, objectColor color)
{
    string window_name;

    switch(color)
    {
        case RED:
        window_name = RED_MASK_WINDOW_NAME; break;
        case ORANGE:
        window_name = ORANGE_MASK_WINDOW_NAME; break;
        case YELLOW:
        window_name = YELLOW_MASK_WINDOW_NAME; break;
        case GREEN:
        window_name = GREEN_MASK_WINDOW_NAME; break;
        case BLUE:
        window_name = BLUE_MASK_WINDOW_NAME; break;
        case VIOLET:
        window_name = VIOLET_MASK_WINDOW_NAME; break;
    }

    namedWindow(window_name, 1);

    int displayed_image = 0;

    createTrackbar(DISPLAYED_IMAGE_TRACKBAR_NAME, window_name, &displayed_image, 2, NULL);
    createTrackbar(H_MIN_TRACKBAR_NAME, window_name, &(mask->h_min), MAX_MASK_VALUE, NULL);
    createTrackbar(H_MAX_TRACKBAR_NAME, window_name, &(mask->h_max), MAX_MASK_VALUE, NULL);
    createTrackbar(S_MIN_TRACKBAR_NAME, window_name, &(mask->s_min), MAX_MASK_VALUE, NULL);
    createTrackbar(S_MAX_TRACKBAR_NAME, window_name, &(mask->s_max), MAX_MASK_VALUE, NULL);
    createTrackbar(V_MIN_TRACKBAR_NAME, window_name, &(mask->v_min), MAX_MASK_VALUE, NULL);
    createTrackbar(V_MAX_TRACKBAR_NAME, window_name, &(mask->v_max), MAX_MASK_VALUE, NULL);
    createTrackbar(ACTIVE_TRACKBAR_NAME, window_name, &(mask->active), true, NULL);

    while(1)
    {
        updateRawAndHSVImages();
        updateThresholdedImage(mask);

        switch(displayed_image)
        {
            case 0:
                imshow(window_name,thresholded_image); break;
            case 1:
                imshow(window_name,raw_image); break;
            case 2:
                imshow(window_name,hsv_image); break;
        }

        if(waitKey(WAIT_KEY_PRESS_TIME) == DONE_KEY)
            break;
    }

    destroyWindow(window_name);
}
