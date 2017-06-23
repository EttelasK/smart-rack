Smart Rack
======================
+ Created: 2015
+ Last Updated: March 2017

Description
-----------
Smart Rack is an open source project for inventory management.  Inventory is placed on a rack or bin like scale and based on the weight of one unit, the smart-rack will be able to continuosly count how many units are in that rack/bin location  

The smart rack uses a [Particle Photon](https://docs.particle.io/guide/getting-started/intro/photon/) in order to connect back to any WMS or inventory management ERP via WiFi connection. There is a built-in LCD display on the front of the rack/bin that will display the unit quantity and allow the user to recalibrate the rack/bin for a different part.  The weight is determined via a load cell and uses the HX711ADC.h library.


Use
-----------
To provide warehouses/ stores with the most realtime and accurate inventory possible.  No more cycle counting.  No more stock outs.  Let gravity do the work for you! 

Instructions
-----------
1. The LCD will begin by Welcoming the user momentarily and then display the following message:
  ```arduino
  "REMOVE ALL"
  "TO ZERO OUT"
  ```
2. Once inventory is removed, user is to push and hold the button 1 time until the following message is displayed (light will also flash to signal button press was received):
  ```arduino
  "CALIBRATING FOR"
  "ZERO UNITS"
  ```
3. The user will then initiate the next step by press and holding the button until the following message is displayed:
  ```arduino
  "PLACE ONE UNIT"
  "ON BIN"
  ```
4. As instructed, the user will place one unit on the bin/rack in order for the load cell to capture the weight of one unit and store it in memory. Press and hold the button again once complete:
  ```arduino
  "CALIBRATED!"
  ```
5. The LCD will then display the quantity of widgets in/ on that bin/rack.  The quantites will be updated real time as units are picked or stocked to the shelf. 

## Sample Prototype
+ Calibrating for 0 units (empty scale/rack/bin):

![alt text](https://github.com/EttelasK/smart-rack/blob/master/SR-img/sr_img1.png)

+ Capture weight of 1 unit:

![alt text](https://github.com/EttelasK/smart-rack/blob/master/SR-img/sr-img2.png)

+ Unit Inventory = Total weight on scale / 1 Unit weight:

![alt text](https://github.com/EttelasK/smart-rack/blob/master/SR-img/sr-img3.png)
