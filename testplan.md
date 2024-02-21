# Virtual Processor Project Test Plan
<br>

| Authors | Mouatassime Seiv |
|---|---|
|Created|01/14/2024|
|Last Updated| 02/22/2024 |
|Status| Finish|

<br>

### Virtual Processor Project Test Plan

#### 1. Introduction

1.1 **Purpose of the Test Plan**  
   The purpose of this test plan is to ensure the successful development and deployment of the Virtual Processor Project by defining the testing approach, objectives, and strategies.

1.2 **Scope of Testing**  
   This test plan covers various testing phases, including unit testing, integration testing, system testing, and user acceptance testing, to validate the functionality, reliability, and performance of the Virtual Processor.

1.3 **GLOSSARY**

<br>

|Term|Definition|Source|
|---|---|---|
|Assembly language| An assembly language is a low-level computer language whose instructions correspond directly to the machine language instructions of a specific processor type. In assembly, human-readable mnemonics replace the binary numbers of the machine language.| [UITS](https://kb.iu.edu/d/aewk#:~:text=An%20assembly%20language%20is%20a,numbers%20of%20the%20machine%20language.)|
|Virtual Processor (CPU) | A virtual CPU (vCPU) is the processor of a virtual machine (VM). Each vCPU represents the ability to run one processing thread at a time. The VM hypervisor manages the scheduling of the vCPU time to the physical CPU.| [TechTarget](https://www.techtarget.com/whatis/definition/virtual-CPU-vCPU)|
|C Language |C is a general-purpose programming language created by Dennis Ritchie at the Bell Laboratories in 1972 it is a very popular language, despite being old. The main reason for its popularity is because it is a fundamental language in the field of computer science C is strongly associated with UNIX, as it was developed to write the UNIX operating system.| [w3schools](https://www.w3schools.com/c/c_intro.php?external_link=true)|
| Operating System | An operating system (OS) is system software that manages computer hardware and software resources, and provides common services for computer programs.| [Wikipedia](https://en.wikipedia.org/wiki/Operating_system)|
|IDE: Integrated Development Environment |An integrated development environment (IDE) is a software application that helps programmers develop software code efficiently. It increases developer productivity by combining capabilities such as software editing, building, testing, and packaging in an easy-to-use application.|[AWS Amazon](https://aws.amazon.com/what-is/ide/#:~:text=An%20integrated%20development%20environment%20IDE,easy%2Dto%2Duse%20application.)|
|GCC|The GNU Compiler Collection, commonly known as GCC, is a set of compilers and development tools available for Linux, Windows, various BSDs, and a wide assortment of other operating systems. It includes support primarily for C and C++ and includes Objective-C, Ada, Go, Fortran, and D. The Free Software Foundation (FSF) wrote GCC and released it as completely free (as in libre) software.| [incredibuild](https://www.incredibuild.com/integrations/gcc)|
|Test case| A test case, or test case, is a set of prerequisites, input data, actions and expected results, developed with the aim of verifying the proper functioning of an evolution or a product.|[Wefiit](https://www.wefiit.com/blog/rediger-cas-test-exigences#:~:text=Un%20cas%20de%20test%2C%20ou,%C3%A9volution%20ou%20d'un%20produit.)| 
| Project Manager | The project manager, as his name suggests, is a project expert and the end-to-end pilot, that is to say from its development with the client, from its planning to the delivery stage| [HEIP](https://www.heip.fr/lecole/faq/tout-savoir-sur-le-metier-de-project-manager-etudes-salaires/#:~:text=Le%20project%20manager%2C%20comme%20son,%C3%A0%20l'%C3%A9tape%20de%20livraison.)|
| QA | In the context of product and service development, quality assurance (or QA for Quality Assurance) refers to any systematic process aimed at verifying that a product or service under development complies with specific requirements.| [LeMagIT](https://www.lemagit.fr/definition/Assurance-Qualite-QA#:~:text=In%20the%20context%20of%20product%20and%20service%20development%2C%20quality%20assurance%20(or%20QA%20for%20Quality%20Assurance)%20refers%20to%20any%20systematic%20process%20aimed%20at%20verifying%20that%20a%20product%20or%20service%20under%20development%20complies%20with%20specific%20requirements.)|
| Technical Lead | He oversees the technical aspects of a software team by making architectural and design decisions, guiding team members in technical matters, and supervising system modifications. |[Ironhack](https://www.ironhack.com/gb/blog/what-is-a-tech-lead#:~:text=A%20technical%20lead%20%E2%80%93%20or%20tech,matters%2C%20and%20supervising%20system%20modifications.)|
|Software Engineer |The Software Engineer is responsible for validating software modules, their integration and maintenance. Indeed, it may be necessary to modify or improve solutions already implemented by companies for maintenance or correction purposes.| [JUNIA](https://www.junia.com/fr/fiches-metiers/ingenieur-logiciel/#:~:text=The%20Software%20Engineer%20is%20responsible%20for%20validating%20software%20modules%2C%20their%20integration%20and%20maintenance.%20Indeed%2C%20it%20may%20be%20necessary%20to%20modify%20or%20improve%20solutions%20already%20implemented%20by%20companies%20for%20maintenance%20or%20correction%20purposes.)|
| Program Manager | He is a strategic project-management professional whose job is to help oversee and coordinate the various projects, products, and other strategic initiatives across an organization.| [ARAVATI]( https://aravati.fr/fichemetier/program-manager/#:~:text=The%20Program%20Manager,of%20the%20program.) |
<br>

#### 2. Test Objectives

2.1 **Verify Instruction Execution**  
   Ensure the correctness and accuracy of the virtual processor's instruction execution.

2.2 **Integration Testing**  
   Validate the seamless integration of individual components within the virtual processor.

2.3 **Interpreter Functionality**  
   Verify the functionality of the interpreter for executing assembly code.

2.4 **Performance Assessment**  
   Assess the performance of the virtual processor under different conditions and workloads.

#### 3. Test Environment


| Task | Start Date | End Date |
| ---- | ---------- | -------- |
| Review the documentation | February 14, 2024 | March 1, 2024 |
| First meeting with Dev team | February 14, 2024 |  March 1, 2024 |
| Create and give templates | February 14, 2024 | March 1, 2024 |
| First meeting with other teams' QA | February 14, 2024 | March 1, 2024 |
| Second meeting with Dev team | February 19, 2024 | March 1, 2024 |
| GitHub Actions | February 14, 2024 | February 22, 2024 |
| Unit tests | February 14, 2023 | February 24, 2024 |
| Functional tests | February 19, 2024 | February 23, 2024 |

3.1 **Hardware Requirements**  
   Specify the hardware configurations for testing, including processor specifications and memory requirements.

3.2 **Software Requirements**  
   List the required software tools, compilers, and environments necessary for conducting tests.

#### 4. Test Strategies

4.1 **Unit Testing**  
   Develop and execute test cases to validate the functionality of individual components.

4.2 **Integration Testing**  
   Test the interaction between different modules to ensure seamless integration.

4.3 **System Testing**  
   Verify the overall functionality, reliability, and performance of the virtual processor.

4.4 **User Acceptance Testing (UAT)**  
   Conduct testing with end-users to ensure the virtual processor meets their requirements.

#### 5. Test Schedule

5.1 **Test Milestones**  
   - Unit Testing: [February 19] - [February 24]
   - Integration Testing: [February 14] - [February 22]
   - System Testing: [February 13] - [February 25]
   - UAT: [February 14] - [February 23]

5.2 **Test Deliverables**  
   - Documented test cases
   - Test results and reports for each testing phase

#### 6. Test Cases

6.1 **Unit Test Cases**  
   Develop detailed test cases for each unit or component of the virtual processor.

6.2 **Integration Test Cases**  
   Define test cases for the integration of different modules within the virtual processor.

6.3 **System Test Cases**  
   Outline test cases to validate the overall system functionality, reliability, and performance.

6.4 **UAT Test Cases**  
   Detail test cases for user acceptance testing, incorporating end-user scenarios.

#### 7. Responsibilities

Clearly define the roles and responsibilities of team members involved in testing activities, including developers, testers, and end-users.

#### 8. Risks and Contingencies

Identify potential risks associated with the testing process and propose contingency plans to mitigate these risks.

#### 9. Approvals

Obtain approvals from relevant stakeholders, including project managers, developers, and end-users, for the test plan.

#### 10. Conclusion

Summarize the key points of the test plan, emphasizing the importance of thorough testing to ensure the success of the Virtual Processor Project.

