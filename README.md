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

## Sample Pictures
+ Calibrating for 0 units (empty scale/rack/bin)

+ Capture weight of 1 unit

+ Unit Inventory = Total weight on scale / 1 Unit weight
