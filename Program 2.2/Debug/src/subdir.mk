################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/laserMaze.cpp \
../src/laserMazeGame.cpp \
../src/lmModule.cpp \
../src/lmmBlocker.cpp \
../src/lmmCheckPoint.cpp \
../src/lmmDblMirror.cpp \
../src/lmmLaser.cpp \
../src/lmmMirror.cpp \
../src/lmmPassThru.cpp \
../src/lmmSplitter.cpp \
../src/lmmTarget.cpp 

OBJS += \
./src/laserMaze.o \
./src/laserMazeGame.o \
./src/lmModule.o \
./src/lmmBlocker.o \
./src/lmmCheckPoint.o \
./src/lmmDblMirror.o \
./src/lmmLaser.o \
./src/lmmMirror.o \
./src/lmmPassThru.o \
./src/lmmSplitter.o \
./src/lmmTarget.o 

CPP_DEPS += \
./src/laserMaze.d \
./src/laserMazeGame.d \
./src/lmModule.d \
./src/lmmBlocker.d \
./src/lmmCheckPoint.d \
./src/lmmDblMirror.d \
./src/lmmLaser.d \
./src/lmmMirror.d \
./src/lmmPassThru.d \
./src/lmmSplitter.d \
./src/lmmTarget.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


