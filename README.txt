MPS FINAL PROJECT

Description:
	-Our project is to connect a PIR sensor and a camera to the microcontroler to create our own
	 alarm system. Whenever the PIR sensor was triggered the camera would snap a picture of what
	 triggered it and store that in a folder for the user to see.

Dependencies:	
	-Need GPIO, DCMI, DMA and USB (For Webcam) I2C (Camera Module) libraries 
	Webcam:
		-Install USBH DRIVER VIDEO from https://github.com/iliasam/STM32_HOST_UVC_Camera
		(Still needs updating a lot of errors and warnings in usbh_video_desc_parsing.c and 
		usbh_video_stream_parsing.c)
		-Need to add VIDEO Class to debug and C/C++ General Path
		-HAL_Drivers Libraries needed: DCMI, DMA, DMA2, TIM, EXTI,I2C

How it works:
	-usb_host.c has all the usb intializations most of it was written by the same person
	 who made the driver however we updated USBH_UserProcess 
	-In main.c we intialized GPIO for everything in the case that it worked however ran into 
	 trouble with using DMA to streamline process so it was removed the only GPIO we still use 
	 is for pin J0 for the PIR sensor 
	-In our main we have a while loop that constantly checks if the PIR sensor has a high and if
	 it does then we call our camera function to take the picture and then place the picture in a 
	 directory of our choice 
	 
Problems we had:
	-When we were first working on this project the camera module we had did not have pins for HSYNCH
	 or PIXCLK so it was unable to work with the DCMI which caused us to move over to a webcam connected
	 through the USB 
	-USB Webcam is not a HID or MSC so we did not have drivers for it and the only driver we could find was
	 on someones github which was riddled with errors and warnings throught 
	-We were unable to get another camera leaving us fixing the driver without being able to test and see if 
	 it worked as intended 
	-Adding to the path for debugging is not fun when you don't know how to do it and you need to add a new class to the 
	 General Path, Need to add to the object list(I think at least we did) in Debug and fix GDB things
	 

Contributions and Updates:
	-https://github.com/mattlevine68/MPS-Final-Project (version with DCMI and camera module that could not connect)
	-Submitting to submitty version with usb Webcam that can't connect because of driver
	-Python code for Raspberry Pi will be uploaded to Submitty 
	
Version:
	-Webcam folder is final version
	-Bash file is Raspberry Pi version
	-OV5467 folder is DCMI/I2C version
	
Future Versions:
	-With a correct camera module use DCMI to interface with it 
	-Create our own USBH Driver Class when we have the knowledge
	-Add LCD screen.
