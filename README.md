# Introduction

The Secure Watch Observation Response Device (S.W.O.R.D) is an advanced at-home monitoring system designed to enhance home security and provide users with convenient control over essential functions. This system allows users to lock and unlock doors, check door statuses, and arm or disarm the alarm system. With a focus on creating a reliable and responsive user experience, S.W.O.R.D integrates multiple peripherals to deliver both functionality and interactivity.

Key peripherals used in this project include:

* UART (Universal Asynchronous Receiver-Transmitter): Enables seamless communication between the microcontroller and a terminal, allowing users to control the system through a menu-based interface.
* GPIO (General-Purpose Input/Output): Provides control for physical components, such as push buttons for door and alarm interactions, as well as LEDs for status indication.
* Buzzer: Generates auditory alerts to notify users of status changes, such as locking or unlocking doors and arming/disarming the alarm.
* LEDs: Used for visual feedback, indicating system statuses, including armed/disarmed modes and door locks.

This project highlights the integration of these peripherals to create an intuitive security solution, emphasizing UART's role in facilitating real-time feedback and user interaction.

# Background and Methodology
The idea to develop an alarm system for our project stemmed from a combination of practical utility and technical curiosity. Home security systems are an essential part of modern living, offering peace of mind and convenience for users. Designing an alarm system not only allowed us to address this real-world application but also provided an opportunity to explore and deepen our understanding of embedded systems and microcontroller functionality.

S.W.O.R.D utilizes concepts regarding UART, sound generation, and general-purpose input/output.
* UART (Universal Asynchronous Receiver-Transmitter) plays a crucial role in the S.W.O.R.D system by enabling efficient and reliable communication between devices. In a security system like S.W.O.R.D, where real-time feedback and user interaction are essential, UART facilitates seamless data exchange between the microcontroller and the user’s terminal.
* Sound Generation is also integrated for alarm functionality. For instance, if the home is armed and a door is locked or unlocked, an alert sound will play through a buzzer on the microcontroller board, signaling these status changes.
* GPIO (General-Purpose Input/Output) forms the core interface, with push buttons serving as the control points for various actions, such as opening doors, locking doors, and arming/disarming the system.

We successfully achieved our project goals by leveraging UART as the primary communication interface between the microcontroller and a terminal, enabling real-time user interaction through a menu-based system. The integration of peripherals like GPIO, LEDs, and a buzzer enhanced the functionality and usability of the alarm system. GPIO pins allowed us to control the status of virtual doors, represented by LEDs, while the buzzer provided auditory feedback for system events such as locking, unlocking, and arming the alarm. Rigorous testing and iterative debugging ensured that the system was both functional and reliable, meeting our objectives of creating an intuitive, responsive, and practical security solution.

# Block Diagrams

The block diagram provided is the final result. Compared to the previous block diagram provided in the proposal, there are less hardware peripherals due to the main focus switching to UART. The second diagram illustrates the role of UART in the S.W.O.R.D system. The process begins with the user entering their selection on the terminal, which transmits the data to the receiver—the TIVA microcontroller (MCU). Upon receiving the data, the MCU executes the corresponding function and sends a response back to the terminal for user feedback.

![Block Diagram](../../../Downloads/Updated_Flow_Chart.drawio.png)

![UART Diagram](<../../../Downloads/UART Diagram.png>)