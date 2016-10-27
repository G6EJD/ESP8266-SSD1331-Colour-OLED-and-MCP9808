# ESP8266-SSD1331-Colour-OLED-and-MCP9808

This code displays a temperature reading from the highly accurate MCP9808 temperature sensor
on a colour 0.96" OLED which uses the SSD1331 chipset. Display resolution is 96x64 pixels.

Installation:

1. Create a library folder called 'SSD1331' the folder name does not really matter
2. Copy the following updated files into the new folder: Adafruit_SSD1306.CPP and Adafruit_SSD1306.H
3. Connect ESP8266 to SSD1331 display as per included diagram
4. Optionally, connect MCP9890 to ESP8266 as per included diagram (omit this device if not required)
5. Compile code and upload to ESP8266 to display the temperature from the MCP9808 or to conduct a display test.

Alternatively

6. Compile and upload 'ESP8266_Colour_OLED_SSD1331_Test.ino' that will demonstrate all of the OLED functions in colour
7. Note the test runs once only, reset to repeat or move the commands into the programme loop section.
8. Enjoy!

Get a display from here: https://www.aliexpress.com/item/Free-Shipping-0-95-inch-7pin-Full-Color-65K-Color-ssd1331-OLED-Display-3-3v-5v/32646204260.html?spm=2114.01010208.0.0.VIMSHX

