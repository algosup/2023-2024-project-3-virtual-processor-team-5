# Technical Specifications
|              |              |
| ------------ | :----------: |
| Author       | Mathis lebel |
| Reviewers    |              |
| Created on   |  2024-01-15  |
| Last updated |  2024-02-09  |

| Role                | Name                                       | Email                                          | LinkedIn                                        | GitHub                                       |
|---------------------|--------------------------------------------|---------------------------------------------|------------------------------------------------|----------------------------------------------|
| Project Manager     | <img src="img/technicalImg/picture_of_wilfried.png" width="30px"/> Wilfried PORTET      | [<img src="https://img.icons8.com/material-rounded/24/000000/mail.png"/>](mailto:wilfried.portet@algosup.com) | [<img src="https://www.presse-citron.net/app/uploads/2020/06/linkedin-logo.jpg" width="20px">](https://www.linkedin.com/in/wilfried-portet-a882b9293/) | [<img src="https://cdn.pixabay.com/photo/2022/01/30/13/33/github-6980894_1280.png" width="20px">](https://github.com/PortetWilfried) |
| Program Manager     | <img src="img/technicalImg/picture_of_remy.png" width="30px"/> Rémy CHARLES         | [<img src="https://img.icons8.com/material-rounded/24/000000/mail.png"/>](mailto:remy.charles@algosup.com) | [<img src="https://www.presse-citron.net/app/uploads/2020/06/linkedin-logo.jpg" width="20px">](https://www.linkedin.com/in/r%C3%A9my-charles-2a8960232/) | [<img src="https://cdn.pixabay.com/photo/2022/01/30/13/33/github-6980894_1280.png" width="20px">](https://github.com/RemyCHARLES) |
| Tech Lead           | <img src="img/technicalImg/picture_of_mathis.png" width="30px"/> Mathis LEBEL          | [<img src="https://img.icons8.com/material-rounded/24/000000/mail.png"/>](mailto:mathis.lebel@algosup.com) | [<img src="https://www.presse-citron.net/app/uploads/2020/06/linkedin-logo.jpg" width="20px">](https://www.linkedin.com/in/mathis-lebel-429114293/) | [<img src="https://cdn.pixabay.com/photo/2022/01/30/13/33/github-6980894_1280.png" width="20px">](https://github.com/mathislebel) |
| Software Developer  | <img src="img/technicalImg/picture_of_lucas.png" width="30px"/> Lucas MEGNAN          | [<img src="https://img.icons8.com/material-rounded/24/000000/mail.png"/>](mailto:lucas.megnan@algosup.com) | [<img src="https://www.presse-citron.net/app/uploads/2020/06/linkedin-logo.jpg" width="20px">](https://www.linkedin.com/in/lucas-megnan/) | [<img src="https://cdn.pixabay.com/photo/2022/01/30/13/33/github-6980894_1280.png" width="20px">](https://github.com/LucasMegnan)     |
| Software Developer  | <img src="img/technicalImg/picture_of_gregory.png" width="30px"/> Grégory PAGNOUX       | [<img src="https://img.icons8.com/material-rounded/24/000000/mail.png"/>](mailto:gregory.pagnoux@algosup.com) | [<img src="https://www.presse-citron.net/app/uploads/2020/06/linkedin-logo.jpg" width="20px">](https://www.linkedin.com/in/gregory-pagnoux-313b3a251/) | [<img src="https://cdn.pixabay.com/photo/2022/01/30/13/33/github-6980894_1280.png" width="20px">](https://github.com/Gregory-Pagnoux) |
| Quality Assurance   | <img src="img/technicalImg/picture_of_atifa.png" width="30px"/> Atifa AMIRI           | [<img src="https://img.icons8.com/material-rounded/24/000000/mail.png"/>](mailto:atifa.amiri@algosup.com) | [<img src="https://www.presse-citron.net/app/uploads/2020/06/linkedin-logo.jpg" width="20px">](https://www.linkedin.com/in/atifa-amiri-565a1225b/) | [<img src="https://cdn.pixabay.com/photo/2022/01/30/13/33/github-6980894_1280.png" width="20px">](https://github.com/Atifabaran)     |

## Table of Contents
<details>
<summary>Click to expand</summary>

- [I. Introduction](#i-introduction) 
  - [1. Customer Request](#1-customer-request) 
  - [2. Document Purpose & Definition](#2-document-purpose--definition) 
  - [3. Project Overview](#3-project-overview) 
    - [3.1 Project Brief](#31-project-brief) 
    - [3.2 Requirements](#32-requirements)   
      - [3.2.1 Setting up the Development Environment](#321-setting-up-the-development-environment) 
        - [3.2.1.1 Software Requirements](#3211-software-requirements) 
      - [3.2.2. Coding Methodology](#322-coding-methodology) 
        - [3.2.2.1 How We will Go About It](#3221-how-well-go-about-it)
            - [3.2.2.1.1 Requirements Analysis](#32211-requirements-analysis)
            - [3.2.2.1.2 Quick Daily Meetings](#32212-quick-daily-meetings)
            - [3.2.2.1.3 Version Control with Git](#32213-version-control-with-git)
            - [3.2.2.1.4 Modular Development](#32214-modular-development)
            - [3.2.2.1.5 Continuous Integration](#32215-continuous-integration)
            - [3.2.2.1.6 Testing](#32216-testing)
            - [3.2.2.1.7 Documentation](#32217-documentation)
            - [3.2.2.1.8 Debugging](#32218-debugging)
            - [3.2.2.1.9 Code Reviews](#32219-code-reviews)
        - [3.2.2.2 Workflow](#3222-workflow) 
        - [3.2.2.3 Coding conventions](#3223-coding-conventions) 
            - [3.2.2.3.1 Naming](#32231-naming) 
            - [3.2.2.3.2 Formatting](#32232-formatting) 
            - [3.2.2.3.3 Comments](#32233-comments) 
        - [3.2.2.4 Documenting Conventions](#3224-documenting-conventions) 
        - [3.2.2.5 Test Procedure](#3225-test-procedure) 
      - [3.2.3 Setting up the Virtual Processor](#323-setting-up-the-virtual-processor) 
        - [3.2.3.1 Software Requirements](#3231-software-requirements) 
        - [3.2.3.2 Coding Methodology](#3232-coding-methodology) 
            - [3.2.3.2.1 Testing Framework](#32321-testing-framework) 
            - [3.2.3.2.2 Debugger](#32322-debugger) 
            - [3.2.3.2.3 Continuous Integration](#32323-continuous-integration)
            - [3.2.3.2.4 Virtual Terminal Implementation](#32324-virtual-terminal-implementation) 
            - [3.2.3.2.5 Built-in Debugger Implementation](#32325-built-in-debugger-implementation) 
            - [3.2.3.2.6 System Call Implementation](#32326-system-call-implementation) 
    - [3.3 Assumptions & Constraints](#33-assumptions--constraints) 
- [II-Technical Specifications](#ii-technical-specifications) 
  - [1. Folder Structure](#1-folder-structure) 
  - [2. Data Structures](#2-data-structures) 
    - [2.1 Register Structure](#21-register-structure)
    - [2.2 Memory Structure](#22-memory-structure)
    - [2.3 instruction-structure](#23-instruction-structure)
    - [2.4 virtual terminal structure](#24-virtual-terminal-structure)
- [III. How to Make It](#iii-how-to-make-it) 
  - [1. Architecture](#1-architecture) 
    - [1.1 Syntaxe of our Code](#11-syntaxe-of-our-code)
    - [1.2 Modularity](#12-modularity)
      - [1.2.1 Module Breakdown](#121-module-breakdown) 
    - [1.3 Header Files](#13-header-files) 
    - [1.4 Abstraction](#14-abstraction)
      - [1.4.1 Memory Management](#141-memory-management) 
      - [1.4.2 Registers](#142-registers) 
    - [1.5 Instruction Interpreter](#15-instruction-interpreter) 
      - [1.5.1 Parsing](#151-parsing) 
      - [1.5.2 Execution](#152-execution) 
    - [1.6 Input/Output Management](#16-inputoutput-management) 
      - [1.6.1 I/O Simulation](#161-io-simulation)
    - [1.7 Testing and Validation](#17-testing-and-validation) 
      - [1.7.1 Unit Testing](#171-unit-testing) 
    - [1.8 Documentation and Coding Standards](#18-documentation-and-coding-standards) 
      - [1.8.1 Comments and Documentation](#181-comments-and-documentation) 
      - [1.8.2 Adherence to Standards](#182-adherence-to-standards) 
    - [1.9 User Interface](#19-user-interface)
      - [1.9.1 CLI or GUI](#191-cli-or-gui) 
    - [1.10 Scalability and Maintenance](#110-scalability-and-maintenance) 
      - [1.10.1 Scalable Design](#1101-scalable-design) 
  - [2. Understand the Basics of Processor](#2-understand-the-basics-of-processor) 
  - [3. Define the Instruction Set](#3-define-the-instruction-set) 
  - [4. Design the Architecture](#4-design-the-architecture) 
- [IV. Glossary](#iv-glossary) 
- [V. Conclusion](#v-conclusion) 


</details>

# I. Introduction
## 1. Customer Request

We are asked in the call of tender to create a virtual processor and an interpreter to run assembly code on this processor. This project must be carried out in the basic C code language, that is to say without the use of any external library apart from the standard C libraries. This project's recommendations are to use GCC as compiler and Visual Studio Code as the IDE.

First, we need to invent a minimal assembly language for our processor. Also our set of instructions must contain at least this following instructions:

- Storing an immediate value in a register.

- Copying the value of one register into another register.

- Read the value from memory at the address contained by a register and store it in
another register.

- Storing the value of a register in memory at the address contained by another register.

- Compare the contents of the registers.

- Unconditionally move to a label.

- Jump conditionally to a label.

- Calling a subroutine.

- Return from a subroutine.

- The 4 basic arithmetic operations: addition, subtraction, multiplication and division.

- The 4 basic logical operations: OR, AND, XOR and NOT.

Then we need to write a C program capable of reading a text file containing a program written in our assembly dialect and run it. The C program must also verify that the assembly program is semantically valid and detects syntactic errors. In order to see that the assembly program is actually running, we also need to implement a virtual system call to display text in a virtual terminal, accessible from assembly code. Then we need to display the contents of the registers and have a built-in debugger.
And finally we need to be able to write small assembly programs conceptually similar to unit tests to prove that everything works as expected.

## 2. Document Purpose & Definition

The goal of the Technical Specifications is to take the Functional Requirements which defines the features, scope and goals of the project, to dissect each requirements and turn it into instructions, as clear as possible, to guide the development team as well as the quality assurance team in the successful completion of their mission.

We therefore encourage thorough reading of the [Functional Specifications](https://github.com/algosup/2023-2024-project-3-virtual-processor-team-5/blob/main/Specifications/functionalSpecification.md) before further reading.

The goal of the Technical Requirements is to clarify as many dark areas as possible, to avoid the engineers making decisions.
In a sense, while the Functional Requirements represent the "What/Why" aspect of the project, the Technical Requirements are supposed to represent the "How" of the project.

With that being said, we will try to cover as many functional and non-functional aspects of the project while making technological and architectural decisions, evaluating those decisions, measuring their associated risks and impact (providing mitigation) and compare those to other potential solutions.

The document should also benefits other stakeholders and project owners by giving insight into our methodology and may serve as a future reference for maintenance or simple documentation purposes.

## 3. Project Overview

### 3.1 Project Brief
---
As stated in the Functional Requirements,this project involves the creation of a virtual processor designed to execute assembly code.

We have been given 7 week to complete this project.
Looking deeper into the project, we decided to have a meeting together to find out what to start, to agree on the direction to take and also to know what we wanted as a result at the end of the project.
After this meeting we decided to adopt a step-by-step strategy with daily tasks. We find that, this method is simpler to follow and is the simplest to be effective.

### 3.2 Requirements
---
*Even if this document is intended to be as exhaustive and demonstrative as possible, it is expected that its reader has some basic knowledge in virtual machines, more precisely in this case in virtual processors, and also certain knowledge in programming.*

As indicated in the call for tender, at the end of the project we must be able to code in an assembler created by us with an interpreter also created by us, execute it on a virtual processor also created by us, be able to prove that it executes well by making a virtual terminal and finally we can also display the contents of the registers and have a built-in debugger.

The task may seem difficult, it is true that it is not the simplest project but with good organization and respect for the tasks the project can greatly improve the ease of progress of this project.

As an IDE, Visual Studio Code allows us to run all our programs in a simple and portable way, which means that Windows and MacOs team members will be able to run and test the program, which will prove useful during the process of development.

#### 3.2.1 Setting up the Development Environment

The first step is to set up the development environment, which we can define as follows:

##### 3.2.1.1 Software Requirements
- [VSCode](https://code.visualstudio.com/) as an IDE to run our code simply and efficiently.

- The programming language is [C](https://en.wikipedia.org/wiki/C_(programming_language)#:~:text=C%20is%20an%20imperative%20procedural,all%20with%20minimal%20runtime) to program our entire project.
- [GCC](https://gcc.gnu.org): We will use GCC as the C compiler for our project. 
- We use Github or other source control management to  communicate the progress of our project, [Github](https://github.com/) is recommended for this task.
- We also use [Trello](https://trello.com/) for our step-by-step strategy by putting the different tasks to do during the day for better optimization of time.

#### 3.2.2 Coding Methodology

##### 3.2.2.1 How We'll Go About It

#### 3.2.2.1.1 Requirements Analysis:
  - We begin by thoroughly understanding what the clients want, detailing all the requirements.

##### 3.2.2.1.2 Quick Daily Meetings:
  - Every day, we gather quickly to discuss progress, potential issues, and plan tasks for the day.
  - We keep our Trello board updated for effective organization.

##### 3.2.2.1.3 Version Control with Git:
  - We use Git and GitHub to keep track of all versions of our code.
  - Whenever we add something new or fix a bug, we create a specific branch.

##### 3.2.2.1.4 Modular Development:
  - The project is broken down into logical pieces, each serving a specific purpose.
  - We use header files to clearly define what each piece does.
  - For each pieces, we write tests to ensure it functions correctly.

##### 3.2.2.1.5 Continuous Integration:
  - Whenever we make a change, we ensure the entire project compiles correctly and passes all tests.

##### 3.2.2.1.6 Testing:
  - We avoid unpleasant surprises by writing tests for everything. Small tests for each piece and comprehensive tests for the entire system.
  - This prevents tears later on.

##### 3.2.2.1.7 Documentation:
  - No need to guess what each piece does. We document everything.
  - Clear comments in the code and a detailed README for everyone to understand.

##### 3.2.2.1.8 Debugging:
  - We are not all perfect, so we use debugging tools to track down and eliminate bugs.
  - Serious testing and debugging during development.

##### 3.2.2.1.9 Code Reviews:
  - We trust each other, but two pairs of eyes are better than one. We review the code of others and provide constructive feedback.

#### 3.2.2.2 Workflow
The development team began working on features requested in the project's call for tender, such as storing an immediate value in a register.

- Copy the value of one register to another register.

- Read the value in memory at the address contained by a register and store it in
another register.

- Storing the value of a register in memory at the address contained by another register.

- Compare the contents of the registers.

- Unconditionally move to a label.

- Jump conditionally to a label.

- Calling a subroutine.

- Return from a subroutine.

- The 4 basic arithmetic operations: addition, subtraction, multiplication and division.

- The 4 basic logical operations: OR, AND, XOR and NOT before the specifications are fully understood and defined.

Once the functional specifications are dissected into the technical specifications, the project functions and features are all reflected in the trello in the form of “Tasks” which we prefer to call “tickets” internally.
Each of these tickets is then sent to QA in the "next release" section once verified, the tickets are sent to the "done" section, assigned to the team members and prioritized by the project manager or technical manager, in function of the task.

Each ticket represents a part of the work, a bug found, a feature request, an update. This abstraction makes it possible to track many types of tasks, break them down even further, and move forward quickly.

We will return to this more at the end of this document.

#### 3.2.2.3 Coding Conventions

##### 3.2.2.3.1 Naming

- We use camelCase notation for our variables and functions.
- Constants are in uppercase with underscores.

##### 3.2.2.3.2 Formatting

- We indent with 4 spaces to ensure consistent readability.
- Opening braces are placed on the same line as the control statements.

##### 3.2.2.3.3 Comments

- We use meaningful comments to clarify the code.
- Comment near 100% of the Functions in the code.

##### 3.2.2.4 Documenting Conventions

We will automatically generate documentation for this project.
How to use it will also be included in the readme.

##### 3.2.2.5 Test Procedure

We will test all the functionalities of the project step by step during the project for better efficiency instead of testing everything on the same day to avoid an unpleasant surprise on the day of the final rendering.

#### 3.2.3 Setting up the Virtual Processor

##### 3.2.3.1 Software Requirements

For the virtual processor development, we need the following software tools and components:

- [Visual Studio Code (VSCode)](https://code.visualstudio.com/): We will use VSCode as the IDE for writing, editing, and managing our C code. It provides a simple and efficient platform for development.

- [C](https://en.wikipedia.org/wiki/C_(programming_language)#:~:text=C%20is%20an%20imperative%20procedural,all%20with%20minimal%20runtime): The entire project will be implemented in the C language. It is a powerful and efficient language, suitable for system-level development.

- [GCC (GNU Compiler Collection)](https://gcc.gnu.org): We will use GCC as the C compiler for our project.

- [GitHub](https://github.com/): We will utilize GitHub for source code management, version control, and collaboration among team members.

- [Trello](https://trello.com/): Trello will be our project management tool for organizing tasks, setting priorities, and tracking progress with a step-by-step strategy.

#### 3.2.3.2 Coding Methodology

##### 3.2.3.2.1 Testing Framework

**Unit Testing Framework** *(e.g., Unity or CUnit)*: To ensure the correctness of our code, we will implement unit tests for individual components and system functionalities. The choice of a specific testing framework will be determined during the project.

##### 3.2.3.2.2 Debugger

**Debugger in Visual Studio Code**: We will leverage the debugging features provided by VSCode to identify, analyze, and correct errors in our code. This includes setting breakpoints, inspecting variable values, and stepping through code execution.

##### 3.2.3.2.3 Continuous Integration

**Continuous Integration Tool** *(e.g., Jenkins or Travis CI)*: To maintain code quality, we will implement continuous integration, ensuring that the entire project compiles correctly and passes all tests with each code change.

##### 3.2.3.2.4 Virtual Terminal Implementation

**Virtual Terminal Implementation**: A mechanism to simulate a virtual terminal for displaying text output from assembly code. This will be implemented as part of the virtual processor, and the details will be defined during the development process.

##### 3.2.3.2.5 Built-in Debugger Implementation

**Built-in Debugger Implementation**: A built-in debugger for the virtual processor, integrated into the development environment. This debugger will assist in identifying and resolving issues during the execution of assembly code.

##### 3.2.3.2.6 System Call Implementation

**System Call Implementation**: Implementation of a virtual system call mechanism to facilitate interaction between assembly code and the virtual processor, particularly for displaying text output.
These software tools and components will form the foundation for setting up the virtual processor development environment and ensuring a smooth development process.

### 3.3 Assumptions & Constraints
---

| Assumptions                                       | Constraints                                             |
|---------------------------------------------------|---------------------------------------------------------|
| The 7-week development period is sufficient to accomplish the development tasks. | The project must be implemented in the C language without external libraries, limiting the use of advanced features. |
| Visual Studio Code and GCC are suitable tools for the project's development environment. |

  
# II. Technical Specifications

## 1. Folder Structure

Here is the folder structure that we decided to put in place for software engineers:
```
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

Explanation:

`src/`: Contains the source code files for the main program, interpreter, virtual processor, instructions, utility functions, and virtual terminal.

`include/`: Includes header files for each module, ensuring clean separation between declarations and implementations.

`programs/`: Provides example programs for testing the functionality of the virtual processor.

`build/`: Stores generated object files during compilation.

`bin/`: Contains the final executable of the virtual processor.

`Makefile`: The Makefile automates the compilation process and  
## 2. Data Structures
### 2.1 Register Structure
---

- **Description:** The register structure is used to represent the registers of the virtual processor. Each register can store a value and is identified by a unique name.
- **Members:**
  - `name`: Name of the register.
  - `value`: Current value stored in the register.

### 2.2 Memory Structure
---

- **Description:** The memory structure is used to model the memory of the virtual processor. It can store data and program instructions.

- **Members:**
  - `address`: Memory address.
  - `data`: Data stored at the specified address.

### 2.3 Instruction Structure
---

- **Description:** The instruction structure represents an instruction from the assembly language used by the virtual processor.

- **Members:**
  - `opcode`: Operation code indicating the type of instruction.
  - `operands`: Operands of the instruction (registers, immediate values, etc.).

### 2.4 Virtual Terminal Structure
---

- **Description:** This structure is used to simulate a virtual terminal for displaying text output generated by assembly programs.

- **Members:**
  - `content`: Content displayed in the virtual terminal.

These data structures are crucial for the implementation and proper functioning of the virtual processor, allowing for efficient storage and manipulation of information needed for the execution of assembly code.
# III. How to Make It

## 1. Architecture

### 1.1 Syntaxe of our Code
---

Our code will follow a clear and consistent syntax to enhance readability and maintainability. We'll adhere to the coding conventions mentioned earlier, using camelCase for variables and functions, and keeping the indentation uniform at 4 spaces. We will use comments to explain complex sections and ensure code  understanding.

Note that all the C instructions and their descriptions can be found in the functional specification, so we invite you to read the functional specification as indicated above for more information on the different instructions.

Here are the different syntaxes and in what cases they are used:

<br>
  
    ```asm
    ; Example: Moving data from R1 to R2
    MOV R1, #10   ; Load immediate value 10 into R1
    MOV R1, R2     ; Move data from R1 to R2
    ```

<br>

<br>

    ```asm
    ; Example: Loading data from memory into R1
    LDR R1, [0x1000]   ; Load data from memory address 0x1000 into R1
    ```
  
<br>

  ```asm
    ; Example: Pushing a register's content onto the stack
    MOV R1, #8    ; Load immediate value 8 into R1
    PUSH R1       ; Push the contents of R1 onto the stack
  ```
<br>

<br>

```asm
    ; Example: Popping the top of the stack into a register
    POP R2        ; Pop the top of the stack into R2
```

<br>

<br>

  ```asm
    ; Example: Loading an address into a register
    LEA R3, [0x2000]   ; Load the address 0x2000 into R3
  ```

<br>

<br>

  ```asm
    ; Example: Loading an immediate value into a register
    LDI R4, #15    ; Load immediate value 15 into R4
  ```
  
<br>

Here is some syntax that we are going to find in our project note that here, all the instructions are not mentioned because here we show the different type of syntax that we are going to do. As mentioned above, for more informations on the different instructions we advise you to read the functional specifications of the project.

### 1.2 Modularity
---

#### 1.2.1 Module Breakdown

##### 1. Main Module (`main.c`):

- **Responsibilities:**
  - Main entry point of the program.
  - System initialization.
  - Command line argument handling.

- **Dependencies:**
  - All other modules.

##### 2. Interpreter Module (`interpreter.c` and `interpreter.h`):

- **Responsibilities:**
  - Interpretation of assembly code.
  - Handling instructions and execution.
  - Checking semantic validity.

- **Dependencies:**
  - Processor Module.
  - Instructions Module.

##### 3. Processor Module (`processor.c` and `processor.h`):

- **Responsibilities:**
  - Simulation of the virtual processor.
  - Management of registers and memory.
  - Execution of instructions.

- **Dependencies:**
  - Instructions Module.
  - Virtual Terminal Module.

##### 4. Instructions Module (`instructions.c` and `instructions.h`):

- **Responsibilities:**
  - Definition of instruction structures.
  - Implementation of operations for each instruction.

- **Dependencies:**
  - No external dependencies.

##### 5. Utils Module (`utils.c` and `utils.h`):

- **Responsibilities:**
  - Generic utility functions.
  - Management of data structures.

- **Dependencies:**
  - No external dependencies.

##### 6. Virtual Terminal Module (`virtual_terminal.c` and `virtual_terminal.h`):

- **Responsibilities:**
  - Simulation of a virtual terminal for text output.
  - Interaction with the virtual operating system.

- **Dependencies:**
  - No external dependencies.

##### Header Files (`include/`):

- Contains all necessary header files for each module, allowing a clean separation between declarations and implementations.

##### Makefile (`Makefile`):

- **Responsibilities:**
  - Automation of the compilation process.
  - Linking between different modules.

##### Example Programs (`programs/`):

- Contains example programs to test the functionality of the virtual processor.

##### Build and Bin Directories (`build/` and `bin/`):

- Store generated object files during compilation and the final executable, respectively.


### 1.3 Header Files
---

The `include/` directory contains header files for each module, facilitating a clean separation between declarations and implementations. These headers provide a clear interface for each module and promote modularity within the codebase.

#### 1. Main Module Header (`include/main.h`):

- **Description:**
  - Header file for the main module.
  - Defines the main entry point and system initialization functions.

- **Contents:**
  ```c
  // include/main.h
  #ifndef MAIN_H
  #define MAIN_H
  
  // Function declarations
  void initializeSystem();
  void processCommandLineArguments(int argc, char *argv[]);
  int main(int argc, char *argv[]);
  
  #endif // MAIN_H

#### 2. Interpreter Module Header (`include/interpreter.h`):
Description:

Header file for the interpreter module:
- Declare functions related to assembly code interpretation.

Contents:
```c

// include/interpreter.h
#ifndef INTERPRETER_H
#define INTERPRETER_H

// Function declarations
void interpretAssemblyCode(const char* assemblyCode);
void executeInstruction(const Instruction* instruction);
int checkSemanticValidity(const Instruction* instruction);

#endif // INTERPRETER_H
```

#### 3. Processor Module Header (`include/processor.h`):
Description:

Header file for the processor module:
- Defines functions for virtual processor simulation.

Contents:

```c
// include/processor.h
#ifndef PROCESSOR_H
#define PROCESSOR_H

// Function declarations
void simulateProcessor();
void manageRegisters();
void executeInstruction(const Instruction* instruction);

#endif // PROCESSOR_H
```

#### 4. Instructions Module Header (`include/instructions.h`):
Description:

Header file for the instructions module:
- Contains definitions for instruction structures and operation functions.

Contents:
```c
// include/instructions.h
#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

// Instruction structure definition
typedef struct {
    OpCode opcode;
    Operand operands[MAX_OPERANDS];
} Instruction;

// Function declarations
void executeAdd(Registers* registers, const Operand* operands);
void executeSubtract(Registers* registers, const Operand* operands);
// ... (similar declarations for other instructions)

#endif // INSTRUCTIONS_H
```

#### 5. Utils Module Header (`include/utils.h`):
Description:

Header file for the utils module:
- Declares utility functions and data structure management.

Contents:
```c
// include/utils.h
#ifndef UTILS_H
#define UTILS_H

// Data structure management functions
void initializeRegisters(Registers* registers);
void initializeMemory(Memory* memory);
// ... (other utility function declarations)

#endif // UTILS_H
```

#### 6. Virtual Terminal Module Header (`include/virtual_terminal.h`):
Description:

Header file for the virtual terminal module:
- Contains functions related to simulating a virtual terminal.

Contents:
```c
// include/virtual_terminal.h
#ifndef VIRTUAL_TERMINAL_H
#define VIRTUAL_TERMINAL_H

// Function declarations
void displayText(const char* text);
// ... (other virtual terminal function declarations)

#endif // VIRTUAL_TERMINAL_H
```
These header files define the interfaces for each module, promoting a modular and organized structure for the codebase.

### 1.4 Abstraction
---

#### 1.4.1 Memory Management
Memory Structure (`memory.h`)
Description:

The Memory Structure represents the memory of the virtual processor. It encapsulates the management of memory addresses and data storage.

Members:

`address` : Memory address.

`data` : Data stored at the specified address.
```c
// memory.h

#ifndef MEMORY_H
#define MEMORY_H

typedef struct {
    unsigned int address;
    unsigned int data;
} Memory;

#endif // MEMORY_H
```
#### 1.4.2 Registers

Register Structure (`register.h`)
Description:

The Register Structure is responsible for representing the registers of the virtual processor. It provides an abstraction for managing register names and their associated values.

Members:

`name` : Name of the register.

`value` : Current value stored in the register.

```c
// register.h

#ifndef REGISTER_H
#define REGISTER_H

typedef struct {
    char name[3]; // Assuming register names are 2 characters (e.g., R1, R2)
    int value;
} Register;

#endif // REGISTER_H
```

### 1.5 Instruction Interpreter
---

Instruction Structure (instruction.h)
Description:

The Instruction Structure represents an instruction from the assembly language used by the virtual processor. It encapsulates the operation code (opcode) and operands.

Members:

`opcode` : Operation code indicating the type of instruction.
`operands` : Operands of the instruction (registers, immediate values, etc.).

```
// instruction.h

#ifndef INSTRUCTION_H
#define INSTRUCTION_H

typedef struct {
    char opcode[5]; // Assuming opcodes are 4 characters (e.g., MOV, ADD)
    char operands[3][3]; // Assuming each instruction has at most 2 operands
} Instruction;

#endif // INSTRUCTION_H
```


#### 1.5.1 Parsing

##### Description:

Parsing involves breaking down an assembly program into individual instructions. The interpreter reads the program line by line and converts each line into an Instruction structure.

##### Implementation:

The interpreter reads the assembly program line by line.
For each line, it parses the opcode and operands and creates an Instruction structure.
The parsed instructions are then passed to the execution phase.

#### 1.5.2 Execution

##### Description:

The execution phase includes the interpretation and execution of each instruction. The interpreter reads the instruction structures generated during syntax analysis and performs the corresponding actions.

##### Implementation

We use a switch instruction or lookup table to match opcodes with the corresponding execution functions.
The execution functions manipulate registers, memory and perform other actions depending on the type of instruction.

### 1.6 Input/Output Management
---

#### 1.6.1 I/O Simulation 

##### Description:

The virtual terminal structure is responsible for simulating the input and output operations of the virtual processor. It provides an abstraction for displaying text output and interacting with the virtual operating system.

### 1.7 Testing and Validation
---

#### 1.7.1 Unit Testing

##### Description:

Unit testing involves testing individual components and functions to ensure that they are correct. For the virtual processor project, unit tests can be written for each module, focusing on specific functionality.

##### Implementation:

We develop test cases for each function and module.

We ensure that potential boundary cases and error scenarios are covered by the tests.

### 1.8 Documentation and Coding Standards
---

#### 1.8.1 Comments and Documentation

##### Description:

Comments and documentation are essential for maintaining the readability and understanding of code. They make it possible to understand the purpose of functions, modules and individual blocks of code.

##### Implementation:

We use comments to explain complex sections of code, particularly where the logic is not immediately obvious.
And we document function headers, specifying parameters, return values and any side effects.
We maintain a detailed README file explaining the project structure, dependencies and instructions for building and executing the code.

#### 1.8.2 Adherence to Standards

#### Description:

Compliance with coding standards guarantees the consistency of the code base. Consistent naming conventions, formatting and structure contribute to ease of maintenance.

#### Implementation:

To enforce coding conventions through code reviews.
We use linters and static code analysis tools to identify and address deviations from coding standards.
We regularly update and refine coding standards in line with evolving best practice.

### 1.9 User Interface
---

#### 1.9.1 CLI or GUI

##### Description:

Decide whether the virtual processor will have a Command Line Interface (CLI) or a Graphical User Interface (GUI) for user interaction.

##### Implementation:

If CLI, provide clear and concise command-line options for running assembly programs and interacting with the virtual processor.
If GUI, design an intuitive interface for loading assembly programs, displaying output, and interacting with the virtual processor.

### 1.10 Scalability and Maintenance
---

#### 1.10.1 Scalable Design

##### Description :

An evolutionary design allows new functionalities or modifications to be added without major restructuring. The project must be designed in such a way as to allow for possible future improvements.

##### Implementation:

We modularise the code base, ensuring that each module has a well-defined responsibility.
We use interfaces and abstractions to decouple components, making them easy to extend or replace.
We anticipate future needs by adopting flexible design models.

## 2. Understand the Basics of Processor

A processor, also known as a Central Processing Unit (CPU), is a key component of a computer system responsible for executing instructions of a computer program. The fundamental operations of a processor include:

`Fetch`: The processor retrieves instructions from memory. The program counter (PC) keeps track of the memory address of the next instruction to be fetched.

`Decode`: The fetched instruction is decoded to determine the operation to be performed and the operands involved.

Execute: The processor performs the actual operation specified by the decoded instruction. This may involve arithmetic or logical operations, data movement, or control flow changes.

`Write`: The result of the execution is written back to registers or memory.

Key Concepts:

### 1. Registers:

Definition: Small, fast storage locations within the CPU used for temporary data storage and quick access.

Purpose: Hold operands for instructions, store intermediate results, and manage control flow.

### 2. Memory:

Definition: Storage used for storing data and program instructions.

Access: Memory is accessed by specifying a memory address.

### 3. Instruction Set Architecture (ISA):

Definition: The set of instructions that a processor can execute.

Examples: Arithmetic operations (addition, subtraction), data movement (load, store), control flow (jump, branch).

### 4. Control Unit:

Definition: The control unit manages the execution of instructions, directing the flow of data between the CPU and other parts of the computer system.

### 5. ALU (Arithmetic Logic Unit):

Definition: The ALU performs arithmetic and logical operations on data.

Operations: Addition, subtraction, AND, OR, XOR, etc.

### 6. Program Counter (PC):

Definition: A register that holds the memory address of the next instruction to be fetched.

### 7. Stack:

Definition: A region of memory used for managing function calls, storing local variables, and handling return addresses.

Implementing a Virtual Processor

Registers in the Virtual Processor:

- Define a set of registers with names (e.g., R1, R2) to store data.
Memory Management:

- Simulate memory to store both data and program instructions.

Instruction Set:

- Define a minimal instruction set that includes arithmetic, logical, and control flow operations.

Control Flow:

- Implement mechanisms for handling program counter updates, unconditional jumps, and conditional jumps.

ALU Operations:

- Develop functions for performing arithmetic and logical operations.
Fetch-Decode-Execute Cycle:

- Implement the main loop where instructions are fetched, decoded, and executed.

Stack Management:

- If required, simulate a stack for managing subroutine calls and local variables.

I/O Simulation:

- Implement functions or structures for simulating input/output operations.

Understanding the basics of a processor provides a foundation for designing and implementing a virtual processor. It involves creating abstractions for key components, defining an instruction set, and implementing the fetch-decode-execute cycle. The goal is to simulate the behavior of a real processor within the constraints of the project requirements.
## 3. Define the Instruction Set

### 3.1 Instruction Set for the Virtual Processor

#### Arithmetic Operations:
1. **ADD** *addition* - Add two register values
   - Syntax: `ADD destination, source1, source2`
   - Example: `ADD R1, R2, R3` (R1 = R2 + R3)

2. **SUB** *subtraction* - Subtract one register from another
   - Syntax: `SUB destination, source1, source2`
   - Example: `SUB R4, R5, R6` (R4 = R5 - R6)

3. **MULT** *multiplication* - Multiply two register values
   - Syntax: `MULT destination, source1, source2`
   - Example: `MULT R7, R8, R9` (R7 = R8 * R9)

4. **DIV** *division* - Divide one register by another
   - Syntax: `DIV destination, source1, source2`
   - Example: `DIV R10, R11, R12` (R10 = R11 / R12)

#### Logical Operations:
5. **AND** - Perform logical AND between two register values
   - Syntax: `AND destination, source1, source2`
   - Example: `AND R13, R14, R15` (R13 = R14 & R15)

6. **OR** - Perform logical OR between two register values
   - Syntax: `OR destination, source1, source2`
   - Example: `OR R16, R17, R18` (R16 = R17 | R18)

7. **XOR** - Perform logical XOR between two register values
   - Syntax: `XOR destination, source1, source2`
   - Example: `XOR R19, R20, R21` (R19 = R20 ^ R21)

8. **NOT** - Perform logical NOT between two register values
   - Syntax: `NOT destination, source1, source2`
   - Example: `NOT R19, R20, R21` (R19 = R20 ~ R21)


## 4. Design the Architecture

Syntax of Assembly Code:

The assembly code for the virtual processor follows a clear and consistent syntax to enhance readability and maintainability. The code adheres to the specified conventions, including camelCase notation for variables and functions, consistent indentation, and meaningful comments.

```asm
  ; Example: Moving data from R1 to R2
MOV R1, #10   ; Load immediate value 10 into R1
MOV R2, R1    ; Move data from R1 to R2

; Example: Loading data from memory into R3
LDR R3, [0x1000]   ; Load data from memory address 0x1000 into R3

; Example: Storing data from R4 into memory
STR R4, [0x2000]   ; Store the content of R4 into memory address 0x2000

; Example: Unconditionally jump to a label
JUMP startLabel    ; Jump to the label 'startLabel'

; Example: Conditionally jump to a label based on the content of R5
JUMPIF R5, endLabel   ; Jump to 'endLabel' if the content of R5 is true

; Example: Call a subroutine at the label 'subroutine'
CALL subroutine    ; Call the subroutine at 'subroutine'

; Example: Return from a subroutine
RET    ; Return from the current subroutine

; Example: Compare the contents of R6 and R7
CMP R6, R7    ; Compare R6 and R7

; Example: Halt the execution of the virtual processor
HLT    ; Halt execution

```

# IV. Glossary

| **Concept**           | **Definition**                                                                                                                                                                                                                                                                                                                                      | **GitHub Links**                                |
|-----------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------|
| **Assembler**         | A low-level programming language designed for specific computer architectures, lying between machine language and high-level languages.                                                                                                                                                                                                            | [Assembler GitHub](https://github.com/assembler) |
| **Interpreter**       | Software executing high-level programming language programs without prior compilation. It translates source code into executable instructions on the fly, aiding flexible interaction with the code.                                                                                                                                               | [Interpreter GitHub](https://github.com/interpreter) |
| **Processor (CPU)**   | Central Processing Unit - Executes machine instructions, handles operations, and manages data flow in a computer system. Interprets and executes instructions from programs stored in memory.                                                                                                                                                          | [Processor GitHub](https://github.com/processor)   |
| **Virtual Processor** | Software emulation of a physical processor, creating an isolated environment for operating systems or applications. Allows running multiple systems on a single machine.                                                                                                                                                                               | [Virtual Processor GitHub](https://github.com/virtualprocessor) |
| **Compiler**          | Software translating high-level programming language source code into executable binary code specific to a hardware architecture. Performs lexical analysis, parsing, intermediate code generation, optimization, and code generation.                                                        | [Compiler GitHub](https://github.com/compiler)     |
| **Debugger**          | A tool for detecting, analyzing, and correcting errors in a program's source code. Allows step-by-step program execution, variable inspection, and debugging features like breakpoints and watches.                                                                                                                                                  | [Debugger GitHub](https://github.com/debugger)     |
| **Logical Operations**| Fundamental binary logic operations (OR, XOR, AND, NOT) used in computer science. OR returns true if at least one operand is true. XOR returns true if exactly one operand is true. AND returns true only if both operands are true. NOT inverts the logic value of its operand.                                                            | [Logical Operations GitHub](https://github.com/logicaloperations) |
| **IDE**               | Integrated Development Environment - Software combining tools for software development, including a text editor, compiler/interpreter, debugger, and other features. Enhances programmer efficiency and simplifies development tasks.                                                                                                          | [IDE GitHub](https://github.com/ide)             |
| **C Language**        | High-level, procedural, and imperative programming language developed by Dennis Ritchie. Offers direct control over memory and system resources, with a simple syntax and modular programming approach. Widely used in system, low-level, desktop, and embedded development.                                                                 | [C Language GitHub](https://github.com/clanguage) |

# V. Conclusion

In conclusion, the Technical Specifications document provides a comprehensive overview of the development process for creating a virtual processor and interpreter for assembly code. The document outlines the project's goals, requirements, and the methodology adopted by the development team.

The folder structure, data structures, and security considerations are discussed, providing a solid foundation for the implementation of the virtual processor. The document also delves into the architectural design, choice of programming language, and the implementation of key components like the instruction interpreter, memory management, and input/output simulation.

Throughout the development process, a strong emphasis is placed on modularity, abstraction, and adherence to coding standards. The testing and validation procedures, continuous integration, and debugging strategies ensure the reliability and correctness of the final product.

The glossary provides a quick reference for key concepts, and the document concludes by summarizing the entire development journey, showcasing the organized and systematic approach taken by the development team.

As the project progresses, regular updates and collaboration between team members, along with effective project management using tools like Trello and GitHub, will contribute to the successful completion of the virtual processor and interpreter.