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

RAWResource::RAWResource(string filename, int width, int height, int depth)
  : loaded(false), filename(filename), data(NULL),
    width(width), height(height), depth(depth) {
    id = 0;
}

RAWResource::~RAWResource() {
    Unload();
}

void RAWResource::Load() {
    if (loaded) return;
    ifstream* file = File::Open(filename,ios::binary);

    //@todo: check that the file size equals w*h*d

    int numberOfCharsPerColor = (depth/8);
    long size = width * height * numberOfCharsPerColor;
    data = new unsigned char[size]; 
    
    file->read((char*)data, sizeof(unsigned char)*size); 
    if (file->fail()) {
        delete [] data;
        data = NULL;
        file->close();
        delete file;
        throw ResourceException("Error loading RAW data in: " + filename);
    }
    file->close();
    delete file;

    // no image data 
    if (data == NULL)
    	throw ResourceException("Unsupported data in file: " + filename);

    loaded = true;
}

void RAWResource::Unload() {
    if (loaded) {
        delete[] data;
        loaded = false;
    }
}

int RAWResource::GetID(){
    return id;
}

void RAWResource::SetID(int id){
    this->id = id;
}

int RAWResource::GetWidth(){
    return width;
}

int RAWResource::GetHeight(){
    return height;
}

int RAWResource::GetDepth(){
    return depth;
}

unsigned char* RAWResource::GetData(){
    return data;
}

} //NS Resources
} //NS OpenEngine