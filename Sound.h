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
    
    void setMusicPosition(glm::vec3 position);
    void setMusic2Position(glm::vec3 position);
    void setWasdPosition(glm::vec3 position);
    void setScratch1Position(glm::vec3 position);
    void setScratch2Position(glm::vec3 position);
    void setScratch3Position(glm::vec3 position);
    void setOxygenPosition(glm::vec3 position);
    void setOutPosition(glm::vec3 position);
    void setKlicksPosition(glm::vec3 position);
    void setHeartbeatPosition(glm::vec3 position);
    void setNoisePosition(glm::vec3 position);

    void playMusic2();
    void playMusic();
    void playWasd();
    void playScratch1();
    void playScratch2();
    void playScratch3();
    void playOxygen();
    void playOut();
    void playKlicks();
    void playHeartbeat();
    void playNoise();
    
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
            
    ALuint music_source_;
    ALuint music_source2_;
    ALuint music_buffer_;
    
    ALuint wasd_source_;
    ALuint wasd_buffer_;
    
    ALuint scratch1_source_;
    ALuint scratch1_buffer_;    
    
    ALuint scratch2_source_;
    ALuint scratch2_buffer_;    
    
    ALuint scratch3_source_;
    ALuint scratch3_buffer_;
    
    ALuint oxygen_source_;
    ALuint oxygen_buffer_;
    
    ALuint out_source_;
    ALuint out_buffer_;
    
    ALuint klicks_source_;
    ALuint klicks_buffer_;
    
    ALuint heartbeat_source_;
    ALuint heartbeat_buffer_;
    
    ALuint noise_source_;
    ALuint noise_buffer_;
    

};

#endif	/* SOUND_H */

