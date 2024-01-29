# Technical Specifications


| Role | Name | mail | github |
|---|---|---|---|
| Project Manager | Wilfried PORTET | wilfried.portet@algosup.com | https://github.com/PortetWilfried|
| Program Manager | Rémy CHARLES |remy.charles@algosup.com  | https://github.com/RemyCHARLES |
| Tech Lead | Mathis LEBEL |mathis.lebel@algosup.com  | https://github.com/mathislebel |
| Software Developer | Lucas MEGNAN |lucas.megnan@algosup.com | https://github.com/LucasMegnan |
| Software Developer | Grégory PAGNOUX | gregory.pagnoux@algosup.com | https://github.com/Gregory-Pagnoux |
| Quality Assurance | Atifa AMIRI|atifa.amiri@algosup.com  | https://github.com/Atifabaran|


<details>

<summary>

## Table of Content

</summary>

- [1. Introduction](#1-introduction)
 	- [Document Purpose & Definition](#document-purpose--definition)
 	- [Glossary](#glossary)
	  - [ASSEMBLY](#assembly)
	  - [INTERPRETER](#interpreter)
	  - [PROCESSOR](#processor)
	  - [VIRTUAL PROCESSOR](#virtual-processor)
	  - [COMPILER](#compiler)
	  - [DEBUGGER](#debugger)
	  - [Logical operation (OR,XOR,AND,NOT)](#logical-operation-orxorandnot)
	  - [IDE](#ide)
	  - [C laguage](#c-laguage)
 	- [Project Overview](#project-overview)
  		- [Project Brief](#project-brief)
  		- [Requirements](#requirements)
			- ➭ [Setting up the Development Environment](#setting-up-the-development-environment)
                    - [Hardware Requirements](#hardware-requirements)
                    - [Software Requirements](#software-requirements)
				- [Coding Methodology](#coding-methodology)
                    - [Workflow](#-workflow)
					- [Coding Conventions](#-coding-conventions)
                    - [Documenting Conventions](#-documenting-conventions)
                    - [Test Procedure](#-test-procedure)
            - ➭ [Setting up the Virtual Processor](#setting-up-the-virtual-processor)
                - [Hardware Requirements](#hardware-requirements-1)
                - [Software Requirements](#software-requirements-1)
        - [Assumptions & Constraints](#assumptions--constraints)
- [2. Technical Specification](#2-technical-specifications)
	- [Folder Structure](#folder-structure)
	- [Data Structures](#data-structures)
    - [security](#security)
- [How to make it](#how-to-make-it)
    - [Architecture of Code](#architecture-of-code)
	    - [Modularity](#modularity)
		    - [Module Breakdown](#module-breakdown)
			- [Header Files](#header-files)
		- [Abstraction](#abstraction)
		    - [Memory Management](#memory-management)
			- [Registers](#registers)
		- [Instruction Interpreter](#instruction-interpreter)
		    - [Parsing](#parsing) 
			- [Execution](#execution)
		- [Input/Output Management](#input/output-management)
		    - [I/O Simulation](#i/o-simulation)
		- [Testing and Validation](#testing-and-validation)
		    - [Unit Testing](#unit-testing)
		- [Continuous Integration](#continuous-integration)
		- [Documentation and Coding Standards](#documentation-and-coding-standards)
		    - [Comments and Documentation](#comments-and-documentation)
			- [Adherence to Standards](#adherence-to-standards)
        - [User Interface](#user-interface)
		    - [CLI or GUI](#cli-or-gui)
		- [Scalability and Maintenance](#scalability-and-maintenance)
		    -[Scalable Design](#scalable-design)
		- [Directory Structure](#directory-structure)
    - [Understand the Basic of Processor](#understand-the-basic-of-processor)
	- [Define the Instruction Set](#define-the-instruction-set)
	- [Design the Architecture](#design-the-architecture)
	- [Programming the Virtual Processor](#programming-the-virtual-processor)
		- [Choice of Programming Language](#choice-of-programming-language)
		- [Implement Components](#implement-compoments)
		- [Instruction Interpretation](#instruction-interpretation)
    - [Simulate Memory and Input/Output](#Simulate-Memory-and-Input/Output)
		- [Memory](#memory)
		- [Input/Output](#input/output)
	- [Testing and Debugging](#testing-and-debugging)
	- [User Interface](#user-interface)
	- [Documentation and Maintenance](#documentation-and-maintenance)
- [3. Conclusion](#3-conclusion)
	- [Thanks](#thanks)

</details>

# 1. Introduction

We are asked in the call of tender to create a virtual processor and an interpreter to run assembly code on this processor. This project must be carried out in the basic C code language, that is to say without the use of any external library apart from the standard C libraries. This project's recommendations are to use gcc as compiler and Visual Studio Code as IDE.

First, we need to invent a minimal assembly language for our processor. Our set of instructions must contain at least the following instructions:
• Storing an immediate value in a register.
• Copying the value of one register into another register.
• Read the value from memory at the address contained by a register and store it in
another register.
• Storing the value of a register in memory at the address contained by another register.
• Compare the contents of the registers.
• Unconditionally move to a label.
• Jump conditionally to a label.
• Calling a subroutine.
• Return from a subroutine.
• The 4 basic arithmetic operations: addition, subtraction, multiplication and division.
• The 4 basic logical operations: OR, AND, XOR and NOT.

then we need to write a C program capable of reading a text file containing a program written in our
assembly dialect and run it. The C program must also verify that the assembly program is
semantically valid and detect syntactic errors.In order to see that the assembly program is actually running, we also need to implement a virtual system call to
display text in a virtual terminal, accessible from assembly code. we also need to display
the contents of the registers and have a built-in debugger.
And finally we need to be able to write small assembly programs conceptually similar to unit tests to prove that everything works as expected.
# Document Purpose & Definition
The goal of the Technical Specifications is to take the Functional Requirements which defines the features, scope and goals of the project, to dissect each requirement and turn it into instructions, as clear as possible, to guide the development team as well as the quality assurance team in the successful completion of their mission.

We therefore encourage thorough reading of the [Functional Specifications](https://github.com/algosup/2023-2024-project-3-virtual-processor-team-5/blob/main/Specifications/functionalSpecification.md) before further reading.

The goal of the Technical Requirements is to clarify as many dark areas as possible to avoid the engineers making decisions
In a sense, while the Functional Requirements represent the "What/Why" aspect of the project, the Technical Requirements are supposed to represent the "How" of the project.

With that being said, we will try to cover as many functional and non-functional aspects of the project while making technological and architectural decisions, evaluating those decisions, measuring their associated risks and impact (providing mitigation) and compare those to other potential solutions.

The document should also benefit other stakeholders and project owners by giving insight into our methodology and may serve as a future reference for maintenance or simple documentation purposes.
# Glossary
## ASSEMBLY:
An assembler is a low-level programming language designed specifically for specific computer architectures, usually tied to a particular processor. It lies between machine language (direct binary representation of processor instructions) and more programmer-friendly high-level languages(a high-level programming language is designed to be more easily understood by humans, providing greater abstraction and usability compared to low-level languages ​​such as assembly or machine language.).

## INTERPRETER:
An interpreter is software responsible for directly executing programs written in a high-level programming language, without requiring a prior compilation step. Unlike compilers, interpreters translate source code into executable instructions on the fly, making development and debugging easier by allowing more flexible interaction with the code.

## PROCESSOR:
A processor, also called a central processing unit (CPU), is a computer component that executes machine instructions, handles logical and arithmetic operations, and manages the flow of data within a computer system. It interprets and executes instructions from programs stored in memory, thereby coordinating the fundamental operations necessary for a computer to function.

## VIRTUAL PROCESSOR:
A virtual machine, in virtual processor terms, is a software emulation of a physical processor, allowing programs to run as if they were running on dedicated physical hardware. It creates an isolated environment, called a virtual machine, in which an operating system or application can operate independently of the underlying hardware. Virtual processors are often used to run multiple operating systems or applications on a single physical machine, providing flexibility and more efficient resource management.

## COMPILER:
A compiler is software that translates source code written in a high-level programming language into executable binary code specific to a hardware architecture. It performs this conversion in several stages, including lexical analysis, parsing, intermediate code generation, code optimization, and finally, machine code or bytecode generation. The final result of the compiler is an executable program independent of the source code, allowing its execution on the target platform without requiring the presence of the compiler.

## DEBUGGER:
A debugger is a software tool used by programmers to detect, analyze, and correct errors in a program's source code. It allows you to follow program execution step by step, inspect variable values, identify logic errors, and pause execution to examine the execution context at specific points. Debuggers provide features such as breakpoints, watches to monitor variables, execution tracers, and the ability to run the program step by step to facilitate the debugging process and improve the reliability of the code.

## Logical operation (OR,XOR,AND,NOT):
Logical operations (OR, XOR, AND, NOT) are fundamental operations in the field of binary logic used in computer science. Here are brief definitions for each of these operations:

OR (OR): The OR logical operation returns true (1) if at least one of the operands is true (1). Otherwise, it returns false (0).

XOR (exclusive OR): The XOR logical operation returns true (1) if exactly one of the operands is true (1), but not both. If neither or both are true, it returns false (0).

AND: The logical AND operation returns true (1) only if both operands are true (1). Otherwise, it returns false (0).

NOT: The NOT logic operation inverts the logic value of its operand. If the operand is true (1), NOT will return false (0), and vice versa.

These operations are commonly used in binary data manipulation at the hardware level and in logical expressions in programming. They are essential for logical calculations and flow control in computer systems.X

## IDE:
An integrated development environment (IDE) is software that brings together several tools intended to facilitate software development. It typically offers a text editor for writing source code, a compiler or interpreter for turning the code into an executable, a debugger for detecting and correcting errors, and other features such as versioning, tools user interface design, performance analyzers, etc. IDEs are designed to improve the efficiency of programmers by providing an integrated environment that simplifies tasks related to software development. Examples of popular IDEs include Eclipse, Visual Studio, IntelliJ IDEA, and PyCharm.

## C language:
The C programming language is a high-level, procedural, imperative language originally developed by Dennis Ritchie in the early 1970s at Bell Labs. It played a fundamental role in the development of many operating systems and inspired many other programming languages.

The C language offers direct control over memory and system resources, making it a preferred choice for system and low-level development. It uses a simple and compact syntax, with a modular programming approach, encouraging code reuse. C is also used for developing desktop applications, embedded systems, and is the basis of languages ​​such as C++ and Objective-C.

Key features of the C language:

Syntax: Its syntax is relatively simple, with low-level constructs allowing fine control over the hardware.
Portability: C programs can be compiled on different platforms, promoting source code portability.
Efficiency: The C language allows direct access to memory, providing significant performance efficiency.
Modularity: Modular programming is encouraged through functions and libraries, making code reuse easy.
The C language is still widely used in software development, and many critical systems and applications depend on it. 

# Project Overview

## Project Brief

## Requirements

## Setting up the Development Environment

### Hardware Requirements

### Software Requirements

### Coding Methodology

#### ➭ <ins>Workflow</ins>

#### ➭ <ins>Coding Conventions</ins>

#### ➭ <ins>Commenting Conventions</ins>

#### ➭ <ins>Test Procedure</ins>

## Setting up the Virtual Processor

### Hardware Requirements

### Software Requirements

## Assumptions & Constraints

# 2. Technical Specifications

## Folder Structure

## Data Structures

## Security

# How to make it

## Architecture

### Modularity

#### Module Breakdown

#### Header Files

### Abstraction

#### Memory Management

#### Registers

### Instruction Interpreter

#### Parsing

#### Execution

### Input/Output Management

#### I/O Simulation

### Testing and Validation

#### Unit Testing

### Continuous Integration

### Documentation and Coding Standards

#### Comments and Documentation

#### Adherence to Standards

### User Interface

#### CLI or GUI

### Scalability and Maintenance

#### Scalable Design

### Directory Structure
```
virtual_processor/
|-- src/
|   |-- main.c              // Main entry point
|   |-- interpreter.c       // Interpreter implementation
|   |-- processor.c         // Virtual processor implementation
|   |-- instructions.c      // Instruction set and execution functions
|   |-- utils.c             // Utility functions
|
|-- include/
|   |-- interpreter.h       // Header file for the interpreter
|   |-- processor.h         // Header file for the virtual processor
|   |-- instructions.h      // Header file for instructions
|   |-- utils.h             // Header file for utility functions
|
|-- Makefile               // Makefile for building the project
|-- README.md              // Project documentation
|-- programs/              // Example programs for testing
|   |-- add_program.c      // Example program with ADD instruction
|   |-- halt_program.c     // Example program with HALT instruction
|
|-- build/                 // Directory to store compiled binaries
|-- bin/                   // Directory to store the final executable
```

## Understand the Basic of Processor

## Define the Instruction Set

## Design the Architecture

## Programming the Virtual Processor

### Choice of Programming Language

### Implement Components

### Instruction Interpretation

## Simulate Memory and Input/Output

### Memory

### Input/Output

## Testing and Debugging

## User Interface

## Documentation and Maintenance

# 3. Conclusion

## Thanks
