/* 
 * File:   Assets.h
 * Author: morgan
 *
 * Created on February 25, 2014, 6:38 PM
 */

#ifndef ASSETS_H
#define	ASSETS_H

#include <string>
#include <map>
#include <memory>
#include <mo/Mesh.h>
#include <mo/Texture2D.h>

class Assets {
public:
    typedef std::map<std::string, std::shared_ptr<mo::Mesh> > MeshMap;
    typedef std::map<std::string, std::shared_ptr<mo::Texture2D> > TextureMap;
    typedef std::pair<std::string, std::shared_ptr<mo::Mesh> > MeshPair;
    typedef std::pair<std::string, std::shared_ptr<mo::Texture2D> > TexturePair;
    
    Assets();
    virtual ~Assets();
    
    mo::Mesh * loadMesh(std::string path);
    mo::Texture2D * loadTexture(std::string path);    
    
private:
    MeshMap models_;
    TextureMap textures_;
};

#endif	/* ASSETS_H */

