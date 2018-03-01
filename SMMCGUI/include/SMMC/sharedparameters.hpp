#ifndef SHAREDPARAMETERS_HPP
#define SHAREDPARAMETERS_HPP

#include <boost/serialization/utility.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

#include <iostream>
#include <fstream>

#include "smmclib.hpp"

class SharedParameters
{
private:
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive &ar, const unsigned int version);

    void loadDefaults(void);

    //Vision variables
    VisionField vision_field;

    //AI variables

    //Communication variables

public:
    SharedParameters();
    ~SharedParameters();
    void loadSettingsFromFile(void);
};

#endif // SHAREDPARAMETERS_HPP
