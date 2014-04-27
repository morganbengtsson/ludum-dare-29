/* 
 * File:   Sound.cpp
 * Author: morgan
 * 
 * Created on April 27, 2014, 10:55 AM
 */

#include "Sound.h"

Sound::Sound() {
    /* initialize OpenAL context, asking for 44.1kHz to match HRIR data */
   ALCint contextAttr[] = {ALC_FREQUENCY,44100,0};
   device_ = alcOpenDevice( NULL );
   context_ = alcCreateContext( device_, contextAttr );
   alcMakeContextCurrent(context_);    
   
   setListenerPosition(glm::vec3(0.0f, 1.5f, 0.0f));
   setListenerVelocity(glm::vec3(0.0f, 0.0f, 0.0f));
   setListenerOrientation(glm::vec3(0.0f, 0.0f, -1.0f));
   
   //One source for now
   alGenSources( 1, &source_);
   alSourcef( source_, AL_PITCH, 1. );
   alSourcef( source_, AL_GAIN, 1. );
   setSourcePosition(glm::vec3(0.0f, 0.0f, 3.0f));
   setSourceVelocity(glm::vec3(0.0f, 0.0f, 0.0f));
   alSourcei( source_, AL_LOOPING, AL_TRUE );   
   
   alGenBuffers( 1, &buffer_ );
   {
      long dataSize;
      const ALvoid* data = load( "footsteps.raw", &dataSize );
      /* for simplicity, assume raw file is signed-16b at 44.1kHz */
      alBufferData( buffer_, AL_FORMAT_MONO16, data, dataSize, 44100 );
      free( (void*)data );
   }
   alSourcei( source_, AL_BUFFER, buffer_ );      
}

void Sound::setListenerPosition(glm::vec3 position) {
    alListener3f( AL_POSITION, position.x, position.y, position.z);
}
void Sound::setListenerVelocity(glm::vec3 velocity) {
    alListener3f( AL_VELOCITY, velocity.x, velocity.y, velocity.z );
}
void Sound::setListenerOrientation(glm::vec3 orientation) {
   float orient[6] = { /*fwd:*/ orientation.x, orientation.y, orientation.z, /*up:*/ 0., 1., 0. };
   alListenerfv( AL_ORIENTATION, orient );
}

void Sound::setSourcePosition(glm::vec3 position) {
    alSource3f( source_, AL_POSITION, position.x, position.y, position.z );
}

void Sound::setSourceVelocity(glm::vec3 velocity){
    alSource3f( source_, AL_VELOCITY, velocity.x, velocity.y, velocity.z);
}

void Sound::play(){
   alSourcePlay( source_);
}

Sound::~Sound() {
   alDeleteSources( 1, &source_ );
   alDeleteBuffers( 1, &buffer_ );
   alcDestroyContext( context_ );
   alcCloseDevice( device_ );
}

