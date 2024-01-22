# Functional Specification - Team 5's Virtual Processor

|              |              |
| ------------ | :----------: |
| Author       | Rémy CHARLES |
| Reviewers    |              |
| Created on   |  2024-01-12  |
| Last updated |  2024-01-22  |

## Table of contents

<details>

<summary>Click to expand</summary>

- [Functional Specification - Team 5's Virtual Processor](#functional-specification---team-5s-virtual-processor)
  - [Table of contents](#table-of-contents)
  - [1. Introduction](#1-introduction)
  - [2. Development Environment](#2-development-environment)
  - [3. Assembly Language Specification](#3-assembly-language-specification)
    - [3.1. Instructions](#31-instructions)
    - [3.2. Operations](#32-operations)
  - [4. C Program Development](#4-c-program-development)
    - [4.1 Program Structure](#41-program-structure)
    - [4.2 Reading Assembly Code](#42-reading-assembly-code)
    - [4.3 Executing Instructions](#43-executing-instructions)
    - [4.4 Error Handling and Reporting](#44-error-handling-and-reporting)
    - [4.5 Debugging and Logging](#45-debugging-and-logging)
  - [5. Virtual System Call Implementation](#5-virtual-system-call-implementation)
    - [5.1 Text Display](#51-text-display)
    - [5.2 Debugging Features](#52-debugging-features)
    - [5.3 I/O Operations](#53-io-operations)
    - [5.4 Extension Mechanisms](#54-extension-mechanisms)
  - [6. Testing and Validation](#6-testing-and-validation)
    - [6.1. Unit Tests](#61-unit-tests)
    - [6.2. Testing Methodology](#62-testing-methodology)
  - [7. Conclusion](#7-conclusion)
  - [8. Glossary](#8-glossary)


</details>


## 1. Introduction

The purpose of this document is to provide a comprehensive functional specification for Team 5's Virtual Processor Project. This project involves the creation of a virtual processor designed to execute assembly code. The processor is to be developed in the C programming language, adhering to principles of portability and efficiency. This document outlines the essential elements and specifications of the project, including the development environment, assembly language design, and implementation details.

The virtual processor aims to offer a simplified yet functional platform for understanding and executing basic assembly instructions. It serves as an educational tool, facilitating the learning of low-level programming concepts. The processor will be equipped to handle a custom assembly language, which will be fully detailed in this specification. The project will emphasize the importance of efficient programming practices and the intricacies of processor design and operation.

This specification serves as a guideline for developers and contributors to understand the project's goals, requirements, and design philosophy. It will ensure that all aspects of the project align with the outlined objectives and standards.

## 2. Development Environment

The development of the Virtual Processor will be conducted in a specific programming and toolset environment to ensure consistency, compatibility, and performance. The key components of this environment are:

- **Programming Language**: The entire project is to be developed in standard C language. This choice is made to leverage the portability and efficiency of C, making the virtual processor adaptable to various platforms.

- **Compiler**: The GNU Compiler Collection (GCC) is designated as the primary compiler. Its widespread availability and compatibility with various operating systems make it an ideal choice.

- **Integrated Development Environment (IDE)**: Visual Studio Code (VS Code) is recommended for its versatility and robust support for C/C++ development. It offers valuable features like debugging tools and source code management integration.

- **Libraries**: Only standard C libraries are to be used in this project. The use of external or third-party libraries is restricted to ensure the simplicity and portability of the code.

- **Version Control**: Git, in conjunction with GitHub, will be used for source code management. This allows for effective collaboration, version tracking, and code review processes.

- **Code Style and Conventions**: Adherence to common C programming conventions is expected to maintain code readability and maintainability. A specific style guide will be provided to ensure consistency across the project.

This environment is chosen to balance functionality, ease of use, and accessibility for developers. It will support the project's goals of creating a portable and efficient virtual processor.


## 3. Assembly Language Specification

The virtual processor will be equipped to handle a custom assembly language. This language will be designed to be simple and intuitive, allowing for easy comprehension and execution. The language will be fully detailed in this section, including instructions, operations, and syntax.

### 3.1. Instructions

The assembly language designed for the Virtual Processor will include a set of fundamental instructions. These instructions form the core functionality of the language, enabling basic programming operations. The instruction set is designed to be minimal yet sufficient for a wide range of tasks. Key aspects include:

- **Data Movement Instructions**: These will include instructions for loading and storing data, moving data between registers, and handling immediate values. 
  
    - ```mov``` *uses direct addressing to move data between registers and memory locations.*
    - ```ldr``` *uses indirect addressing to load data from memory into registers.* 
    - ```str``` *uses indirect addressing to store data from registers into memory.* 
    - ```push``` *uses indirect addressing to push data from registers onto the stack.* 
    - ```pop``` *uses indirect addressing to pop data from the stack into registers.* 
    - ```lea``` *uses direct addressing to load the address of a memory location into a register.*
    - and ```ldi``` *uses direct addressing to load an immediate value into a register.*

- **Arithmetic Operations**: Basic arithmetic instructions such as addition, subtraction, multiplication, and division will be implemented.
  
    - ```add``` uses direct addressing to add data from a memory location to a register.
    - ```sub``` uses direct addressing to subtract data from a memory location to a register.
    - ```mul``` uses direct addressing to multiply data from a memory location to a register.
    - and ```div``` uses direct addressing to divide data from a memory location to a register.

- **Logical Operations**: Instructions for logical operations like AND, OR, XOR, and NOT are included.
  
    - ```and``` *uses direct addressing to perform a logical AND operation between data from a memory location and a register.*
    - ```or``` *uses direct addressing to perform a logical OR operation between data from a memory location and a register.*
    - ```xor``` *uses direct addressing to perform a logical XOR operation between data from a memory location and a register.*
    - and ```not``` *uses direct addressing to perform a logical NOT operation between data from a memory location and a register.*

- **Control Flow**: Instructions for branch, jump, and call operations will facilitate the control flow within the assembly programs. 
  
    - ```jmp``` *uses direct addressing to jump to a memory location.* 
    - ```jz``` *uses direct addressing to jump to a memory location if the zero flag is set.*
    - ```jnz``` *uses direct addressing to jump to a memory location if the zero flag is not set.*
    - ```je``` *uses direct addressing to jump to a memory location if the equal flag is set.*
    - ```jne``` *uses direct addressing to jump to a memory location if the equal flag is not set.*
    - ```call``` *uses direct addressing to call a subroutine at a memory location.*
    - and ```ret``` *uses direct addressing to return from a subroutine.*

- **Special Instructions**: A set of special instructions for system calls, input/output operations, and other processor-specific tasks. 
    - ```syscall``` *uses direct addressing to call a system call.*
    - ```in``` *uses direct addressing to read data from a memory location into a register.*
    - ```out``` *uses direct addressing to write data from a register into a memory location.* 
    - ```nop``` *uses direct addressing to perform no operation.*
    - and ```hlt``` *uses direct addressing to halt the processor.*

Each instruction will be described in detail, including its syntax, operation, and usage examples. This will ensure a clear understanding of how to program using the Virtual Processor's assembly language.``

### 3.2. Operations

The operations of the assembly language define how each instruction manipulates data and controls the flow of the program. This section will detail the operational characteristics of the assembly language, which are critical for the Virtual Processor’s functionality:

- **Register Operations**: Detailed explanations of how instructions interact with registers, including register loading, storing, and manipulation. Registers' name: 
  
  - ``ax`` *is the accumulator register.*
  - ``bx`` *is the base register.*
  - ``cx`` *is the counter register.*
  - ``dx`` *is the data register.*
  - ``ix`` *is the index register.*

- **Memory Operations**: Descriptions of instructions for memory access, including direct and indirect addressing, and memory management techniques. 
  
- **Arithmetic and Logical Operations**: Clarification on how arithmetic and logical instructions process data, including flags affected, and overflow handling. Arithmetic instructions include ```add```, ```sub```, ```mul```, and ```div```. Logical instructions include ```and```, ```or```, ```xor```, and ```not```.

- **Control Flow Operations**: Insight into how jump, branch, and call instructions manage the program flow, including condition checks and subroutine handling. ```jmp```, ```jz```, ```jnz```, ```je```, ```jne```, ```call```, and ```ret``` are included.

- **System-Level Operations**: Overview of operations related to system calls and I/O handling, essential for interacting with the system and external environment. System call instructions include ```syscall```, ```in```, ```out```, ```nop```, and ```hlt```.

Each operation will be described in the context of its effect on the processor state, including any changes to registers, memory, or the program counter. Examples will be provided to illustrate typical use cases and expected outcomes.

## 4. C Program Development

This section delves into the design and implementation of the C program, crucial for interpreting and executing the assembly language of the Virtual Processor.

### 4.1 Program Structure
- **Overview:** Description of the C program's architecture, including its main components and their interrelationships.
- **Modules:** Detailed breakdown of key modules such as the interpreter loop, instruction set handler, and memory management system.

### 4.2 Reading Assembly Code
- **Parsing Method:** Exploration of the methodology for reading and parsing assembly language instructions.
- **Error Detection:** Strategies for detecting and handling syntax errors within the assembly code.

### 4.3 Executing Instructions
- **Instruction Interpretation:** Detailed explanation of how the program interprets and executes each assembly instruction.
- **Operational Handling:** Discussion on managing registers, memory, and control flow during instruction execution.

### 4.4 Error Handling and Reporting
- **Runtime Errors:** Approach to detecting and managing errors during the runtime.
- **Reporting Mechanism:** System for reporting errors to the user, ensuring clarity and comprehensiveness.

### 4.5 Debugging and Logging
- **Debugging Tools:** Overview of debugging tools integrated into the C program.
- **Logging System:** Description of the logging system and its role in development and troubleshooting.

*This section aims to provide a comprehensive understanding of the C program's functionality, essential for the effective operation of the Virtual Processor's assembly language.*

## 5. Virtual System Call Implementation

This section outlines the implementation of virtual system calls in the Virtual Processor. These system calls enable interaction between the assembly program and the virtual environment, enhancing the processor's functionality.

### 5.1 Text Display
- **Functionality:** Description of the system call for displaying text within the virtual environment.
- **Implementation Details:** Technical specifics on how text display is handled by the processor and any limitations or special features.

### 5.2 Debugging Features
- **Debugging Support:** Overview of the debugging capabilities provided by the virtual system calls, including register inspection and breakpoint setting.
- **Usage Guidelines:** Instructions on how to use these debugging features effectively during assembly code development and testing.

### 5.3 I/O Operations
- **Input Handling:** Details on how the system call manages input operations, if applicable.
- **Output Management:** Explanation of output operations, including standard output and error handling.

### 5.4 Extension Mechanisms
- **Adding New System Calls:** Guidance on how new system calls can be implemented to extend the processor's capabilities.
- **Customization:** Discussion on customizing existing system calls for specific use cases or enhancements.

*The implementation of virtual system calls is a critical aspect of the Virtual Processor, providing essential functionalities and enriching the user experience.*

## 6. Testing and Validation

`TODO: Write testing and validation`

### 6.1. Unit Tests

`TODO: Write unit tests`

### 6.2. Testing Methodology

`TODO: Write testing methodology`

## 7. Conclusion

`TODO: Write conclusion`

## 8. Glossary

| Term | Definition |
| ---- | ---------- |
| **C** | A general-purpose, procedural computer programming language supporting structured programming, lexical variable scope, and recursion, with a static type system. |
| **GCC** | The GNU Compiler Collection (GCC) is a compiler system produced by the GNU Project supporting various programming languages. |
| **IDE** | An integrated development environment (IDE) is a software application that provides comprehensive facilities to computer programmers for software development. |
| **VS Code** | Visual Studio Code is a free source-code editor made by Microsoft for Windows, Linux and macOS. |
| **Git** | Git is a distributed version-control system for tracking changes in source code during software development. |
| **GitHub** | GitHub is a provider of Internet hosting for software development and version control using Git. |
| **Assembly Language** | A low-level programming language for a computer, or other programmable device, in which there is a very strong correspondence between the language and the architecture's machine code instructions. |
| **System Call** | A system call is the programmatic way in which a computer program requests a service from the kernel of the operating system it is executed on. |
| **Virtual System Call** | A virtual system call is a system call that is implemented in software rather than by the operating system. |
| **Virtual Processor** | A virtual processor is a software-based processor that executes assembly code. |

