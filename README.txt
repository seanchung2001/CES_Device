COMP3004B 
Final Project 
April 16, 2022


Team 18

Israel Babalola 101147765, 
Sean Chung 101156263, 
Richard Kim 101138475, and 
Erica Morgan 101015691.


The following below outlines what each member worked on:

Sean: Made CES device GUI, Power On/Off functionality, and responsible for all things done with the device battery. Helped with use cases and sequence diagrams.

Israel: Connetion.cpp, Connection.h, Within Mainwindow.cpp: blink_modeLight(), displayConnection(), clearDisplay(), checkConneciton() Helped with: Use Cases, Sequence Diagrams

Erica: Therapy.cpp, Therapy.h, Session.h, Duration.h Wrote the following functions in the Mainwindow class: getDuration(), setDuration(), setSession(), startTherapy(), endTherapy(), incIntensity(), decIntensity(), blinkOnIntensity(), blindOffIntensity() Traceability Matrix Helped with Use Case diagram and UML class diagram

Richard: All related to DBManager, UML diagram, description of design patterns used. Helped with: Use Cases, Testing


Directory Structure:

COMP3004_FinalProject_Team18:
    CES_Device:
        Directory that contains the actual source codes
        labels:
            Includes images used in the GUI
        CES.qrc - Used to retrieve the images in 'labels' directory
        CES_Device.pro - Used to configure the project on QT C++
        DBManager.cc, DBManager.h - Used to represent the DBManager system of the CES_Device that saves therapy session logs using /build-CES_Device_Desktop_Debug/database.txt
        battery.cpp, battery.h - Used to represent the battery of the CES_Device
        connectiontest.cpp, connectiontest.h - Used to implement connection test of the CES_Device to the earlobes
        duration.h - Used to create Enums to represent duration categories
        main.cpp - Main file to run the mainwindow
        mainwindow.cpp, mainwindow.h - File that acts as the main 'AI' of the project (mediator). Represents the actual CES_Device, and incoorporates other classes to run the simulation controlled via GUI.
        session.h - Used to create Enums to represent session categories
        therapy.cpp, therapy.h - Used to represent therapy sessions provided by the CES_Device

    Diagrams:
        Includes all the diagrams included in the report as PNG filesso they can be viewed easier and clearer

    Documents:
        MeetingMinutes.pdf - Minutes of all the meetings held for this project
        ProjectDesign_ClassesFunctions.pdf - Document used while planning / designing overall project and individual classes / functions
        COMP3004_FinalProject_Report.pdf - Main report of the project including use case model, diagrams, traceability matrix, and any explaination required

    build-CES_Device_Desktop_Debug: 
        Includes files necessary for running the project (.o files, executable files, ect)
        database.txt - Text file used as a session log database

    README.txt - This text file


Tested Scenarios: