/* 
 * File:   Sound.h
 * Author: morgan
 *
 * Created on April 27, 2014, 10:55 AM
 */

#ifndef SOUND_H
#define	SOUND_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>  /* for usleep() */
#include <math.h>    /* for sqrtf() */
#include <time.h>    /* for time(), to seed srand() */

/* OpenAL headers */
#include <AL/al.h>
#include <AL/alc.h>
#include <AL/alext.h>

#include <glm/glm.hpp>

class Sound {
public:
    Sound();
    void setListenerPosition(glm::vec3 position);
    void setListenerVelocity(glm::vec3 velocity);
    void setListenerOrientation(glm::vec3 orientation);
    
    void setSourcePosition(glm::vec3 position);
    void setSourceVelocity(glm::vec3 velocity);    
    
    void play();
    
    void* load( char *fname, long *bufsize ){
        FILE* fp = fopen( fname, "rb" );
        fseek( fp, 0L, SEEK_END );
        long len = ftell( fp );
        rewind( fp );
        void *buf = malloc( len );
        fread( buf, 1, len, fp );
        fclose( fp );
        *bufsize = len;
        return buf;
     }
    
    virtual ~Sound();
private:    
    ALCdevice* device_;
    ALCcontext* context_;
    
    ALuint source_;
    ALuint buffer_;
    

};

#endif	/* SOUND_H */

