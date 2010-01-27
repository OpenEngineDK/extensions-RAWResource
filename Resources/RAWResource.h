// RAW image resource
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#ifndef _RAW_RESOURCE_H_
#define _RAW_RESOURCE_H_

#include <Resources/ITextureResource.h>
#include <string>
#include <iostream>
#include <fstream>

#include <boost/serialization/base_object.hpp>
#include <boost/serialization/export.hpp>
#include <boost/serialization/split_member.hpp>
#include <Logging/Logger.h>

namespace OpenEngine {
namespace Resources {

using namespace std;

/**
 * RAW image resource.
 *
 * @class RAWResource RAWResource.h Resources/RAWResource.h
 */
class RAWResource : public ITextureResource {
private:
    string filename;

public:

    /**
     * Constructor
     *
     * @param file tga file to load.
     */

    //    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version) {
        ar & boost::serialization::base_object<ITextureResource>(*this);
        ar & filename;
    }

    RAWResource() : ITextureResource() {}

    RAWResource(string file, int width, int height, int channels);
    ~RAWResource();

    // resource methods
    void Load();
    //    void Unload();
};

} //NS Resources
} //NS OpenEngine

BOOST_CLASS_EXPORT(OpenEngine::Resources::RAWResource)

#endif // _RAW_RESOURCE_H_
