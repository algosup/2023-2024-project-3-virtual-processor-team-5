# Functional Specification - Team 5's Virtual Processor

[<img src="https://www.presse-citron.net/app/uploads/2020/06/linkedin-logo.jpg"  width="20px" align=right>](https://www.linkedin.com/in/r%C3%A9my-charles-2a8960232/)
[<img src="https://cdn.pixabay.com/photo/2022/01/30/13/33/github-6980894_1280.png" width="20" align="right">](https://github.com/RemyCHARLES)



|**Author**|Rémy CHARLES|
|:---|:---|
|**Version**|**1.1**|
|**Project**|**Virtual Processor**|
|**Created on**|**2024-01-12**|
|**Last updated**|**2024-01-23**|



## Table of contents

<details>

<summary>Click to expand 🖋️</summary>

- [Functional Specification - Team 5's Virtual Processor](#functional-specification---team-5s-virtual-processor)
  - [Table of contents](#table-of-contents)
  - [1. Introduction](#1-introduction)
  - [2. Development Environment](#2-development-environment)
  - [3. Functional Requirements](#3-functional-requirements)
  - [4. Usability Requirements](#4-usability-requirements)
  - [5. Non-Functional Requirements](#5-non-functional-requirements)
  - [6. Assembly Language Specification](#6-assembly-language-specification)
    - [6.1. Instructions](#61-instructions)
    - [6.2. Operations](#62-operations)
  - [7. C Program Development](#7-c-program-development)
    - [7.1. Program Structure](#71-program-structure)
    - [7.2. Reading Assembly Code](#72-reading-assembly-code)
    - [7.3. Executing Instructions](#73-executing-instructions)
    - [7.4. Error Handling and Reporting](#74-error-handling-and-reporting)
    - [7.5. Debugging and Logging](#75-debugging-and-logging)
  - [8. Virtual System Call Implementation](#8-virtual-system-call-implementation)
    - [8.1. Text Display](#81-text-display)
      - [Functionality](#functionality)
      - [Advanced Features](#advanced-features)
    - [8.2. Debugging Features](#82-debugging-features)
      - [Comprehensive Tools](#comprehensive-tools)
      - [User Guide](#user-guide)
    - [8.3. I/O Operations](#83-io-operations)
      - [Input Handling](#input-handling)
      - [Output Procedures](#output-procedures)
    - [8.4. Extension Mechanisms](#84-extension-mechanisms)
      - [Extensibility Framework](#extensibility-framework)
      - [Customization Strategies](#customization-strategies)
  - [9. Conclusion](#9-conclusion)
  - [10. Glossary](#10-glossary)


</details>


## 1. Introduction

The purpose of this document is to provide a comprehensive functional specification for **Team 5's Virtual Processor Project**. This project involves the creation of a **virtual processor** designed to execute **assembly code**. The processor must to be developed in the **C programming language**, adhering to principles of portability and efficiency. This document outlines the essential elements and specifications of the project, including the development environment, assembly language design, and implementation details.

The virtual processor aims to offer a simplified yet functional platform for understanding and executing basic assembly instructions. It serves as an educational tool, facilitating the learning of low-level programming concepts. The processor will be equipped to handle a **custom** assembly language, which will be fully detailed in this specification. The project will emphasize the importance of efficient programming practices and the intricacies of processor design and operation.

This specification serves as a guideline for developers and contributors to understand the project's goals, requirements, and design philosophy. It will ensure that all aspects of the project align with the outlined objectives and standards.

<img src="img/functionalImg/SequenceDiagram.png">

*The sequence diagram depicts the flow of operations in the execution of assembly code by a virtual processor. It begins with the C Program loading the code, followed by the Parser ensuring its correctness. The Virtual Processor oversees the execution flow, where the Instruction Decoder translates each command for the Execution Unit. System Calls are special functions, such as output display, which are executed as needed. This sequence loops until the program ends, with results displayed to the User.*

## 2. Development Environment

The development of the Virtual Processor will be conducted in a specific programming and toolset environment to ensure **consistency**, **compatibility**, and **performance**. The key components of this environment are:

- **Programming Language**: The entire project is to be developed in standard C language. This choice is made to leverage the portability and efficiency of C, making the virtual processor adaptable to various platforms.

- **Compiler**: The GNU Compiler Collection (GCC) is designated as the primary compiler. Its widespread availability and compatibility with various operating systems make it an ideal choice.

- **Integrated Development Environment (IDE)**: Visual Studio Code (VS Code) is recommended for its versatility and robust support for C/C++ development. It offers valuable features like debugging tools and source code management integration.

- **Libraries**: Only standard C libraries are to be used in this project. The use of external or third-party libraries is restricted to ensure the simplicity and portability of the code.

- **Version Control**: Git, in conjunction with GitHub, will be used for source code management. This allows for effective collaboration, version tracking, and code review processes.

- **Code Style and Conventions**: Adherence to common C programming conventions is expected to maintain code readability and maintainability. A specific style guide will be provided to ensure consistency across the project.

This environment is chosen to balance functionality, ease of use, and accessibility for developers. It will support the project's goals of creating a portable and efficient virtual processor.

<img src="img/functionalImg/workflowDiagram.png">

*In the development workflow, developers use Visual Studio Code (VS Code) to write and manage code. Git handles version control, facilitating collaboration and code tracking. Changes are committed, branched, and merged. The GNU Compiler Collection (GCC) compiles code into an executable binary. This streamlined process ensures efficient project development.*


## 3. Functional Requirements

This section defines the capabilities that the virtual processor must possess:

<center>

| *ID*    | *Requirement*                 | *Description*                                                                                              |
| ------- | ----------------------------- | ---------------------------------------------------------------------------------------------------------- |
| **FR1** | **Instruction Set Execution** | The system must execute the predefined instruction set accurately.                                         |
| **FR2** | **Error Handling**            | The system should be able to handle errors gracefully and provide meaningful error messages.               |
| **FR3** | **System Calls**              | The system must support a set of system calls for I/O operations, text display, and other functionalities. |
| **FR4** | **Program Loading**           | The system should allow loading and execution of assembly programs from an external source.                |
| **FR5** | **Debugging Support**         | The system must provide debugging capabilities for the assembly code being executed.                       |

</center>

## 4. Usability Requirements

This section outlines the expectations for how the system will interact with its users:

<center>

| *ID*    | *Requirement*      | *Description*                                                                                                                 |
| ------- | ------------------ | ----------------------------------------------------------------------------------------------------------------------------- |
| **UR1** | **Documentation**  | Comprehensive documentation must be provided, detailing system use and capabilities.                                          |
| **UR2** | **Error Messages** | Error messages should be clear, informative, and guide the user towards possible solutions.                                   |
| **UR3** | **Learning Curve** | The system should be designed such that a new user can write and execute a simple program within a few hours of introduction. |
| **UR4** | **Accessibility**  | Interface design must consider accessibility guidelines to be usable by people with a wide range of abilities.                |

</center>

## 5. Non-Functional Requirements

This section outlines the standards the virtual processor must adhere to that do not pertain directly to specific functionalities:

<center>

| *ID*     | *Requirement*       | *Description*                                                                                                  |
| -------- | ------------------- | -------------------------------------------------------------------------------------------------------------- |
| **NFR1** | **Performance**     | The system should execute instructions within the predefined time limits to ensure efficiency.                 |
| **NFR2** | **Reliability**     | The processor must have an uptime of 99%, ensuring consistent availability and stability.                      |
| **NFR3** | **Scalability**     | The system should be capable of handling an increasing number of instructions without performance degradation. |
| **NFR4** | **Maintainability** | Code should be well-documented and structured to allow for easy maintenance and updates.                       |
| **NFR5** | **Portability**     | The system must be able to run in different environments without requiring changes.                            |
| **NFR6** | **Compliance**      | The system must comply with all relevant legal and regulatory requirements.                                    |

</center>

## 6. Assembly Language Specification

The virtual processor will be equipped to handle a custom assembly language. This language will be designed to be **simple** and **intuitive**, allowing for easy comprehension and execution. The language will be fully detailed in this section, including **instructions**, **operations**, and **syntax**.

🔥 You can find a detailed description of the assembly language in the [Assembly Language Specification](../Documentation/AssemblyLanguageSpecification.md)

### 6.1. Instructions

The assembly language designed for the Virtual Processor will include a set of fundamental instructions. These instructions form the core functionality of the language, enabling basic programming operations. The instruction set is designed to be minimal yet sufficient for a wide range of tasks. Key aspects include:

- **Data Movement Instructions**: These will include instructions for loading and storing data, moving data between registers, and handling immediate values. 

    - **``MOV`` (Move Data)**
      - Source Operand --> Destination Operand
      - Operation: Copy data from source to destination.
  
  <br>
  
    ```assembly 
    ; Example: Moving data from R1 to R2
    MOV R1, #10   ; Load immediate value 10 into R1
    MOV R1, R2     ; Move data from R1 to R2
    ```

  <br>

    - **``LDR`` (Load from Memory)**
      - Memory Location (Address) --> Register
      - Operation: Load data from memory into the register.

  <br>

    ```assembly
    ; Example: Loading data from memory into R1
    LDR R1, [0x1000]   ; Load data from memory address 0x1000 into R1
    ```
  
  <br>

    - **``STR`` (Store to Memory)**
      - Register --> Memory Location (Address)
      - Operation: Store data from register into memory.

  <br>

    ```assembly
    ; Example: Storing data from R1 into memory
    MOV R1, #5         ; Load immediate value 5 into R1
    STR R1, [0x1000]   ; Store data from R1 into memory address 0x1000
    ```

  <br>

    - **``PUSH`` (Push onto Stack)**
      - Register --> Stack
      - Operation: Push data from register onto the stack.

  <br>

    ```assembly
    ; Example: Pushing a register's content onto the stack
    MOV R1, #8    ; Load immediate value 8 into R1
    PUSH R1       ; Push the contents of R1 onto the stack
    ```
  
  <br>

    - **``POP`` (Pop from Stack)**
      - Stack --> Register
      - Operation: Pop data from stack into the register.

  <br>

    ```assembly
    ; Example: Popping the top of the stack into a register
    POP R2        ; Pop the top of the stack into R2
    ```
  <br>

    - **``LEA`` (Load Effective Address)**
      - Memory Location (Address) --> Register
      - Operation: Load the address into the register.

  <br>

    ```assembly
    ; Example: Loading an address into a register
    LEA R3, [0x2000]   ; Load the address 0x2000 into R3
    ```

  <br>

    - **``LDI`` (Load Immediate)**
      - Immediate Value --> Register
      - Operation: Load immediate value into the register.

  <br>

    ```assembly
    ; Example: Loading an immediate value into a register
    LDI R4, #15    ; Load immediate value 15 into R4
    ```
  
  <br>

- **Arithmetic Operations**: Basic arithmetic instructions such as addition, subtraction, multiplication, and division will be implemented.
  
   - **``ADD`` (Addition)**
     To perform subtraction, you can use a combination of the following two instructions:
        - Source Operand 1 + Source Operand 2 --> Destination Operand
        - Operation: Add values from Source Operand 1 and Source Operand 2, and store the result in the Destination Operand.
  
  <br>

    ```assembly
    ; Example: Adding two register values
    MOV R1, #10       ; Load immediate value 10 into R1
    MOV R2, #20       ; Load immediate value 20 into R2
    ADD R3, R1, R2    ; R3 = R1 + R2 (30)
    ```
  
  <br>

   - **``SUB`` (Subtraction)**
       To perform subtraction, you can use a combination of the following two instructions:
      - **``NOT`` (Bitwise NOT)**
        - Source Operand --> Destination Operand
        - Operation: Perform bitwise NOT on the Source Operand and store the result in the Destination Operand.
      - **``ADD`` (Addition)**
        - Source Operand 1 + Source Operand 2 --> Destination Operand
        - Operation: Add values from Source Operand 1 and Source Operand 2, and store the result in the Destination Operand. This effectively accomplishes subtraction by adding the bitwise NOT of the second operand.

  <br>

    ```assembly
    ; Example: Subtracting one register from another
    MOV R1, #30       ; Load immediate value 30 into R1
    MOV R2, #20       ; Load immediate value 20 into R2
    SUB R3, R1, R2    ; R3 = R1 - R2 (10)
    ```

  <br>

   - **``MULT`` (Multiplication)**
  To perform multiplication, you can use a combination of the following two instructions:
      - **``AND`` (Bitwise AND)**
        - Source Operand 1 AND Source Operand 2 --> Destination Operand
        - Operation: Perform bitwise AND between Source Operand 1 and Source Operand 2, and store the result in the Destination Operand.
      - **``ADD`` (Addition)**
        - Source Operand 1 + Source Operand 2 --> Destination Operand
        - Operation: Add values from Source Operand 1 and Source Operand 2, and store the result in the Destination Operand. This effectively accomplishes multiplication by repeatedly adding Source Operand 1 to itself (Source Operand 2 times).

  <br>

    ```assembly
    ; Example: Multiplying two register values
    MOV R1, #4        ; Load immediate value 4 into R1
    MOV R2, #5        ; Load immediate value 5 into R2
    MULT R3, R1, R2   ; R3 = R1 * R2 (20)
    ```

  <br>

   - **``DIV`` (Division)**
  To perform division in LC3, you can use a combination of the following two instructions:
      - **``AND`` (Bitwise AND)**
        - Source Operand 1 AND Source Operand 2 --> Destination Operand
        - Operation: Perform bitwise AND between Source Operand 1 and Source Operand 2, and store the result in the Destination Operand.
      - **``ADD`` (Addition)**
        - Source Operand 1 + Source Operand 2 --> Destination Operand
        - Operation: Add values from Source Operand 1 and Source Operand 2, and store the result in the Destination Operand. This effectively accomplishes division by repeatedly subtracting Source Operand 2 from Source Operand 1 and counting the number of subtractions.

  <br>

    ```assembly
    ; Example: Dividing one register by another
    MOV R1, #20       ; Load immediate value 20 into R1
    MOV R2, #5        ; Load immediate value 5 into R2
    DIV R3, R1, R2    ; R3 = R1 / R2 (4)
    ```

  <br>

- **Logical Operations**: Instructions for logical operations like AND, OR, XOR, and NOT are included.
  
    - **``AND`` (Logical AND)** 
      - Source Operand 1 AND Source Operand 2 --> Destination Operand
      - Operation: Perform logical AND.

  <br>

    ```assembly
    ; Example: AND operation between two registers
    MOV R1, #12       ; Load immediate value 12 into R1
    MOV R2, #5        ; Load immediate value 5 into R2
    AND R3, R1, R2    ; R3 = R1 AND R2 (4)
    ```

  <br>

    - **``OR`` (Logical OR)**
      - Source Operand 1 OR Source Operand 2 --> Destination Operand
      - Operation: Perform logical OR.

  <br>

    ```assembly
    ; Example: OR operation between two registers
    MOV R1, #12       ; Load immediate value 12 into R1
    MOV R2, #5        ; Load immediate value 5 into R2
    OR R3, R1, R2     ; R3 = R1 OR R2 (13)
    ```

  <br>

    - **``XOR`` (Logical XOR)**
      - Source Operand 1 XOR Source Operand 2 --> Destination Operand
      - Operation: Perform logical XOR.

  <br>

    ```assembly
    ; Example: XOR operation between two registers
    MOV R1, #12       ; Load immediate value 12 into R1
    MOV R2, #5        ; Load immediate value 5 into R2
    XOR R3, R1, R2    ; R3 = R1 XOR R2 (9)
    ```

  <br>

    - **``NOT`` (Logical NOT)**
      - NOT Source Operand --> Destination Operand
      - Operation: Perform logical NOT.

  <br>

    ```assembly
    ; Example: NOT operation on a register
    MOV R1, #12       ; Load immediate value 12 into R1
    NOT R2, R1        ; R2 = NOT R1
    ```
  
  <br>

- **Control Flow**: Instructions for branch, jump, and call operations will facilitate the control flow within the assembly programs. 
  
    - **``JMP`` (Jump)**
      - Destination Operand --> Program Counter
      - Operation: Jump to the specified address.

  <br>

    ```assembly
    ; Example: Unconditional jump to an address
    JMP 0x3000       ; Jump to address 0x3000
    ```

  <br>

    - **``JZ`` (Jump if Zero)**
      - Destination Operand --> Program Counter
      - Operation: Jump to the specified address if the zero flag is set.

  <br>

    ```assembly
    ; Example: Conditional jump if zero flag is set
    CMP R1, R2       ; Compare R1 and R2
    JZ 0x3000        ; Jump to 0x3000 if zero flag is set
    ```

  <br>

    - **``JNZ`` (Jump if Not Zero)**
      - Destination Operand --> Program Counter
      - Operation: Jump to the specified address if the zero flag is not set.

  <br>

    ```assembly
    ; Example: Conditional jump if zero flag is not set
    CMP R1, R2       ; Compare R1 and R2
    JNZ 0x3000       ; Jump to 0x3000 if zero flag is not set
    ```

  <br>  

    - **``JE`` (Jump if Equal)**
      - Destination Operand --> Program Counter
      - Operation: Jump to the specified address if the equal flag is set.

  <br>

    ```assembly
    ; Example: Conditional jump if equal flag is set
    CMP R1, R2       ; Compare R1 and R2
    JE 0x3000        ; Jump to 0x3000 if equal flag is set
    ```

  <br>

    - **``JNE`` (Jump if Not Equal)**
      - Destination Operand --> Program Counter
      - Operation: Jump to the specified address if the equal flag is not set.

  <br>

    ```assembly
    ; Example: Conditional jump if equal flag is not set
    CMP R1, R2       ; Compare R1 and R2
    JNE 0x3000       ; Jump to 0x3000 if equal flag is not set
    ```

  <br>

    - **``CALL`` (Call Subroutine)**
      - Destination Operand --> Program Counter
      - Operation: Call the subroutine at the specified address.

  <br>

    ```assembly
    ; Example: Calling a subroutine
    CALL 0x4000      ; Call subroutine at 0x4000
    ```

  <br>

    - **``RET`` (Return from Subroutine)**
      - Stack --> Program Counter
      - Operation: Return from the subroutine.
  
  <br>

    ```assembly
    ; Example: Returning from a subroutine
    RET              ; Return from subroutine
    ```
  
  <br>

- **Special Instructions**: A set of special instructions for system calls, input/output operations, and other processor-specific tasks. 
  
    - **``SYSCALL`` (System Call)**
      - System Call Number --> System Call Handler
      - Operation: Invoke the specified system call.

  <br>

    ```assembly
    ; Example: Invoking a system call
    MOV R1, #1       ; Load system call number into R1
    SYSCALL R1       ; Perform system call #1
    ```

  <br>

    - **``IN`` (Input)**
      - Input Device --> Register
      - Operation: Read input from the specified device.

  <br>

    ```assembly
    ; Example: Reading input from a device
    IN R2, #2        ; Read input from device #2 into R2
    ```
  
  <br>

    - **``OUT`` (Output)**
      - Register --> Output Device
      - Operation: Write output to the specified device.

  <br>

    ```assembly
    ; Example: Writing output to a device
    MOV R3, #123     ; Load data into R3
    OUT R3, #3       ; Write output from R3 to device #3
    ```

  <br>

    - **``NOP`` (No Operation)**
      - No Operation
      - Operation: Do nothing.

  <br>

    ```assembly
    ; Example: Executing a no operation
    NOP              ; Do nothing
    ```

  <br>

    - **``HALT`` (Halt)**
      - Halt
      - Operation: Halt the processor. 

  <br>

    ```assembly
    ; Example: Halting the processor
    HALT             ; Halt the processor
    ```

  <br>

*Each instruction will be described in detail, including its syntax, operation, and usage examples. This will ensure a clear understanding of how to program using the Virtual Processor's assembly language.*

### 6.2. Operations

The operations of the assembly language define how each instruction manipulates data and controls the flow of the program. This section will detail the **operational characteristics** of the assembly language, which are critical for the Virtual Processor’s functionality:

- **Register Operations**: Detailed explanations of how instructions interact with registers, including register loading, storing, and manipulation. Registers' name: 
    - ``R0`` - ``R7``: General-purpose registers
    - ``PC``: Program counter
    - ``LR``: Link register
    - ``PSR``: Processor status register
    - ``USP``: User stack pointer
    - ``SSP``: Supervisor stack pointer

- **Memory Operations**: Descriptions of instructions for memory access, including direct and indirect addressing, and memory management techniques. 
  
- **Arithmetic and Logical Operations**: Clarification on how arithmetic and logical instructions process data, including flags affected, and overflow handling. Arithmetic instructions include ```ADD```, ```SUB```, ```MULT```, and ```DIV```and logical instructions include ```AND```, ```OR```, ```XOR```, and ```NOT```.

- **Control Flow Operations**: Insight into how jump, branch, and call instructions manage the program flow, including condition checks and subroutine handling. ```JMP```, ```JZ```, ```JNZ```, ```JE```, ```JNE```, ```CALL```, and ```RET``` are included.

- **System-Level Operations**: Overview of operations related to system calls and I/O handling, essential for interacting with the system and external environment. System call instructions include ```SYSCALL```, ```IN```, ```OUT```, ```NOP```, and ```HALT```.

*Each operation will be described in the context of its effect on the processor state, including any changes to registers, memory, or the program counter. Examples will be provided to illustrate typical use cases and expected outcomes.*

## 7. C Program Development

The C program is essential for the Virtual Processor, acting as the **interface** for **interpreting** and **executing** the **assembly language**. This section details its intricate design and comprehensive implementation.

### 7.1. Program Structure
- **Overview:** This part describes the overarching structure of the C program, emphasizing modularity and efficient processing.
- **Modules:**
    - `Interpreter Loop`: The main loop that repeatedly reads and executes assembly instructions, acting as the heart of the program.
    - `Instruction Set Handler`: Decodes and processes each instruction, translating assembly language into executable actions.
    - `Memory Management`: Manages the virtual memory system, including allocation, access, and deallocation, ensuring efficient memory usage.

### 7.2. Reading Assembly Code
- **Parsing Method:** Explains the sophisticated parsing mechanism used to interpret the assembly language, including lexical analysis and syntax parsing.
- **Error Detection:**
    - `Syntax Analysis`: Details the method for identifying syntax errors, ensuring adherence to assembly language specifications.
    - `Semantic Checks`: Describes the process for logical validation, ensuring that the instructions make sense within the context of the language.

### 7.3. Executing Instructions
- **Instruction Interpretation:** This subsection breaks down how the C program interprets and executes each type of instruction in the assembly language.
- **Operational Handling:**
    - `Register Operations`: Discusses how the program manages data in registers, ensuring accurate and efficient data manipulation.
    - `Control Flow Management`: Elaborates on handling jumps, loops, and conditional executions within the program.

### 7.4. Error Handling and Reporting
- **Runtime Errors:** Outlines the strategies for catching and addressing errors during the program's execution. That includes syntax errors, semantic errors, and runtime errors. 
- **Reporting Mechanism:** Details the comprehensive error reporting system, designed to provide clear and actionable information to the user.

### 7.5. Debugging and Logging
- **Debugging Tools:** Describes the built-in debugging tools, including breakpoints, step execution, and state inspection, to facilitate troubleshooting. 
- **Logging System:** Explores the logging mechanism, which records execution details, aiding in post-execution analysis and debugging.

*In-depth understanding of the C program's development is crucial for ensuring the effective operation and reliability of the Virtual Processor.*

## 8. Virtual System Call Implementation

This section elaborates on the implementation of virtual system calls within the Virtual Processor, key to bridging the assembly program and the virtual environment.

### 8.1. Text Display

#### Functionality
The text display system call is a pivotal component of the Virtual Processor, enabling the output of text to the virtual screen. This functionality encompasses a wide range of features that contribute to a rich and interactive user experience. Some of the core functionalities include:

- **Text Rendering:** The system call can render text on the virtual screen, supporting various fonts and character sizes.
- **Formatting:** Users can apply formatting to the displayed text, including font styles (bold, italic), alignment, and line spacing.
- **Color Control:** The system call allows for precise control over text and background colors, facilitating visual distinction and highlighting of text.
- **Cursor Management:** Users can control the position and behavior of the text cursor, making it easy to implement text-based interfaces and user interactions.
- **Scrolling:** The system call supports scrolling of text when the content exceeds the visible screen area.

#### Advanced Features
In addition to the fundamental text display capabilities, the system call offers advanced features to enhance user interactions and create dynamic virtual environments:

- **Interactive Input:** Users can create interactive text-based forms and menus, where the cursor can be moved to specific input fields, and users can provide input via keyboard or other input methods.
- **Animation:** The system call allows for text-based animation, enabling the creation of dynamic and engaging virtual environments.
- **Screen Clearing:** Users can clear the screen or specific regions, making it easy to refresh the display and create responsive user interfaces.
- **Cursor Effects:** The cursor can be customized with different shapes, colors, and blinking patterns to provide visual cues to the user.
- **Text Effects:** Users can apply text effects such as text shadows, outlines, and gradients to enhance the visual appeal of text elements.

### 8.2. Debugging Features

#### Comprehensive Tools
The debugging features provided by the Virtual Processor's system calls are extensive and essential for effective program development and troubleshooting. These tools include:

- **Real-Time Variable Tracking:** Developers can monitor the values of variables and registers in real-time as the program executes, allowing for quick identification of issues.
- **Stack Trace Analysis:** The system call provides detailed stack trace information, showing the call hierarchy of functions and procedures, aiding in identifying the source of errors.
- **Conditional Breakpoints:** Developers can set breakpoints at specific points in the code and specify conditions for when the program should pause, allowing for precise debugging.

#### User Guide
To make the best use of these debugging tools, a comprehensive user guide is provided. This guide offers step-by-step instructions on how to leverage the debugging features effectively. It includes:

- **Setting Breakpoints:** A detailed explanation of how to set breakpoints at specific lines of code or memory addresses and configure conditions for breaking.
- **Variable Inspection:** Instructions on how to inspect the values of variables and registers during program execution, including viewing variable contents and their memory addresses.
- **Stack Trace Examination:** Guidance on analyzing the stack trace to identify function calls and their sequence.
- **Handling Runtime Errors:** Instructions on handling runtime errors, including suggestions for common debugging scenarios and strategies for error resolution.
- **Interactive Debugging:** Tips on using the interactive debugging interface, including stepping through code, examining memory contents, and modifying variables for testing purposes.

### 8.3. I/O Operations

#### Input Handling
The I/O system calls in the Virtual Processor cater to various forms of input, including keyboard input and file-based inputs. Key functionalities include:

- **Keyboard Input:** The system call provides mechanisms to capture keyboard input from the user. It allows for the detection of keystrokes, including key codes and characters entered.
- **File-Based Input:** Users can interact with files, reading data from external files and processing them within the virtual environment. This feature supports reading data records and configuration files.

#### Output Procedures
Output management is a crucial aspect of the I/O system calls, ensuring that data is displayed or stored efficiently. Key procedures include:

- **Display Output:** The system call supports the display of text, data, and graphics on the virtual screen. Users can control the positioning of output and apply formatting to enhance readability.
- **File Output:** Users can write data to external files, allowing for data storage and retrieval. This feature is useful for logging and data persistence.
- **Error Handling:** The I/O system calls include error handling mechanisms to address issues such as file not found, permission denied, or disk full. Clear error messages are provided to aid in issue resolution.

### 8.4. Extension Mechanisms

#### Extensibility Framework
The architecture of the Virtual Processor's system calls is designed with extensibility in mind. This framework allows for the seamless addition of new system calls to enhance the processor's functionality. Key components of the extensibility framework include:

- **API for System Calls:** A well-defined API allows developers to create custom system calls by providing access to essential functions and resources.
- **System Call Registration:** Developers can register new system calls with the Virtual Processor, making them available for use within assembly programs.
- **Resource Management:** The framework manages system resources efficiently, ensuring that custom system calls do not conflict with existing ones.

#### Customization Strategies
In addition to adding new system calls, developers can customize existing system calls to meet specific operational requirements. This customization can involve:

- **Parameterization:** Adjusting system call parameters to tailor their behavior to specific use cases.
- **Event Handling:** Defining custom event handlers to respond to specific events triggered by system calls.
- **User Interface Customization:** Modifying the appearance and behavior of system call interfaces to align with application requirements.

Enhancing the Virtual Processor's capabilities through these system calls ensures a versatile and user-friendly programming environment, allowing developers to create a wide range of applications and simulations within the virtual environment. These features empower users to build interactive, responsive, and feature-rich programs while streamlining the debugging and I/O processes.



## 9. Conclusion

Throughout this functional specification document, we have delineated a comprehensive framework for the construction of **Team 5's Virtual Processor**. From the foundational development environment, through the meticulous assembly language specifications, to the nuanced virtual system call implementation, each section has been carefully crafted to serve as a beacon guiding the development journey. The document has established a clear set of **functional**, **usability**, and **non-functional requirements** that are pivotal to the creation of a virtual processor that is not only a robust educational platform but also an embodiment of technical excellence.

In the pursuit of these objectives, the document emphasizes the importance of a collaborative development environment, leveraging standardized tools and practices to ensure consistency and quality in the project's outcomes. The processor's custom assembly language has been designed with an educational focus, ensuring that learning the fundamental concepts of low-level programming is both accessible and engaging. Moreover, the detailed C program development guidelines underscore the importance of a methodical approach to software construction, one that fosters **maintainability** and **scalability**.

The virtual system call implementation stands out as a feature that bridges the gap between the theoretical aspects of assembly language and practical software application, offering a suite of capabilities that will encourage innovation and exploration among its users.

As the project transitions from planning to execution, this document will act as a cornerstone, ensuring that the virtual processor is developed in alignment with the initial vision—combining educational value with practical utility. The specifications herein are not just a set of instructions; they are a commitment to quality, a reflection of our team's dedication, and a promise to deliver a product that meets the intricate demands of programming education and software development.

In conclusion, this functional specification is more than a set of guidelines—it is a narrative of our aspirations, a blueprint of our design, and a prelude to the ingenuity that Team 5 will bring to life in the Virtual Processor project.

## 10. Glossary

| Term                    | Definition                                                                                                                                                                                                        |
| ----------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **C Language**          | A general-purpose, procedural computer programming language supporting structured programming, lexical variable scope, and recursion, with a static type system.                                                  |
| **GCC**                 | The GNU Compiler Collection (GCC) is a compiler system produced by the GNU Project supporting various programming languages.                                                                                      |
| **IDE**                 | An integrated development environment (IDE) is a software application that provides comprehensive facilities to computer programmers for software development.                                                    |
| **VS Code**             | Visual Studio Code is a free source-code editor made by Microsoft for Windows, Linux, and macOS.                                                                                                                  |
| **Git**                 | Git is a distributed version-control system for tracking changes in source code during software development.                                                                                                      |
| **GitHub**              | GitHub is a provider of Internet hosting for software development and version control using Git.                                                                                                                  |
| **Assembly Language**   | A low-level programming language for a computer or other programmable device, in which there is a very strong correspondence between the language and the architecture's machine code instructions.               |
| **System Call**         | A system call is the programmatic way in which a computer program requests a service from the kernel of the operating system it is executed on.                                                                   |
| **Virtual System Call** | A virtual system call is a system call that is implemented in software rather than by the operating system.                                                                                                       |
| **Virtual Processor**   | A virtual processor is a software-based processor that executes assembly code.                                                                                                                                    |
| **Assembler**           | An assembler is a software tool that translates assembly language code into machine code, allowing it to be executed by a computer's processor. It plays a key role in the assembly language programming process. |

