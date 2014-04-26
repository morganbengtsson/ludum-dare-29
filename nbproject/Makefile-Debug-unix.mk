#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug-unix
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Assets.o \
	${OBJECTDIR}/Player.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=../Sirkel/dist/Debug/GNU-Linux-x86/libsirkel.a ../mo/dist/Debug/GNU-Linux-x86/libmo.a ../glfw/src/libglfw3.a ../glew-1.9.0/lib/libGLEW.a ../Box2D_v2.2.1/Box2D/libBox2D.a -lX11 -lGL -lXrandr -lXi -lXxf86vm -lpthread

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ludum-dare-29

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ludum-dare-29: ../Sirkel/dist/Debug/GNU-Linux-x86/libsirkel.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ludum-dare-29: ../mo/dist/Debug/GNU-Linux-x86/libmo.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ludum-dare-29: ../glfw/src/libglfw3.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ludum-dare-29: ../glew-1.9.0/lib/libGLEW.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ludum-dare-29: ../Box2D_v2.2.1/Box2D/libBox2D.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ludum-dare-29: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ludum-dare-29 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Assets.o: Assets.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lodepng -I../Box2D_v2.2.1 -I../glew-1.9.0/include -I../glfw/include -I../glm -I../Sirkel -I../stb -I../rapidxml-1.13 -I../ogli -I../imgui -I../mo -I../objload -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Assets.o Assets.cpp

${OBJECTDIR}/Player.o: Player.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lodepng -I../Box2D_v2.2.1 -I../glew-1.9.0/include -I../glfw/include -I../glm -I../Sirkel -I../stb -I../rapidxml-1.13 -I../ogli -I../imgui -I../mo -I../objload -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Player.o Player.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../lodepng -I../Box2D_v2.2.1 -I../glew-1.9.0/include -I../glfw/include -I../glm -I../Sirkel -I../stb -I../rapidxml-1.13 -I../ogli -I../imgui -I../mo -I../objload -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:
	cd ../mo && ${MAKE}  -f Makefile CONF=Debug

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ludum-dare-29

# Subprojects
.clean-subprojects:
	cd ../mo && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
