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
   alGenSources( 1, &music_source_);
   alSourcef( music_source_, AL_PITCH, 1. );
   alSourcef( music_source_, AL_GAIN, 1. );
   setMusicPosition(glm::vec3(0.0f, 0.0f, 3.0f));
   alSource3f( music_source_, AL_VELOCITY, 0.0f, 0.0f, 0.0f);
   alSourcei( music_source_, AL_LOOPING, AL_TRUE );

//One source for now
   alGenSources( 1, &music_source2_);
   alSourcef( music_source2_, AL_PITCH, 1. );
   alSourcef( music_source2_, AL_GAIN, 2. );
   setMusicPosition(glm::vec3(0.0f, 0.0f, 3.0f));
   alSource3f( music_source2_, AL_VELOCITY, 0.0f, 0.0f, 0.0f);
   alSourcei( music_source2_, AL_LOOPING, AL_TRUE );   
   
   alGenBuffers( 1, &music_buffer_ );
   {
      long dataSize;
      const ALvoid* data = load( "data/Music.raw", &dataSize );
      /* for simplicity, assume raw file is signed-16b at 44.1kHz */
      alBufferData( music_buffer_, AL_FORMAT_MONO16, data, dataSize, 44100 );
      free( (void*)data );
   }
   alSourcei( music_source_, AL_BUFFER, music_buffer_ );
   alSourcei( music_source2_, AL_BUFFER, music_buffer_ );
   
   
   //One source for now
   alGenSources( 1, &wasd_source_);
   alSourcef( wasd_source_, AL_PITCH, 1. );
   alSourcef( wasd_source_, AL_GAIN, 0.5);
   setMusicPosition(glm::vec3(0.0f, 0.0f, 3.0f));
   alSource3f( wasd_source_, AL_VELOCITY, 0.0f, 0.0f, 0.0f);
   //alSourcei( wasd_source_, AL_LOOPING, AL_TRUE );   
   
   alGenBuffers( 1, &wasd_buffer_ );
   {
      long dataSize;
      const ALvoid* data = load( "data/Wasd.raw", &dataSize );
      /* for simplicity, assume raw file is signed-16b at 44.1kHz */
      alBufferData( wasd_buffer_, AL_FORMAT_MONO16, data, dataSize, 44100 );
      free( (void*)data );
   }
   alSourcei( wasd_source_, AL_BUFFER, wasd_buffer_ );  
   
   
   
   //One source for now
   alGenSources( 1, &scratch1_source_);
   alSourcef( scratch1_source_, AL_PITCH, 1. );
   alSourcef( scratch1_source_, AL_GAIN, 1. );
   setMusicPosition(glm::vec3(0.0f, 0.0f, 3.0f));
   alSource3f( scratch1_source_, AL_VELOCITY, 0.0f, 0.0f, 0.0f);
   //alSourcei( scratch1_source_, AL_LOOPING, AL_TRUE );   
   
   alGenBuffers( 1, &scratch1_buffer_ );
   {
      long dataSize;
      const ALvoid* data = load( "data/Scratch1.raw", &dataSize );
      /* for simplicity, assume raw file is signed-16b at 44.1kHz */
      alBufferData( scratch1_buffer_, AL_FORMAT_MONO16, data, dataSize, 44100 );
      free( (void*)data );
   }
   alSourcei( scratch1_source_, AL_BUFFER, scratch1_buffer_ );  
   
   
   //One source for now
   alGenSources( 1, &scratch2_source_);
   alSourcef( scratch2_source_, AL_PITCH, 1. );
   alSourcef( scratch2_source_, AL_GAIN, 1. );
   setMusicPosition(glm::vec3(0.0f, 0.0f, 3.0f));
   alSource3f( scratch2_source_, AL_VELOCITY, 0.0f, 0.0f, 0.0f);
  // alSourcei( scratch2_source_, AL_LOOPING, AL_TRUE );   
   
   alGenBuffers( 1, &scratch2_buffer_ );
   {
      long dataSize;
      const ALvoid* data = load( "data/Scratch2.raw", &dataSize );
      /* for simplicity, assume raw file is signed-16b at 44.1kHz */
      alBufferData( scratch2_buffer_, AL_FORMAT_MONO16, data, dataSize, 44100 );
      free( (void*)data );
   }
   alSourcei( scratch2_source_, AL_BUFFER, scratch2_buffer_ );  
   
   
   //One source for now
   alGenSources( 1, &scratch3_source_);
   alSourcef( scratch3_source_, AL_PITCH, 1. );
   alSourcef( scratch3_source_, AL_GAIN, 1. );
   setMusicPosition(glm::vec3(0.0f, 0.0f, 3.0f));
   alSource3f( scratch3_source_, AL_VELOCITY, 0.0f, 0.0f, 0.0f);
   //alSourcei( scratch3_source_, AL_LOOPING, AL_TRUE );   
   
   alGenBuffers( 1, &scratch3_buffer_ );
   {
      long dataSize;
      const ALvoid* data = load( "data/Scratch3.raw", &dataSize );
      /* for simplicity, assume raw file is signed-16b at 44.1kHz */
      alBufferData( scratch3_buffer_, AL_FORMAT_MONO16, data, dataSize, 44100 );
      free( (void*)data );
   }
   alSourcei( scratch3_source_, AL_BUFFER, scratch3_buffer_ );  
   
   
   //One source for now
   alGenSources( 1, &oxygen_source_);
   alSourcef( oxygen_source_, AL_PITCH, 1. );
   alSourcef( oxygen_source_, AL_GAIN, 1. );
   setMusicPosition(glm::vec3(0.0f, 0.0f, 3.0f));
   alSource3f( oxygen_source_, AL_VELOCITY, 0.0f, 0.0f, 0.0f);
   //alSourcei( oxygen_source_, AL_LOOPING, AL_TRUE );   
   
   alGenBuffers( 1, &oxygen_buffer_ );
   {
      long dataSize;
      const ALvoid* data = load( "data/Oxygen.raw", &dataSize );
      /* for simplicity, assume raw file is signed-16b at 44.1kHz */
      alBufferData( oxygen_buffer_, AL_FORMAT_MONO16, data, dataSize, 44100 );
      free( (void*)data );
   }
   alSourcei( oxygen_source_, AL_BUFFER, oxygen_buffer_ );  
   
   
   //One source for now
   alGenSources( 1, &out_source_);
   alSourcef( out_source_, AL_PITCH, 1. );
   alSourcef( out_source_, AL_GAIN, 0.5);
   setMusicPosition(glm::vec3(0.0f, 0.0f, 3.0f));
   alSource3f( out_source_, AL_VELOCITY, 0.0f, 0.0f, 0.0f);
   //alSourcei( out_source_, AL_LOOPING, AL_TRUE );   
   
   alGenBuffers( 1, &out_buffer_ );
   {
      long dataSize;
      const ALvoid* data = load( "data/Out.raw", &dataSize );
      /* for simplicity, assume raw file is signed-16b at 44.1kHz */
      alBufferData( out_buffer_, AL_FORMAT_MONO16, data, dataSize, 44100 );
      free( (void*)data );
   }
   alSourcei( out_source_, AL_BUFFER, out_buffer_ );  
   
   
   //One source for now
   alGenSources( 1, &klicks_source_);
   alSourcef( klicks_source_, AL_PITCH, 1. );
   alSourcef( klicks_source_, AL_GAIN, 1. );
   setMusicPosition(glm::vec3(0.0f, 0.0f, 3.0f));
   alSource3f( klicks_source_, AL_VELOCITY, 0.0f, 0.0f, 0.0f);
   //alSourcei( klicks_source_, AL_LOOPING, AL_TRUE );   
   
   alGenBuffers( 1, &klicks_buffer_ );
   {
      long dataSize;
      const ALvoid* data = load( "data/Klicks.raw", &dataSize );
      /* for simplicity, assume raw file is signed-16b at 44.1kHz */
      alBufferData( klicks_buffer_, AL_FORMAT_MONO16, data, dataSize, 44100 );
      free( (void*)data );
   }
   alSourcei( klicks_source_, AL_BUFFER, klicks_buffer_ );  
   
   
   //One source for now
   alGenSources( 1, &heartbeat_source_);
   alSourcef( heartbeat_source_, AL_PITCH, 1. );
   alSourcef( heartbeat_source_, AL_GAIN, 1. );
   setMusicPosition(glm::vec3(0.0f, 0.0f, 3.0f));
   alSource3f( heartbeat_source_, AL_VELOCITY, 0.0f, 0.0f, 0.0f);
   //alSourcei( heartbeat_source_, AL_LOOPING, AL_TRUE );   
   
   alGenBuffers( 1, &heartbeat_buffer_ );
   {
      long dataSize;
      const ALvoid* data = load( "data/Heartbeat.raw", &dataSize );
      /* for simplicity, assume raw file is signed-16b at 44.1kHz */
      alBufferData( heartbeat_buffer_, AL_FORMAT_MONO16, data, dataSize, 44100 );
      free( (void*)data );
   }
   alSourcei( heartbeat_source_, AL_BUFFER, heartbeat_buffer_ );  
   
   
   //One source for now
   alGenSources( 1, &noise_source_);
   alSourcef( noise_source_, AL_PITCH, 1. );
   alSourcef( noise_source_, AL_GAIN, 10.5 );
   setMusicPosition(glm::vec3(0.0f, 0.0f, 3.0f));
   alSource3f( noise_source_, AL_VELOCITY, 0.0f, 0.0f, 0.0f);
   alSourcei( noise_source_, AL_LOOPING, AL_TRUE );   
   
   alGenBuffers( 1, &noise_buffer_ );
   {
      long dataSize;
      const ALvoid* data = load( "data/Noise.raw", &dataSize );
      /* for simplicity, assume raw file is signed-16b at 44.1kHz */
      alBufferData( noise_buffer_, AL_FORMAT_MONO16, data, dataSize, 44100 );
      free( (void*)data );
   }
   alSourcei( noise_source_, AL_BUFFER, noise_buffer_ );
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


