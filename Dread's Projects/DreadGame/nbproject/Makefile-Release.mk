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
CND_PLATFORM=Cygwin-Windows
CND_DLIB_EXT=dll
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/DreadGame.o \
	${OBJECTDIR}/GameData/GameData.o \
	${OBJECTDIR}/GameData/NPC.o \
	${OBJECTDIR}/GameData/Player.o \
	${OBJECTDIR}/GameStates/BattleState.o \
	${OBJECTDIR}/GameStates/GameState.o \
	${OBJECTDIR}/GameStates/MainMenuState.o \
	${OBJECTDIR}/Interface.o \
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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dreadgame.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dreadgame.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/dreadgame ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/DreadGame.o: DreadGame.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DreadGame.o DreadGame.cpp

${OBJECTDIR}/GameData/GameData.o: GameData/GameData.cpp
	${MKDIR} -p ${OBJECTDIR}/GameData
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/GameData/GameData.o GameData/GameData.cpp

${OBJECTDIR}/GameData/NPC.o: GameData/NPC.cpp
	${MKDIR} -p ${OBJECTDIR}/GameData
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/GameData/NPC.o GameData/NPC.cpp

${OBJECTDIR}/GameData/Player.o: GameData/Player.cpp
	${MKDIR} -p ${OBJECTDIR}/GameData
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/GameData/Player.o GameData/Player.cpp

${OBJECTDIR}/GameStates/BattleState.o: GameStates/BattleState.cpp
	${MKDIR} -p ${OBJECTDIR}/GameStates
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/GameStates/BattleState.o GameStates/BattleState.cpp

${OBJECTDIR}/GameStates/GameState.o: GameStates/GameState.cpp
	${MKDIR} -p ${OBJECTDIR}/GameStates
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/GameStates/GameState.o GameStates/GameState.cpp

${OBJECTDIR}/GameStates/MainMenuState.o: GameStates/MainMenuState.cpp
	${MKDIR} -p ${OBJECTDIR}/GameStates
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/GameStates/MainMenuState.o GameStates/MainMenuState.cpp

${OBJECTDIR}/Interface.o: Interface.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Interface.o Interface.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
