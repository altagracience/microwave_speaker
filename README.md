**Microwave Buzzer Replacement**

Description:

This project involves replacing the buzzer in a microwave oven with a custom speaker that emits personalized messages for different actions. The hardware utilized includes an ESP8266 microcontroller, an old TV speaker, and a BGH Quick Chef microwave.

Objective:

The main goal of this project is to remove the standard buzzer from the microwave and substitute it with a speaker capable of playing custom audio messages corresponding to various microwave operations.

Hardware Used:

ESP8266: The ESP8266 is a popular microcontroller known for its Wi-Fi capabilities, making it suitable for IoT projects.
Old TV Speaker: Repurposing an old speaker from a TV for audio output.
BGH Quick Chef Microwave: The microwave used as the project's base device.

Signal Processing:

The microwave emits a 2kHz signal modulated in amplitude by a 20Hz signal, which serves two distinct purposes:
A. A short-length signal for user interaction with the microwave's buttons.
B. A longer-length signal indicating the end of a cooking cycle.

These signals are processed by the ESP8266, where they are averaged over temporal blocks to determine whether they correspond to type A or B signals. This allows triggering the appropriate audio message accordingly.

Project Status and Improvements:

While the project is functional, there is ample room for improvement. This implementation serves as one of the creator's early projects, dating back to 2018.

Demo video:

[![Alt Text](http://img.youtube.com/vi/1X3EEnkKixM/0.jpg)](http://www.youtube.com/watch?v=1X3EEnkKixM)


Contact:

For questions or further information about the project, feel free to contact the project maintainer fantinstefano96@gmail.com.

Enjoy exploring the Microwave Buzzer Replacement project!