void Sound::setWasdPosition(glm::vec3 position){
    alSource3f( wasd_source_, AL_POSITION, position.x, position.y, position.z );
}
void Sound::setScratch1Position(glm::vec3 position){
    alSource3f( scratch1_source_, AL_POSITION, position.x, position.y, position.z );
}
void Sound::setScratch2Position(glm::vec3 position){
    alSource3f( scratch2_source_, AL_POSITION, position.x, position.y, position.z );
}
void Sound::setScratch3Position(glm::vec3 position){
    alSource3f( scratch3_source_, AL_POSITION, position.x, position.y, position.z );
}
void Sound::setOxygenPosition(glm::vec3 position){
    alSource3f( oxygen_source_, AL_POSITION, position.x, position.y, position.z );
}
void Sound::setOutPosition(glm::vec3 position){
    alSource3f( out_source_, AL_POSITION, position.x, position.y, position.z );
}
void Sound::setKlicksPosition(glm::vec3 position){
    alSource3f( klicks_source_, AL_POSITION, position.x, position.y, position.z );
}
void Sound::setHeartbeatPosition(glm::vec3 position){
    alSource3f( heartbeat_source_, AL_POSITION, position.x, position.y, position.z );
}
void Sound::setNoisePosition(glm::vec3 position){
    alSource3f( noise_source_, AL_POSITION, position.x, position.y, position.z );
}
void Sound::setMusicPosition(glm::vec3 position) {
    alSource3f( music_source_, AL_POSITION, position.x, position.y, position.z );
}
void Sound::setMusic2Position(glm::vec3 position) {
    alSource3f( music_source2_, AL_POSITION, position.x, position.y, position.z );
}

void Sound::playMusic(){
   alSourcePlay( music_source_);
}
void Sound::playMusic2(){
   alSourcePlay( music_source2_);
}
void Sound::playWasd(){
    alSourcePlay( wasd_source_);
}
void Sound::playScratch1(){
    alSourcePlay( scratch1_source_);
}
void Sound::playScratch2(){
    alSourcePlay( scratch2_source_);
}
void Sound::playScratch3(){
    alSourcePlay( scratch3_source_);
}
void Sound::playOxygen(){
    alSourcePlay( oxygen_source_);
}
void Sound::playOut(){
    alSourcePlay( out_source_);
}
void Sound::playKlicks(){
    alSourcePlay( klicks_source_);
}
void Sound::playHeartbeat(){
    alSourcePlay( heartbeat_source_);
}
void Sound::playNoise(){
    alSourcePlay( noise_source_);
}

Sound::~Sound() {
   alDeleteSources( 1, &music_source_ );
   alDeleteBuffers( 1, &heartbeat_buffer_ );
   alcDestroyContext( context_ );
   alcCloseDevice( device_ );
}

