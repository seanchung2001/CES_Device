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

    1)  Normal Use:
            Pressed the power button to turn the device on.
            Observed the battery level being displayed.
            Chose a session and duration using buttons on GUI.
            Started the session.
            Observed the device showing result of the connection test.
            Observed the battery level slightly decreasing.
            Observed the soft on functionality slowly increasing the intensity.
            Adjusted the intensity using 'UP' / 'DOWN' buttons.
            Observed the topmost number light blinking.
            Pressed the 'Record Session' button to save the therapy session information.
            After few minutes, the session has ended.
            Observed soft off functionality slowly decreasing the intensity.
            Observed the device powered off automatically.
            Pressed the 'View Session Logs' button to view the therapy session log.
        
        This scenario tested Use cases: 1, 3, 4, 5, 6, 7.
    
    2)  Powering off during a session:
            Pressed the power button to turn the device on.
            Observed the battery level being displayed.
            Chose a session and duration using buttons on GUI.
            Started the session.
            Observed the device showing result of the connection test.
            Observed the battery level slightly decreasing.
            Observed the soft on functionality slowly increasing the intensity.
            Pressed the power button again to end the session early and turn the device off.
            Observed soft off functionality slowly decreasing the intensity.
            Observed the device powered off.
        
        This scenario tested Use cases: 1, 2, 3, 4, 5.
    
    3)  Replacing battery:
            Pressed the power button to turn the device on.
            Observed the battery level being displayed.
            Pressed the power button again to turn the device off.
            Observed soft off functionality slowly decreasing the intensity.
            Observed the device powered off.
            Pressed the 'Replace Battery' button to replace the battery.
            Pressed the power button to turn the device on again.
            Observed the battery level is back to 800.
        
        This scenario tested Use cases: 1, 2, 3.
    
    4)  Connection Test:
            Pressed the power button to turn the device on.
            Observed the battery level being displayed.
            Chose a session and duration using buttons on GUI.
            Started the session.
            Observed the device showing result of the connection test.

            This sccenario has 3 variations:
                1) With all 4 checkboxes clicked (Left Ear, Right Ear, Wet earlobe (L), Wet earlobe(R))
                2) With only 2 checkboxes clicked (Left Ear, Right Ear)
                3) With no checkboxes clicked.
            
            1 results in "Excellent Connection"
            2 results in "Okay Connection"
            3 results in "No Connection"

        This scenario tested Use cases: 1, 4, 5.
