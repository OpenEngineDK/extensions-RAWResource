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

#include <Resources/Texture2D.h>
#include <string>
#include <iostream>
#include <fstream>

#include <Logging/Logger.h>

namespace OpenEngine {
namespace Resources {

using namespace std;

/**
 * RAW image resource.
 *
 * @class RAWResource RAWResource.h Resources/RAWResource.h
 */
class RAWResource : public Texture2D<unsigned char> {
private:
    string filename;

public:

    /**
     * Constructor
     *
     * @param file tga file to load.
     */

    RAWResource() : Texture2D<unsigned char>() {}

    RAWResource(string file, int width, int height, int channels);
    ~RAWResource();

    // resource methods
    void Load();
};

} //NS Resources
} //NS OpenEngine

#endif // _RAW_RESOURCE_H_
