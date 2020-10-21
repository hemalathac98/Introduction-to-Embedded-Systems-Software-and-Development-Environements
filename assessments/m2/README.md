# Week 2 - Programming Assignment

In this assignment, a build system using GNU tools, GCC and GNU Make is created.

## Description

In this assignment, I have to

1. Compile multiple files

2. Link them together

3. Create a final output executable.

Some files are provided, but two platforms need to be supported; the host environment and the target embedded system MSP432. The host system will allow you to simulate software on a host platform. The target system will be used in upcoming assignments as we begin to create our microcontroller applications.

## Deliverables and instructions

A makefile has to be developed that can compile multiple source files and support two platform targets. Following is the folder structure along with a set of source files.

In the assessments/c2 folder:

* msp432p401r.lds - The linker file used for linking

**'src' folder** : contains five source files (*.c)

* Makefile and sources.mk - Edited by me for assignment

* main.c - Main file you are to work with

* memory.c - File that interacts with memory through an IO abstraction interface

* interrupts_msp432p401r_gcc.c - MSP432 specific C-file for interrupts

* startup_msp432p401r_gcc.c - MSP432 specific C-file for startup

* system_msp432p401r.c - MSP432 specific C-file for for system information

**'include' folder** : contains the three directories of supporting header files

* common - Contains common headers for both platform targets

* msp432 - Contains MSP432 platform headers

* CMSIS - Contains ARM architecture specific headers


Inside the **common** folder, a memory.h and a platform.h file are provided. The platform.h file gives you an interface to printf using the macro PRINTF as a mechanism to reduce the dependencies on the stdio.h library.

## Platforms and Flag Support Guidelines

Two target platforms and their own specific compilers need to be supported. These two platforms are the HOST and the MSP432. The host embedded system will use the native compiler, **gcc**. The target embedded system will use the cross compiler, **arm-none-eabi-gcc**. The **PLATFORM** keyword provided in the Makefile should be used to conditionally assign the appropriate compiler flags, linker flags, and architecture flags. The target platform must be provided at the command line with the make command to set the platform you are compiling for. 

Example:

```bash
make build PLATFORM=MSP432
make build PLATFORM=HOST
```

**TO DO**
Upon completion of a build, you should provide a build report of code size using the gcc **size** tool. Note, you will need to select the right GCC Toolchain Size application.


The output executable that gets built needs to be called **c1m2.out**. Must be executed as follows

```bash
./c1m2.out
```

The Makefile and sources.mk have already been populated with a few makefile variables that need to be defined at a minimum as listed below:

* **CC** - Compiler that will perform the build(native or cross)

* **CFLAGS** - C-programming flags for gcc

* **CPPFLAGS** - C-Preprocessor Flags

* **LDFLAGS** - Linker Flags

* **PLATFORM** - The target platform you are compiling for (Platform Specific)

* **SOURCES** - The list of sources files that will need to be compiled (Platform specific)

* **INCLUDES** - The list of include directories ( Hint: Use the -I flag )



A handful of files need to be generated for each complete build. Those are:

* **c1m2.map** - Map file for the full build ( Use the -Map=<FILE> option )

* **(*.d)** - Dependency Files for each source file (main.dep, memory.dep, etc) ( Use the -M* options [MP, MF, MD, MM, etc])

* **(*.o)** - Individual object files (main.o, memory.o, etc)

* **c1m2.out** - Output Executable file



A variety of flags need to be supported for building. These include general, platform and architecture specific flags. Those are listed below

General Flags(Both Platforms)

* -Wall

* -Werror

* -g

* -O0

* -std=c99


Platform Specific Flags(MSP432/HOST)

* **Linker File (MSP432)** : -T msp432p401r.lds
* **Platform Target (Both)**: -DMSP432 or -DHOST


Architecture Specific Flags(ARM only)

* -mcpu=cortex-m4

* -mthumb

* -march=armv7e-m

* -mfloat-abi=hard

* -mfpu=fpv4-sp-d16

* --specs=nosys.specs 


## Build Target Guidelines

A number of build rules and target files need to be supported. Any rules with a prerequisite list must have only dependednt files and dependent targets listed. For any prerequisite that is in another build target prerequisite list, that target dependency needs to execute those rules before running the initially provided target. Finally, you do NOT need to go from source file to preprocessor file to assembly file to object file to relocatable file to executable file for this build. You can have build rules that directly compile a file.

Below are the targets which need to be supported in the makefile:

**%.i**

 * Generate the preprocessed output of all c-program implementation files(use the -E flag).

 * This can be done by providing a single target name

	Example:
	
	```bash
	$ make main.i
	```

**%.asm**

 * Generate assembly output of c-program implementation files and the final output executable (Use the -S flag and the objdump utility).

 * This can be done by providing a single target name
	
	Example
	
	```bash
	$ make main.asm
	```

**%.o**

 * Generate the object file for all c-source files (but do not link) by specifying the object file you want to compile

	Example:
	
	```bash
	$ make main.o
	```

**compile-all**

 * Compile all object files, but **DO NOT** link

 * Needs to have .PHONY protection

 * Example:

```bash
$ make compile-all
```

**Build**

 * Compile all object files and link into a final executable

 * Needs to have a .PHONY protection

 * Example:

```bash
$ make build
```

**clean**

 * This should remove all compiled objects, preprocessed outputs, assembly outputs, executable files and build output files.

 * Need to have a .PHONY protection

 * This includes but is not limited to .map .out .o .asm .i etc.

Example:

```bash
$ make clean
```


## Testing the System

The build system can be tested intermittently as you write them. Few examples are as follows

```bash
$ make memory.o PLATFORM=MSP432
$ make build PLATFORM=HOST
$ make main.asm PLATFORM=HOST
$ make memory.i PLATFORM=HOST
```

Each of these build commands will produce one or more output files. You then use linux’s ls command to list the current files in the directory. This should show the generated file. You then should be able to clean those files with the make clean command. Running the ls command once more, should show that these files have been removed. An example is provided below:

```bash
$ ls -la
$ make clean
$ ls -la
```

Finally, the host code should be able to run natively on your system. You can test that this file works properly by running ./c1m2.out. The cortex build will not be able to run natively. This should throw an error if you try to run natively.The native target execution should output a string “aXy72_L+R”






