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
CND_PLATFORM=MinGW-Windows
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
	${OBJECTDIR}/_ext/29dd86f/Dice.o \
	${OBJECTDIR}/_ext/29dd86f/QwintoScoreSheet.o \
	${OBJECTDIR}/_ext/29dd86f/main.o \
	${OBJECTDIR}/Colour.o \
	${OBJECTDIR}/Player.o \
	${OBJECTDIR}/QwintoPlayer.o \
	${OBJECTDIR}/QwintoRow.o \
	${OBJECTDIR}/QwintoScoreSheet.o \
	${OBJECTDIR}/QwixxPlayer.o \
	${OBJECTDIR}/QwixxRow.o \
	${OBJECTDIR}/QwixxScoreSheet.o \
	${OBJECTDIR}/RandomDice.o \
	${OBJECTDIR}/RollOfDice.o \
	${OBJECTDIR}/ScoreSheet.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppproject.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppproject.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/cppproject ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/29dd86f/Dice.o: ../../Dice.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/29dd86f
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/29dd86f/Dice.o ../../Dice.cpp

${OBJECTDIR}/_ext/29dd86f/QwintoScoreSheet.o: ../../QwintoScoreSheet.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/29dd86f
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/29dd86f/QwintoScoreSheet.o ../../QwintoScoreSheet.cpp

${OBJECTDIR}/_ext/29dd86f/main.o: ../../main.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/29dd86f
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/29dd86f/main.o ../../main.cpp

${OBJECTDIR}/Colour.o: Colour.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Colour.o Colour.cpp

${OBJECTDIR}/Player.o: Player.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Player.o Player.cpp

${OBJECTDIR}/QwintoPlayer.o: QwintoPlayer.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/QwintoPlayer.o QwintoPlayer.cpp

${OBJECTDIR}/QwintoRow.o: QwintoRow.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/QwintoRow.o QwintoRow.cpp

${OBJECTDIR}/QwintoScoreSheet.o: QwintoScoreSheet.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/QwintoScoreSheet.o QwintoScoreSheet.cpp

${OBJECTDIR}/QwixxPlayer.o: QwixxPlayer.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/QwixxPlayer.o QwixxPlayer.cpp

${OBJECTDIR}/QwixxRow.o: QwixxRow.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/QwixxRow.o QwixxRow.cpp

${OBJECTDIR}/QwixxScoreSheet.o: QwixxScoreSheet.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/QwixxScoreSheet.o QwixxScoreSheet.cpp

${OBJECTDIR}/RandomDice.o: RandomDice.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/RandomDice.o RandomDice.cpp

${OBJECTDIR}/RollOfDice.o: RollOfDice.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/RollOfDice.o RollOfDice.cpp

${OBJECTDIR}/ScoreSheet.o: ScoreSheet.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ScoreSheet.o ScoreSheet.cpp

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
