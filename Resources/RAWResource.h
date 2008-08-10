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
#include <Resources/ResourcePlugin.h>
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
    bool loaded;
    string filename;
    unsigned char* data;
    int id, width, height, depth;

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

    RAWResource() : loaded(false),data(NULL) {
        width = height = depth = id = 0;
    };

    RAWResource(string file, int width, int height, int depth);
    ~RAWResource();

    // resource methods
    void Load();
    void Unload();

    // texture resource methods
	int GetID();
	void SetID(int id);   
    int GetWidth();
	int GetHeight();
	int GetDepth();
	unsigned char* GetData();

};

} //NS Resources
} //NS OpenEngine

BOOST_CLASS_EXPORT(OpenEngine::Resources::RAWResource)

#endif // _RAW_RESOURCE_H_
