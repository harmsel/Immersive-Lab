# HvA_Immersive_Lab
This repository is intended for the users of the Immersive Lab at the Hogeschool van Amsterdam (HvA). 
The templates and code in this repository are free to use for Students and Staff of the HvA; this includes commercial use. Other users should stick to the Creative Commons Attribution-NonCommercial 4.0 International license.

The template has several blocks with ready to use components. Each component should have a description on what it does.

The SandBox folder contains several examples of interaction  components that can be reused in the main template.

## Projecting content into the Immersive Lab

The template to project content in to the lab can be found into the file "Immersive_room_HvA_template_NO_license.toe"

Open the file and load the content into TouchDesigner; for videos or images you can use the Movie_file_in TOP operator. Connect the output of this operator to the node on the inputs block where you want to project the content.

### Content splitter

In order to split content trough all the four walls use the the "NLsplitter_for_walls" under the Wall-splitter-Experimental block. Content should be in 16:9 ratio

Connect the content as input on the right of the component and link the outputs to the corresponding walls. 
You can see the name of the wall by hoevering on each output.

Use the custom parameters to fine tune the mapping

## Zig Sim App

Zig sim app is a third party app  that can be used to use the sensors of a smartphone as data input to modify content.

The pro version, aka payed version, allows to use Face an body recognition using ArKit; it also provides functionality to use the depth camera of the smart phone.

The app requires to stablish communication using OSC between the mobile device and the computer.

Here is documentation of the app https://1-10.github.io/zigsim/getting-started.html

Here are some tutorials on the basic set up using TouchDesigner: 

https://youtu.be/pwwuZj8KK6M?si=1FDtNI06D6hz5EgV

https://youtu.be/dfKfVJfy7SI?si=m3RAjZf14sFxH8wb

### Depth Camera

The pro version also allows you to use your smartphone's depth camera. 

Set up:
Make sure the NDI SDK is installed on your computer. You can download it from here. https://ndi.video/download-ndi-sdk/

Once the SDK is installed, follow the following steps:
* Make sure your phone and computer are on the same network. At the University, you must create a hotspot for communication to work.
* Get the IP address of your phone.
* Selecting the NDI sensor in the Zif Sim app and click start.
  * Select the world option on the NDI options.
* Add the NDI In TOP to your TouchDesigner network.
  * Write the IP of your phone on the "Extra Search IPs."
  * Your phone should now be selectable on the Source field. By selecting it, you should see the image.
  * The depth info is coded in the alpha channel. Use a Chamix TOP to extract it; follow https://youtu.be/dfKfVJfy7SI?si=m3RAjZf14sFxH8wb for more details. 
