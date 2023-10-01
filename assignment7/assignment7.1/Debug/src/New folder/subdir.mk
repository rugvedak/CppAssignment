################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/New\ folder/Employee.cpp \
../src/New\ folder/Manager.cpp \
../src/New\ folder/Salesman.cpp \
../src/New\ folder/Salesmanager.cpp \
../src/New\ folder/assignment7.1.cpp 

CPP_DEPS += \
./src/New\ folder/Employee.d \
./src/New\ folder/Manager.d \
./src/New\ folder/Salesman.d \
./src/New\ folder/Salesmanager.d \
./src/New\ folder/assignment7.1.d 

OBJS += \
./src/New\ folder/Employee.o \
./src/New\ folder/Manager.o \
./src/New\ folder/Salesman.o \
./src/New\ folder/Salesmanager.o \
./src/New\ folder/assignment7.1.o 


# Each subdirectory must supply rules for building sources it contributes
src/New\ folder/Employee.o: ../src/New\ folder/Employee.cpp src/New\ folder/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/New folder/Employee.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/New\ folder/Manager.o: ../src/New\ folder/Manager.cpp src/New\ folder/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/New folder/Manager.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/New\ folder/Salesman.o: ../src/New\ folder/Salesman.cpp src/New\ folder/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/New folder/Salesman.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/New\ folder/Salesmanager.o: ../src/New\ folder/Salesmanager.cpp src/New\ folder/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/New folder/Salesmanager.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/New\ folder/assignment7.1.o: ../src/New\ folder/assignment7.1.cpp src/New\ folder/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/New folder/assignment7.1.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-New-20-folder

clean-src-2f-New-20-folder:
	-$(RM) ./src/New\ folder/Employee.d ./src/New\ folder/Employee.o ./src/New\ folder/Manager.d ./src/New\ folder/Manager.o ./src/New\ folder/Salesman.d ./src/New\ folder/Salesman.o ./src/New\ folder/Salesmanager.d ./src/New\ folder/Salesmanager.o ./src/New\ folder/assignment7.1.d ./src/New\ folder/assignment7.1.o

.PHONY: clean-src-2f-New-20-folder

