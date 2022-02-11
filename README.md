# OTA_ESP32

## Creating a secure ESP32 OTA update system based on a Python server, MySQL and using TCP connections

**/!\ Warning this project is in developpement and don't have yet securities. Tcp exchanges are in clear text !!!**


### Goal :
  - The code is easy to read and coder-friendly
  - The update system is easy to set-up
  - The process is secure and don't have security issues.
  - The system is be user friendly
  
### How to use :
  - Clone the project
  - Import the MYSQL database
  - Insert in the database your device information and the updates.
  - Modify the Python Server.py parameters depending on your Mysql database authentification and execute it.
  - Modify the ESP32 parameters depending the device and networking informations you want and upload the code on your device
  
### Known bugs :
  - Memory corruption if too much OTA updates are done or the updates are not finished... To resolve just upload the code with the cable.
  
### Upcoming : 
  - Complete installation guide
  - Completely secure transactions
  - GUI
