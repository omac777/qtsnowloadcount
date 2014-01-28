qtsnowloadcount<br>
===============<br>
<br>
c++-based qt for android(necessitas) wizard gui example with serialization and with sendsms<br>
This project loves to open by default into the desktop target.  In order to target the android project,
you need to click on the projects button in the left pane of the qtcreator IDE.<br>  
Then select the android armv7 target.<br>
Then click the configure button.<br>
Then rebuild project.<br>
Then Deploy and run.<br>

If your android is connected to your computer, then the deploy and run will automagically happen onto your android phone.
If the SendSMS doesn't work, it's because the AndroidManifest.xml permissions have not been generated properly
into the apk file.
Modify the AndroidManifest.xml file outside of the qtcreator ide, then ndk_build then ant dist/debug.
