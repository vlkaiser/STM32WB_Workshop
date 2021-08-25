<!-- Using Circuit Studio Templates and Libraries -->
# STM32WB55 - STM MOOC Projects

<!-- TABLE OF CONTENTS -->
## Table of Contents

* [About the Project](#about-the-project)
* [About the Module](#about-this-module)
* [Getting Started](#getting-started)
  * [Prerequisites](#prerequisites)
  * [Installation](#installation)
* [IOC Setup](#ioc-setup)
* [Roadmap](#roadmap)
* [Contributing](#contributing)
* [Contact](#contact)
* [Acknowledgements/Resources](#acknowledgements/resources)

<!-- ABOUT THE PROJECT -->
## About The Project
This is a repository of STM32WB55 MOOC projects for personal reference.

[The STM32WB Workshop MOOC:](https://www.youtube.com/watch?v=5Lp9cDBzG94&list=PLnMKNibPkDnGRfqUO1Q_-1nW-tOKfDQbc) working through this seminar to become familiar with the the chip, bluetooth practices and the development environment. 

The goal at the end of this course is to practice the material learned by applying it towards developing an end-to-end device which: 
1. Records time, temperature, and humidity to an SD card
2. Live updates the data on an OLED display
3. Broadcasts that data periodically over bluetooth to an Android app

Then creating the android app which receives the bluetooth data and displays it.

________________________
<!-- GETTING STARTED -->
## About this Module
The [STM32WB5MMG Module](https://www.st.com/en/microcontrollers-microprocessors/stm32wb5mmg.html#overview) is a small form-factor BLE 5.0/ZigBee 3.0/Open Thread module which is certified for: ZigBee, BLE, CE, FCC, ISED-GCB, JRF, GOST, KC, NCC, IC, SRRC(?), RoHS, REACH.

8/25/2021 (DigiKey 0 stock)  
| $12.98 | Qty 01 |  
| $11.93 | Qty 10 |  
| $11.43 | Qty 25 |

[<img src="https://www.mouser.com/images/stmicroelectronics/images/P-NUCLEO-WB55_t.jpg">](https://www.mouser.com/images/stmicroelectronics/images/P-NUCLEO-WB55_t.jpg)

________________________
<!-- GETTING STARTED -->
## Getting Started

[Link to the course materials](https://www.st.com/content/st_com/en/support/learning/stm32-education/stm32-moocs/STM32WB_workshop_MOOC.html) (downloads, materials list, setup instructions)

### Prerequisites
This is an example of how to list things you need to use the software and how to install them.

* P-NUCLEO-WB55
* 128x32 OLED LCD display (“white version”)
* Four 2.54mm pitch jumpers
* 1x microUSB cable
* PC with Windows 7 (of more recent) operating system 
  * Java JRE v8 (v1.80.0_191 or newer)
  * Installed STM32WB_workshop_package_V2.1.exe (see link above)
* A smartphone (iOS 7+ or Android 5.0+) with Bluetooth v4.x and preinstalled ST BLE 
  * Sensor application (v4.1.2 or newer)
  * Charger for smartphone (nice to have)

### Installation

[Link to the course materials](https://www.st.com/content/st_com/en/support/learning/stm32-education/stm32-moocs/STM32WB_workshop_MOOC.html)

________________________
<!-- SETUP EXAMPLE -->
## IOC Setup
### Enabling Debugging in the IOC
1. System Core -> SYS -> Debug: Serial Wire

### Enabling the radios in the IOC
1. System Core -> RCC -> HSE/LSE to Crystal/Ceramic Resonator
2. System Core -> HSEM -> Activated
3. Timers -> RTC -> Activate Clock Source
4. Connectivity -> RF -> Activate RF1
5. Middleware -> STM32_WPAN -> BLE

### Enabling UART (COM Port)
1. Connectivity -> USART1 -> Mode: Asynchronous  
  * Configure Parameter Settings as appropriate (Baud, Bits, Parity, Stop, etc.)

### Enabling OLED Display (I2C)
1. Connectivity -> I2C3 -> I2C
  * GPIO Settings (SCL/SDA): Alternate Function Open Drain / Pull-up
2. System Core -> GPIO -> Select two pins for Display VDD and VSS
  * e.g. PA0 (DISP_VDD): GPIO Output HIGH / Output Push/Pull / No Pull-up / Very High Max Output  
  e.g. PA1 (DISP_VSS): GPIO Output LOW / Output Push/Pull / No Pull-up / Very High Max Output  

### Enabling Input/Output Peripherals
System Core -> GPIO
1. Pushbutton (PC4)
  * GPIO Mode: External Interrupt / Pull-up / Max Output N/A
2. LED (GR: PB0, BLUE: PB5)
  * GPIO Mode: Output Push/Pull / No Pull-up / Max Output LOW

## Clock Setup
LSE Input Frequency: 32.768kHz  
HSE Input Frequency: 32MHz

RTC/LCD Source: LSE (32.768 KHz)  
System Clock Mux: HSE_SYS (SYSCLK 32MHz)

HCLK1: 32MHz  
HCLK2: 32MHz  
I2C3 Clock Mux: PCLK1 (32MHz)  
USART1 CLock Mux: PCLK2 (32MHz)  
RFWKP Clock Mux: LSE (32.768KHz)  
SMPS Clock Mux: HSE (4MHz)

## Project Manager Setup
### Project:
Project folder settings are configured here
### Code Generator:
There is a template folder included in the MOOC project documents.  This contains libraries for the LCD (SSD1306) as well as fonts and logos. 
1. Template Settings ->  Browse to template source folder -> Open (folder)
2. Click (Add >>) or (Add All >>) to select templates to add to project
3. OK
 
_Notice: There are some differences in STM32CubeIDE versions.  If the files add to the project in their own INC/SRC folders apart from the CORE INC/SRC folders, move the tempalte files to the CORE INC/SRC folders or they will not build in the project._

### Advanced Settings:
The order in which functions are initialized.
It is important that the STM32_WPAN is initialized __last__.  
My Order:
1. GPIO
2. RCC
3. I2C3
4. USART1
5. RF
6. RTC
7. STM32_WPAN
________________________
<!-- ROADMAP -->
## Roadmap

See the [open issues](https://www.zoho.com) for a list of proposed features (and known issues).

________________________
<!-- CONTRIBUTING -->
## Contributing

Please follow these steps to contribute to the Project

Fork the Project
Create your Feature Branch (`git checkout -b feature/AmazingFeature`)  
Commit your Changes (`git commit -m 'Add some AmazingFeature`)  
Push to the Branch (`git push origin feature/AmazingFeature`)  
Open a Pull Request  


________________________
<!-- LICENSE -->
## License

Whatever STMicroelectronics has for their stuff  
MIT Open Source for my stuff

<!-- CONTACT -->
## Contact

________________________
<!-- ACKNOWLEDGEMENTS -->
## Acknowledgements/Resources
* [Markdown Cheat Sheet](https://www.markdownguide.org/cheat-sheet/)
* [Git Cheat Sheet](https://github.github.com/training-kit/downloads/github-git-cheat-sheet.pdf)