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

- [1. Introduction](#1-introduction) 
  - [1.1 Customer Request](#11-customer-request) 
  - [1.2 Document Purpose & Definition](#12-document-purpose--definition) 
  - [1.3 Glossary](#13-glossary) 
    - [ASSEMBLY](#assembly) 
    - [INTERPRETER](#interpreter) 
    - [PROCESSOR](#processor) 
    - [VIRTUAL PROCESSOR](#virtual-processor) 
    - [COMPILER](#compiler) 
    - [DEBUGGER](#debugger) 
    - [Logical Operation (OR, XOR, AND, NOT)](#logical-operation-or-xor-and-not) 
    - [IDE](#ide) 
    - [C Language](#c-language) 
  - [1.4 Project Overview](#14-project-overview) 
    - [1.4.1 Project Brief](#141-project-brief) 
    - [1.4.2 Requirements](#142-requirements)   
      - [Setting up the Development Environment](#setting-up-the-development-environment) 
        - [Software Requirements](#software-requirements) 
      - [Coding Methodology](#coding-methodology) 
        - [How We'll Go About It](#how-well-go-about-it) 
        - [Workflow](#workflow) 
        - [Coding conventions](#coding-conventions) 
            - [Naming](#naming) 
            - [Formatting](#formatting) 
            - [Comments](#comments) 
        - [Documenting Conventions](#documenting-conventions) 
        - [Test Procedure](#test-procedure) 
      - [Setting up the Virtual Processor](#setting-up-the-virtual-processor) 
        - [Software Requirements](#software-requirements-1) 
        - [Coding Methodology](#coding-methodology-1) 
            - [Testing Framework:](#testing-framework) 
            - [Debugger:](#debugger) 
            - [Continuous Integration:](#continuous-integration) 
            - [Virtual Terminal Implementation:](#virtual-terminal-implementation) 
            - [Built-in Debugger Implementation:](#built-in-debugger-implementation) 
            - [System Call Implementation:](#system-call-implementation) 
    - [1.4.3 Assumptions & Constraints](#143-assumptions--constraints) 
- [2. Technical Specifications](#2-technical-specifications) 
  - [2.1 Folder Structure](#21-folder-structure) 
  - [2.2 Data Structures](#22-data-structures) 
  - [2.3 Security](#23-security) 
- [3. How to Make It](#3-how-to-make-it) 
  - [3.1 Architecture](#31-architecture) 
    - [3.1.1 Modularity](#311-modularity)
      - [Module Breakdown](#module-breakdown) 
      - [Header Files](#header-files) 
    - [3.1.2 Abstraction](#312-abstraction)
      - [Memory Management](#memory-management) 
      - [Registers](#registers) 
    - [3.1.3 Instruction Interpreter](#313-instruction-interpreter) 
      - [Parsing](#parsing) 
      - [Execution](#execution) 
    - [3.1.4 Input/Output Management](#314-inputoutput-management) 
      - [I/O Simulation](#io-simulation)
    - [3.1.5 Testing and Validation](#315-testing-and-validation) 
      - [Unit Testing](#unit-testing) 
    - [3.1.6 Continuous Integration](#316-continuous-integration) 
    - [3.1.7 Documentation and Coding Standards](#317-documentation-and-coding-standards) 
      - [Comments and Documentation](#comments-and-documentation) 
      - [Adherence to Standards](#adherence-to-standards) 
    - [3.1.8 User Interface](#318-user-interface)
      - [CLI or GUI](#cli-or-gui) 
    - [3.1.9 Scalability and Maintenance](#319-scalability-and-maintenance) 
      - [Scalable Design](#scalable-design) 
    - [3.1.10 Directory Structure](#3110-directory-structure) 
  - [3.2 Understand the Basics of Processor](#32-understand-the-basics-of-processor) 
  - [3.3 Define the Instruction Set](#33-define-the-instruction-set) 
  - [3.4 Design the Architecture](#34-design-the-architecture) 
  - [3.5 Programming the Virtual Processor](#35-programming-the-virtual-processor) 
    - [3.5.1 Choice of Programming Language](#351-choice-of-programming-language) 
    - [3.5.2 Implement Components](#352-implement-components) 
    - [3.5.3 Instruction Interpretation](#353-instruction-interpretation) 
  - [3.6 Simulate Memory and Input/Output](#36-simulate-memory-and-inputoutput) 
    - [3.6.1 Memory](#361-memory) 
    - [3.6.2 Input/Output](#362-inputoutput) 
  - [3.7 Testing and Debugging](#37-testing-and-debugging)
  - [3.8 User Interface](#38-user-interface) 
  - [3.9 Documentation and Maintenance](#39-documentation-and-maintenance) 
- [4. Conclusion](#4-conclusion) 
  - [4.1 Thanks](#41-thanks) 


</details>

# 1. Introduction
## 1.1 Customer Request
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

## 1.2 Document Purpose & Definition

The goal of the Technical Specifications is to take the Functional Requirements which defines the features, scope and goals of the project, to dissect each requirement and turn it into instructions, as clear as possible, to guide the development team as well as the quality assurance team in the successful completion of their mission.

We therefore encourage thorough reading of the [Functional Specifications](https://github.com/algosup/2023-2024-project-3-virtual-processor-team-5/blob/main/Specifications/functionalSpecification.md) before further reading.

The goal of the Technical Requirements is to clarify as many dark areas as possible to avoid the engineers making decisions
In a sense, while the Functional Requirements represent the "What/Why" aspect of the project, the Technical Requirements are supposed to represent the "How" of the project.

With that being said, we will try to cover as many functional and non-functional aspects of the project while making technological and architectural decisions, evaluating those decisions, measuring their associated risks and impact (providing mitigation) and compare those to other potential solutions.

The document should also benefit other stakeholders and project owners by giving insight into our methodology and may serve as a future reference for maintenance or simple documentation purposes.

## 1.3 Glossary

### ASSEMBLY:
An assembler is a low-level programming language designed specifically for specific computer architectures, usually tied to a particular processor. It lies between machine language (direct binary representation of processor instructions) and more programmer-friendly high-level languages(a high-level programming language is designed to be more easily understood by humans, providing greater abstraction and usability compared to low-level languages ​​such as assembly or machine language.).

### INTERPRETER:
An interpreter is software responsible for directly executing programs written in a high-level programming language, without requiring a prior compilation step. Unlike compilers, interpreters translate source code into executable instructions on the fly, making development and debugging easier by allowing more flexible interaction with the code.

### PROCESSOR:
A processor, also called a central processing unit (CPU), is a computer component that executes machine instructions, handles logical and arithmetic operations, and manages the flow of data within a computer system. It interprets and executes instructions from programs stored in memory, thereby coordinating the fundamental operations necessary for a computer to function.

### VIRTUAL PROCESSOR:
A virtual machine, in virtual processor terms, is a software emulation of a physical processor, allowing programs to run as if they were running on dedicated physical hardware. It creates an isolated environment, called a virtual machine, in which an operating system or application can operate independently of the underlying hardware. Virtual processors are often used to run multiple operating systems or applications on a single physical machine, providing flexibility and more efficient resource management.

### COMPILER:
A compiler is software that translates source code written in a high-level programming language into executable binary code specific to a hardware architecture. It performs this conversion in several stages, including lexical analysis, parsing, intermediate code generation, code optimization, and finally, machine code or bytecode generation. The final result of the compiler is an executable program independent of the source code, allowing its execution on the target platform without requiring the presence of the compiler.

### DEBUGGER:
A debugger is a software tool used by programmers to detect, analyze, and correct errors in a program's source code. It allows you to follow program execution step by step, inspect variable values, identify logic errors, and pause execution to examine the execution context at specific points. Debuggers provide features such as breakpoints, watches to monitor variables, execution tracers, and the ability to run the program step by step to facilitate the debugging process and improve the reliability of the code.

### Logical Operation (OR, XOR, AND, NOT):
Logical operations (OR, XOR, AND, NOT) are fundamental operations in the field of binary logic used in computer science. Here are brief definitions for each of these operations:

OR (OR): The OR logical operation returns true (1) if at least one of the operands is true (1). Otherwise, it returns false (0).

XOR (exclusive OR): The XOR logical operation returns true (1) if exactly one of the operands is true (1), but not both. If neither or both are true, it returns false (0).

AND: The logical AND operation returns true (1) only if both operands are true (1). Otherwise, it returns false (0).

NOT: The NOT logic operation inverts the logic value of its operand. If the operand is true (1), NOT will return false (0), and vice versa.

These operations are commonly used in binary data manipulation at the hardware level and in logical expressions in programming. They are essential for logical calculations and flow control in computer systems.

### IDE:
An integrated development environment (IDE) is software that brings together several tools intended to facilitate software development. It typically offers a text editor for writing source code, a compiler or interpreter for turning the code into an executable, a debugger for detecting and correcting errors, and other features such as versioning, tools user interface design, performance analyzers, etc. IDEs are designed to improve the efficiency of programmers by providing an integrated environment that simplifies tasks related to software development. Examples of popular IDEs include Eclipse, Visual Studio, IntelliJ IDEA, and PyCharm.

### C Language:
The C programming language is a high-level, procedural, imperative language originally developed by Dennis Ritchie in the early 1970s at Bell Labs. It played a fundamental role in the development of many operating systems and inspired many other programming languages.

The C language offers direct control over memory and system resources, making it a preferred choice for system and low-level development. It uses a simple and compact syntax, with a modular programming approach, encouraging code reuse. C is also used for developing desktop applications, embedded systems, and is the basis of languages ​​such as C++ and Objective-C.

Key features of the C language:

Syntax: Its syntax is relatively simple, with low-level constructs allowing fine control over the hardware.
Portability: C programs can be compiled on different platforms, promoting source code portability.
Efficiency: The C language allows direct access to memory, providing significant performance efficiency.
Modularity: Modular programming is encouraged through functions and libraries, making code reuse easy.
The C language is still widely used in software development, and many critical systems and applications depend on it. 

## 1.4 Project Overview

### 1.4.1 Project Brief
As stated in the Functional Requirements,this project involves the creation of a virtual processor designed to execute assembly code.

we have been given 7 week to complete this project
Looking deeper into the project we decided to have a meeting together to find out what to start, to agree on the direction to take and also to know what we wanted as a result at the end of the project.
After this meeting we decided to adopt a step-by-step strategy with daily tasks. We find that this method is simpler to follow and is the simplest to be effective.

### 1.4.2 Requirements
Even if this document is intended to be as exhaustive and demonstrative as possible, it is expected that its reader has some basic knowledge in virtual machines, more precisely in this case in virtual processors, and also certain knowledge in programming.

As indicated in the call for tender, at the end of the project we must be able to code in an assembler created by us with an interpreter also created by us, execute it on a virtual processor also created by us, be able to prove that it executes well by making a virtual terminal and finally we can also display
the contents of the registers and have a built-in debugger.

the task may seem difficult, it is true that it is not the simplest project but with good organization and respect for the tasks the project can greatly improve the ease of progress of this project.

As an IDE visual studio code allows us to run all our programs in a simple and portable way, which means that PC and Mac team members will be able to run and test the program, which will prove useful during the process of development.

#### Setting up the Development Environment

The first step is to set up the development environment, which we can define as follows:
##### Software Requirements
- [VSCode](https://code.visualstudio.com/) as an IDE to run our code simply and efficiently
- the programming language is [C](https://en.wikipedia.org/wiki/C_(programming_language)#:~:text=C%20is%20an%20imperative%20procedural,all%20with%20minimal%20runtime) to program our entire project
- pour compiler notre en c nous utilisons le compiler [GCC](https://gcc.gnu.org)
- we use Github or other source control management to  communicate the progress of our project, [Github](https://github.com/) is recommended for this task.
- we also use [trello](https://trello.com/) for our step-by-step strategy by putting the different tasks to do during the day for better optimization of time.

#### Coding Methodology

##### How We'll Go About It

1. ######  **Requirements Analysis:**
  - We begin by thoroughly understanding what the clients want, detailing all the requirements.

2. ###### **Quick Daily Meetings:**
  - Every day, we gather quickly to discuss progress, potential issues, and plan tasks for the day.
  - We keep our Trello board updated for effective organization.

3. ######  **Version Control with Git:**
  - We use Git and GitHub to keep track of all versions of our code.
  - Whenever we add something new or fix a bug, we create a specific branch.

4. ######  **Modular Development:**
  - The project is broken down into logical pieces, each serving a specific purpose.
  - We use header files to clearly define what each piece does.
  - For each piece, we write tests to ensure it functions correctly.

5. ######  **Continuous Integration:**
  - Whenever we make a change, we ensure the entire project compiles correctly and passes all tests.

6. ######  **Testing:**
  - We avoid unpleasant surprises by writing tests for everything. Small tests for each piece and comprehensive tests for the entire system.
  - This prevents tears later on.

7. ######  **Documentation:**
  - No need to guess what each piece does. We document everything.
  - Clear comments in the code and a detailed README for everyone to understand.

8. ######  **Debugging:**
  - We're not all perfect, so we use debugging tools to track down and eliminate bugs.
  - Serious testing and debugging during development.

9. ######  **Code Reviews:**
  - We trust each other, but two pairs of eyes are better than one. We review the code of others and provide constructive feedback.

##### Workflow
The development team began working on features requested in the project's call for tender, such as storing an immediate value in a register.
• Copy the value of one register to another register.
• Read the value in memory at the address contained by a register and store it in
another register.
• Storing the value of a register in memory at the address contained by another register.
• Compare the contents of the registers.
• Unconditionally move to a label.
• Jump conditionally to a label.
• Calling a subroutine.
• Return from a subroutine.
• The 4 basic arithmetic operations: addition, subtraction, multiplication and division.
• The 4 basic logical operations: OR, AND, XOR and NOT.
before the specifications are fully understood and defined.

Once the functional specifications are dissected into the technical specifications, the project functions and features are all reflected in the trello in the form of “Tasks” which we prefer to call “tickets” internally.
Each of these tickets is then sent to QA in the "next release" section once verified, the tickets are sent to the "done" section, assigned to the team members and prioritized by the project manager or technical manager, in function of the task.

Each ticket represents a part of the work, a bug found, a feature request, an update. This abstraction makes it possible to track many types of tasks, break them down even further, and move forward quickly.
We will return to this more at the end of this document.
##### Coding Conventions
###### Naming
- We use camelCase notation for our variables and functions.
- Constants are in uppercase with underscores.
###### Formatting
- We indent with 4 spaces to ensure consistent readability.
- Opening braces are placed on the same line as the control statements.
###### Comments
- We use meaningful comments to clarify the code.
- Comment near 100% of the Functions in the code.

##### Documenting Conventions

We will automatically generate documentation for this project.
How to use it will also be included in the readme.

##### Test Procedure

we will test all the functionalities of the project little by little during the project for better efficiency instead of testing everything on the same day to avoid an unpleasant surprise on the day of the final rendering.

#### Setting up the Virtual Processor
##### Software Requirements
For the virtual processor development, we need the following software tools and components:

- [Visual Studio Code (VSCode)](https://code.visualstudio.com/): We will use VSCode as the IDE for writing, editing, and managing our C code. It provides a simple and efficient platform for development.

- [C](https://en.wikipedia.org/wiki/C_(programming_language)#:~:text=C%20is%20an%20imperative%20procedural,all%20with%20minimal%20runtime): The entire project will be implemented in the C language. It is a powerful and efficient language, suitable for system-level development.

- [GCC (GNU Compiler Collection)](https://gcc.gnu.org): We will use GCC as the C compiler for our project.

- [GitHub](https://github.com/): We will utilize GitHub for source code management, version control, and collaboration among team members.

- [Trello](https://trello.com/): Trello will be our project management tool for organizing tasks, setting priorities, and tracking progress with a step-by-step strategy.

#### Coding Methodology

##### Testing Framework:

Unit Testing Framework (e.g., Unity or CUnit): To ensure the correctness of our code, we will implement unit tests for individual components and system functionalities. The choice of a specific testing framework will be determined during the project.

##### Debugger:

Debugger in Visual Studio Code: We will leverage the debugging features provided by VSCode to identify, analyze, and correct errors in our code. This includes setting breakpoints, inspecting variable values, and stepping through code execution.

##### Continuous Integration:

Continuous Integration Tool (e.g., Jenkins or Travis CI): To maintain code quality, we will implement continuous integration, ensuring that the entire project compiles correctly and passes all tests with each code change.

##### Virtual Terminal Implementation:

A mechanism to simulate a virtual terminal for displaying text output from assembly code. This will be implemented as part of the virtual processor, and the details will be defined during the development process.

##### Built-in Debugger Implementation:

A built-in debugger for the virtual processor, integrated into the development environment. This debugger will assist in identifying and resolving issues during the execution of assembly code.

##### System Call Implementation:

Implementation of a virtual system call mechanism to facilitate interaction between assembly code and the virtual processor, particularly for displaying text output.
These software tools and components will form the foundation for setting up the virtual processor development environment and ensuring a smooth development process.

### 1.4.3 Assumptions & Constraints
...

# 2. Technical Specifications

## 2.1 Folder Structure
...

## 2.2 Data Structures
...

## 2.3 Security
...

# 3. How to Make It

## 3.1 Architecture

### 3.1.1 Modularity

#### Module Breakdown
...

#### Header Files
...

### 3.1.2 Abstraction

#### Memory Management
...

#### Registers
...

### 3.1.3 Instruction Interpreter

#### Parsing
...

#### Execution
...

### 3.1.4 Input/Output Management

#### I/O Simulation
...

### 3.1.5 Testing and Validation

#### Unit Testing
...

### 3.1.6 Continuous Integration
...

### 3.1.7 Documentation and Coding Standards

#### Comments and Documentation
...

#### Adherence to Standards
...

### 3.1.8 User Interface

#### CLI or GUI
...

### 3.1.9 Scalability and Maintenance

#### Scalable Design
...

### 3.1.10 Directory Structure
...

## 3.2 Understand the Basics of Processor
...

## 3.3 Define the Instruction Set
...

## 3.4 Design the Architecture
...

## 3.5 Programming the Virtual Processor

### 3.5.1 Choice of Programming Language
...

### 3.5.2 Implement Components
...

### 3.5.3 Instruction Interpretation
...

## 3.6 Simulate Memory and Input/Output

### 3.6.1 Memory
...

### 3.6.2 Input/Output
...

## 3.7 Testing and Debugging
...

## 3.8 User Interface
...

## 3.9 Documentation and Maintenance
...

# 4. Conclusion

## 4.1 Thanks
...
