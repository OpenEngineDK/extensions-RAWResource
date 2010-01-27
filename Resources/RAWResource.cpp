// RAW image resource
// -------------------------------------------------------------------
// Copyright (C) 2007 OpenEngine.dk (See AUTHORS) 
// 
// This program is free software; It is covered by the GNU General 
// Public License version 2 or any later version. 
// See the GNU General Public License for more details (see LICENSE). 
//--------------------------------------------------------------------

#include <Resources/RAWResource.h>
#include <Resources/Exceptions.h>
#include <Resources/File.h>
#include <Utils/Convert.h>

namespace OpenEngine {
namespace Resources {

using OpenEngine::Utils::Convert;

RAWResource::RAWResource(string filename, int width, int height, int channels)
    : ITextureResource(), filename(filename){
    this->width = width;
    this->height = height;
    this->channels = channels;

    // Set format
    switch(this->channels){
    case 1:
        format = LUMINANCE;
        break;
    case 3:
        format = RGB;
        break;
    case 4:
        format = RGBA;
        break;
    default:
        throw Exception("unknown color format");
    }
}

RAWResource::~RAWResource() {
    this->Unload();
}

void RAWResource::Load() {
    if (this->data) return;
    ifstream* file = File::Open(filename,ios::binary);

    //@todo: check that the file size equals w*h*d

    long size = this->width * this->height * this->channels;;
    this->data = new unsigned char[size];
    
    file->read((char*)this->data, sizeof(unsigned char)*size); 
    if (file->fail()) {
        delete [] this->data;
        this->data = NULL;
        file->close();
        delete file;
        throw ResourceException("Error loading RAW data in: " + filename);
    }
    file->close();
    delete file;

    // no image data 
    if (this->data == NULL)
    	throw ResourceException("Unsupported data in file: " + filename);
}

} //NS Resources
} //NS OpenEngine
