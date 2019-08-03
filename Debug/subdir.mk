################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Child.c \
../City.c \
../General.c \
../Kindergarten.c \
../main.c 

OBJS += \
./Child.o \
./City.o \
./General.o \
./Kindergarten.o \
./main.o 

C_DEPS += \
./Child.d \
./City.d \
./General.d \
./Kindergarten.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


