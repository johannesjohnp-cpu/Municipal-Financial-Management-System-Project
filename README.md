# Municipal Financial Management System (MFMS) - Project A

## Group Information
* Course: PAP521S - Programming in Practice (Project A: Foundation System)
* Group Size: 7 Students
* Due Date: 02 October 2026

### Group Members & Student Numbers
* John Pendapala Johannes (226153053) – Testing, Documentation, and Git Coordination
* Martha Ashipala (226007219) – Budget Management Module
* Tunomwaami Uajambekange Mufeti (226021955) – Asset Management Module
* Fillipus N. Kayla (225091801) – Employee Management Module
* Marj Marthin (226121992) – Supplier Management Module
* Matheus Kandjulu (226175030) – Reports Module
* Hilma Lushu (226176754) – Main Menu, Functions, Integration, and Validation



## Project Description
The Municipal Financial Management System (MFMS) is a modular console-based application developed entirely in ANSI C. It provides a foundational enterprise solution for municipal resource tracking, handling core operational domains including employee compensation, departmental budgets, supplier directories, asset inventories, and consolidated reporting.

## System Features
* Interactive Main Menu: Centralized navigation interface utilizing loops and control structures.
* Employee Management Module: Manages personnel records, salaries, and statutory allowances while preventing invalid negative entries.
* Budget Management Module: Tracks departmental allocations against expenditures and flags budget overruns.
* Supplier Management Module: Maintains active municipal supplier directories and contact details.
* Asset Management Module: Operates a structured asset register tracking valuation, condition, and departmental deployment.
* Consolidated Reports Module: Generates automated statistical overviews of workforce data, financial execution, and asset registers.


## Compilation Instructions
To compile all modular source and header files together using GCC via the terminal, run the following command in the project root directory:

gcc main.c employees.c budget.c suppliers.c assets.c reports.c -o municipal_system

## How to Run the System
After successful compilation, execute the generated binary file using:

./municipal_system
*(On Windows Command Prompt, run municipal_system.exe)*
